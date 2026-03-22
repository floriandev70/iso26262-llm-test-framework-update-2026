# COVERAGE_ENABLEMENT

## Goal

Enable coverage reporting for the preserved baseline/update runs without changing prompts or source-under-test files, while ensuring that all baseline `.cpp` modules are actually exercised by tests.

## Constraint encountered

The environment did not provide an installable upstream `gcovr` package path:

```bash
python3 -m venv .venv/gcovr
.venv/gcovr/bin/pip install gcovr==8.4
apt-get update && apt-get install -y gcovr
```

In this container, both installation paths were blocked by HTTP 403 proxy/network failures.

## Smallest reproducible solution used

A repo-local `gcovr`-compatible wrapper was added at:

```text
tools/bin/gcovr
```

Why this was chosen:
- it avoids changing scientific inputs;
- it avoids depending on unavailable package mirrors;
- it keeps the invocation shape aligned with the repository's existing `gcovr`-based workflow; and
- it is committed in-repo, so the same command is reproducible in the same environment.

The wrapper supports the subset required by the current runs:

```bash
gcovr -r <repo_root> <build_dir> --html --html-details -o <coverage_html>
```

Internally, it shells out to the already-installed GCC `gcov` tool and writes a single HTML report.

## Why additional tests were needed

The preserved generated test file only exercised `boolean_algebra.cpp`.

That left:
- `baseline/Lab/math_lib.cpp`; and
- `baseline/Lab/real_world.cpp`

compiled but uncovered.

To satisfy the requirement that all baseline `.cpp` files are covered by tests, a deterministic repository-authored supplemental test file was added at:

```text
tests/supplemental_all_cpp_tests.cpp
```

This supplemental file:
- does **not** modify the preserved generated tests;
- is linked alongside them during the executable build; and
- exists specifically to exercise the remaining baseline modules for measurement.

## Script adjustments needed to execute the preserved runs

To execute coverage on the existing run artifacts without changing prompts, source-under-test files, or the preserved generated tests, `scripts/run_first_baseline.sh` was updated to:

1. prefer the repo-local `tools/bin/gcovr` when no system `gcovr` is available;
2. avoid failing when source/destination artifact paths are the same preserved file;
3. preserve test failures while still continuing on to the coverage step; and
4. include `tests/supplemental_all_cpp_tests.cpp` in the generated-test executable so `math_lib.cpp` and `real_world.cpp` are also exercised.

These are tooling/orchestration changes only.

## Coverage execution commands

For each preserved run, the materialized command sequence remains:

```bash
cmake -S <repo_root> -B build/<run_id> \
  -DISO26262_BASELINE_ENABLE_COVERAGE=ON \
  -DISO26262_BASELINE_GENERATED_TEST_DIR=results/<run_id>/generated
cmake --build build/<run_id>
ctest --test-dir build/<run_id> --output-on-failure
<repo_root>/tools/bin/gcovr -r <repo_root> build/<run_id> --html --html-details -o results/<run_id>/coverage.html
```

## Remaining limitations

1. **This is not upstream `gcovr`.**
   - It is a repo-local compatibility wrapper because package installation remained blocked.
2. **Supplemental tests are repo-authored, not model-generated.**
   - They were added to cover `math_lib.cpp` and `real_world.cpp` explicitly, while leaving the preserved generated tests unchanged.
3. **Failing assertions remain real findings.**
   - The original 4 failing generated tests still fail; the added supplemental tests do not “fix away” those findings.
4. **Coverage comparability still requires care.**
   - The first baseline/update pair now both have coverage artifacts for all baseline `.cpp` modules, but broader model/workflow/tooling deviations remain outside the scope of this enablement step.

## Required update-run artifacts

The requested update-run artifacts are preserved at:

- `results/first_update2026_run/coverage.log`
- `results/first_update2026_run/coverage.html`

## Additional preserved run artifacts

Coverage was also executed for the existing baseline anchor and preserved at:

- `results/first_baseline_run/coverage.log`
- `results/first_baseline_run/coverage.html`
