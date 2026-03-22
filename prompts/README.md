# prompts

This directory is reserved for versioned prompt artifacts used by the controlled replication and extension study.

## Intent

Future prompt sets should be stored here in a structure that makes the following visible at a glance:

- experiment purpose, such as replication versus extension;
- targeted ASIL level;
- prompt family or task type;
- exact prompt version; and
- prompt changelog or revision history.

## Suggested structure

A minimal future structure is:

```text
prompts/
  replication/
    asil-a/
    asil-b/
    asil-c/
    asil-d/
  extension/
    asil-a/
    asil-b/
    asil-c/
    asil-d/
```

Within each leaf directory, store versioned prompt files and their changelog, for example:

```text
unit-test-generation/
  v1.0.md
  CHANGELOG.md
```

## Repository rules

- Do not overwrite a prompt that has already been used in a logged run.
- Keep prompt versions stable and traceable.
- Preserve the exact text used for each experiment.
- Separate replication-oriented prompts from extension-oriented prompts.
- If prompt rendering is dynamic, preserve the fully rendered prompt in the corresponding run evidence.

See `docs/PROMPT_VERSIONING.md` for the repository-level prompt governance rules.
