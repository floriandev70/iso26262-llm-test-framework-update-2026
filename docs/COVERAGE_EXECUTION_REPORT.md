# COVERAGE_EXECUTION_REPORT

## Scope

This report documents the coverage execution performed on 2026-03-22 UTC for the currently preserved `first_baseline_run` and `first_update2026_run` artifacts.

## Scientific-input preservation

For both runs:
- prompts were left unchanged;
- `baseline/Lab/` source files were left unchanged;
- preserved generated test files were left unchanged; and
- the original 4 failing generated assertions were preserved as findings.

Coverage was treated strictly as measurement.

## Supplemental test scope added for full module coverage

The preserved generated tests covered `boolean_algebra.cpp`, but did not exercise `math_lib.cpp` or `real_world.cpp`.

To ensure that all baseline `.cpp` modules were actually exercised, a deterministic repository-authored supplemental file was added:

- `tests/supplemental_all_cpp_tests.cpp`

This supplemental file was linked beside the preserved generated tests in the run-local executable. It adds direct tests for:
- arithmetic and reference functions in `math_lib.cpp`;
- `Temp_Calc_Pres_Wacol_Temp_48V`; and
- `check_abort` plus `autom_MCU_state_machine` in `real_world.cpp`.

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
- the combined executable ran 103 tests total;
- 99 tests passed and 4 generated tests failed; and
- coverage HTML/log artifacts were produced.

Primary measured coverage highlights:
- `baseline/Lab/boolean_algebra.cpp`: `100.00% of 87` lines, `100.00% of 106` branches executed, `97.17% of 106` branches taken at least once;
- `baseline/Lab/math_lib.cpp`: `91.88% of 160` lines, `100.00% of 148` branches executed, `77.70% of 148` branches taken at least once;
- `baseline/Lab/real_world.cpp`: `93.48% of 46` lines, `100.00% of 25` branches executed, `92.00% of 25` branches taken at least once.

Preserved artifacts:
- `results/first_baseline_run/coverage.log`
- `results/first_baseline_run/coverage.html`

### 2. `first_update2026_run`

Execution status:
- configure/build completed successfully;
- the combined executable ran 103 tests total;
- 99 tests passed and 4 generated tests failed; and
- coverage HTML/log artifacts were produced.

The preserved failing generated tests remained:
1. `BooleanAlgebra.AAndBXorAAndNotC_AAndB_CFalse`
2. `BooleanAlgebra.AAndBXorAAndNotC_AllTrue`
3. `BooleanAlgebra.AAndBXorAAndNotCOrD_AAndB`
4. `BooleanAlgebra.AAndBXorAAndNotCOrD_AAndBOrC`

Primary measured coverage highlights:
- `baseline/Lab/boolean_algebra.cpp`: `100.00% of 87` lines, `100.00% of 106` branches executed, `97.17% of 106` branches taken at least once;
- `baseline/Lab/math_lib.cpp`: `91.88% of 160` lines, `100.00% of 148` branches executed, `77.70% of 148` branches taken at least once;
- `baseline/Lab/real_world.cpp`: `93.48% of 46` lines, `100.00% of 25` branches executed, `92.00% of 25` branches taken at least once.

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
2. **The all-module coverage pass includes supplemental repository-authored tests.**
   - This broadens module coverage, but it is distinct from the preserved generated test content.
3. **Coverage does not erase the original generated failures.**
   - Both runs still preserve the same 4 failing generated assertions.
4. **Coverage alone does not resolve broader comparability concerns.**
   - Model/workflow/tooling deviations outside this coverage step remain documented elsewhere.

## Supersession note

Earlier repository documentation said coverage was unavailable because `gcovr` was missing, and later that only `boolean_algebra.cpp` was effectively exercised by the generated tests.

As of 2026-03-22 UTC, that is superseded for the current first baseline/update pair:
- coverage has now been executed for both preserved runs;
- all three baseline `.cpp` modules are exercised by the combined test executable; and
- the remaining limitation is specifically that the executed tool path is the repo-local `gcovr` compatibility wrapper and that full-module coverage depends in part on supplemental repository-authored tests.
