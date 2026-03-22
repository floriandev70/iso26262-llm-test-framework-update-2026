# COVERAGE_ENABLEMENT

## Goal

Enable coverage measurement for the preserved runs without changing the scientific inputs, generated tests, or source under test.

## What was attempted

The repository already supported coverage instrumentation through CMake:

- `-DISO26262_BASELINE_ENABLE_COVERAGE=ON` enables `--coverage` compile and link flags.
- The preserved update run already had a build/test procedure that used those flags.

The missing piece was the reporting tool.

## Requested tool: `gcovr`

The smallest reproducible enablement path attempted in this environment was to install `gcovr` directly from the system/package channels already available to the container:

1. Python virtual environment attempt:

   ```bash
   python3 -m venv .venv/gcovr
   .venv/gcovr/bin/pip install gcovr==8.4
   ```

2. System package attempt:

   ```bash
   apt-get update && apt-get install -y gcovr
   ```

Both installation attempts failed because this container's proxy/network path returned HTTP 403 errors for package retrieval.

## Reproducible fallback used

Because `gcovr` could not be made available from the environment's package channels, coverage reporting for the executable preserved run was performed with the already-installed GCC coverage toolchain:

```bash
cmake -S . -B build/first_update2026_run \
  -DISO26262_BASELINE_ENABLE_COVERAGE=ON \
  -DISO26262_BASELINE_GENERATED_TEST_DIR=/workspace/iso26262-llm-test-framework-update-2026/results/first_update2026_run/generated
cmake --build build/first_update2026_run
ctest --test-dir build/first_update2026_run --output-on-failure
gcov -b -c build/first_update2026_run/baseline/Lab/CMakeFiles/baseline_lab.dir/boolean_algebra.cpp.gcno
gcov -b -c build/first_update2026_run/generated_baseline_tests/CMakeFiles/first_baseline_generated_tests.dir/generated_test_file.cpp.gcno
```

This fallback keeps coverage as a measurement-only activity:

- no prompt files were changed;
- no C/C++ source under test was changed;
- no generated tests were changed; and
- failing assertions remained visible in the preserved execution log.

## Why this fallback is acceptable for now

- The build already emitted `.gcno` / `.gcda` coverage artifacts under GCC `--coverage` instrumentation.
- `gcov` is the underlying coverage data reader for this toolchain and was already present in the environment.
- The fallback was applied only to the already-preserved executable update run, not by altering study inputs.

## Remaining limitations

1. **`gcovr` is still not actually installed.**
   - The repository now has preserved coverage measurement for the executable update run, but not a native `gcovr --html` report.
2. **The first baseline-side anchor still lacks a complete executable run.**
   - That run does not yet have a fully preserved generated-output execution chain comparable to `first_update2026_run`, so no symmetric baseline coverage report was created here.
3. **Tool comparability remains limited.**
   - Current coverage evidence for `first_update2026_run` is `gcov`-based fallback evidence, not `gcovr`-native evidence.
4. **Failing tests still matter.**
   - Coverage collection does not reinterpret or erase the four preserved failing assertions from the update run.

## Artifacts produced

- Log of the coverage execution and exact commands: `results/first_update2026_run/coverage.log`
- HTML coverage artifact derived from preserved `gcov` output: `results/first_update2026_run/coverage.html`
- Run-level narrative report: `docs/COVERAGE_EXECUTION_REPORT.md`
