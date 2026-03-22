# BASELINE_IMPORT_LOG

## Import scope

This document records the **first minimal controlled baseline import** from the historical repository into `iso26262-llm-test-framework-update-2026`.

Historical source repository:
- URL: <https://github.com/floriandev70/iso26262-llm-test-framework>
- frozen snapshot used for this import: latest visible `main` commit `5ef5ff3` on the GitHub commits page as observed on 2026-03-22 UTC

This import follows the repository's conservative planning documents and is intentionally limited to the minimum artifact set needed to make a first reproducible baseline-aligned run possible.

## Imported artifacts

| Historical path | Destination path | Why needed for the first minimal baseline run | Import mode | Adaptation notes |
| --- | --- | --- | --- | --- |
| `CMakeLists.txt` | `CMakeLists.txt` | Provides a baseline-aligned top-level CMake entrypoint so the successor repo can configure a C++17 build and prepare for generated-test execution. | rewritten from historical reference | Recreated minimally for the successor repo layout; keeps CMake 3.20/C++17, test enablement, and optional coverage flags, but does not fetch GoogleTest until generated tests are added. |
| `Lab/CMakeLists.txt` | `baseline/Lab/CMakeLists.txt` | Needed to compile the imported baseline source-under-test modules in a clearly separated baseline tree. | rewritten from historical reference | Adapted to build a static library instead of the historical unit-test target so this first import does not pull in handwritten tests or generated tests prematurely. |
| `Lab/includes/boolean_algebra.h` | `baseline/Lab/includes/boolean_algebra.h` | Declares the boolean logic baseline functions needed for baseline-aligned generation tasks. | copied with formatting normalization | Only whitespace/style normalization was applied while preserving declared interface intent. |
| `Lab/includes/math_lib.h` | `baseline/Lab/includes/math_lib.h` | Declares the arithmetic baseline functions needed for minimal baseline task coverage. | adapted minimally | Added local compatibility definitions (`<cstdint>`, stub sensor-access helpers, and macros) required to compile the historical implementation in this successor repo without importing unrelated platform dependencies. |
| `Lab/includes/real_world.h` | `baseline/Lab/includes/real_world.h` | Declares the application-style baseline functions and state constants for the minimal baseline corpus. | adapted minimally | Added an inline definition for `g_current_state` so the imported state-machine code links cleanly as a standalone baseline library. |
| `Lab/boolean_algebra.cpp` | `baseline/Lab/boolean_algebra.cpp` | Baseline source-under-test for the boolean logic task family. | copied with formatting normalization | No logic changes intended; only reformatted into standard multiline C++ for readability and auditability. |
| `Lab/math_lib.cpp` | `baseline/Lab/math_lib.cpp` | Baseline source-under-test for the arithmetic/utility task family. | adapted minimally | Reflowed formatting and kept the historical implementation behavior; retained the temperature-calculation function with local compile-only compatibility shims from the header. |
| `Lab/real_world.cpp` | `baseline/Lab/real_world.cpp` | Baseline source-under-test for the real-world/application task family. | copied with formatting normalization | Added an explicit `default` branch in the state-machine switch to make the standalone library robust when no transition applies. |
| `prompts/common_ASIL_assistant_test_instructions.md` | `prompts/replication/baseline/common_ASIL_assistant_test_instructions.md` | Preserves the common baseline prompt instructions required by the first prompt-preserved baseline run. | copied with formatting normalization | Converted the historical single-line markdown into multiline markdown while preserving prompt content. |
| `prompts/ASIL_a_assistant_test_instructions.md` | `prompts/replication/baseline/ASIL_a_assistant_test_instructions.md` | Preserves the smallest ASIL-specific prompt variant recommended for the first controlled baseline run. | copied with formatting normalization | Converted the historical single-line markdown into multiline markdown while preserving prompt content. |

## Explicit assumptions for this first import

1. **First-run ASIL choice:** The first minimal baseline-aligned run will use **ASIL A**, because `docs/IMPORT_SEQUENCE.md` recommends ASIL A as the smallest first controlled prompt variant.
2. **Knowledge attachments for the first run:** No `prompts/knowledge/` files were imported in this first step. This is an explicit scope choice, not an omission by accident. The current import is limited to the smallest artifact set needed to prepare a first baseline-aligned run. If the first executed run attaches any knowledge file, that file must be imported and logged in a later reviewed step before the run is claimed as baseline-aligned.
3. **Generated tests are out of scope for this import:** The imported CMake layout intentionally prepares for later generated tests via `ISO26262_BASELINE_GENERATED_TEST_DIR`, but does not import historical handwritten tests or fabricate generated tests.

## What was adapted

### Build adaptation

- The historical root build logic was **not copied verbatim**. It was rewritten minimally to fit this repository's baseline separation requirements and to avoid silently importing optional historical behavior such as GoogleTest fetching or handwritten test registration before those artifacts are intentionally added.
- The historical `Lab/CMakeLists.txt` logic was reduced to a standalone `baseline_lab` static library so the source-under-test can be built now and linked by later generated tests without conflating imported baseline code with future outputs.

### Source compatibility adaptation

- `baseline/Lab/includes/math_lib.h` includes local compatibility definitions needed to compile the imported `Temp_Calc_Pres_Wacol_Temp_48V` function without importing additional historical platform headers that are not classified as required for the first minimal run.
- `baseline/Lab/includes/real_world.h` includes a local inline definition of `g_current_state` so the imported MCU state-machine code can link in the current minimal baseline layout.

### Prompt normalization

- The imported prompt files were normalized into readable multiline Markdown. Their substantive wording and the historical model/date label were preserved.

## What was intentionally not imported

The following historical artifacts were intentionally **not** imported in this first minimal baseline step:

- `prompts/ASIL_b_assistant_test_instructions.md`
- `prompts/ASIL_d_assistant_test_instructions.md`
- all `prompts/knowledge/*` files
- `Lab/tests/` handwritten historical tests
- `main/` executable scaffolding
- `.github/workflows/ci.yml`
- historical README, paper directory references, helper scripts, prior results, coverage reports, and generated outputs

These were excluded because the current repository planning documents classify them as optional, later-phase, ambiguous, or not needed for the first minimal baseline-aligned run.

## Why this import remains controlled

- Imported source-under-test artifacts are placed under `baseline/Lab/` rather than mixed into new framework or experiment directories.
- Imported prompt artifacts are placed under `prompts/replication/baseline/` rather than mixed with future extension prompts.
- No historical results, tests, or measurements were imported.
- All non-trivial adaptations are recorded here explicitly.
