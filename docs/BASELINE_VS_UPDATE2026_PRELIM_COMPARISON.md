# BASELINE_VS_UPDATE2026_PRELIM_COMPARISON

## Purpose

This document records a conservative preliminary comparison between the current baseline-side anchor and the first update-2026 comparison run.

It is intentionally limited to dimensions for which repository evidence currently exists.

## Shared evidence dimensions currently available

At present, the repository contains comparable evidence for the following dimensions:
- preserved prompt package structure;
- preserved generated test artifacts;
- preserved test-suite size at execution time;
- preserved count of failing assertions at execution time; and
- explicit documentation of tooling deviations and missing coverage.

Coverage-backed comparison is **not** currently available.

## Baseline-side anchor evidence currently available

The repository's baseline-side documentation currently supports the following conservative statements:
- the baseline-side anchor executed 61 tests;
- 4 assertions failed; and
- coverage remained unavailable.

The repository also preserves a baseline-side generated test file whose relevant failing-prone region is textually identical to the corresponding region in the update-2026 generated test file.

## Update-2026 run evidence currently available

For `first_update2026_run`, the repository preserves:
- a successful build;
- execution of 61 tests;
- 4 failed assertions; and
- the exact failing assertion names in the preserved test log.

## Preliminary comparison table

| Dimension | Baseline-side anchor | First update-2026 run | Comparison status |
| --- | --- | --- | --- |
| Prompt family | Baseline-aligned ASIL A prompt family documented | Frozen baseline ASIL A prompt family used unchanged | Broadly aligned |
| Source under test | `boolean_algebra` baseline source family documented | Same preserved `boolean_algebra` source used | Aligned |
| Generated suite size at execution | 61 tests documented | 61 tests observed | Comparable |
| Failing assertion count | 4 failures documented | 4 failures observed | Comparable at count level |
| Assertion-level failure identity | Not fully preserved in currently cited baseline execution logs | Preserved explicitly in `results/first_update2026_run/test.log` | Only partially comparable |
| Coverage | Unavailable | Unavailable | Comparable only in the sense of shared absence |
| Tooling path | Local GoogleTest shim fallback documented for baseline-side anchor | Local GoogleTest-compatible shim documented for update-2026 run | Broadly aligned as a deviation |

## What can be compared conservatively

### 1. Failure-count pattern

A conservative comparison is possible at the pattern level:
- both sides are documented as executing 61 tests; and
- both sides are documented as having 4 failed assertions.

This supports a preliminary statement that the update-2026 run did **not** diverge from the baseline-side anchor at the coarse execution-count / failure-count level.

### 2. Artifact-level similarity in the relevant failure region

The baseline-side preserved generated test artifact and the update-2026 preserved generated test artifact contain the same assertion bodies for the two affected function families:
- `check_a_AND_b_XOR_a_AND_NOT_c`; and
- `check_a_AND_b_XOR_a_AND_NOT_c_OR_d`.

This makes it plausible that the same semantic weakness exists on both sides.

**Important limitation:** this is an inference from preserved artifact identity, not a substitute for a baseline-side assertion-by-assertion execution log.

### 3. Shared methodological limitation

Both sides currently remain limited by the absence of coverage data, so no branch, statement, or MC/DC comparison should be attempted from these artifacts.

## What cannot yet be claimed

The current repository evidence does **not** yet justify the following stronger claims:
- that the exact same four named assertions failed on both sides, unless baseline-side assertion-level execution evidence is preserved and cited later;
- that the update-2026 run improved or worsened semantic correctness relative to baseline; or
- that either side is superior in coverage, since coverage is unavailable for both.

## Conservative bottom line

The best preliminary comparison currently supported by repository evidence is:
- baseline-side anchor and first update-2026 run are aligned on the same source family and prompt family;
- both are documented at the coarse outcome level as **61 tests executed, 4 assertions failed**; and
- the update-2026 run now provides explicit assertion-level failure evidence that can guide later, more precise comparison work.

Anything stronger than that should wait for more complete baseline-side assertion-level evidence.
