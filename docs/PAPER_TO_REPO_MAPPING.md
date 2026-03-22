# PAPER_TO_REPO_MAPPING.md

## Purpose

This document maps paper-level study concepts to repository artifacts needed for a controlled replication and extension study.

The goal is not to treat the manuscript as executable truth. The goal is to ensure that every publishable concept is backed by a concrete repository artifact, preserved workflow, or explicitly logged ambiguity.

## Mapping rules

- Prefer repository-grounded artifacts over narrative descriptions.
- If a paper concept has no implemented artifact yet, map it to a planned artifact and mark it as such.
- If the paper and repository differ, record the discrepancy explicitly rather than normalizing it away.
- Do not use dissertation terminology or dissertation-only concepts as sources for this mapping.

## Concept-to-artifact mapping

| Paper-level concept | Repository-grounded interpretation | Current or planned repository artifact | Status | Notes |
| --- | --- | --- | --- | --- |
| Research question / study objective | Controlled replication and extension objective for ISO 26262 SWE.4 unit-test generation and coverage analysis | `REPLICATION_PLAN.md`; future experiment definitions under `experiments/` | partial | Repository plan exists; experiment definitions are still to be instantiated |
| Historical baseline definition | Reference-only baseline that defines prior tasks, prompts, and workflow targets | `docs/BASELINE_MAPPING.md`; future baseline artifact registry | partial | Must remain distinct from reproduced evidence |
| Baseline replication scope | Minimum historical elements that must be reproduced before extensions are valid | `docs/REPLICATION_SPEC.md` | implemented | This document is the normative replication scope in the current repository |
| Experiment definition | Controlled run specification for one function/task, prompt, model, and measurement chain | `docs/EXPERIMENT_MATRIX.md`; future `experiments/` entries | partial | Matrix exists; executable experiment definitions are not yet populated |
| Unit under test / target task | Historical module/function to be exercised by test generation | future `experiments/` definitions and run metadata fields such as `function_under_test` | planned | Historical repository exposes task families such as `boolean_algebra`, `math_lib`, and `real_world` |
| ASIL-specific prompting | Prompt family split by ASIL with shared common instructions and domain knowledge attachments | `docs/PROMPT_VERSIONING.md`; future `prompts/replication/...` files | partial | Naming/versioning scheme exists; prompt texts not yet recreated here |
| Common prompt instructions | Shared baseline-aligned prompt core used across ASIL variants | future prompt artifact under `prompts/replication/` | planned | Historical baseline contains a common prompt asset |
| Knowledge augmentation for prompting | Supplemental knowledge files used alongside prompt instructions | future preserved prompt-knowledge files under `prompts/replication/` | planned | Historical baseline stores these under `prompts/knowledge/` |
| Test generation workflow | Prompted generation of unit tests against concrete source functions with preserved prompts and outputs | `docs/REPLICATION_SPEC.md`; `docs/EVIDENCE_LOGGING.md`; future scripts and run directories | partial | Workflow is specified, not yet executed |
| Coverage analysis | Instrumented build, test execution, and preservation of coverage outputs | `docs/REPLICATION_SPEC.md`; `docs/EVIDENCE_LOGGING.md`; future `scripts/` and `results/` reports | partial | Coverage reporting format exists; toolchain not yet frozen |
| Coverage objectives | Statement/line, branch, and MC/DC, with ASIL-specific emphasis | `docs/REPLICATION_SPEC.md`; `docs/EXPERIMENT_MATRIX.md` | implemented | Historical repository identifies the objective families |
| Observed failure classes | Controlled anomaly and failure taxonomy for generated tests and workflows | `docs/EXPERIMENT_MATRIX.md` columns; future anomaly taxonomy document or schema | partial | Current matrix tracks false positives, silent modifications, and anomalies but taxonomy is not yet formalized |
| Human interaction observations | Logged record of manual interventions, operator steering, and repair steps | `docs/EVIDENCE_LOGGING.md` field `manual_interventions`; `docs/EXPERIMENT_MATRIX.md` field `human_interventions_needed` | implemented | Requires run-time preservation, not conversational summaries |
| Silent source modification risk | Governance-relevant observation that a workflow altered source under test without authorization | `AGENTS.md`; `docs/EVIDENCE_LOGGING.md`; `docs/EXPERIMENT_MATRIX.md` | implemented | Must remain an explicit observation, not an implicit side effect |
| Reproducibility evidence | Preserved prompt, source snapshot, commands, logs, outputs, and assessment | `docs/EVIDENCE_LOGGING.md`; future `results/<run_id>/` layout | implemented | Core repository policy already exists |
| Historical results used as reference evidence | Auditable prior-study values, if later linked, kept separate from reproduced results | future baseline-reference evidence registry under `results/` or `docs/` | planned | Must never be mixed with reproduced outputs |
| Manuscript claim traceability | Link from reporting text to repository evidence | current documentation policy in `docs/README.md`; future claim-to-evidence trace artifact | partial | Explicit trace file still needed |

## Terminology normalization for this repository

To keep the repository audit-friendly, the following terminology is preferred.

| Prefer in this repository | Avoid when not artifact-backed | Rationale |
| --- | --- | --- |
| controlled replication run | vague references to "same as prior study" | forces explicit run evidence |
| baseline reference artifact | wording that implies historical artifacts are already reproduced | preserves separation between old and new evidence |
| prompt family / prompt version | informal references to "the ASIL prompt" | supports version control and auditability |
| anomaly taxonomy | informal failure anecdotes | enables structured evidence collection |
| manual intervention log | general statements about human guidance | makes operator influence reviewable |
| coverage workflow | generic coverage claim | ties claims to commands, instrumentation, and reports |

## Known mapping gaps

The following paper-to-repository links are not yet fully resolved and must remain explicit.

1. exact manuscript terminology for each experiment phase has not yet been reconciled against repository file names;
2. no prompt text has yet been recreated in this repository, only prompt-governance rules;
3. no anomaly taxonomy file yet distinguishes compilation failures, logic errors, false positives, flaky tests, or source-modification attempts;
4. no claim-to-evidence index yet links manuscript statements to concrete run directories; and
5. historical recorded results, if later referenced, still need a controlled evidence container and provenance fields.

## Immediate next artifacts implied by this mapping

The following additions would reduce ambiguity without importing old implementation code:

- a baseline artifact inventory that enumerates historical source modules, prompt files, and workflow files;
- a prompt registry for recreated baseline-aligned prompt families;
- an anomaly taxonomy document for generated-test and workflow failures; and
- a claim-to-evidence trace template for later manuscript synchronization.
