# REPLICATION_PLAN.md

## Objective

Establish a reproducible framework for a controlled replication and extension study of ISO 26262 SWE.4 unit test generation and coverage analysis, using current OpenAI coding and agent-based workflows while keeping historical baseline evidence separate from new evidence.

## Baseline reference

Historical reference baseline:
- `floriandev70/iso26262-llm-test-framework`
- URL: <https://github.com/floriandev70/iso26262-llm-test-framework>

This baseline is a study reference only and must not be treated as reproduced evidence inside this repository.

## Manuscript alignment

A manuscript artifact is stored at `docs/LLAIS1_paper_26.pdf`.

The manuscript should be treated as a synchronized reporting artifact for the study, with repository evidence taking precedence whenever there is uncertainty. Any statement intended for publication should be traceable to preserved repository artifacts, commands, prompts, and result logs.

## Replication scope

Initial replication scope:

- reproduce the prior study workflow as closely as feasible using documented current tooling;
- define comparable tasks for ISO 26262 SWE.4 unit test generation;
- capture prompts, model/workflow settings, execution commands, outputs, and evidence;
- measure comparable quality and coverage dimensions without overstating equivalence where tooling differs.

## Extension scope

Initial extension scope:

- evaluate current OpenAI coding models and agent-based workflows;
- study agent governance constraints such as prevention of silent source modifications;
- compare the level of human guidance required across workflows;
- explore whether branch coverage and MC/DC-oriented workflows are practical to study for higher ASIL contexts.

## Risks to validity

- differences between historical and current model behavior may limit strict comparability;
- toolchain drift may affect compilation, test execution, or coverage measurement;
- agent-assisted workflows may introduce hidden intervention unless carefully logged;
- prompt changes and orchestration changes may confound attribution of observed effects;
- safety-relevant interpretations may be overstated if evidence trails are incomplete; and
- manuscript wording may drift away from the reproducible artifact trail unless claim-to-evidence links are maintained.

## First implementation milestones

1. Create repository governance documents and a reproducible scaffold.
2. Define directory conventions for prompts, agents, experiments, scripts, and evidence.
3. Connect the historical baseline as a reference-only input with clear provenance.
4. Define the experiment matrix and versioned prompt structure.
5. Define evidence logging, coverage reporting, and result comparison formats.
6. Add a claim-to-evidence trace process so manuscript statements can be audited against repository artifacts.
7. Implement deterministic execution scripts for the first controlled pilot runs.

## TODO

- [ ] connect old repo as reference only
- [ ] define experiment matrix
- [ ] define prompt versioning
- [ ] define evidence logging format
- [ ] define coverage toolchain and reporting format
- [ ] define claim-to-evidence trace format for manuscript alignment
