# FROZEN_BASELINE_INPUTS

## Purpose

This document freezes the baseline-side comparison inputs that must remain unchanged for the **first update-2026 comparison run**.

It defines the minimum baseline artifact set that the update-2026 run must compare against.

It does **not** start the update-2026 run.

## Frozen baseline inputs

The following artifacts are the frozen baseline comparison inputs for the first update-2026 comparison run.

### 1. Source-under-test artifacts

- `baseline/Lab/boolean_algebra.cpp`
- `baseline/Lab/includes/boolean_algebra.h`

These files define the baseline task unit that must remain fixed for the first comparison run.

### 2. Frozen research prompt artifacts

- `prompts/replication/baseline/common_ASIL_assistant_test_instructions.md`
- `prompts/replication/baseline/ASIL_a_assistant_test_instructions.md`

These prompt files are the exact baseline-aligned research prompt inputs referenced by the first baseline run procedure.

### 3. Expected generated test target artifacts

- `results/first_baseline_run/generated/generated_test_file.cpp`
- `results/first_baseline_run/generated/CMakeLists.txt`

These files define the preserved generated baseline test material that anchors the first comparison pair.

### 4. Build and test procedure references

- `scripts/run_first_baseline.sh`
- `CMakeLists.txt`
- `baseline/Lab/CMakeLists.txt`

These files define the documented baseline build/test materialization path and the build integration expected by the frozen baseline inputs.

## Freeze rule

For the **first update-2026 comparison run**, the baseline comparison question must be constrained as follows:

- the source-under-test task unit stays fixed to `boolean_algebra` / `check_a_OR_b` within the preserved baseline source tree;
- the baseline research prompt files stay text-identical;
- the preserved baseline generated test target stays unchanged as the baseline-side comparison anchor; and
- the update-2026 run must be recorded separately rather than by editing the baseline-side evidence.

## Files that must not be edited

The following files must **not** be edited for the first update-2026 comparison run:

- `baseline/Lab/boolean_algebra.cpp`
- `baseline/Lab/includes/boolean_algebra.h`
- `prompts/replication/baseline/common_ASIL_assistant_test_instructions.md`
- `prompts/replication/baseline/ASIL_a_assistant_test_instructions.md`
- `results/first_baseline_run/generated/generated_test_file.cpp`
- `results/first_baseline_run/generated/CMakeLists.txt`

The following procedure references should also remain unchanged during the first comparison run unless a deviation is explicitly declared **before** execution:

- `scripts/run_first_baseline.sh`
- `CMakeLists.txt`
- `baseline/Lab/CMakeLists.txt`

## Files that may change during execution/logging only

No frozen baseline input listed above may change during execution.

For the first update-2026 comparison run, only **new run-specific outputs** may be created or updated, for example:

- a new update-2026 results directory under `results/`;
- run-specific logs such as prompt renderings, raw model output, build logs, test logs, and coverage logs for the new run;
- run-specific metadata or assessment files for the new run; and
- build artifacts under a run-specific build directory.

These execution/logging outputs must be stored as new evidence and must **not** overwrite the frozen baseline-side artifacts.

## Minimal audit conclusion

For the first update-2026 comparison run, the frozen baseline input set is:

1. baseline boolean source/header pair;
2. baseline common + ASIL A prompt files;
3. preserved baseline generated test target; and
4. the documented baseline build/test procedure references.

Any deviation from this frozen set must be documented explicitly before the comparison run starts.
