# PROMPT_VERSIONING.md

## Purpose

This document defines a minimal prompt versioning scheme for the replication study.
The goal is to preserve prompt provenance across baseline-oriented replication runs and future extension experiments without silently changing the experimental input.

## Design principles

- Prompt identifiers must remain stable once assigned.
- Prompt revisions must be logged explicitly.
- Prompt families must be separated by ASIL level and experiment purpose.
- Reproducibility takes precedence over convenience.
- Silent prompt overwrites are not allowed.

## Prompt identifier scheme

Each prompt should use a stable identifier with the following structure:

`<purpose>-<asil>-<prompt_name>-v<major>.<minor>`

Examples:

- `replication-asil-b-unit-test-generation-v1.0`
- `replication-asil-d-coverage-augmentation-v1.0`
- `extension-asil-c-agent-guardrail-evaluation-v1.0`

### Field meanings

- `purpose`: high-level experiment category such as `replication` or `extension`
- `asil`: safety context such as `qm`, `asil-a`, `asil-b`, `asil-c`, or `asil-d`
- `prompt_name`: short stable descriptive label
- `major.minor`: semantic-style prompt revision number

## Versioning rules

### Stable prompt IDs

- The identifier for a released prompt version must never be reused for different text.
- If the prompt text changes, the version must change.
- References in experiment logs must cite the full prompt ID, not an abbreviated nickname.

### Change log per prompt

Each prompt file or prompt directory should include a short changelog containing:

- prompt ID
- creation date
- author or process that created the revision
- reason for change
- summary of textual or structural changes
- expected comparability impact

A minimal changelog entry format is:

```text
Prompt ID: replication-asil-b-unit-test-generation-v1.1
Date: YYYY-MM-DD
Change reason: clarify output formatting
Change summary: added explicit requirement to preserve source code under test
Comparability impact: low; instruction wording clarified without changing target task
```

### Separation by ASIL level and experiment purpose

- Prompts must be organized so that ASIL-targeted prompts are not mixed together without labels.
- Replication prompts and extension prompts must remain in separate directories or clearly separated naming groups.
- If the same base prompt is adapted for another ASIL level, create a new prompt versioned artifact rather than silently editing the old one.

### Reproducibility rules

For a prompt to be considered reproducible, the repository must preserve:

- the exact prompt text;
- the full prompt ID;
- any system or wrapper instructions that materially affect the run;
- any templated variables and their resolved values for the run;
- the model name used with the prompt; and
- the run ID that consumed that exact prompt version.

If part of the prompt is assembled dynamically, the run log must preserve the fully rendered prompt actually sent.

### No silent prompt overwrites

The following actions are prohibited:

- replacing prompt text in place while keeping the same version ID;
- editing a prompt after it has been used in a logged run without creating a new version; and
- keeping only the latest prompt text when earlier revisions were used for experiments.

## Suggested file layout

A minimal future layout is:

```text
prompts/
  replication/
    asil-b/
      unit-test-generation/
        v1.0.md
        CHANGELOG.md
  extension/
    asil-b/
      agent-guardrail-evaluation/
        v1.0.md
        CHANGELOG.md
```

This structure is a recommendation, not yet a populated prompt set.

## Release guidance

- Increase the major version when the task, evaluation target, or expected behavior changes materially.
- Increase the minor version when wording, formatting, or guardrail language changes but the core task remains comparable.
- When in doubt, create a new version and document the reason.
