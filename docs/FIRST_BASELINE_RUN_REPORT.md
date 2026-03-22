# FIRST_BASELINE_RUN_REPORT

## Current run status

Status as of 2026-03-22 UTC: **partially prepared, not yet a fully executed baseline-aligned run**.

What is now working:
- the imported baseline source tree is present under `baseline/Lab/`;
- the baseline library configures and builds with the repository root CMake entrypoint;
- a deterministic run script exists at `scripts/run_first_baseline.sh`;
- the script preserves prompt inputs, records commands, records run metadata, and can execute an actual run once real generated tests and raw model output are supplied.

What is not yet complete:
- no preserved raw model output for the first run has been supplied in this repository;
- no preserved generated baseline test source has been supplied in this repository;
- therefore no valid baseline-aligned generated-test execution has yet been completed or claimed.

## Baseline-minimum structure verification

The imported baseline-minimum structure was verified against the current repository layout:

- root build entrypoint: `CMakeLists.txt`.【F:CMakeLists.txt†L1-L23】
- imported baseline source-under-test tree: `baseline/Lab/`.【F:baseline/Lab/CMakeLists.txt†L1-L8】
- imported baseline prompt files for the first ASIL A run:
  - `prompts/replication/baseline/common_ASIL_assistant_test_instructions.md`
  - `prompts/replication/baseline/ASIL_a_assistant_test_instructions.md`.【F:docs/FIRST_BASELINE_RUN_PLAN.md†L31-L38】
- run-evidence destination root: `results/`.【F:results/README.md†L1-L23】

The baseline library build itself was also verified successfully with the existing imported source set. The current minimal build target is `baseline_lab`.【F:baseline/Lab/CMakeLists.txt†L1-L8】

## Minimal fixes applied

Only the minimal missing execution scaffolding required for a reproducible first baseline-aligned run was added:

1. Added `scripts/run_first_baseline.sh` to make the first run procedure deterministic and file-backed instead of ad hoc. The script:
   - validates prerequisites;
   - preserves the prompt package;
   - records exact commands;
   - writes run metadata;
   - supports a `--dry-run` validation mode; and
   - performs configure/build/test/coverage steps only when real generated tests and raw model output are provided.【F:scripts/run_first_baseline.sh†L1-L253】
2. Added this report to record the current status and observed behavior without overstating success.【F:docs/FIRST_BASELINE_RUN_REPORT.md†L1-L85】
3. Added `docs/KNOWN_BLOCKERS.md` to separate remaining execution blockers from implemented repository scaffolding.【F:docs/KNOWN_BLOCKERS.md†L1-L41】

No baseline source-under-test logic was modified.

## Prerequisites

### Required tools

- CMake 3.20 or newer.【F:CMakeLists.txt†L1-L2】
- A C++17-capable compiler.【F:CMakeLists.txt†L3-L6】
- `ctest`, installed with CMake.
- `git`, used to capture the source revision in run metadata.【F:scripts/run_first_baseline.sh†L146-L162】

### Required run inputs for an actual baseline-aligned execution

- preserved raw model output file for the chosen first run;
- preserved generated test source file derived from that raw model output;
- the imported common prompt and ASIL A prompt files;
- the target baseline header and implementation for the chosen module/function.

The script currently defaults to the smallest planned first target:
- module: `boolean_algebra`
- function: `check_a_OR_b`
- ASIL level: `A`.【F:scripts/run_first_baseline.sh†L37-L45】

### Optional tool

- `gcovr` for HTML coverage output. If `gcovr` is absent, the script records that coverage was not executed automatically rather than silently substituting another tool.【F:scripts/run_first_baseline.sh†L122-L139】【F:scripts/run_first_baseline.sh†L248-L253】

## Exact commands

### Verification commands executed during this repository preparation

```bash
cmake -S . -B build/check
cmake --build build/check
scripts/run_first_baseline.sh --run-id dry-run-boolean-a-001 --dry-run
```

### Deterministic command to perform the first actual baseline-aligned run

```bash
scripts/run_first_baseline.sh \
  --run-id baseline-a-001 \
  --raw-output <path-to-raw-model-output.txt> \
  --generated-test-source <path-to-generated-test-source.cpp>
```

### Exact build/test/coverage commands materialized by the script

For each run, the script preserves a `results/<run_id>/commands.sh` file containing the exact commands it intends to run.【F:scripts/run_first_baseline.sh†L167-L179】

For an actual run these commands are, in effect:

```bash
cmake -S <repo_root> -B build/<run_id> \
  -DISO26262_BASELINE_ENABLE_COVERAGE=ON \
  -DISO26262_BASELINE_GENERATED_TEST_DIR=results/<run_id>/generated
cmake --build build/<run_id>
ctest --test-dir build/<run_id> --output-on-failure
gcovr -r <repo_root> build/<run_id> --html --html-details -o results/<run_id>/coverage.html
```

The final `gcovr` command is included only when `gcovr` is actually available in the execution environment.【F:scripts/run_first_baseline.sh†L175-L179】

## Observed build/test/coverage behavior

### Baseline library build

Observed behavior:
- configuration succeeded;
- compilation succeeded;
- `baseline_lab` was built successfully;
- no generated tests were built in that verification step because no generated-test directory was supplied.

This confirms that the imported baseline source tree is currently buildable in its minimal separated form.

### Dry-run behavior

A dry-run was executed using:

```bash
scripts/run_first_baseline.sh --run-id dry-run-boolean-a-001 --dry-run
```

Observed dry-run behavior:
- the script created a run directory under `results/dry-run-boolean-a-001/`;
- the prompt package was preserved in `prompt.txt`;
- `metadata.env` and `commands.sh` were generated;
- the script correctly reported that the actual run remains blocked because no raw model output or generated test source was provided;
- the script also reported that `gcovr` is unavailable in the current environment.

This is a valid preparation/dry-run result, not an executed baseline experiment result.

## Blocking issues, if any

The remaining blockers for a clean baseline-aligned execution are:

1. missing preserved raw model output for the selected first run;
2. missing preserved generated unit test source file for that raw output;
3. missing installed `gcovr` in the current environment, which prevents the script from completing the documented default HTML coverage step automatically.

These blockers are documented separately in `docs/KNOWN_BLOCKERS.md`.【F:docs/KNOWN_BLOCKERS.md†L1-L41】

## Remaining gaps before a fully valid baseline replication

Even after these minimal preparation fixes, the repository is still short of a fully valid first baseline replication because:

- the actual model invocation record is not yet preserved;
- the actual generated test artifact is not yet preserved;
- no generated tests have yet been compiled and executed from repository evidence;
- no coverage result has yet been produced from a real generated-test run;
- comparability to the historical baseline remains only provisional until a real run record exists with inputs, outputs, and assessment.

Accordingly, this repository is now **execution-ready for the first minimal baseline path**, but it does **not** yet contain a completed baseline-aligned replication run.
