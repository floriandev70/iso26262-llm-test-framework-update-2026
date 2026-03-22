# THREATS_TO_VALIDITY.md

## Purpose

This document records the initial threats to validity for the controlled replication and extension study.

It is intentionally conservative. No mitigation listed here should be read as proof that a threat has been eliminated. The purpose is to make validity risks explicit early, so that future experiment definitions and result claims can be audited against them.

## Internal validity

Internal validity concerns whether observed outcomes can be attributed to the intended experimental factors rather than hidden changes in workflow, tooling, or operator behavior.

### Major threats

- **Hidden source changes**: agent or user workflows may modify source code under test, changing the evaluation target.
- **Unlogged manual repair**: compilation fixes, test edits, reruns, and environment adjustments may materially affect outcomes if not preserved.
- **Prompt-package mismatch**: using a prompt that differs from the baseline design while treating the run as a baseline replication confounds attribution.
- **Mixed study phases**: combining baseline-reference evidence, controlled replication evidence, and extension evidence in one table or narrative can create false comparability.
- **Inconsistent function selection**: changing which historical functions are included can change apparent performance independently of the model or workflow.

### Initial mitigations

- preserve source revisions and generated outputs for every run;
- log all manual interventions explicitly;
- version prompts and store the exact rendered prompt;
- keep study phases distinct in experiment records; and
- freeze the baseline function/task inventory before comparative claims are made.

## Construct validity

Construct validity concerns whether the study metrics and procedures actually measure the concepts they are claimed to measure.

### Major threats

- **Coverage as proxy for test quality**: high statement, branch, or MC/DC coverage does not by itself prove requirement adequacy, defect detection strength, or ISO 26262 suitability.
- **False-positive under-definition**: if "false positives" are not defined operationally, counts may vary by reviewer.
- **Human interaction ambiguity**: without a structured intervention taxonomy, "required human guidance" can be interpreted inconsistently.
- **ASIL prompt interpretation drift**: ASIL-specific prompts may encode different expectations than the paper narrative or later reproduction assumes.
- **Failure-class ambiguity**: compile failures, semantically wrong assertions, flaky tests, and unauthorized code modifications are different phenomena and should not be merged into one undifferentiated outcome.

### Initial mitigations

- treat coverage as one measurement dimension rather than the sole success criterion;
- formalize an anomaly taxonomy before scaled experimentation;
- record reviewer decisions and rationale when classifying failures;
- keep prompt families versioned and ASIL-labeled; and
- distinguish compilation, execution, semantic, and governance failures in the evidence model.

## External validity

External validity concerns whether observed results generalize beyond the exact repository, functions, prompts, and tooling used.

### Major threats

- **Limited benchmark scope**: the historical baseline repository appears to use a small set of source modules, which may not represent broader automotive software diversity.
- **Domain realism limits**: modules such as arithmetic and boolean logic tasks may underrepresent integration-heavy or hardware-coupled SWE.4 contexts.
- **Prompt-specific overfitting**: results may depend heavily on one prompt family rather than general model capability.
- **Toolchain-specific behavior**: build, compiler, and coverage behavior may differ across environments.
- **Model-provider specificity**: conclusions from one provider or one model family may not generalize to other LLMs or agent platforms.

### Initial mitigations

- describe the replication target narrowly and avoid overstated generalization;
- separate baseline replication claims from later extension claims;
- report exact prompt, model, and tooling context for every run; and
- characterize the historical task set explicitly before drawing broader conclusions.

## Reproducibility risks

Reproducibility risks concern whether a third party could reconstruct the exact workflow, evidence, and conclusions from repository artifacts.

### Major threats

- **Missing raw logs**: narrative summaries without compiler, execution, and coverage logs are insufficient.
- **Prompt non-preservation**: storing only prompt templates and not the fully rendered prompt undermines repeatability.
- **Unpinned environments**: unspecified compiler, CMake, coverage, or CI versions may affect outcomes.
- **Ephemeral platform behavior**: hosted agent tools may change behavior without repository-visible changes.
- **Baseline evidence gaps**: if historical results are referenced without preserved provenance, later comparisons become unauditable.

### Initial mitigations

- follow the repository evidence logging requirements strictly;
- preserve exact commands, raw outputs, and source hashes;
- record toolchain identifiers and versions wherever feasible; and
- keep historical reference evidence distinct from reproduced evidence.

## Model drift and platform change risks

This study compares current workflows against a historical baseline that referenced `GPT-4-turbo`. Model and platform evolution is therefore a first-order validity issue rather than a background nuisance.

### Major threats

- **Model snapshot drift**: the historically used model snapshot may no longer be accessible or behaviorally stable.
- **Provider-side updates**: model serving, safety layers, or response formatting may change without a repository change.
- **Agent orchestration drift**: current coding-agent platforms may add hidden planning, tool use, or code-edit behavior not present in the baseline workflow.
- **Evaluation asymmetry**: comparing a manually prompted baseline against a richer agent workflow may confound model capability with orchestration capability.

### Initial mitigations

- record exact model/workflow identifiers and execution context;
- separate pure prompt-based replications from agent-mediated extensions;
- treat inaccessible historical model snapshots as a comparability limitation, not as something to be hand-waved away; and
- document orchestration capabilities that materially alter the generation process.

## Prompt drift risks

Prompt drift includes any change in instructions, scaffolding, or context assembly that changes the task being given to the model.

### Major threats

- **Silent prompt edits**: small wording changes may materially alter generation behavior.
- **Wrapper-instruction creep**: system prompts, agent instructions, or orchestration policies may add constraints not present in the baseline prompts.
- **Knowledge-file mismatch**: changing, omitting, or augmenting the supplemental knowledge documents changes the effective prompt package.
- **ASIL label without ASIL semantics**: a prompt may keep its ASIL label while losing the historically intended coverage objective.

### Initial mitigations

- version prompts semantically and never overwrite a released prompt ID;
- preserve the complete rendered prompt used in each run;
- preserve supplemental knowledge artifacts as part of the prompt package; and
- classify wrapper/system instructions as part of the experimental input when they affect behavior.

## Tooling differences versus the historical baseline

Tooling differences can make results only partially comparable even when the source functions and prompts appear matched.

### Major threats

- **Coverage-tool differences**: `gcovr` and `llvm-cov` may report differently depending on instrumentation, compiler, and exclusion behavior.
- **Compiler differences**: GCC, Clang, and MSVC may differ in warnings, generated code, and coverage support.
- **Build-configuration drift**: debug versus non-debug builds, sanitizer flags, or coverage flags can affect observed outcomes.
- **CI versus local-run asymmetry**: CI automation can differ from interactive local workflows in dependencies, environment variables, and artifact retention.
- **Dependency-version drift**: the historical baseline fetched GoogleTest, and upstream changes in transitive tooling or host platform behavior may influence reproducibility.

### Initial mitigations

- record compiler, build mode, and coverage tooling for each run;
- avoid comparing coverage metrics across materially different instrumentation setups without an explicit caveat;
- preserve coverage commands and raw outputs;
- treat CI as supportive infrastructure rather than implicit proof; and
- document deviations from the historical baseline as first-class run metadata.

## Current study-level caution

At the current repository stage, no reproduced runs have been logged. Therefore:

- no empirical claim should yet be framed as validated in this repository;
- threat mitigations are procedural commitments, not demonstrated controls; and
- any future manuscript synchronization must distinguish clearly between planned controls and executed evidence.
