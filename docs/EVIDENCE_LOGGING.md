# EVIDENCE_LOGGING.md

## Purpose

This document defines the minimum evidence that must be preserved for each experiment run.
No run should be treated as valid study evidence unless its inputs, outputs, and final assessment are logged in a traceable way.

## Minimum run record

Each experiment run must preserve the following fields.

| Field | Required content |
| --- | --- |
| `timestamp` | Start time and, if feasible, end time in a stable format such as UTC ISO 8601 |
| `run_id` | Stable identifier linking all artifacts from the run |
| `model_name` | Exact model or workflow name used |
| `prompt_id` | Versioned prompt identifier |
| `exact_prompt` | Full rendered prompt actually sent to the model or workflow |
| `source_function` | Exact function under test, including file path or equivalent identifier |
| `source_hash` | Commit hash, file hash, or preserved source snapshot identifier |
| `generated_output_files` | List of generated tests, logs, and any other created artifacts |
| `compiler_output` | Preserved compiler invocation and compiler output |
| `test_execution_output` | Preserved test invocation and execution output |
| `coverage_output` | Preserved coverage command and coverage output |
| `manual_interventions` | Description of every manual action taken during or after the run |
| `final_assessment` | Controlled conclusion such as accepted, rejected, partial, or inconclusive |

## Logging requirements

### Timestamp

- Record timestamps in UTC where possible.
- If multiple phases occur, record separate timestamps for generation, compilation, execution, and assessment.

### Model name

- Record the provider-specific model name exactly as used.
- If an agent workflow orchestrates the run, also record the workflow or toolchain identifier.

### Exact prompt

- Preserve the complete rendered prompt, not only a template reference.
- If system, wrapper, or orchestration instructions affect behavior, store those alongside the user prompt or clearly link them.

### Source function and hash

- The source function must be identified unambiguously.
- The corresponding source revision must be preserved by commit hash or another immutable snapshot reference.
- If the source changes after a run, the old run remains tied to the original recorded hash.

### Generated output files

Generated artifacts should be listed explicitly, for example:

- generated unit test files
- transformed prompt files
- raw model outputs
- patch files
- coverage reports
- structured summaries derived from the run

### Compiler, execution, and coverage output

- Preserve raw tool output where possible.
- Record the command that produced the output.
- If a step was skipped, state `not run` and explain why.
- If a tool fails, preserve the failure output rather than replacing it with a paraphrase.

### Manual interventions

Manual interventions include, but are not limited to:

- editing generated tests;
- rerunning a command with changed flags;
- correcting paths or environment variables;
- excluding a generated test from execution; or
- manually preventing or reverting a silent source modification.

If no intervention occurred, record that explicitly.

### Final assessment

A final assessment should summarize whether the run is suitable for study use. Suggested controlled labels are:

- `accepted`
- `accepted-with-intervention`
- `rejected`
- `partial`
- `inconclusive`

The label should be accompanied by a short rationale.

## Suggested artifact layout

A minimal future run layout is:

```text
results/
  <run_id>/
    metadata.json
    prompt.txt
    compiler.log
    test_execution.log
    coverage.log
    generated/
    assessment.md
```

The exact format may evolve, but the evidence content must remain preserved.

## Invalid evidence patterns

The following do not count as adequate evidence by themselves:

- conversational summaries without preserved files;
- manually copied metrics with no underlying logs;
- coverage percentages without the tool output that produced them; and
- claims that a run succeeded when compile or execution output was not retained.
