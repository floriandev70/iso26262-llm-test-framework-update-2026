# COMPARABILITY_ASSESSMENT

## Purpose

This document records an explicit, conservative assessment of how the current baseline run relates to the historical baseline and under what minimum conditions it may be treated as partially comparable.

The assessment is intentionally conservative. When a choice exists between a stronger claim and a more auditable claim, this document chooses the more auditable claim.

## Current comparability verdict

### Verdict

**Current run status: partially comparable for workflow-level analysis only; not yet strongly comparable for outcome-level historical replication claims.**

This verdict follows directly from the currently disclosed evidence chain:

- a baseline-aligned generation/build/test path was executed;
- the preserved generated suite built and executed;
- 61 tests ran and 4 assertions failed;
- coverage is unavailable due to missing `gcovr` in the execution environment;
- the run used `gpt-4.1` because historical `gpt-4-turbo` was unavailable; and
- the run used a local GoogleTest shim fallback instead of the historically closer live dependency-fetch path.

Because these deviations are explicit and at least one historically relevant output dimension (coverage) is missing, the run should **not** be presented as a strict baseline reproduction.

## Explicit deviations from the historical baseline

The following deviations must remain visible in any future comparison write-up.

### 1. Model substitution

- **Historical baseline reference:** `gpt-4-turbo` is the historically referenced model family in the repository's replication framing.
- **Current run:** `gpt-4.1`.
- **Reason:** historical `gpt-4-turbo` was unavailable.
- **Methodological effect:** the generation model is not historically matched, so any observed test quality, failure count, or future coverage result may reflect model drift rather than only workflow differences.

### 2. Dependency provisioning deviation for GoogleTest

- **Historically closer path:** live GoogleTest provisioning/fetch as assumed by the baseline-oriented setup.
- **Current run:** local GoogleTest shim fallback.
- **Reason:** live dependency fetch failed in the current environment and would otherwise have blocked the run.
- **Methodological effect:** the harness/runtime layer differs from the historically intended path, so the shim must be treated as an intervention whose scope should be preserved and reviewed.

### 3. Coverage missing

- **Historical baseline intent:** coverage is part of the baseline evaluation design.
- **Current run:** no coverage result.
- **Reason:** `gcovr` could not be installed in this environment.
- **Methodological effect:** the run cannot support coverage-based historical comparison and cannot yet satisfy the full replication chain defined in `docs/REPLICATION_SPEC.md`.

### 4. Outcome mismatch within the executed suite

- **Current run outcome:** 61 tests executed and 4 assertions failed.
- **Methodological effect:** even if all tooling had matched, this would still be an observed non-clean execution outcome that requires interpretation rather than silent normalization.

## What “partially comparable” means here

For this repository, the current run may be treated as **partially comparable** only in the following limited sense:

- it exercises the same broad research workflow class as the historical baseline: prompt-based test generation, materialization of generated tests, build, and test execution;
- it operates on the baseline-replication side of the study rather than the update-2026 extension side;
- it yields an auditable execution artifact that can anchor procedural comparisons; and
- it provides a concrete baseline-side run record against which a later update-2026 run can be contrasted, provided the deviations are held constant or explicitly analyzed.

It does **not** mean:

- comparable coverage performance;
- comparable raw model capability;
- interchangeable dependency conditions;
- replicated historical metrics; or
- readiness for pooled quantitative claims across historical and successor runs.

## Minimum conditions for treating the current run as partially comparable

The current run should be treated as partially comparable **only if all** of the following conditions are met in the run record and later analysis:

1. **The run remains labeled as partial comparability only.**
   - No stronger label such as “strictly comparable,” “fully replicated,” or “historically reproduced” may be used.

2. **All known deviations are disclosed together.**
   - At minimum: model substitution, local GoogleTest shim fallback, and missing coverage.

3. **The comparison scope is limited to workflow- and artifact-level observations.**
   - Acceptable examples: whether generation yielded compilable tests, whether tests executed, how many tests ran, and what assertion failures were observed.
   - Unacceptable examples: claiming coverage parity, model parity, or direct equivalence to published historical effectiveness.

4. **The source-under-test and prompt family remain baseline-aligned.**
   - The run must still be tied to the baseline replication corpus and prompt package rather than blended with update-2026 prompt changes.

5. **The preserved generated suite used for build/test remains the comparison anchor.**
   - Future interpretation must refer to the exact preserved generated test artifact actually executed, not a reconstructed or later-edited variant.

6. **Failed assertions are preserved as observed outcomes, not filtered away.**
   - Partial comparability requires keeping the imperfections in view.

7. **Coverage is treated as unavailable, not estimated.**
   - No imputed or substitute metric may be inserted unless separately produced, preserved, and documented as a deviation.

If any one of these conditions is not satisfied, the current run should be downgraded from **partially comparable** to **not comparable**.

## Conditions that would upgrade the baseline status later

The current run could support a stronger comparability judgment only if future documentation closes the key gaps, including:

- coverage collection with preserved tooling/version/invocation details;
- explicit preservation and review of the GoogleTest shim scope;
- a clearly documented mapping between the current run's prompt/rendering procedure and the historical baseline prompt design; and
- a justified interpretation of the `gpt-4.1` substitution relative to the unavailable historical model.

Even then, strong comparability would still need to remain qualified unless the model and dependency conditions were historically matched or convincingly bridged.

## Conservative bottom line

The current baseline run is best used as a **methodologically transparent baseline-side anchor run** for the first update-2026 comparison, but only under a **partial comparability** label and only with all deviations carried forward explicitly.
