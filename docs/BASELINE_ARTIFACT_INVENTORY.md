# BASELINE_ARTIFACT_INVENTORY

## Purpose

This document inventories **baseline-relevant artifacts observed in the historical repository**:
- historical repo: <https://github.com/floriandev70/iso26262-llm-test-framework>

This is an **inventory only**. It does not authorize import.

## Observation basis

The inventory below is based on accessible repository pages and files visible during this analysis, plus the current repository's own replication-spec documents.

Where a historical artifact was mentioned in the old repository README but could not be independently confirmed from accessible pages during this analysis, it is marked as **unverified**.

## Inventory by area

### 1. Top-level build and repository scaffolding

| Historical path | Observed status | Baseline relevance | Notes |
| --- | --- | --- | --- |
| `CMakeLists.txt` | verified | high | Top-level build entrypoint; sets CMake minimum version 3.20, C++17, Debug coverage flags, and test enablement. |
| `README.md` | verified | medium | Summarizes historical structure, build commands, prompt family, and coverage workflow. Useful reference, not direct evidence. |
| `.github/workflows/ci.yml` | verified | medium | Encodes CI build/test and Linux coverage workflow; useful reference but secondary to preserved local evidence. |
| `.gitignore` | verified from root listing | low | Repository housekeeping only. |
| `LICENSE` | mentioned in README, not independently inspected | low | Repository licensing artifact, not baseline-critical for first reproduction. |
| `paper/` | unverified | unclear | Mentioned in README as containing `paper.md`, but contents were not directly confirmed in accessible repository pages during this analysis. |
| `scripts/` | unverified | unclear | Mentioned in README as optional helper scripts, but no concrete script inventory was verified during this analysis. |

### 2. Application / source-under-test layout

| Historical path | Observed status | Baseline relevance | Notes |
| --- | --- | --- | --- |
| `Lab/CMakeLists.txt` | verified | high | Builds a `unit_tests` target from recursively globbed `*.cpp` and `*.h`, links GoogleTest, and discovers tests. |
| `Lab/includes/boolean_algebra.h` | verified | high | Declares the boolean-logic benchmark functions. |
| `Lab/includes/math_lib.h` | verified | high | Declares arithmetic / library-style functions and some additional domain-specific definitions. |
| `Lab/includes/real_world.h` | verified | high | Declares the real-world/application-style functions and MCU state-machine constants. |
| `Lab/boolean_algebra.cpp` | verified | high | Logic-heavy source module used for baseline boolean test-generation tasks. |
| `Lab/math_lib.cpp` | verified | high | Arithmetic / utility source module used for baseline math-style tasks. |
| `Lab/real_world.cpp` | verified | high | Application-style source module used for baseline real-world tasks. |
| `main/CMakeLists.txt` | verified | low to medium | Builds an auxiliary `main_exec` target. |
| `main/main.cpp` | verified | low to medium | Auxiliary entrypoint; likely not required for the first baseline replication run. |

### 3. Prompt family

| Historical path | Observed status | Baseline relevance | Notes |
| --- | --- | --- | --- |
| `prompts/common_ASIL_assistant_test_instructions.md` | verified | high | Common shared prompt telling the assistant to generate test-case tables, GoogleTest functions, and an HTML output artifact. |
| `prompts/ASIL_a_assistant_test_instructions.md` | verified | high | ASIL A extension targeting requirement-derived tests and full line/statement coverage. |
| `prompts/ASIL_b_assistant_test_instructions.md` | verified | high | ASIL B extension targeting requirements analysis, equivalence classes, boundary values, statement coverage, and branch coverage. |
| `prompts/ASIL_d_assistant_test_instructions.md` | verified | high | ASIL D extension targeting requirements analysis, equivalence classes, boundary values, branch coverage, and MC/DC coverage. |

### 4. Prompt knowledge attachments

| Historical path | Observed status | Baseline relevance | Notes |
| --- | --- | --- | --- |
| `prompts/knowledge/equivalence_partitioning_boundary.md` | verified by directory listing | high | Supplemental knowledge for equivalence partitioning and boundary-oriented prompting. |
| `prompts/knowledge/hints_for_testing.md` | verified by directory listing | high | Supplemental prompt knowledge. Exact run-time usage per historical experiment is still unclear. |
| `prompts/knowledge/mcc.md` | verified by directory listing | high | Supplemental prompt knowledge associated with coverage reasoning. |
| `prompts/knowledge/mcdc.md` | verified by directory listing | high | Supplemental prompt knowledge associated with MC/DC-oriented prompting. |

### 5. Historical handwritten test suites

| Historical path | Observed status | Baseline relevance | Notes |
| --- | --- | --- | --- |
| `Lab/tests/boolean_algebra_tests.cpp` | verified | medium | Historical GoogleTest file for the boolean module; useful as reference validation, but not itself the generated-test baseline target. |
| `Lab/tests/math_lib_tests.cpp` | verified | medium | Historical GoogleTest file for the math module; same caution applies. |
| `Lab/tests/real_world_tests.cpp` | verified | medium | Historical GoogleTest file for the real-world module; same caution applies. |

## Observed function families

The historical repository exposes at least the following function families relevant to replication planning.

### Boolean logic family
- constant-return helpers such as `return_0` and `return_1`;
- single-variable logic like `return_a` and `return_NOT_a`;
- two-input logic like `check_a_OR_b`, `check_a_XOR_b`, `check_a_NOR_b`, `check_a_AND_b`, `check_a_NAND_b`; and
- compound decision logic such as `check_a_OR_b_OR_c`, `check_a_OR_b_AND_c`, `check_a_AND_b_OR_a_AND_c`, and related variants.

### Arithmetic / utility family
- arithmetic functions such as `add`, `subtract`, `multiply`, `divide`;
- utility functions such as `factorial`, `fibonacci`, and `prime_number`;
- refactored counterparts such as `add_ref`, `subtract_ref`, `divide_ref`, `fibonacci_ref`, and `prime_number_ref`; and
- additional domain-specific items declared in the header, including `myFunc` and `Temp_Calc_Pres_Wacol_Temp_48V`.

### Real-world / application family
- `check_abort`; and
- `autom_MCU_state_machine` plus its state constants and preserved current-state handling.

## Baseline-relevant workflow evidence observed

The historical repository explicitly exposed the following workflow elements:
- CMake-based build configuration;
- GoogleTest integration;
- a command-line build path via `cmake -S . -B build`, `cmake --build build`, and `ctest`;
- conditional coverage instrumentation in the top-level CMake configuration;
- CI coverage generation using `gcovr` on Linux; and
- prompt artifacts split into common, ASIL A, ASIL B, and ASIL D instructions plus knowledge attachments.

## Ambiguities recorded explicitly

The following baseline-relevant questions remain open and should not be silently resolved by assumption:

1. whether the historical `paper/` directory is present and relevant in the currently accessible repository state;
2. whether a `scripts/` directory exists, and if it does, whether any script is necessary for baseline replication rather than convenience;
3. which exact knowledge files were attached to each historical prompt execution;
4. whether the handwritten `Lab/tests/*.cpp` files acted only as reference tests, as paper-evaluation artifacts, or as part of the practical benchmark scaffold; and
5. which exact function subset from the available headers and sources formed the published evaluation set.

## Recommended inventory use

This inventory should be used as the source document for:
- deciding the first import tranche;
- assigning each artifact a migration mode (`copy`, `rewrite`, or `reference only`);
- recording provenance for every later import step; and
- ensuring that baseline replication artifacts remain separate from extension artifacts and reproduced results.
