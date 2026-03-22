# FROZEN_INPUT_MANIFEST

## Run role

This manifest records the frozen baseline input package that anchors the **first update-2026 comparison run**.

It is a concise reference manifest only.

## Frozen inputs

| Category | Frozen artifact(s) | Status for first update-2026 comparison run |
| --- | --- | --- |
| Source under test | `baseline/Lab/boolean_algebra.cpp` | MUST NOT EDIT |
| Source under test header | `baseline/Lab/includes/boolean_algebra.h` | MUST NOT EDIT |
| Research prompt | `prompts/replication/baseline/common_ASIL_assistant_test_instructions.md` | MUST NOT EDIT |
| Research prompt | `prompts/replication/baseline/ASIL_a_assistant_test_instructions.md` | MUST NOT EDIT |
| Expected generated test target | `results/first_baseline_run/generated/generated_test_file.cpp` | MUST NOT EDIT |
| Generated test build wrapper | `results/first_baseline_run/generated/CMakeLists.txt` | MUST NOT EDIT |
| Build/test procedure reference | `scripts/run_first_baseline.sh` | HOLD CONSTANT FOR FIRST COMPARISON |
| Build integration reference | `CMakeLists.txt` | HOLD CONSTANT FOR FIRST COMPARISON |
| Baseline library build reference | `baseline/Lab/CMakeLists.txt` | HOLD CONSTANT FOR FIRST COMPARISON |

## Allowed changes during execution/logging only

For the first update-2026 comparison run, only new run-specific evidence may be added, such as:

- a separate update-2026 results directory;
- rendered prompt text for that new run;
- raw model output for that new run;
- generated test files for that new run;
- build/test/coverage logs for that new run; and
- run-specific metadata and assessment files.

## Explicit non-goals

- Do not edit the frozen baseline artifacts listed above.
- Do not overwrite `results/first_baseline_run/` baseline evidence.
- Do not start the update-2026 comparison run from this manifest.
