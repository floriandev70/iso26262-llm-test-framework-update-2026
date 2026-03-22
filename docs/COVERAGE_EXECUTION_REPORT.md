# COVERAGE_EXECUTION_REPORT

## Scope

This report covers coverage execution status as of 2026-03-22 UTC for the currently preserved run artifacts in this repository.

## Run inventory assessed

### 1. `first_update2026_run`

Status: **coverage executed with preserved failing tests left intact**.

Why this run was eligible:
- preserved generated test source exists;
- preserved raw model output exists;
- preserved run-local generated CMake content exists; and
- the configure/build/test workflow is executable in the current environment.

### 2. `first_baseline_run`

Status: **coverage not executed**.

Why this run was not re-measured here:
- the repository still treats it as a partially prepared anchor rather than a complete executable baseline-aligned run; and
- this task explicitly forbids changing scientific inputs, so no missing baseline-side experimental inputs were invented or regenerated.

## `first_update2026_run` execution record

### Scientific-input preservation

The following inputs were left unchanged during coverage execution:

- frozen prompt package already preserved under `results/first_update2026_run/prompt.txt`;
- source under test under `baseline/Lab/`;
- preserved raw model output under `results/first_update2026_run/raw_model_output.txt`; and
- preserved generated tests under `results/first_update2026_run/generated/generated_test_file.cpp`.

Coverage was treated purely as post-generation measurement.

### Tool enablement outcome

Attempted native `gcovr` enablement:

```bash
python3 -m venv .venv/gcovr
.venv/gcovr/bin/pip install gcovr==8.4
apt-get update && apt-get install -y gcovr
```

Observed outcome:
- package retrieval was blocked by HTTP 403 proxy/network failures; therefore
- native `gcovr` reporting was still unavailable in this container.

### Commands actually executed for coverage measurement

```bash
cmake -S . -B build/first_update2026_run \
  -DISO26262_BASELINE_ENABLE_COVERAGE=ON \
  -DISO26262_BASELINE_GENERATED_TEST_DIR=/workspace/iso26262-llm-test-framework-update-2026/results/first_update2026_run/generated
cmake --build build/first_update2026_run
ctest --test-dir build/first_update2026_run --output-on-failure
gcov --version | head -n 1
gcov -b -c build/first_update2026_run/baseline/Lab/CMakeFiles/baseline_lab.dir/boolean_algebra.cpp.gcno
gcov -b -c build/first_update2026_run/generated_baseline_tests/CMakeFiles/first_baseline_generated_tests.dir/generated_test_file.cpp.gcno
```

The full terminal output for these commands was preserved in `results/first_update2026_run/coverage.log`.

## Observed outcomes for `first_update2026_run`

### Test execution outcome

Coverage execution did **not** hide test failures.

Observed preserved outcome:
- 61 tests executed;
- 57 tests passed; and
- 4 tests failed.

The failing tests remained:
1. `BooleanAlgebra.AAndBXorAAndNotC_AAndB_CFalse`
2. `BooleanAlgebra.AAndBXorAAndNotC_AllTrue`
3. `BooleanAlgebra.AAndBXorAAndNotCOrD_AAndB`
4. `BooleanAlgebra.AAndBXorAAndNotCOrD_AAndBOrC`

### Coverage measurements obtained from `gcov`

#### Source under test: `baseline/Lab/boolean_algebra.cpp`

- Lines executed: `100.00% of 87`
- Branches executed: `100.00% of 106`
- Branches taken at least once: `97.17% of 106`

#### Generated tests: `results/first_update2026_run/generated/generated_test_file.cpp`

- Lines executed: `100.00% of 61`
- Branches executed: `30.08% of 512`
- Branches taken at least once: `15.04% of 512`
- Calls executed: `24.78% of 573`

## Artifacts preserved

### Required artifacts completed

- `results/first_update2026_run/coverage.log`
- `results/first_update2026_run/coverage.html`
- `docs/COVERAGE_ENABLEMENT.md`
- `docs/COVERAGE_EXECUTION_REPORT.md`

### Additional preserved intermediate evidence

Run-local `.gcov` intermediates were also preserved temporarily under:

- `results/first_update2026_run/.coverage_tmp/`

These files are direct outputs of the executed `gcov` commands and support auditability of the HTML artifact.

## Remaining limitations

1. **No native `gcovr` binary or Python package was installed.**
   - The environment blocked package retrieval, so the report is a `gcov`-based fallback.
2. **Coverage is currently asymmetric across the first baseline/update pair.**
   - `first_update2026_run` now has preserved coverage evidence; `first_baseline_run` still does not.
3. **Coverage should not be overstated as equivalence evidence.**
   - This report adds measurement evidence, but it does not remove model, workflow, or tooling deviations already documented elsewhere.
4. **Failing assertions remain part of the finding set.**
   - Coverage availability is not a justification to alter generated tests or reinterpret the failures as tooling noise.

## Supersession note

Earlier repository documentation stated that coverage for `first_update2026_run` was unavailable because `gcovr` was missing.

As of 2026-03-22 UTC, that statement is no longer fully accurate for the update run:
- native `gcovr` is still unavailable; but
- preserved fallback coverage measurement has now been executed and stored for `first_update2026_run`.
