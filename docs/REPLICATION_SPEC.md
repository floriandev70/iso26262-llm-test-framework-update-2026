# REPLICATION_SPEC.md

## Purpose

This specification defines the minimum historical baseline elements that must be replicated in this repository before any extension experiment is treated as methodologically valid.

This document is intentionally **replication-first**. It does not authorize import of historical implementation code, generated tests, or historical result tables into this repository. Historical artifacts remain reference inputs until independently reproduced here.

## Source basis and precedence

The replication specification follows the repository source priority requested for this study:

1. historical baseline repository: `floriandev70/iso26262-llm-test-framework`;
2. manuscript artifact in this repository: `docs/LLAIS1_paper_26.pdf`; and
3. historical recorded results, only where preserved and auditable.

If the manuscript and baseline repository differ, this specification prefers the **repository-grounded reproducible interpretation** and records the discrepancy explicitly.

## Baseline system scope

The historical baseline repository defines the baseline system as a reproducible C/C++ unit-test environment for evaluating LLM-assisted ISO 26262-oriented test generation. The repository-level scope that must be replicated is:

- a CMake-based C++17 build and test environment;
- GoogleTest-based unit test execution;
- C/C++ source modules under test contained in the historical `Lab/` project layout;
- ASIL-specific prompt assets for at least `ASIL A`, `ASIL B`, and `ASIL D`;
- a common base prompt plus supplemental knowledge documents;
- coverage-oriented evaluation using statement/line, branch, and MC/DC objectives; and
- a reproducible execution path based on command-line build/test commands, with CI as secondary support rather than primary evidence.

## Target functions and tasks to replicate

Before extension work is considered valid, the replication phase must replicate the **task classes** represented in the historical repository.

### Task classes

1. **Boolean logic unit-test generation**
   - replicate generation tasks for logic-heavy functions represented by the historical `boolean_algebra` module;
   - preserve the distinction between simple boolean operators and more compound decision logic.

2. **Arithmetic / library-style unit-test generation**
   - replicate generation tasks for arithmetic or utility-style functions represented by the historical `math_lib` module.

3. **Real-world or application-style unit-test generation**
   - replicate generation tasks for functions represented by the historical `real_world` module.

### Replication unit definition

A replication unit is not merely "a repository" or "a prompt." It is the combination of:

- the identified source function or function set under test;
- the exact source revision or preserved snapshot;
- the ASIL-specific prompt variant used;
- the model/workflow used for generation;
- the resulting generated tests;
- the compile, execution, and coverage outcomes; and
- the final comparability assessment.

## Original evaluation dimensions to replicate

The baseline repository explicitly identifies the following evaluation dimensions and targets.

### Prompt- and ASIL-related dimensions

- **ASIL A**: statement/line-coverage-oriented test generation;
- **ASIL B**: equivalence partitioning, boundary value analysis, and branch-oriented test generation;
- **ASIL D**: equivalence partitioning, boundary value analysis, branch coverage, and MC/DC-oriented test generation.

### Outcome dimensions

The controlled replication must preserve measurement slots for at least:

- generated test correctness / usability;
- compile success or failure;
- test execution success or failure;
- statement or line coverage where the baseline treated this as relevant;
- branch coverage;
- MC/DC coverage where the baseline treated this as relevant;
- observed false positives or non-actionable tests;
- observed silent or unannounced source modifications, if any workflow attempts them; and
- required human interaction or manual intervention.

## Original constraints and assumptions to replicate

The following baseline constraints are directly supported by repository evidence and therefore fall inside the replication target.

### Tooling and environment constraints

- CMake minimum version: 3.20.
- C++ language level: C++17.
- GoogleTest is fetched automatically by the build system.
- Coverage flags are enabled conditionally for debug-style builds in the historical CMake setup.
- Coverage tooling is described as `gcovr` or `llvm-cov`, depending on toolchain.
- Command-line build/test execution is part of the baseline workflow.

### Method constraints

- The prompts are separated by ASIL level and share a common base instruction set.
- Additional knowledge documents are part of the historical prompting design.
- The workflow evaluates generated tests against concrete source modules rather than abstract benchmark descriptions alone.
- CI may automate build/test/coverage, but CI artifacts are not a substitute for preserved run evidence in this repository.

### Constraints for this successor repository

Because this repository is a controlled replication and extension study, the following additional constraints apply before a run can count as replicated here:

- historical code and generated tests remain reference-only until explicitly imported under a reviewed procedure;
- historical measured results must not be copied in as if newly reproduced;
- all prompts, commands, logs, and outputs used here must be preserved in this repository; and
- source-under-test modifications must never occur silently.

## Test-generation workflow to replicate

The baseline repository supports a prompt-driven test-generation workflow centered on ASIL-specific instructions.

The replication target workflow is therefore:

1. identify a historical source module and concrete function under test;
2. preserve or reconstruct the applicable prompt package consisting of:
   - common prompt instructions;
   - ASIL-specific instructions; and
   - any supplemental knowledge materials used by that prompt family;
3. execute the chosen model/workflow against the preserved source-under-test context;
4. store the exact rendered prompt and raw generated output;
5. materialize generated unit tests as explicit files;
6. compile the generated tests in the baseline-compatible build environment;
7. run the tests; and
8. assess whether the output is comparable, partially comparable, or not comparable to the historical baseline intent.

### Replication requirement

A future run is **not** a valid replication run if it skips prompt preservation, generated-test preservation, or source revision identification.

## Coverage workflow to replicate

The baseline repository describes a coverage workflow based on statement/line, branch, and MC/DC objectives and identifies `gcovr` or `llvm-cov` as the relevant tooling family.

The replication target coverage workflow is therefore:

1. build the source and generated tests in a coverage-capable configuration;
2. execute the compiled tests;
3. run the selected coverage toolchain and preserve the exact invocation;
4. store raw coverage outputs and, where produced, derived reports;
5. record which coverage notion is being claimed for each run: statement/line, branch, and/or MC/DC; and
6. explicitly note any tooling-driven departures from the historical baseline.

### Coverage comparability rule

Coverage values are comparable only when the following are known:

- source revision under test;
- test set actually executed;
- coverage tool and version or tool family;
- coverage metric definition; and
- whether excluded files, build flags, or instrumentation choices differ materially from the baseline.

## Criteria for successful replication

A replication unit should be labeled **successful replication** only when all of the following hold:

1. the unit under test is traceably mapped to a historical baseline task class or concrete historical artifact;
2. the prompt family is baseline-aligned and preserved in full;
3. the source revision and generated tests are preserved;
4. the generated tests compile in the defined build environment, or a failure is itself the faithful reproduced outcome of the workflow;
5. test execution output is preserved;
6. the intended baseline-relevant coverage measurement is executed and preserved, unless the historical task clearly did not require that metric;
7. all manual interventions are logged;
8. no undisclosed source modification occurred; and
9. the final run assessment concludes that the run is strongly or acceptably comparable to the historical baseline definition.

A replication can still be scientifically useful even if it does **not** reproduce the same quantitative result, provided the methodological chain above is complete and the non-match is recorded rather than normalized away.

## Criteria for not comparable

A run should be labeled **not comparable** when one or more of the following apply:

- the function or task cannot be mapped clearly to a historical baseline artifact or task class;
- the prompt package differs materially from the baseline design and the difference is not isolated;
- the model/workflow performs additional hidden orchestration that cannot be logged adequately;
- the source-under-test changed in ways that make the historical comparison target unclear;
- coverage tooling or metric definitions differ and no defensible bridge is documented;
- generated tests were manually rewritten without preserving the original model output and the edit trail;
- historical and reproduced scopes are mixed in one result record; or
- baseline claims rely on manuscript wording or anecdote without auditable repository support.

## Explicit discrepancies currently identified

### Repository-grounded interpretation preferred over manuscript wording

The historical baseline repository explicitly identifies:

- ASIL-specific prompt files for `ASIL A`, `ASIL B`, and `ASIL D`;
- common prompt instructions and separate knowledge files;
- a CMake/GoogleTest workflow;
- `gcovr` or `llvm-cov` as coverage tooling families; and
- statement, branch, and MC/DC coverage objectives.

If the manuscript describes these items differently, the replication program should follow the repository-grounded interpretation unless the discrepancy is documented and justified.

### Baseline repository identifies coverage goals more clearly than preserved paper-readable evidence in this environment

At the time of writing this specification, the manuscript PDF is present in the repository, but its detailed text has not yet been extracted into a machine-readable audit artifact inside this repository. Therefore, paper-derived details that are not already corroborated by repository artifacts remain open for explicit verification rather than being silently assumed.

## Open ambiguities requiring explicit decisions

The following ambiguities must be resolved explicitly before a strict baseline-comparison claim is made.

1. **Exact historical function set**
   - The baseline repository clearly exposes module families, but this repository does not yet contain a reviewed, explicit enumeration of every historical function that belonged to the published evaluation set.

2. **Exact prompt text version actually used in each historical experiment**
   - The baseline repository stores prompt files, but the exact prompt rendering and any wrapper/system instructions used in the historical study are not yet preserved here.

3. **Exact model snapshot and invocation parameters**
   - The baseline repository references `GPT-4-turbo`, but the exact historical model snapshot, temperature, and surrounding orchestration parameters require explicit capture from preserved evidence if strict comparability is later claimed.

4. **Coverage tool choice per historical run**
   - The baseline repository names `gcovr` and `llvm-cov`, but does not by itself resolve which tool was used for which reported baseline result.

5. **Treatment of CI-generated artifacts**
   - The repository mentions CI coverage uploads, but the evidentiary role of CI output versus local preserved run logs must be decided explicitly for this study.

6. **Definition of false positives and failure classes**
   - The new repository intends to track false positives and anomalies, but the historically used taxonomy, if any, is not yet captured as a controlled artifact here.

7. **Paper-to-repository terminology alignment**
   - The manuscript may use terminology that does not align one-to-one with repository artifact names. Any mismatch must be captured in a mapping document before claims are made.

## Precondition for valid extension experiments

No extension experiment should be treated as baseline-comparable until:

- the baseline task mapping is frozen;
- the baseline-aligned prompt family is versioned in this repository;
- the build/test/coverage workflow has been executed at least once as a controlled replication run; and
- the resulting evidence chain satisfies the logging expectations already defined in this repository.
