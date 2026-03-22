cmake -S /workspace/iso26262-llm-test-framework-update-2026 -B /workspace/iso26262-llm-test-framework-update-2026/build/first_baseline_run \
  -DISO26262_BASELINE_ENABLE_COVERAGE=ON \
  -DISO26262_BASELINE_GENERATED_TEST_DIR=/workspace/iso26262-llm-test-framework-update-2026/results/first_baseline_run/generated
cmake --build /workspace/iso26262-llm-test-framework-update-2026/build/first_baseline_run
ctest --test-dir /workspace/iso26262-llm-test-framework-update-2026/build/first_baseline_run --output-on-failure
"/workspace/iso26262-llm-test-framework-update-2026/tools/bin/gcovr" -r /workspace/iso26262-llm-test-framework-update-2026 /workspace/iso26262-llm-test-framework-update-2026/build/first_baseline_run --html --html-details -o /workspace/iso26262-llm-test-framework-update-2026/results/first_baseline_run/coverage.html
