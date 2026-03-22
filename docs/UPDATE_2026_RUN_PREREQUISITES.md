# UPDATE_2026_RUN_PREREQUISITES

## Purpose

This document defines the exact prerequisites that must be satisfied **before** starting the first update-2026 comparison run.

Its goal is to keep the first comparison methodologically aligned with the current baseline-side anchor while preventing accidental drift, hidden intervention, or overstated comparability.

This document does **not** start the update-2026 run.

## Guiding principle

The first update-2026 comparison run should answer a narrow question:

> Given the currently documented baseline-side anchor run, what changes when the successor update-2026 condition is executed under a matched and fully disclosed run protocol?

To preserve that question, the update-2026 run must be designed as a **controlled comparison unit**, not as an open-ended new experiment.

## Exact prerequisites

### 1. Freeze the baseline-side anchor record first

Before any update-2026 run begins, the baseline-side anchor must be frozen in documentation with the following fields explicitly recorded in one place or linked unambiguously:

- source-under-test revision or preserved snapshot;
- target module/function selection;
- exact prompt package used;
- exact model identifier used;
- generated-test artifact path/hash;
- build command(s);
- test command(s);
- observed result summary: **61 tests executed, 4 assertions failed**;
- explicit note that coverage is unavailable because `gcovr` could not be installed; and
- explicit note that a local GoogleTest shim fallback was used.

Rationale: the update-2026 run cannot be meaningfully compared against a moving or partly implicit baseline anchor.

### 2. Keep the comparison target fixed

The first update-2026 run must use the **same baseline task unit** as the current anchor run unless a deviation is explicitly approved and documented beforehand.

At minimum this means matching:

- the same source-under-test corpus;
- the same module/function focus, unless a reviewed deviation note explains why not; and
- the same baseline-vs-update comparison boundary.

Rationale: changing the task unit at the same time as the workflow condition would confound the first comparison.

### 3. Preserve a matched evidence package

The update-2026 run must preserve, at minimum:

- rendered prompt text;
- raw model output;
- generated test source exactly as materialized for build input;
- build logs;
- test logs;
- coverage logs if coverage becomes available;
- environment notes for missing tools or fallback dependencies;
- a comparability assessment specific to that run; and
- artifact hashes where feasible.

Rationale: the update-2026 run should not have a weaker evidence chain than the baseline-side anchor.

### 4. Decide the comparison policy for deviations **before** execution

Before starting the update-2026 run, the run plan must state whether each of the following is being:

- **held constant** relative to the current baseline-side anchor,
- **updated intentionally**, or
- **left unavailable**.

Required items:

- model family/identifier;
- prompt structure and prompt wrappers;
- source-under-test revision;
- generated-test materialization procedure;
- GoogleTest provisioning method;
- compiler and CMake versions if they differ materially;
- coverage tool availability and invocation method.

Rationale: without this declaration, any later difference becomes difficult to attribute.

### 5. Keep baseline-side deviations visible rather than “repairing” them silently

If the update-2026 run uses conditions that differ from the current baseline-side anchor, the comparison write-up must state whether the change:

- improves environmental completeness,
- changes the treatment condition itself, or
- introduces a new confound.

Examples:

- If the update-2026 run uses a different dependency path than the baseline-side local GoogleTest shim, that change must be logged as a comparison factor.
- If the update-2026 run gains coverage while the baseline-side anchor still lacks coverage, the comparison must state clearly that coverage is not a symmetric comparison dimension for the first pair.

Rationale: the first comparison run should expose asymmetries, not hide them.

### 6. Define the allowed comparison outputs in advance

Before execution, the run plan should explicitly state that the first update-2026 comparison may compare only the dimensions that are actually available on both sides.

Initially safe shared dimensions are likely limited to:

- whether generation produced a preservable artifact;
- whether the generated suite compiled;
- whether tests executed;
- how many tests executed;
- how many failures were observed; and
- qualitative differences in generated test structure, if grounded in preserved artifacts.

Unsafe dimensions unless newly produced on both sides:

- coverage deltas;
- branch or MC/DC comparisons;
- claims of superiority/inferiority attributable only to model generation quality;
- pooled summary statistics across incomparable runs.

### 7. Write the update-2026 run as a separate phase record

The first update-2026 run must be recorded as an **extension/update phase artifact**, not merged into the baseline run record.

Minimum separation requirements:

- separate run identifier;
- separate results directory;
- separate assessment file;
- explicit cross-reference back to the frozen baseline-side anchor document.

Rationale: this repository's replication-first rules require clean separation between baseline replication and extension work.

### 8. Do not start until the baseline-side artifact gap is acceptable for the intended claim

The first update-2026 run may start once the team accepts that the intended claim is limited to a **conservative first comparison against a partially comparable baseline-side anchor**.

If the intended claim instead requires:

- strict historical comparability,
- coverage-backed comparison, or
- historically matched model conditions,

then the update-2026 run must wait until those prerequisites are satisfied on the baseline side first.

## Recommended pre-run checklist

Use the following checklist immediately before authorizing the first update-2026 run:

- [ ] The baseline-side anchor record is frozen and cites the exact preserved artifacts.
- [ ] The baseline-side deviations are listed explicitly: `gpt-4.1`, local GoogleTest shim fallback, and missing coverage.
- [ ] The update-2026 task unit matches the baseline-side task unit.
- [ ] The update-2026 evidence package layout is defined before execution.
- [ ] The treatment-vs-confound status of each planned deviation is declared before execution.
- [ ] The comparison questions are limited to dimensions available on both sides.
- [ ] The run is explicitly labeled as the **first update-2026 comparison run**, not as a new baseline replication.
- [ ] No one has claimed or implied that the update-2026 run has already started.

## Bottom line

The first update-2026 comparison run should begin **only after** the current baseline-side run is frozen as a **partially comparable anchor** and the comparison protocol is declared narrowly enough that the known baseline-side deviations do not get hidden inside the comparison narrative.
