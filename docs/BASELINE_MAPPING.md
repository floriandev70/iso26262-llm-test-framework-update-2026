# BASELINE_MAPPING.md

## Purpose

This document defines how the current repository should relate to the historical baseline repository during controlled replication planning.
It establishes a reference mapping concept only. It does not authorize code import, automatic synchronization, or retrospective merging.

Historical baseline repository:
- `floriandev70/iso26262-llm-test-framework`
- <https://github.com/floriandev70/iso26262-llm-test-framework>

## What may later be reused as reference

The historical repository may later be reused as reference input for items such as:

- experiment structure and study phase definitions;
- naming of functions, tasks, or benchmark units under test;
- prompt intent or task framing, if provenance is preserved;
- execution workflow descriptions;
- result categories, coverage dimensions, and evaluation criteria; and
- documented toolchain assumptions, versions, or constraints.

Any such reuse must preserve provenance and must distinguish historical reference material from newly reproduced evidence.

## What must remain historically separated

The following should remain explicitly separated from new repository evidence unless a later step authorizes controlled import with documented review:

- original implementation code from the historical repository;
- historical generated tests;
- historical logs, result tables, and coverage values;
- historical prompts treated as if they were current prompt revisions; and
- manuscript claims that are not backed by preserved evidence in this repository.

Historical artifacts may inform planning, but they must not be presented as reproduced outputs from this repository.

## Mapping concept

A controlled mapping between the repositories should eventually document:

1. the historical artifact identifier or path;
2. the role of that artifact in the original study;
3. the corresponding artifact, workflow, or placeholder in this repository;
4. whether the relationship is `reference-only`, `planned replication`, or `validated replication`; and
5. the evidence required before the mapping can be upgraded to `validated replication`.

A minimal mapping table may later use the following structure.

| historical_artifact | historical_role | current_repo_target | mapping_status | validation_evidence_needed |
| --- | --- | --- | --- | --- |
| path or identifier | prompt, script, unit under test, result table, etc. | planned location or corresponding artifact | reference-only / planned replication / validated replication | logs, prompts, commit hash, coverage reports, review note |

## What counts as a valid controlled replication

A run or workflow should count as a valid controlled replication only if all of the following are satisfied:

- the target artifact or task from the historical baseline is identified clearly;
- the current repository preserves the exact prompt or workflow instructions used;
- the source under test and revision are recorded;
- the execution commands and outputs are preserved;
- the resulting generated tests and coverage outputs are stored;
- any divergences from the historical setup are documented explicitly; and
- the final assessment states whether comparability is strong, partial, or limited.

## Current repository posture

At the current stage, the historical baseline should be treated as reference material only.
No historical code, results, or prompt artifacts should be copied into this repository without an explicit later decision and documented review trail.
