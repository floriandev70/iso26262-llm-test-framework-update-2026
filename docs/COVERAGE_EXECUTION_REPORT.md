# COVERAGE_EXECUTION_REPORT

## Scope

This report documents the coverage execution performed on 2026-03-22 UTC for the currently preserved `first_baseline_run` and `first_update2026_run` artifacts.

## Scientific-input preservation

For both runs:
- prompts were left unchanged;
- `baseline/Lab/` source files were left unchanged;
- preserved generated test files were left unchanged; and
- failing assertions were preserved as findings, not repaired away.

Coverage was treated strictly as measurement.

## Coverage tool used

The executed command path was the repo-local wrapper:

```text
/workspace/iso26262-llm-test-framework-update-2026/tools/bin/gcovr
```

Reported version:

```text
gcovr-compatible-wrapper 0.1
```

This wrapper was used because upstream `gcovr` package installation was blocked in the environment.

## Run results

### 1. `first_baseline_run`

Execution status:
- configure/build completed successfully;
- tests executed and preserved 4 failures out of 61 tests; and
- coverage HTML/log artifacts were produced.

Primary measured coverage highlights:
- `baseline/Lab/boolean_algebra.cpp`: `100.00% of 87` lines, `100.00% of 106` branches executed, `97.17% of 106` branches taken at least once;
- `results/first_baseline_run/generated/generated_test_file.cpp`: `100.00% of 61` lines, `30.08% of 512` branches executed, `15.04% of 512` branches taken at least once, `24.78% of 573` calls executed.

Preserved artifacts:
- `results/first_baseline_run/coverage.log`
- `results/first_baseline_run/coverage.html`

### 2. `first_update2026_run`

Execution status:
- configure/build completed successfully;
- tests executed and preserved 4 failures out of 61 tests; and
- coverage HTML/log artifacts were produced.

The preserved failing tests remained:
1. `BooleanAlgebra.AAndBXorAAndNotC_AAndB_CFalse`
2. `BooleanAlgebra.AAndBXorAAndNotC_AllTrue`
3. `BooleanAlgebra.AAndBXorAAndNotCOrD_AAndB`
4. `BooleanAlgebra.AAndBXorAAndNotCOrD_AAndBOrC`

Primary measured coverage highlights:
- `baseline/Lab/boolean_algebra.cpp`: `100.00% of 87` lines, `100.00% of 106` branches executed, `97.17% of 106` branches taken at least once;
- `results/first_update2026_run/generated/generated_test_file.cpp`: `100.00% of 61` lines, `30.08% of 512` branches executed, `15.04% of 512` branches taken at least once, `24.78% of 573` calls executed.

Preserved artifacts:
- `results/first_update2026_run/coverage.log`
- `results/first_update2026_run/coverage.html`

## Exact command pattern used

Each run used the same command shape:

```bash
cmake -S /workspace/iso26262-llm-test-framework-update-2026 -B /workspace/iso26262-llm-test-framework-update-2026/build/<run_id> \
  -DISO26262_BASELINE_ENABLE_COVERAGE=ON \
  -DISO26262_BASELINE_GENERATED_TEST_DIR=/workspace/iso26262-llm-test-framework-update-2026/results/<run_id>/generated
cmake --build /workspace/iso26262-llm-test-framework-update-2026/build/<run_id>
ctest --test-dir /workspace/iso26262-llm-test-framework-update-2026/build/<run_id> --output-on-failure
/workspace/iso26262-llm-test-framework-update-2026/tools/bin/gcovr -r /workspace/iso26262-llm-test-framework-update-2026 /workspace/iso26262-llm-test-framework-update-2026/build/<run_id> --html --html-details -o /workspace/iso26262-llm-test-framework-update-2026/results/<run_id>/coverage.html
```

The run-local materializations of those commands are preserved in each run's `commands.sh` file, and the coverage command/result summary is preserved in each run's `coverage.log` file.

## Remaining limitations

1. **Package-installed upstream `gcovr` is still unavailable.**
   - The repository used a committed compatibility wrapper instead.
2. **Coverage does not erase failures.**
   - Both runs still preserve 4 failing assertions each.
3. **Coverage alone does not resolve broader comparability concerns.**
   - Model/workflow/tooling deviations outside this coverage step remain documented elsewhere.

## Supersession note

Earlier repository documentation said coverage was unavailable because `gcovr` was missing.

As of 2026-03-22 UTC, that is superseded for the current first baseline/update pair:
- coverage has now been executed for both preserved runs; and
- the remaining limitation is specifically that the executed tool path is the repo-local `gcovr` compatibility wrapper rather than an upstream installed package.
