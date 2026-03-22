#include "gtest/gtest.h"

#include "includes/math_lib.h"
#include "includes/real_world.h"

TEST(MathLib, AddValid) { EXPECT_EQ(7, add(3, 4)); }
TEST(MathLib, AddRejectsOutOfRange) { EXPECT_EQ(-1, add(-1, 4)); }
TEST(MathLib, AddRejectsOverflowGuard) { EXPECT_EQ(-1, add(1000, 600)); }

TEST(MathLib, SubtractValid) { EXPECT_EQ(2, subtract(5, 3)); }
TEST(MathLib, SubtractRejectsOutOfRange) { EXPECT_EQ(-1, subtract(-1, 3)); }
TEST(MathLib, SubtractRejectsAToBSwap) { EXPECT_EQ(-1, subtract(3, 5)); }

TEST(MathLib, MultiplyValid) { EXPECT_EQ(12, multiply(3, 4)); }
TEST(MathLib, MultiplyRejectsOutOfRange) { EXPECT_EQ(-1, multiply(-1, 4)); }
TEST(MathLib, MultiplyRejectsOverflowGuard) { EXPECT_EQ(-1, multiply(1000, 2)); }

TEST(MathLib, DivideValid) { EXPECT_EQ(3, divide(9, 3)); }
TEST(MathLib, DivideRejectsZeroDivisor) { EXPECT_EQ(-1, divide(9, 0)); }
TEST(MathLib, DivideRejectsOutOfRange) { EXPECT_EQ(-1, divide(-1, 3)); }

TEST(MathLib, FactorialHandlesBaseCase) { EXPECT_EQ(1, factorial(0)); }
TEST(MathLib, FactorialValidLoop) { EXPECT_EQ(120, factorial(5)); }
TEST(MathLib, FactorialRejectsInvalid) { EXPECT_EQ(-1, factorial(-1)); }
TEST(MathLib, FactorialRejectsOverflowGuard) { EXPECT_EQ(-1, factorial(7)); }

TEST(MathLib, FibonacciHandlesBaseCases) {
  EXPECT_EQ(0, fibonacci(0));
  EXPECT_EQ(1, fibonacci(1));
}
TEST(MathLib, FibonacciValidLoop) { EXPECT_EQ(13, fibonacci(7)); }
TEST(MathLib, FibonacciRejectsInvalid) { EXPECT_EQ(-1, fibonacci(-1)); }
TEST(MathLib, FibonacciRejectsOverflowGuard) { EXPECT_EQ(-1, fibonacci(17)); }

TEST(MathLib, PrimeNumberRejectsInvalid) { EXPECT_EQ(-1, prime_number(-1)); }
TEST(MathLib, PrimeNumberHandlesNonPrimeBaseCase) { EXPECT_EQ(0, prime_number(1)); }
TEST(MathLib, PrimeNumberHandlesTwo) { EXPECT_EQ(1, prime_number(2)); }
TEST(MathLib, PrimeNumberRejectsEvenComposite) { EXPECT_EQ(0, prime_number(8)); }
TEST(MathLib, PrimeNumberRejectsOddComposite) { EXPECT_EQ(0, prime_number(9)); }
TEST(MathLib, PrimeNumberAcceptsPrime) { EXPECT_EQ(1, prime_number(13)); }

TEST(MathLib, AddRefValidAndInvalid) {
  EXPECT_EQ(7, add_ref(3, 4));
  EXPECT_EQ(-1, add_ref(-1, 4));
  EXPECT_EQ(-1, add_ref(1000, 600));
}

TEST(MathLib, SubtractRefValidAndInvalid) {
  EXPECT_EQ(2, subtract_ref(5, 3));
  EXPECT_EQ(-1, subtract_ref(-1, 3));
  EXPECT_EQ(-1, subtract_ref(3, 5));
}

TEST(MathLib, MultiplyRefValidAndInvalid) {
  EXPECT_EQ(12, multiply_ref(3, 4));
  EXPECT_EQ(-1, multiply_ref(-1, 4));
  EXPECT_EQ(-1, multiply_ref(1000, 2));
}

TEST(MathLib, DivideRefValidAndInvalid) {
  EXPECT_EQ(3, divide_ref(9, 3));
  EXPECT_EQ(-1, divide_ref(-1, 3));
  EXPECT_EQ(-1, divide_ref(9, 0));
}

TEST(MathLib, PrimeNumberRefCases) {
  EXPECT_EQ(-1, prime_number_ref(-1));
  EXPECT_EQ(0, prime_number_ref(1));
  EXPECT_EQ(1, prime_number_ref(2));
  EXPECT_EQ(0, prime_number_ref(8));
  EXPECT_EQ(0, prime_number_ref(9));
  EXPECT_EQ(1, prime_number_ref(13));
}

TEST(MathLib, FibonacciRefCases) {
  EXPECT_EQ(-1, fibonacci_ref(-1));
  EXPECT_EQ(0, fibonacci_ref(0));
  EXPECT_EQ(1, fibonacci_ref(1));
  EXPECT_EQ(13, fibonacci_ref(7));
  EXPECT_EQ(-1, fibonacci_ref(17));
}

TEST(MathLib, MyFuncReturnsFloatThree) { EXPECT_EQ(3.0f, myFunc()); }

TEST(MathLib, TempCalcPresWacolTemp48VNominal) {
  const dcdc_ntc_temp_def ntc_temp{0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
  EXPECT_EQ(static_cast<int16_t>(-25), Temp_Calc_Pres_Wacol_Temp_48V(&ntc_temp));
}

TEST(RealWorld, CheckAbortFalsePath) {
  EXPECT_FALSE(check_abort(false, false, false));
  EXPECT_FALSE(check_abort(false, true, false));
}

TEST(RealWorld, CheckAbortTruePaths) {
  EXPECT_TRUE(check_abort(true, false, false));
  EXPECT_TRUE(check_abort(false, true, true));
}

TEST(RealWorld, AutomMcuStateMachineCurrentStateRequest) {
  g_current_state = OFF;
  EXPECT_EQ(OFF, autom_MCU_state_machine(CURRENT_STATE));
}

TEST(RealWorld, AutomMcuStateMachineOffToRun) {
  g_current_state = OFF;
  EXPECT_EQ(RUN, autom_MCU_state_machine(RUN));
}

TEST(RealWorld, AutomMcuStateMachineOffRejectsInvalidRequest) {
  g_current_state = OFF;
  EXPECT_EQ(-1, autom_MCU_state_machine(SLEEP));
}

TEST(RealWorld, AutomMcuStateMachineRunTransitions) {
  g_current_state = RUN;
  EXPECT_EQ(SLEEP, autom_MCU_state_machine(SLEEP));
  g_current_state = RUN;
  EXPECT_EQ(OFF, autom_MCU_state_machine(OFF));
}

TEST(RealWorld, AutomMcuStateMachineSleepTransitions) {
  g_current_state = SLEEP;
  EXPECT_EQ(RUN, autom_MCU_state_machine(RUN));
  g_current_state = SLEEP;
  EXPECT_EQ(-1, autom_MCU_state_machine(OFF));
}

TEST(RealWorld, AutomMcuStateMachineRejectsUnknownCurrentState) {
  g_current_state = 123;
  EXPECT_EQ(-1, autom_MCU_state_machine(RUN));
  g_current_state = OFF;
}
