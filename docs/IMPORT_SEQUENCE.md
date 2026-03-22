# IMPORT_SEQUENCE

## Goal

This document defines the recommended **order of migration** from the historical baseline repository into this successor repository, with emphasis on the **minimum needed for a first reproducible baseline run**.

The sequence is intentionally staged to reduce risk of over-importing historical material or mixing historical reference artifacts with newly reproduced evidence.

## Phase 0 — Freeze the reference mapping before copying anything

1. Record the historical repository URL and the exact commit hash or dated snapshot to be used as the baseline reference.
2. Freeze the baseline artifact inventory in this repository.
3. Confirm the target path convention for imported baseline assets, e.g. `baseline/`, `prompts/replication/baseline/`, and clearly separated `results/` run directories.
4. Decide whether imported handwritten tests, if ever imported, will live under `reference/` rather than next to generated tests.

**Deliverable:** a reviewed artifact registry with no imported files yet.

## Phase 1 — Minimum source-under-test import for the first run

Import only the source-under-test artifacts needed to compile the historical baseline modules:

1. import `Lab/includes/`;
2. import `Lab/boolean_algebra.cpp`;
3. import `Lab/math_lib.cpp`;
4. import `Lab/real_world.cpp`; and
5. recreate or adapt the root and `Lab/` CMake wiring in the new repository.

### Why this first

This establishes the baseline executable surface without yet bringing in optional convenience artifacts, CI wiring, or historical handwritten tests.

**Deliverable:** baseline source tree compiles in the new repository layout, even if no LLM-generated tests have been run yet.

## Phase 2 — Minimum prompt-package import for one controlled ASIL run

Import the smallest prompt package needed for a first prompt-preserved baseline replication:

1. import `prompts/common_ASIL_assistant_test_instructions.md`;
2. import `prompts/ASIL_a_assistant_test_instructions.md`; and
3. import only the knowledge files actually attached to that first ASIL A run, recording explicitly which ones were used.

### Recommendation

Start with **ASIL A** because it is the smallest clearly defined prompt variant and provides the simplest first comparability target.

**Deliverable:** a versioned baseline prompt package that supports one first reproducible generation run.

## Phase 3 — Execute the first reproducible baseline run

1. choose one concrete baseline function or a very small function set;
2. render and preserve the exact prompt package;
3. generate tests with the chosen model/workflow;
4. store raw model output;
5. materialize generated tests as files;
6. compile and run them; and
7. preserve logs and coverage outputs.

### Preferred first-run target

Start with one small `boolean_algebra` or `math_lib` function rather than the full corpus. This minimizes ambiguity and makes the first replication unit reviewable.

**Deliverable:** one complete replication unit with prompt, source snapshot, generated tests, commands, logs, and coverage evidence.

## Phase 4 — Expand baseline prompt coverage to the full ASIL family

After the first run works end-to-end:

1. import `prompts/ASIL_b_assistant_test_instructions.md`;
2. import `prompts/ASIL_d_assistant_test_instructions.md`; and
3. import the remaining verified knowledge documents needed by those prompt families.

**Deliverable:** full baseline prompt-family availability for ASIL A, B, and D.

## Phase 5 — Scale baseline runs across all three task families

Run controlled baseline replications for:

1. boolean logic tasks (`boolean_algebra`);
2. arithmetic / utility tasks (`math_lib`); and
3. application-style tasks (`real_world`).

At this phase, prioritize breadth of baseline task coverage over optional repo-completeness features.

**Deliverable:** at least one successful, fully preserved replication unit per baseline task family.

## Phase 6 — Add optional reference artifacts only if they reduce ambiguity

Only after baseline runs exist should the team consider optional reference imports such as:
- historical handwritten tests under a clearly separated reference location;
- CI workflow logic, rewritten for this repository;
- `main/` executable scaffolding; and
- any verified helper scripts.

**Deliverable:** convenience and validation assets that do not blur the line between historical reference artifacts and new evidence.

## Phase 7 — Resolve unclear artifacts deliberately

Handle only after explicit review:
- any historical `paper/` directory contents;
- any helper `scripts/` if verified to exist; and
- any question about whether historical tests should be imported at all.

**Deliverable:** explicit decisions recorded for every ambiguous artifact class.

## Minimal first-run order summary

If the team wants the shortest path to a first reproducible baseline run, the order should be:

1. freeze historical commit / snapshot;
2. import `Lab/includes/` and the three `Lab/*.cpp` modules;
3. recreate baseline-compatible CMake wiring;
4. import the common prompt plus **ASIL A** prompt;
5. import only the knowledge files actually used for that first run;
6. run one small baseline generation task;
7. preserve commands, outputs, tests, and coverage; and only then
8. expand to ASIL B, ASIL D, optional CI, and optional handwritten-reference tests.

## Stop conditions

The migration should pause for review if any of the following occurs:
- the historical artifact cannot be tied to a clear purpose in baseline replication;
- an imported artifact would mix historical outputs with newly reproduced evidence;
- a file requires non-trivial rewriting beyond path normalization and repository-specific logging hooks;
- the exact historical provenance of an artifact cannot be recorded; or
- the team cannot explain whether an artifact is source-under-test, prompt input, workflow scaffolding, or historical result evidence.
