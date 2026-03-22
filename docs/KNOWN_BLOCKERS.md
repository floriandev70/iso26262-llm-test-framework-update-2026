# KNOWN_BLOCKERS

## Scope

This document lists the remaining blockers or uncertainties that still prevent a clean, fully evidenced first baseline-aligned execution in this repository.

## Current blockers

### 1. No preserved raw model output for the first run

The repository currently contains the baseline source-under-test and the first ASIL A prompt files, but it does not yet contain the raw model output that would justify any generated tests as evidence for a baseline-aligned run. Without that file, the run cannot satisfy the repository requirement to preserve exact inputs and outputs for auditability.【F:docs/FIRST_BASELINE_RUN_PLAN.md†L41-L48】【F:docs/FIRST_BASELINE_RUN_PLAN.md†L78-L86】

### 2. No preserved generated test source for the first run

The current repository state does not yet include a generated test source file for the selected initial replication unit. Because the run script intentionally does not invent test content, an actual build-and-test execution remains blocked until a real generated test file is supplied and preserved.

### 3. Coverage tooling is incomplete in the current environment

`gcovr` is not currently available in the execution environment used for this preparation step. The build system supports coverage flags, but the documented first-run coverage reporting command cannot be executed automatically here without installing `gcovr` or explicitly choosing and documenting a baseline-acceptable alternative.【F:CMakeLists.txt†L8-L15】

## Current uncertainties

### 1. Whether additional historical knowledge attachments are required for the first ASIL A run

The current first-run plan explicitly assumes that no additional historical knowledge file is required for the smallest initial ASIL A trial. If later evidence shows that a knowledge attachment was part of the historically comparable prompt package, that artifact will need to be imported and documented before strict comparability is claimed.【F:docs/FIRST_BASELINE_RUN_PLAN.md†L39-L40】【F:docs/FIRST_BASELINE_RUN_PLAN.md†L52-L54】

### 2. Strict comparability still depends on the actual model/workflow record

Even once the first run becomes executable, strict baseline comparability will still depend on preserving:
- the exact rendered prompt;
- the exact raw output;
- the generated test materialization;
- the exact commands run; and
- the final assessment of any deviations.

This repository now has deterministic scaffolding for those items, but comparability cannot be claimed in advance of an actual preserved run.

## Non-blockers already resolved

The following items were checked during this preparation step and are not current blockers:

- the imported baseline source tree configures and builds successfully as `baseline_lab`; and
- the repository now has a deterministic scriptable path for the first baseline-aligned run once real generated artifacts are available.【F:baseline/Lab/CMakeLists.txt†L1-L8】【F:scripts/run_first_baseline.sh†L1-L253】
