#ifndef ISO26262_GTEST_SHIM_GTEST_H
#define ISO26262_GTEST_SHIM_GTEST_H

#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace testing {

struct TestCaseRecord {
  std::string suite_name;
  std::string test_name;
  std::function<void()> fn;
};

struct TestState {
  int total_assertions = 0;
  int failed_assertions = 0;
  bool current_test_failed = false;
  std::vector<TestCaseRecord> tests;
};

TestState& GetState();
void RegisterTest(const char* suite_name, const char* test_name, std::function<void()> fn);
void RecordFailure(const char* file, int line, const std::string& message);
int InitGoogleTest(int* argc, char** argv);
int RunAllTests();

namespace internal {
class TestRegistrar {
 public:
  TestRegistrar(const char* suite_name, const char* test_name, std::function<void()> fn);
};

inline std::string ToString(bool value) {
  return value ? "true" : "false";
}

inline std::string ToString(const char* value) {
  return value == nullptr ? "<null>" : std::string(value);
}

inline std::string ToString(const std::string& value) {
  return value;
}

template <typename T>
std::string ToString(const T& value) {
  std::ostringstream oss;
  oss << value;
  return oss.str();
}
}  // namespace internal

}  // namespace testing

#define TEST(test_suite_name, test_name)                                             \
  static void test_suite_name##_##test_name##_impl();                                \
  static ::testing::internal::TestRegistrar test_suite_name##_##test_name##_registrar(\
      #test_suite_name, #test_name, test_suite_name##_##test_name##_impl);           \
  static void test_suite_name##_##test_name##_impl()

#define EXPECT_TRUE(condition)                                                        \
  do {                                                                                \
    ::testing::GetState().total_assertions++;                                         \
    if (!(condition)) {                                                               \
      ::testing::RecordFailure(__FILE__, __LINE__,                                    \
                               std::string("EXPECT_TRUE failed: ") + #condition);    \
    }                                                                                 \
  } while (0)

#define EXPECT_FALSE(condition)                                                       \
  do {                                                                                \
    ::testing::GetState().total_assertions++;                                         \
    if ((condition)) {                                                                \
      ::testing::RecordFailure(__FILE__, __LINE__,                                    \
                               std::string("EXPECT_FALSE failed: ") + #condition);   \
    }                                                                                 \
  } while (0)

#define EXPECT_EQ(expected, actual) do {                                              \
    auto gtest_expected_value = (expected);                                           \
    auto gtest_actual_value = (actual);                                               \
    ::testing::GetState().total_assertions++;                                         \
    if (!(gtest_expected_value == gtest_actual_value)) {                              \
      ::testing::RecordFailure(                                                       \
          __FILE__, __LINE__,                                                         \
          std::string("EXPECT_EQ failed: expected=") +                               \
              ::testing::internal::ToString(gtest_expected_value) +                   \
              ", actual=" + ::testing::internal::ToString(gtest_actual_value));       \
    }                                                                                 \
  } while (0)

#endif
