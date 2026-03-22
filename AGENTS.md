# AGENTS.md

This repository supports a controlled replication and extension study for ISO 26262 SWE.4 unit test generation and coverage analysis. All coding agents and automation workflows must follow the rules below.

## Core operating rules

1. **Never silently modify source code under test.**
   - Any change to code under test must be intentional, explicitly disclosed, and justified.
2. **Never invent measurements, coverage values, or experimental outcomes.**
   - If a result has not been produced and preserved, it must be reported as unavailable.
3. **Treat the old repository as reference input, not as a source to merge automatically.**
   - Historical artifacts may inform planning, but they are not to be imported without explicit review.
4. **Separate baseline replication from extension experiments.**
   - Keep study phases, configurations, prompts, and outputs clearly distinguishable.
5. **Log assumptions explicitly.**
   - If an assumption is required, record it close to the relevant experiment or script.
6. **Prefer deterministic scripts and documented commands.**
   - Manual steps should be minimized and documented when unavoidable.
7. **Propose non-trivial changes in small reviewable patches.**
   - Favor traceable, incremental updates over large opaque edits.
8. **Keep prompts, outputs, and experiment configs reproducible.**
   - Version and preserve the inputs required to recreate a run.
9. **When uncertain, choose traceability and auditability over convenience.**
   - A slower but well-evidenced workflow is preferred over an ambiguous shortcut.
10. **Preserve evidence for each experiment run.**
    - Store logs, prompts, configurations, metadata, and derived reports in a way that supports later audit.

## Practical repository expectations

- Do not present placeholder metrics or fabricated tables as real results.
- Distinguish clearly between repository scaffolding, implemented tooling, and reproduced findings.
- Prefer explicit file-based records over ephemeral conversational summaries.
- When interacting with external repositories or tools, document versions, commit hashes, and invocation commands whenever feasible.
- If a workflow cannot be made fully deterministic, document the source of nondeterminism and the mitigation steps used.
