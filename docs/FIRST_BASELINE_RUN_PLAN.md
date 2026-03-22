# FIRST_BASELINE_RUN_PLAN

## Purpose

This document defines the **first minimal baseline-aligned run** that becomes possible after the initial controlled import recorded in `docs/BASELINE_IMPORT_LOG.md`.

The goal of this first run is not to reproduce the full historical study at once. The goal is to execute **one small, prompt-preserved, auditable replication unit** using the imported baseline source-under-test and the imported baseline ASIL A prompt package.

## Selected initial replication unit

Recommended first unit under test:
- module: `baseline/Lab/boolean_algebra.cpp`
- initial function target: `check_a_OR_b`
- prompt family: common baseline prompt + ASIL A baseline prompt

### Why this unit

- It is small and reviewable.
- It belongs to the historical `boolean_algebra` task family identified in `docs/REPLICATION_SPEC.md`.
- It supports a low-ambiguity first compile/run cycle before importing broader prompt families or higher-ASIL coverage guidance.

## Prerequisites

1. **Toolchain**
   - CMake 3.20 or newer
   - A C++17-capable compiler
   - Python 3 for optional helper scripting or prompt materialization
2. **Generated-test harness content**
   - A future run-specific directory under `results/<run_id>/generated/` containing:
     - the raw model output
     - the materialized generated test source file(s)
     - a small `CMakeLists.txt` that builds those generated tests against `baseline_lab`
3. **GoogleTest availability**
   - The generated-test `CMakeLists.txt` should fetch or otherwise provide GoogleTest explicitly for the run, because this first import intentionally does not pull it into the repository root build yet.
4. **Evidence logging destination**
   - A run directory under `results/<run_id>/` prepared according to `docs/EVIDENCE_LOGGING.md`

## Required prompt package for the first run

The first run should preserve, at minimum:

- `prompts/replication/baseline/common_ASIL_assistant_test_instructions.md`
- `prompts/replication/baseline/ASIL_a_assistant_test_instructions.md`
- the selected source context for `baseline/Lab/includes/boolean_algebra.h`
- the selected implementation context for `baseline/Lab/boolean_algebra.cpp`

### Assumption recorded explicitly

This first plan assumes **no additional historical knowledge attachment** is required for the first ASIL A trial. If a run chooses to attach a knowledge file, that file must be imported and logged before the run is treated as baseline-aligned.

## Suggested run directory layout

```text
results/
  <run_id>/
    metadata.json
    prompt.txt
    raw_model_output.txt
    generated/
      CMakeLists.txt
      boolean_algebra_generated_tests.cpp
    compiler.log
    test_execution.log
    coverage.log
    assessment.md
```

## Commands to run

The following command sequence defines the minimal baseline-aligned run once the generated tests have been materialized.

### 1. Create a run directory

```bash
mkdir -p results/<run_id>/generated build/<run_id>
```

### 2. Preserve the rendered prompt package

Example approach:

```bash
cat \
  prompts/replication/baseline/common_ASIL_assistant_test_instructions.md \
  prompts/replication/baseline/ASIL_a_assistant_test_instructions.md \
  baseline/Lab/includes/boolean_algebra.h \
  baseline/Lab/boolean_algebra.cpp \
  > results/<run_id>/prompt.txt
```

### 3. Store the raw model output

```bash
cp <raw_model_output_source> results/<run_id>/raw_model_output.txt
```

### 4. Configure the build using the generated-test directory

```bash
cmake -S . -B build/<run_id> \
  -DISO26262_BASELINE_ENABLE_COVERAGE=ON \
  -DISO26262_BASELINE_GENERATED_TEST_DIR=$PWD/results/<run_id>/generated
```

### 5. Build

```bash
cmake --build build/<run_id> | tee results/<run_id>/compiler.log
```

### 6. Execute tests

```bash
ctest --test-dir build/<run_id> --output-on-failure | tee results/<run_id>/test_execution.log
```

### 7. Run coverage collection

Example with `gcovr`:

```bash
gcovr -r . build/<run_id> --html --html-details -o results/<run_id>/coverage.html \
  | tee results/<run_id>/coverage.log
```

If `gcovr` is unavailable, preserve the exact alternative coverage-tool invocation and explain the deviation in `results/<run_id>/assessment.md`.

## Expected outputs and artifacts

A successful first minimal baseline-aligned run should preserve:

- the exact rendered prompt in `results/<run_id>/prompt.txt`
- the raw model output in `results/<run_id>/raw_model_output.txt`
- generated test source file(s) in `results/<run_id>/generated/`
- build logs in `results/<run_id>/compiler.log`
- test execution logs in `results/<run_id>/test_execution.log`
- coverage command output in `results/<run_id>/coverage.log`
- any derived HTML coverage report such as `results/<run_id>/coverage.html`
- a final assessment document in `results/<run_id>/assessment.md`

## Success criteria for the first baseline-aligned run

The first run counts as successful when all of the following hold:

1. the run targets a function mapped clearly to the historical baseline corpus;
2. the common baseline prompt and ASIL A prompt are both preserved in the run record;
3. the generated tests are preserved as files;
4. the imported source-under-test is not modified during the run;
5. the generated tests compile against `baseline_lab`, or a compile failure is itself preserved as the faithful outcome;
6. test execution output is preserved;
7. at least statement/line-oriented coverage collection is attempted and logged; and
8. the final assessment states whether the run is comparable, partially comparable, or not comparable.

## What remains incomplete after this import step

Even after this first import, the following work remains incomplete:

- importing and versioning the ASIL B and ASIL D prompt variants
- importing any historical knowledge files that prove necessary for specific baseline runs
- creating deterministic helper scripts for prompt materialization and run logging
- defining a standard generated-test `CMakeLists.txt` template for run directories
- executing and preserving the first actual generated-test run
- extending baseline replication beyond one small boolean function to `math_lib` and `real_world`
- evaluating branch and MC/DC-oriented baseline runs
- comparing reproduced results against manuscript claims only where the evidence chain is complete

## Deliberate non-goals of this step

This step does **not**:

- claim any reproduced metric or coverage result
- import historical handwritten tests as if they were generated-test evidence
- execute extension experiments
- modernize or refactor the baseline source beyond minimal compile-enabling adaptations documented in `docs/BASELINE_IMPORT_LOG.md`
