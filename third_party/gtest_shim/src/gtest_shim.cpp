#include "gtest/gtest.h"

#include <exception>

namespace testing {

TestState& GetState() {
  static TestState state;
  return state;
}

void RegisterTest(const char* suite_name, const char* test_name, std::function<void()> fn) {
  GetState().tests.push_back(TestCaseRecord{suite_name, test_name, std::move(fn)});
}

void RecordFailure(const char* file, int line, const std::string& message) {
  auto& state = GetState();
  state.failed_assertions++;
  state.current_test_failed = true;
  std::cerr << file << ':' << line << ": Failure\n" << message << '\n';
}

int InitGoogleTest(int* /*argc*/, char** /*argv*/) {
  return 0;
}

namespace internal {
TestRegistrar::TestRegistrar(const char* suite_name, const char* test_name, std::function<void()> fn) {
  RegisterTest(suite_name, test_name, std::move(fn));
}
}  // namespace internal

int RunAllTests() {
  auto& state = GetState();
  int failed_tests = 0;

  std::cout << "[==========] Running " << state.tests.size() << " tests from "
            << state.tests.size() << " test cases.\n";
  for (const auto& test : state.tests) {
    state.current_test_failed = false;
    std::cout << "[ RUN      ] " << test.suite_name << '.' << test.test_name << '\n';
    try {
      test.fn();
    } catch (const std::exception& ex) {
      RecordFailure(__FILE__, __LINE__, std::string("Unhandled exception: ") + ex.what());
    } catch (...) {
      RecordFailure(__FILE__, __LINE__, "Unhandled non-standard exception");
    }

    if (state.current_test_failed) {
      failed_tests++;
      std::cout << "[  FAILED  ] " << test.suite_name << '.' << test.test_name << '\n';
    } else {
      std::cout << "[       OK ] " << test.suite_name << '.' << test.test_name << '\n';
    }
  }

  std::cout << "[==========] " << state.tests.size() << " tests ran.\n";
  std::cout << "[  PASSED  ] " << (state.tests.size() - failed_tests) << " tests.\n";
  if (failed_tests > 0) {
    std::cout << "[  FAILED  ] " << failed_tests << " tests.\n";
  }
  return failed_tests == 0 ? 0 : 1;
}

}  // namespace testing
