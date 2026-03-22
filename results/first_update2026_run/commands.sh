cmake -S /workspace/iso26262-llm-test-framework-update-2026 -B /workspace/iso26262-llm-test-framework-update-2026/build/first_update2026_run \
  -DISO26262_BASELINE_ENABLE_COVERAGE=ON \
  -DISO26262_BASELINE_GENERATED_TEST_DIR=/workspace/iso26262-llm-test-framework-update-2026/results/first_update2026_run/generated
cmake --build /workspace/iso26262-llm-test-framework-update-2026/build/first_update2026_run
ctest --test-dir /workspace/iso26262-llm-test-framework-update-2026/build/first_update2026_run --output-on-failure
"/workspace/iso26262-llm-test-framework-update-2026/tools/bin/gcovr" -r /workspace/iso26262-llm-test-framework-update-2026 /workspace/iso26262-llm-test-framework-update-2026/build/first_update2026_run --html --html-details -o /workspace/iso26262-llm-test-framework-update-2026/results/first_update2026_run/coverage.html
