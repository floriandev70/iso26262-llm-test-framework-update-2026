# results

This directory is reserved for preserved experiment outputs and evidence logs.

## Validity rule

No result in this repository is scientifically valid merely because a folder, table, or summary exists.
A result becomes valid study evidence only after it has been:

- actually produced by an executed run;
- logged with its exact inputs and outputs;
- tied to a specific source revision and prompt version; and
- preserved in a traceable form that supports later audit.

## Current state

At present, this directory is scaffolding only.
No reproduced experimental results are stored here yet.
Any future metrics, coverage values, or success claims must be backed by preserved evidence under a run-specific directory.

## Suggested future layout

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

This repository must not contain invented measurements, placeholder result tables presented as real findings, or copied historical outputs presented as newly reproduced evidence.
