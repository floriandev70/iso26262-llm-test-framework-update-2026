# EXPERIMENT_MATRIX.md

## Purpose

This document defines the minimum experiment matrix for the controlled replication study.
It is a study design artifact, not a results table. Rows may only be added with observed run metadata, and measured fields must remain empty, `not run`, or `unavailable` until an actual run has been executed and logged.

## Scope

The matrix is intended to support side-by-side comparison between:

- the historical baseline configuration as a reference target for controlled replication; and
- current-model runs executed and logged in this repository.

Historical baseline values must not be copied in as if they were reproduced here. Any historical values referenced later must be explicitly marked as baseline-reference data and linked to their original evidence source.

## Required columns

Each experiment row should include at least the following fields.

| Field | Description | Notes |
| --- | --- | --- |
| `study_phase` | Distinguishes `baseline-reference`, `controlled-replication`, or `extension` | Prevents historical and new evidence from being mixed |
| `experiment_id` | Stable identifier for the experiment definition | Should not change after first use |
| `function_under_test` | Exact function or unit under test | Use a repository-relative path or unambiguous identifier |
| `source_revision` | Commit hash or preserved source snapshot ID | Required for reproducibility |
| `asil_level` | Target ASIL context | Example: `QM`, `ASIL A`, `ASIL B`, `ASIL C`, `ASIL D` |
| `experiment_purpose` | Replication or extension intent | Example: branch coverage comparison, prompt sensitivity, model comparison |
| `prompt_version` | Versioned prompt ID used for the run | Must resolve to a preserved prompt artifact |
| `model_used` | Exact model name or workflow identifier | Record provider-specific naming exactly |
| `run_id` | Stable run identifier | Must map to evidence logs and produced artifacts |
| `generated_test_count` | Number of generated tests or test cases | Only log after generation completes |
| `compile_status` | Compile success or failure | Use controlled values such as `success`, `failure`, `not run` |
| `execution_status` | Test execution success or failure | Use controlled values such as `success`, `failure`, `not run` |
| `branch_coverage` | Measured branch coverage | Record exact reported value and unit, or `unavailable` |
| `mcdc_coverage` | Measured MC/DC coverage if available | Record exact reported value and unit, or `unavailable` |
| `false_positives_observed` | Whether incorrect or non-actionable generated tests were observed | Prefer explicit count plus short note when possible |
| `silent_code_modifications_observed` | Whether the workflow modified source under test without explicit authorization | Must be treated as a governed observation |
| `human_interventions_needed` | Manual steps required to complete the run | Include intervention count or a short classified summary |
| `notes_anomalies` | Free-text notes on unusual behavior, confounders, or anomalies | Keep concise and evidence-linked where possible |

## Initial blank matrix template

The following template is intentionally blank and should be copied into run tracking artifacts or a future tabular registry once experiment execution begins.

| study_phase | experiment_id | function_under_test | source_revision | asil_level | experiment_purpose | prompt_version | model_used | run_id | generated_test_count | compile_status | execution_status | branch_coverage | mcdc_coverage | false_positives_observed | silent_code_modifications_observed | human_interventions_needed | notes_anomalies |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| controlled-replication | | | | | historical-baseline-comparison | | | | not run | not run | not run | unavailable | unavailable | not assessed | not assessed | not assessed | |
| extension | | | | | current-model-comparison | | | | not run | not run | not run | unavailable | unavailable | not assessed | not assessed | not assessed | |

## Recording rules

1. Do not enter coverage values, success states, or test counts unless they were produced by a preserved run.
2. If a field is unknown, mark it explicitly as `unavailable`, `not run`, or `not assessed` rather than leaving ambiguous prose.
3. Keep replication rows and extension rows distinguishable by `study_phase` and `experiment_purpose`.
4. If a row summarizes multiple generated files, link the row to a run-level evidence directory rather than embedding uncontrolled summaries.
5. If a run required manual repair, capture that in `human_interventions_needed` and in the evidence log.
6. If any silent source modification is detected, record it explicitly and treat the run as methodologically significant.

## Future extensions

This matrix may later be extended with additional fields such as toolchain version, compiler version, coverage tool version, token usage, wall-clock runtime, or reviewer assessment, provided that the added fields remain traceable and consistently populated.
