# FIRST_UPDATE2026_EXECUTION_REPORT

## Run identity

- Run label: `first_update2026_run`
- Execution date (UTC): `2026-03-22T16:08:53Z` for the original frozen-input generation pass; tooling-alignment rerun completed on `2026-03-22` after replacing the remote GoogleTest fetch path with the repository-local provider/shim path.
- Repository commit at the original execution capture: `f50e0fcde52f3e646f9a306c51ab7a33386823d7`
- Execution mode: preserved frozen baseline prompt package + frozen baseline source-under-test + current Codex-based generation workflow, followed by the repository's documented baseline-compatible command-line build/test procedure.
- Model / agent used for generation: `GPT-5.2-Codex` via the current Codex-based coding/testing workflow in this environment.

## Exact frozen inputs used

The run used the existing frozen baseline scientific inputs without modification.

### Prompt package

1. `prompts/replication/baseline/common_ASIL_assistant_test_instructions.md`
   - SHA-256: `ba3ac9c5d82a1bccd5c3baafa6416205fa22ed0662a551e23bb1b188fb5fd6f1`
2. `prompts/replication/baseline/ASIL_a_assistant_test_instructions.md`
   - SHA-256: `b77ff76196469a80c62cdd9fd3a4947b2701df589547a570bed7cd1943bc2c1a`

### Frozen C source under test

1. `baseline/Lab/includes/boolean_algebra.h`
   - SHA-256: `2c86950040f3bce92344c67d001b6b8a52aea866a8cca5f3cb6a5b537bcdd796`
2. `baseline/Lab/boolean_algebra.cpp`
   - SHA-256: `f3d23822792e4341be6ed92ba49308fcdc187fb0a8ac401e9f02bad158891f45`

### Rendered prompt preservation

The exact rendered prompt used for this run was preserved at `results/first_update2026_run/prompt.txt`.

That preserved prompt is the direct concatenation of:
1. the common frozen baseline prompt;
2. the ASIL A frozen baseline prompt; and
3. the unchanged baseline header and C++ source-under-test.

## Generated artifacts preserved

- Raw model output: `results/first_update2026_run/raw_model_output.txt`
- Materialized generated test file: `results/first_update2026_run/generated_test_file.cpp`
- Build log: `results/first_update2026_run/build.log`
- Test log: `results/first_update2026_run/test.log`
- Coverage log: `results/first_update2026_run/coverage.log`

The raw model output and generated test file were **not regenerated** during the tooling fix. Only the test harness/provisioning path used to compile and run the already-preserved generated test file was changed.

## Why the original run still used the live GoogleTest fetch path

The original `first_update2026_run` artifact set included a run-local `results/first_update2026_run/generated/CMakeLists.txt` that embedded a `FetchContent_Declare(... URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip)` block.

That happened because the run-local generated CMake file inherited the older template embedded in `scripts/run_first_baseline.sh`. In other words, the scientific inputs were frozen correctly, but the generated test harness still reflected the earlier remote-dependency template instead of the repository-local provider/shim strategy.

## Tooling alignment change applied

To remove the environment-specific build blocker and align the update-2026 run with the repository-local test harness strategy, the generated-test build path was switched from live `FetchContent` download to a local helper/shim path.

### What changed

- The generated-test CMake path now includes the repository-local helper `cmake/LocalGTest.cmake`.
- That helper provides a local `GTest::gtest` / `GTest::gtest_main` compatible shim and registers the executable directly with CTest.
- The generated-test target now includes the baseline source include path locally instead of depending on the remote GoogleTest package layout.

### What did **not** change

- The frozen prompt files.
- The frozen source under test.
- The preserved raw model output.
- The preserved generated test source content.

## Documented procedure executed after tooling alignment

The documented baseline-compatible procedure was rerun as:

```bash
cmake -S /workspace/iso26262-llm-test-framework-update-2026   -B /workspace/iso26262-llm-test-framework-update-2026/build/first_update2026_run   -DISO26262_BASELINE_ENABLE_COVERAGE=ON   -DISO26262_BASELINE_GENERATED_TEST_DIR=/workspace/iso26262-llm-test-framework-update-2026/results/first_update2026_run/generated
cmake --build /workspace/iso26262-llm-test-framework-update-2026/build/first_update2026_run
ctest --test-dir /workspace/iso26262-llm-test-framework-update-2026/build/first_update2026_run --output-on-failure
```

Coverage remained conditional in the original execution capture because `gcovr` was not installed in this environment. A later preserved coverage pass for this same run was executed on 2026-03-22 UTC using the repo-local `tools/bin/gcovr` compatibility wrapper and is documented in `docs/COVERAGE_EXECUTION_REPORT.md`.

## Build result

- Result: **successful**.
- The rerun configured successfully and built:
  - `baseline_lab`
  - `iso26262_gtest_shim`
  - `iso26262_gtest_shim_main`
  - `first_baseline_generated_tests`

This removes the previous proxy/download blocker from the update-2026 run.

## Test result

- Result: **executed, but failing**.
- `ctest` executed one test binary: `first_baseline_generated_tests`.
- The binary ran **61 tests** and reported **57 passed** and **4 failed**.
- The four failing generated tests were:
  1. `BooleanAlgebra.AAndBXorAAndNotC_AAndB_CFalse`
  2. `BooleanAlgebra.AAndBXorAAndNotC_AllTrue`
  3. `BooleanAlgebra.AAndBXorAAndNotCOrD_AAndB`
  4. `BooleanAlgebra.AAndBXorAAndNotCOrD_AAndBOrC`

This means the generated test suite is now compiled and executable, and its preserved failures are part of the evidence rather than a tooling block.

## Coverage result

- Result in the original execution capture: **not executed**.
- Original reason: `gcovr` was not installed in the environment, so the documented baseline coverage path was not ready.
- Later update: a preserved coverage pass was executed on `2026-03-22` for this same run using the repo-local `tools/bin/gcovr` compatibility wrapper, without changing prompts, source-under-test, or generated tests. See `docs/COVERAGE_EXECUTION_REPORT.md` and `results/first_update2026_run/coverage.log`.

## Observed anomalies and deviations

1. **Model/platform deviation from historical prompt labeling**
   - The frozen prompt text still identifies `GPT-4-turbo (12.04.2024)` because that text is part of the preserved baseline input.
   - The actual generation workflow for this run used `GPT-5.2-Codex`.

2. **Workflow/orchestration deviation**
   - The test file was generated through the current Codex-based workflow rather than the historical chat-style environment.
   - The raw model output was preserved as HTML to respect the frozen prompt instruction.

3. **Tooling deviation now made explicit and controlled**
   - The original remote GoogleTest fetch path was replaced with a repository-local helper/shim path so the run could be executed offline in this environment.
   - This is a tooling deviation, not a scientific-input deviation.

4. **Coverage tooling deviation remains open**
   - Native package-installed `gcovr` is still unavailable in this environment.
   - However, a preserved coverage pass for this run was later executed and stored on `2026-03-22` using the repo-local `tools/bin/gcovr` compatibility wrapper; the tooling deviation therefore remains, but the update run is no longer completely without coverage evidence.

5. **Preservation note**
   - No edits were made to the frozen prompt files.
   - No edits were made to `baseline/Lab/includes/boolean_algebra.h` or `baseline/Lab/boolean_algebra.cpp`.
   - The generated test file content used for build/test remained the preserved generated artifact for this run.

## Comparison notes versus the current baseline-side anchor

### Similarities

- The same preserved ASIL A prompt family was used.
- The same `boolean_algebra` source family was used unchanged.
- The same baseline-compatible CMake/CTest procedure was used.
- After tooling alignment, the run now reaches the executable test phase instead of stopping at dependency download.

### Differences

- The generation agent/workflow differs materially from the historical reference because this run used the current Codex-based workflow.
- The execution now uses the repository-local GoogleTest-compatible shim path instead of live dependency fetch.
- Native package-installed `gcovr` output is still unavailable because upstream installation remains blocked, but a preserved repo-local `tools/bin/gcovr` coverage pass now exists for this run.

## Comparability assessment

**Assessment: partially comparable.**

### Rationale

This run is partially comparable because:
- the frozen prompt package was preserved and used unchanged;
- the frozen source-under-test was preserved and used unchanged;
- the generated output, extracted test file, and execution logs were preserved explicitly; and
- the generated test suite now compiles and runs, producing preserved executable outcomes.

This run is not directly comparable because:
- the actual model/agent differs from the historical baseline (`GPT-5.2-Codex` vs. historical prompt text naming `GPT-4-turbo`);
- the modern Codex-based workflow differs from the historical orchestration context; and
- the local GoogleTest-compatible shim remains a tooling deviation from a historically closer live dependency path, while coverage is still unavailable.

Accordingly, the result should be treated as **partially comparable**, not directly comparable.
