# FIRST_GENERATION_EVIDENCE

## Run identity

- Run directory: `results/first_baseline_run`
- Study phase: baseline replication
- Baseline prompt family: common baseline prompt + ASIL A prompt
- Selected first target unit: `baseline/Lab/boolean_algebra.cpp`, initial function focus `check_a_OR_b`
- Source revision: `a08002a439ddb065bbbc68ea4e6e74c4fd3c52f2`
- API base configured in environment: `OPENAI_BASE_URL` (value intentionally not duplicated here)

## First baseline prompt selected

The first minimal baseline prompt used for this run is the repository's ASIL A baseline package rendered exactly as:

1. `prompts/replication/baseline/common_ASIL_assistant_test_instructions.md`
2. `prompts/replication/baseline/ASIL_a_assistant_test_instructions.md`
3. `baseline/Lab/includes/boolean_algebra.h`
4. `baseline/Lab/boolean_algebra.cpp`

These four files were concatenated byte-for-byte into `results/first_baseline_run/prompt.txt`.

## Model/API execution record

1. A direct OpenAI-compatible Responses API call was attempted first with historical model label `gpt-4-turbo`.
2. That attempt failed with API error `model_not_found` and message `The model `gpt-4-turbo` does not exist or you do not have access to it.`
3. A second direct Responses API call was then executed successfully with model `gpt-4.1` using the exact preserved prompt in `results/first_baseline_run/prompt.txt`.
4. The assistant text returned by that successful API call was preserved unchanged in `results/first_baseline_run/raw_model_output.txt`.

## Generated test source preservation

- The raw model output was HTML wrapped, matching the baseline prompt's `Provide the output as HTML` instruction.
- The Google Test source was materialized from the single `<pre><code>...</code></pre>` block in the raw output.
- HTML entities were decoded so the source text became a compilable `.cpp` file, but no source lines were manually edited.
- The resulting file was preserved at `results/first_baseline_run/generated_test_file.cpp`.
- An identical build-input copy used for CMake was placed at `results/first_baseline_run/generated/generated_test_file.cpp`.

## Build/test execution

Build/test was attempted after preserving the generated artifacts.

- Configure/build command output was preserved in `results/first_baseline_run/build.log`.
- Test command output was preserved in `results/first_baseline_run/test.log`.
- The build did not complete because the generated run-local `CMakeLists.txt` fetches GoogleTest from GitHub and the environment's proxy returned HTTP 403 for `https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip`.
- Because configuration was incomplete, `ctest` reported `No tests were found!!!`.

## Coverage status

- `gcovr` is not installed in the current environment.
- Coverage was therefore not executed.
- This is an environment limitation and is not being silently substituted with another tool.

## Artifact hashes

| Path | SHA-256 |
| --- | --- |
| `results/first_baseline_run/prompt.txt` | `330f5f1ebe57900d40fd6daac8ef4cd17b107e45ba6a5ab8339261a1d61195fa` |
| `results/first_baseline_run/raw_model_output.txt` | `9a09e0b186829cb335ca9d23552611cf4ad8000154922cd3988076b5136fdda7` |
| `results/first_baseline_run/generated_test_file.cpp` | `2f06e812d6d78205116ce0f9db79d6094826b7c5b42ff44d4d6396a90266d928` |
| `results/first_baseline_run/build.log` | `e3f18952c9bd455a396e27e37e8441972215c681ca40ee78242e5eee082e9669` |
| `results/first_baseline_run/test.log` | `8adb2c40e36eb9ec59236f5caf49f28969469967123fd6187c4395470e46c9bf` |
| `results/first_baseline_run/generated/CMakeLists.txt` | `a305e0469517f907222cbe5ac2cb3cb86df5cae772241af0900a542eb532b631` |
| `results/first_baseline_run/generated/generated_test_file.cpp` | `2f06e812d6d78205116ce0f9db79d6094826b7c5b42ff44d4d6396a90266d928` |
