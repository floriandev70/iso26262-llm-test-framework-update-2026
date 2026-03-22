#!/usr/bin/env bash
set -euo pipefail

usage() {
  cat <<'EOF'
Usage:
  scripts/run_first_baseline.sh --run-id <run_id> [options]

Purpose:
  Execute the first minimal baseline-aligned run procedure for the imported
  baseline corpus. The script is deterministic orchestration only; it does not
  generate tests itself.

Required for an actual run:
  --run-id <run_id>
  --raw-output <path>
  --generated-test-source <path>

Options:
  --function <name>               Baseline target function. Default: check_a_OR_b
  --module <name>                 Baseline module stem. Default: boolean_algebra
  --asil <level>                  Preserved ASIL prompt variant. Default: A
  --raw-output <path>             Raw model output file to preserve
  --generated-test-source <path>  Generated test source file to preserve/build
  --build-root <path>             Build root directory. Default: build
  --results-root <path>           Results root directory. Default: results
  --coverage-tool <name>          auto|gcovr|none. Default: auto
  --dry-run                       Validate prerequisites and emit commands only
  --help                          Show this message

Examples:
  scripts/run_first_baseline.sh --run-id baseline-a-001 --dry-run

  scripts/run_first_baseline.sh \
    --run-id baseline-a-001 \
    --raw-output /tmp/raw_model_output.txt \
    --generated-test-source /tmp/boolean_algebra_generated_tests.cpp
EOF
}

RUN_ID=""
FUNCTION_NAME="check_a_OR_b"
MODULE_NAME="boolean_algebra"
ASIL_LEVEL="A"
RAW_OUTPUT_PATH=""
GENERATED_TEST_SOURCE=""
BUILD_ROOT="build"
RESULTS_ROOT="results"
COVERAGE_TOOL="auto"
DRY_RUN=0

while [[ $# -gt 0 ]]; do
  case "$1" in
    --run-id)
      RUN_ID="${2:?missing value for --run-id}"
      shift 2
      ;;
    --function)
      FUNCTION_NAME="${2:?missing value for --function}"
      shift 2
      ;;
    --module)
      MODULE_NAME="${2:?missing value for --module}"
      shift 2
      ;;
    --asil)
      ASIL_LEVEL="${2:?missing value for --asil}"
      shift 2
      ;;
    --raw-output)
      RAW_OUTPUT_PATH="${2:?missing value for --raw-output}"
      shift 2
      ;;
    --generated-test-source)
      GENERATED_TEST_SOURCE="${2:?missing value for --generated-test-source}"
      shift 2
      ;;
    --build-root)
      BUILD_ROOT="${2:?missing value for --build-root}"
      shift 2
      ;;
    --results-root)
      RESULTS_ROOT="${2:?missing value for --results-root}"
      shift 2
      ;;
    --coverage-tool)
      COVERAGE_TOOL="${2:?missing value for --coverage-tool}"
      shift 2
      ;;
    --dry-run)
      DRY_RUN=1
      shift
      ;;
    --help)
      usage
      exit 0
      ;;
    *)
      echo "Unknown argument: $1" >&2
      usage >&2
      exit 2
      ;;
  esac
done

if [[ -z "${RUN_ID}" ]]; then
  echo "Error: --run-id is required." >&2
  usage >&2
  exit 2
fi

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
COMMON_PROMPT="${REPO_ROOT}/prompts/replication/baseline/common_ASIL_assistant_test_instructions.md"
ASIL_PROMPT="${REPO_ROOT}/prompts/replication/baseline/ASIL_${ASIL_LEVEL,,}_assistant_test_instructions.md"
HEADER_PATH="${REPO_ROOT}/baseline/Lab/includes/${MODULE_NAME}.h"
SOURCE_PATH="${REPO_ROOT}/baseline/Lab/${MODULE_NAME}.cpp"
RUN_RESULTS_DIR="${REPO_ROOT}/${RESULTS_ROOT}/${RUN_ID}"
GENERATED_DIR="${RUN_RESULTS_DIR}/generated"
BUILD_DIR="${REPO_ROOT}/${BUILD_ROOT}/${RUN_ID}"

require_file() {
  local path="$1"
  if [[ ! -f "${path}" ]]; then
    echo "Required file missing: ${path}" >&2
    exit 1
  fi
}

require_command() {
  local cmd="$1"
  if ! command -v "${cmd}" >/dev/null 2>&1; then
    echo "Required command missing: ${cmd}" >&2
    exit 1
  fi
}

resolve_coverage_tool() {
  case "${COVERAGE_TOOL}" in
    auto)
      if command -v gcovr >/dev/null 2>&1; then
        echo "gcovr"
      else
        echo "none"
      fi
      ;;
    gcovr|none)
      echo "${COVERAGE_TOOL}"
      ;;
    *)
      echo "Unsupported --coverage-tool value: ${COVERAGE_TOOL}" >&2
      exit 2
      ;;
  esac
}

require_command cmake
require_command ctest
require_command git
require_file "${COMMON_PROMPT}"
require_file "${ASIL_PROMPT}"
require_file "${HEADER_PATH}"
require_file "${SOURCE_PATH}"

SELECTED_COVERAGE_TOOL="$(resolve_coverage_tool)"

mkdir -p "${RUN_RESULTS_DIR}"

{
  echo "run_id=${RUN_ID}"
  echo "module=${MODULE_NAME}"
  echo "function=${FUNCTION_NAME}"
  echo "asil=${ASIL_LEVEL}"
  echo "dry_run=${DRY_RUN}"
  echo "coverage_tool=${SELECTED_COVERAGE_TOOL}"
  echo "repo_root=${REPO_ROOT}"
  echo "git_commit=$(git -C "${REPO_ROOT}" rev-parse HEAD)"
  echo "utc_timestamp=$(date -u +"%Y-%m-%dT%H:%M:%SZ")"
} > "${RUN_RESULTS_DIR}/metadata.env"

cat \
  "${COMMON_PROMPT}" \
  "${ASIL_PROMPT}" \
  "${HEADER_PATH}" \
  "${SOURCE_PATH}" \
  > "${RUN_RESULTS_DIR}/prompt.txt"

cat > "${RUN_RESULTS_DIR}/commands.sh" <<EOF
cmake -S ${REPO_ROOT} -B ${BUILD_DIR} \\
  -DISO26262_BASELINE_ENABLE_COVERAGE=ON \\
  -DISO26262_BASELINE_GENERATED_TEST_DIR=${GENERATED_DIR}
cmake --build ${BUILD_DIR}
ctest --test-dir ${BUILD_DIR} --output-on-failure
EOF

if [[ "${SELECTED_COVERAGE_TOOL}" == "gcovr" ]]; then
  cat >> "${RUN_RESULTS_DIR}/commands.sh" <<EOF
gcovr -r ${REPO_ROOT} ${BUILD_DIR} --html --html-details -o ${RUN_RESULTS_DIR}/coverage.html
EOF
fi

if [[ "${DRY_RUN}" -eq 1 ]]; then
  {
    echo "Dry-run status: OK"
    echo "Results directory prepared at: ${RUN_RESULTS_DIR}"
    echo "Prompt package preserved at: ${RUN_RESULTS_DIR}/prompt.txt"
    echo "Commands prepared at: ${RUN_RESULTS_DIR}/commands.sh"
    if [[ -z "${RAW_OUTPUT_PATH}" ]]; then
      echo "Raw model output not provided; actual run remains blocked."
    fi
    if [[ -z "${GENERATED_TEST_SOURCE}" ]]; then
      echo "Generated test source not provided; actual run remains blocked."
    fi
    if [[ "${SELECTED_COVERAGE_TOOL}" == "none" ]]; then
      echo "gcovr not available; coverage would need an explicitly documented alternative."
    fi
  } | tee "${RUN_RESULTS_DIR}/dry_run.log"
  exit 0
fi

if [[ -z "${RAW_OUTPUT_PATH}" || -z "${GENERATED_TEST_SOURCE}" ]]; then
  echo "Actual run requires both --raw-output and --generated-test-source." >&2
  exit 2
fi

require_file "${RAW_OUTPUT_PATH}"
require_file "${GENERATED_TEST_SOURCE}"

mkdir -p "${GENERATED_DIR}" "${BUILD_DIR}"
cp "${RAW_OUTPUT_PATH}" "${RUN_RESULTS_DIR}/raw_model_output.txt"
cp "${GENERATED_TEST_SOURCE}" "${GENERATED_DIR}/$(basename "${GENERATED_TEST_SOURCE}")"

GENERATED_TEST_BASENAME="$(basename "${GENERATED_TEST_SOURCE}")"

cat > "${GENERATED_DIR}/CMakeLists.txt" <<EOF
cmake_minimum_required(VERSION 3.20)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(first_baseline_generated_tests
  ${GENERATED_TEST_BASENAME}
)

target_link_libraries(first_baseline_generated_tests
  PRIVATE
    baseline_lab
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(first_baseline_generated_tests)
EOF

cmake -S "${REPO_ROOT}" -B "${BUILD_DIR}" \
  -DISO26262_BASELINE_ENABLE_COVERAGE=ON \
  -DISO26262_BASELINE_GENERATED_TEST_DIR="${GENERATED_DIR}" \
  2>&1 | tee "${RUN_RESULTS_DIR}/configure.log"

cmake --build "${BUILD_DIR}" 2>&1 | tee "${RUN_RESULTS_DIR}/compiler.log"
ctest --test-dir "${BUILD_DIR}" --output-on-failure 2>&1 | tee "${RUN_RESULTS_DIR}/test_execution.log"

if [[ "${SELECTED_COVERAGE_TOOL}" == "gcovr" ]]; then
  gcovr -r "${REPO_ROOT}" "${BUILD_DIR}" --html --html-details -o "${RUN_RESULTS_DIR}/coverage.html" \
    2>&1 | tee "${RUN_RESULTS_DIR}/coverage.log"
else
  {
    echo "Coverage not executed."
    echo "Reason: gcovr not available in the current environment."
    echo "Alternative tooling is not auto-selected to avoid undocumented deviations."
  } | tee "${RUN_RESULTS_DIR}/coverage.log"
fi
