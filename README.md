# iso26262-llm-test-framework-update-2026

This repository is a **controlled replication and extension study** for ISO 26262 SWE.4 unit test generation and coverage analysis using current OpenAI coding models and agent-based workflows.

It is the successor to the historical baseline repository, [`floriandev70/iso26262-llm-test-framework`](https://github.com/floriandev70/iso26262-llm-test-framework), which must be treated as a **reference baseline only**. The historical repository helps define prior methodology and comparison targets, but its code, prompts, and results are **not** considered reproduced evidence in this repository.

> No experimental claim is valid for this successor study unless it has been explicitly reproduced, logged, and evidenced in this repository.

## Research focus

The project is intended to support a paper-oriented engineering workflow for a controlled replication of a prior GPT-4 Turbo baseline, together with carefully scoped extensions for current OpenAI coding and agent workflows.

The repository scaffold is designed to:

- keep the historical baseline and the new replication work clearly separated;
- make experiments reproducible and auditable;
- support Codex-driven and agent-assisted workflows under explicit governance rules; and
- enable later baseline-versus-current-model comparisons without conflating old and new evidence.

## Relation to the manuscript draft

The repository includes a manuscript artifact at `docs/LLAIS1_paper_26.pdf`.

That document should be treated as a **study narrative artifact**, not as independent proof. The repository remains the operational source of truth for:

- experiment definitions;
- prompts, agent settings, and execution procedures;
- preserved run evidence and logs; and
- reproduced claims that can be audited from repository contents.

If the manuscript draft and repository evidence ever diverge, the discrepancy must be resolved explicitly and documented. The repository must not be retrofitted to match an unverified textual claim.

## Repository structure

- `docs/` — study documentation, manuscript artifacts, protocol notes, and reporting guidance.
- `prompts/` — versioned prompt assets and prompt-related metadata.
- `agents/` — agent instructions, orchestration notes, and agent configuration artifacts.
- `framework/` — experiment framework code and reusable implementation utilities for the new study.
- `experiments/` — experiment definitions, run configurations, and scenario matrices.
- `results/` — generated evidence, logs, summaries, and reproduced outputs only.
- `scripts/` — deterministic helper scripts for setup, execution, validation, and reporting.
- `REPLICATION_PLAN.md` — initial scientific plan for the controlled replication and extensions.
- `AGENTS.md` — mandatory operating rules for coding agents working in this repository.

## Historical baseline handling

The old baseline repository is referenced here strictly as a **historical baseline**.

- It must not be merged into this repository automatically.
- It must not be treated as already reproduced evidence.
- It may inform protocol design, experiment selection, and comparison planning.
- Any future reuse of ideas or assets from the historical baseline must be explicitly documented and reviewed.

## Planned comparison dimensions

The planned comparison dimensions for the controlled replication and extension include:

- test case correctness
- boundary value handling
- false positives
- silent/unannounced code modifications
- branch coverage
- MC/DC feasibility for higher ASIL levels
- degree of human interaction needed

## Scientific use constraints

This repository is intended for **reproducible scientific research**, not benchmark marketing.

Accordingly:

- claims must be tied to reproducible experiment records;
- prompts, configurations, scripts, and outputs should be preserved whenever possible;
- negative, partial, or inconclusive outcomes must not be hidden;
- reported comparisons must distinguish clearly between historical baseline evidence and newly reproduced results; and
- manuscript wording must remain traceable to repository evidence rather than replacing it.

## Current status

This repository currently provides a clean initial scaffold for the replication study. It does **not** yet claim reproduced performance, coverage, or safety-related results.

See `REPLICATION_PLAN.md` for the initial scope and next milestones.
