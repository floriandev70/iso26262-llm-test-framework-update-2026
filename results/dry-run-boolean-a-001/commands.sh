cmake -S /workspace/iso26262-llm-test-framework-update-2026 -B /workspace/iso26262-llm-test-framework-update-2026/build/dry-run-boolean-a-001 \
  -DISO26262_BASELINE_ENABLE_COVERAGE=ON \
  -DISO26262_BASELINE_GENERATED_TEST_DIR=/workspace/iso26262-llm-test-framework-update-2026/results/dry-run-boolean-a-001/generated
cmake --build /workspace/iso26262-llm-test-framework-update-2026/build/dry-run-boolean-a-001
ctest --test-dir /workspace/iso26262-llm-test-framework-update-2026/build/dry-run-boolean-a-001 --output-on-failure
