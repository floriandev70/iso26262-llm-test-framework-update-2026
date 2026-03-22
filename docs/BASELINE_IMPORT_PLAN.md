# BASELINE_IMPORT_PLAN

## Purpose

This document defines a **controlled migration plan** for baseline-relevant artifacts from the historical repository into `iso26262-llm-test-framework-update-2026`.

Historical reference repository:
- <https://github.com/floriandev70/iso26262-llm-test-framework>

This plan is intentionally conservative:
- it does **not** authorize copying files by itself;
- it distinguishes **baseline replication needs** from convenience items;
- it treats the old repository as **reference input only** until each artifact is reviewed; and
- it optimizes for the **minimum reproducible baseline run** before any extension work.

## Classification legend

- **required for baseline replication**: needed to reproduce the baseline workflow in a defensible way.
- **useful but optional**: helpful for convenience, validation, or developer ergonomics, but not strictly required for a first controlled baseline run.
- **not needed**: should not be migrated for the baseline phase, or should remain historical reference only.
- **unclear / needs decision**: evidence exists, but the exact migration treatment is ambiguous and should be decided explicitly before import.

## Artifact-by-artifact plan

| Historical artifact | Classification | Purpose | Why needed / not needed | Target location in new repo | Migration mode |
| --- | --- | --- | --- | --- | --- |
| `CMakeLists.txt` (repo root) | required for baseline replication | Defines the top-level build, C++17 requirement, coverage-flag behavior in Debug, GoogleTest fetching, and test enablement. | A first reproducible baseline run needs a baseline-compatible build entrypoint. The exact file should still be reviewed instead of copied blindly because successor-repo evidence and logging requirements may require edits. | `CMakeLists.txt` or baseline-specific build wrapper such as `baseline/CMakeLists.txt` | **rewrite**, using the historical file as reference |
| `Lab/CMakeLists.txt` | required for baseline replication | Defines how the `Lab/` sources and tests are compiled into the unit-test executable and registered with GoogleTest. | Without the `Lab` build wiring, the baseline source modules cannot be compiled and executed in a comparable way. | `baseline/Lab/CMakeLists.txt` or equivalent under the new baseline source tree | **rewrite** with minimal deviations |
| `Lab/includes/` | required for baseline replication | Declares the baseline functions and interfaces for the modules under test. | The headers are part of the source-under-test context and required to compile a baseline-compatible run. | `baseline/Lab/includes/` | **copy** only after reviewed import; preserve provenance |
| `Lab/boolean_algebra.cpp` | required for baseline replication | Provides the baseline boolean-logic functions used for logic-heavy unit-test generation tasks. | `boolean_algebra` is one of the baseline task families already identified in this repo's replication spec. | `baseline/Lab/boolean_algebra.cpp` | **copy** only after reviewed import |
| `Lab/math_lib.cpp` | required for baseline replication | Provides arithmetic / utility-style functions, including both original and refactored variants visible in the historical headers and source. | `math_lib` is a baseline task family needed to cover non-boolean unit-test generation tasks. | `baseline/Lab/math_lib.cpp` | **copy** only after reviewed import |
| `Lab/real_world.cpp` | required for baseline replication | Provides the application-style functions, including `check_abort` and the MCU state machine. | `real_world` is the baseline task family needed to represent more realistic application logic. | `baseline/Lab/real_world.cpp` | **copy** only after reviewed import |
| `prompts/common_ASIL_assistant_test_instructions.md` | required for baseline replication | Common base prompt shared by the ASIL-specific prompt variants. | The baseline workflow is prompt-driven; this common prompt is part of the minimum preserved prompt package. | `prompts/replication/baseline/common_ASIL_assistant_test_instructions.md` | **copy** with provenance note, or **rewrite** only if formatting/metadata changes are needed |
| `prompts/ASIL_a_assistant_test_instructions.md` | required for baseline replication | ASIL A prompt extension targeting requirement-derived tests and full line/statement coverage. | Required because ASIL A is explicitly part of the baseline prompt family and likely the minimum first-run target. | `prompts/replication/baseline/ASIL_a_assistant_test_instructions.md` | **copy** with provenance note |
| `prompts/ASIL_b_assistant_test_instructions.md` | required for baseline replication | ASIL B prompt extension covering equivalence classes, boundary values, statement coverage, and branch coverage. | Required for full baseline-family replication even if not needed for the *first* run. | `prompts/replication/baseline/ASIL_b_assistant_test_instructions.md` | **copy** with provenance note |
| `prompts/ASIL_d_assistant_test_instructions.md` | required for baseline replication | ASIL D prompt extension targeting branch and MC/DC-oriented generation. | Required for a complete baseline replication scope because ASIL D is explicit in both the historical repository and current replication spec. | `prompts/replication/baseline/ASIL_d_assistant_test_instructions.md` | **copy** with provenance note |
| `prompts/knowledge/` | required for baseline replication | Supplemental knowledge files used alongside the prompt family (`equivalence_partitioning_boundary.md`, `hints_for_testing.md`, `mcc.md`, `mcdc.md`). | The historical repository treats these as part of prompting context, so preserving prompt provenance requires them. | `prompts/replication/baseline/knowledge/` | **copy** with provenance note |
| `main/main.cpp` | useful but optional | Provides a small executable entry point. | A first baseline replication run can focus on the unit-test executable and coverage workflow without needing the standalone main program. Keep only if a later workflow or IDE setup depends on it. | `baseline/main/main.cpp` or omit initially | **reference** first; copy only if needed |
| `main/CMakeLists.txt` | useful but optional | Builds the `main_exec` target around `main.cpp`. | Not required for the minimum baseline test-generation and coverage path; useful only if preserving the historical project shape proves helpful. | `baseline/main/CMakeLists.txt` or omit initially | **reference** first |
| `Lab/tests/` | useful but optional | Contains historical GoogleTest suites for the baseline modules. | These tests are useful as reference validation and smoke checks, but they are not themselves the target of LLM test generation. Importing them too early risks conflating baseline reference tests with generated tests. | `reference/baseline_tests/` or `baseline/reference_tests/` kept clearly separate from generated tests | **reference** first; later **copy** into a clearly separated location if approved |
| `.github/workflows/ci.yml` | useful but optional | Encodes CI build, test, and Linux coverage automation. | Helpful as a reference for environment and command choices, but CI is secondary evidence and should not block the first local reproducible baseline run. | `.github/workflows/baseline-ci.yml` or future workflow location | **rewrite** from reference, not direct copy |
| `README.md` | useful but optional | Summarizes repository structure, build commands, prompt layout, and coverage tooling. | Important as a human-readable baseline reference, but not a primary artifact to import. The new repo should document its own controlled process instead of inheriting the old README wholesale. | `docs/BASELINE_ARTIFACT_INVENTORY.md` and related docs | **reference only** |
| `paper/` (mentioned in historical README) | unclear / needs decision | Historical manuscript or paper material, if actually present. | The README says a `paper/` directory exists, but this analysis could not verify its contents directly from accessible repository pages. It may help terminology mapping, but it is not needed for the first reproducible run. | `docs/reference/paper/` only if later verified and approved | **reference only** until existence and relevance are confirmed |
| `scripts/` (mentioned in historical README) | unclear / needs decision | Potential helper scripts. | The README mentions optional helper scripts, but accessible repository pages did not verify concrete script files. Do not assume they exist. | future `scripts/reference/` only if verified | **reference only** until verified |
| Historical generated test outputs / HTML deliverables described by prompts | not needed | Prior generated outputs from the old study, if any exist outside source control or in prior runs. | Historical generated tests are reference evidence, not newly reproduced results, and must not be imported as if they were baseline replications in this repo. | none for direct import; could later be cataloged under a separate historical-evidence registry | **reference only** |
| Historical coverage reports / result tables / CI artifacts | not needed | Prior measurements and reports from the old study. | These are explicitly disallowed as imported reproduction evidence. New measurements must be rerun and preserved in this repository. | none for direct import | **reference only** |
| `.gitignore` / `LICENSE` | not needed | Repository housekeeping. | These are not baseline-replication artifacts. The new repo already has its own governance and repository identity. | none | **do not import** |

## Minimum set for a first reproducible baseline run

The minimum controlled import set should be limited to the artifacts needed to:
1. compile the historical source-under-test modules,
2. preserve the baseline prompt family for at least one ASIL level,
3. generate tests in a traceable way,
4. run them, and
5. collect baseline-aligned coverage evidence.

Recommended minimum set:
- root `CMakeLists.txt` logic, adapted for the successor repository;
- `Lab/CMakeLists.txt` logic, adapted for the successor repository;
- `Lab/includes/`;
- `Lab/boolean_algebra.cpp`;
- `Lab/math_lib.cpp`;
- `Lab/real_world.cpp`;
- `prompts/common_ASIL_assistant_test_instructions.md`;
- `prompts/ASIL_a_assistant_test_instructions.md`; and
- the specific knowledge files required by the chosen first ASIL run.

## Explicit controls for later import

Before any historical artifact is actually copied, the import step should also record:
- source repository URL;
- source commit hash or frozen snapshot identifier;
- historical path;
- destination path in this repository;
- whether the file is copied verbatim, normalized, or rewritten;
- any textual edits made during migration; and
- reviewer sign-off that the artifact remains clearly separated from newly generated evidence.

## Notes on ambiguity

The following points remain unresolved and should stay explicit:
- whether the historical `paper/` directory is actually present in the accessible repository state or only described in `README.md`;
- whether a `scripts/` directory exists and, if so, whether any scripts are baseline-critical versus convenience-only;
- which exact subset of `prompts/knowledge/` was used for each historical run; and
- whether the historical handwritten tests in `Lab/tests/` were baseline validation scaffolding, benchmark oracles, or part of the paper-facing evaluation narrative.
