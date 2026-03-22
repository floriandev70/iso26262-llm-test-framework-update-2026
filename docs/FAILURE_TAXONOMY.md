# FAILURE_TAXONOMY

## Purpose

This taxonomy defines conservative failure classes for generated-test mismatches observed in the current ISO 26262 replication/update study.

The taxonomy is intentionally evidence-first. A class should be assigned only when the preserved source, preserved generated test, and preserved execution log support it directly or make it the most conservative plausible explanation.

## Classification rules

1. Prefer a **source-grounded** explanation over a speculative prompt-psychology explanation.
2. Use **primary** and optional **secondary** classes when more than one phenomenon appears relevant.
3. Do **not** treat failing assertions as infrastructure defects unless the log shows harness corruption, nondeterminism, or contradictory execution evidence.
4. If no requirement artifact exists beyond source and prompt text, classify against **preserved source semantics** and the generated test's own stated intent.

## Taxonomy classes

### FT-1: Incorrect expected behavior in generated test

**Definition:**
The generated assertion's expected value conflicts directly with the preserved source-under-test behavior for the stated inputs.

**Typical evidence:**
- the function body evaluates deterministically for the failing input tuple;
- the generated assertion expects the opposite result; and
- no harness corruption is evident.

### FT-2: Requirement misunderstanding

**Definition:**
The generated test appears to misread the intended logic encoded in the available artifact set, usually by simplifying or misparsing a compound condition.

**Typical evidence:**
- the failure clusters around one logical subfamily of functions;
- the generated test labels indicate a conceptual story that does not match source semantics; and
- the error is explainable as a misunderstanding of the requirement encoded in function naming and implementation.

### FT-3: Overgeneralization / hallucinated logic

**Definition:**
The generated test appears to apply a plausible but incorrect generalized rule to a compound function, such as assuming two subconditions are mutually exclusive when the source permits overlap.

**Typical evidence:**
- errors repeat across structurally related functions;
- the mistaken expected values follow a simplified mental rule rather than the actual composite expression; and
- the preserved source shows the missing interaction explicitly.

### FT-4: Boundary-value weakness

**Definition:**
The generated test set misses or misclassifies edge combinations that are especially informative for the function's decision boundary.

**Typical evidence:**
- failures occur at transition points or edge combinations;
- neighboring cases pass while a pivotal edge combination fails; and
- the mismatch is better explained by weak boundary partitioning than by wholly invented logic.

### FT-5: Other anomaly requiring separate review

**Definition:**
A failure that does not fit the classes above, or where evidence is insufficient for a stronger claim.

**Examples:**
- infrastructure corruption;
- nondeterministic behavior;
- undefined behavior in the source under test;
- mismatch caused by undocumented preprocessing, wrappers, or hidden assumptions.

## Notes for boolean-logic studies

For boolean functions, `FT-4` should be used carefully. A boolean input space often has exhaustive or near-exhaustive combinations, so a failing case is frequently better classified as `FT-1`, `FT-2`, or `FT-3` unless the evidence specifically shows an edge-partition weakness.
