# FIRST_UPDATE2026_COMPARISON_SCOPE

## Purpose

This document defines the minimal, explicit scope of the **first update-2026 comparison run**.

It is intentionally narrow so that the first comparison remains audit-friendly and does not silently alter the baseline-side input package.

This document does **not** authorize or start the run.

## Comparison unit

The first update-2026 comparison run is scoped to a single frozen baseline task unit:

- module: `boolean_algebra`
- primary comparison anchor function: `check_a_OR_b`
- source-under-test location: `baseline/Lab/boolean_algebra.cpp`
- paired header location: `baseline/Lab/includes/boolean_algebra.h`

## Frozen baseline inputs used by this scope

The following baseline artifacts are in scope as fixed inputs and must remain unchanged:

### Frozen source-under-test

- `baseline/Lab/boolean_algebra.cpp`
- `baseline/Lab/includes/boolean_algebra.h`

### Frozen prompt inputs

- `prompts/replication/baseline/common_ASIL_assistant_test_instructions.md`
- `prompts/replication/baseline/ASIL_a_assistant_test_instructions.md`

### Frozen baseline generated-test anchor

- `results/first_baseline_run/generated/generated_test_file.cpp`
- `results/first_baseline_run/generated/CMakeLists.txt`

### Frozen procedure references

- `scripts/run_first_baseline.sh`
- `CMakeLists.txt`
- `baseline/Lab/CMakeLists.txt`

## Forbidden modifications during the first comparison run

The following changes are out of scope and forbidden for the first update-2026 comparison run:

- editing the baseline source/header under test;
- editing the baseline research prompt files;
- editing or replacing the preserved baseline generated test anchor files;
- changing the baseline-side task unit from `boolean_algebra` / `check_a_OR_b` without a pre-run deviation record; and
- overwriting baseline-side evidence inside `results/first_baseline_run/`.

## Allowed changes during execution/logging only

The following are allowed, but only as **new run evidence** for the update-2026 side:

- creating a separate update-2026 run directory under `results/`;
- preserving the rendered update-2026 prompt package for that new run;
- preserving new raw model output for that new run;
- preserving new generated test material for that new run;
- preserving build/test/coverage logs for that new run; and
- creating a run-specific build directory for that new run.

These allowed changes must be additive and must not modify the frozen baseline inputs.

## Expected comparison boundary

For the first update-2026 comparison run, the comparison boundary is:

- **held constant:** baseline task unit, baseline source-under-test, baseline prompt inputs, and baseline generated-test anchor;
- **allowed to vary only on the update side with preservation:** the newly produced update-2026 prompt rendering, raw output, generated tests, and execution logs; and
- **not yet a valid comparison dimension unless produced symmetrically:** coverage-backed claims.

## Minimal execution rule

Before the first update-2026 comparison run begins, the operator should confirm that:

- the frozen baseline inputs listed above are unchanged;
- the new run will write only to a separate update-2026 evidence location; and
- no baseline-side artifact will be edited in place.
