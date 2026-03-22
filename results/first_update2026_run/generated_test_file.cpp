#include <gtest/gtest.h>
#include "includes/boolean_algebra.h"

// return_0 and return_1
TEST(BooleanAlgebra, Return0) { EXPECT_EQ(return_0(), 0); }
TEST(BooleanAlgebra, Return1) { EXPECT_EQ(return_1(), 1); }

// return_a and return_NOT_a
TEST(BooleanAlgebra, ReturnA_True) { EXPECT_TRUE(return_a(true)); }
TEST(BooleanAlgebra, ReturnA_False) { EXPECT_FALSE(return_a(false)); }
TEST(BooleanAlgebra, NotA_True) { EXPECT_FALSE(return_NOT_a(true)); }
TEST(BooleanAlgebra, NotA_False) { EXPECT_TRUE(return_NOT_a(false)); }

// check_a_OR_b
TEST(BooleanAlgebra, AorB_BothFalse) { EXPECT_FALSE(check_a_OR_b(false, false)); }
TEST(BooleanAlgebra, AorB_Atrue) { EXPECT_TRUE(check_a_OR_b(true, false)); }
TEST(BooleanAlgebra, AorB_Btrue) { EXPECT_TRUE(check_a_OR_b(false, true)); }
TEST(BooleanAlgebra, AorB_BothTrue) { EXPECT_TRUE(check_a_OR_b(true, true)); }

// check_a_XOR_b
TEST(BooleanAlgebra, AXorB_BothFalse) { EXPECT_FALSE(check_a_XOR_b(false, false)); }
TEST(BooleanAlgebra, AXorB_Btrue) { EXPECT_TRUE(check_a_XOR_b(false, true)); }
TEST(BooleanAlgebra, AXorB_Atrue) { EXPECT_TRUE(check_a_XOR_b(true, false)); }
TEST(BooleanAlgebra, AXorB_BothTrue) { EXPECT_FALSE(check_a_XOR_b(true, true)); }

// check_a_NOR_b
TEST(BooleanAlgebra, ANorB_BothFalse) { EXPECT_TRUE(check_a_NOR_b(false, false)); }
TEST(BooleanAlgebra, ANorB_Btrue) { EXPECT_FALSE(check_a_NOR_b(false, true)); }
TEST(BooleanAlgebra, ANorB_Atrue) { EXPECT_FALSE(check_a_NOR_b(true, false)); }
TEST(BooleanAlgebra, ANorB_BothTrue) { EXPECT_FALSE(check_a_NOR_b(true, true)); }

// check_a_AND_b
TEST(BooleanAlgebra, AAndB_BothFalse) { EXPECT_FALSE(check_a_AND_b(false, false)); }
TEST(BooleanAlgebra, AAndB_Btrue) { EXPECT_FALSE(check_a_AND_b(false, true)); }
TEST(BooleanAlgebra, AAndB_Atrue) { EXPECT_FALSE(check_a_AND_b(true, false)); }
TEST(BooleanAlgebra, AAndB_BothTrue) { EXPECT_TRUE(check_a_AND_b(true, true)); }

// check_a_NAND_b
TEST(BooleanAlgebra, ANandB_BothFalse) { EXPECT_TRUE(check_a_NAND_b(false, false)); }
TEST(BooleanAlgebra, ANandB_Btrue) { EXPECT_TRUE(check_a_NAND_b(false, true)); }
TEST(BooleanAlgebra, ANandB_Atrue) { EXPECT_TRUE(check_a_NAND_b(true, false)); }
TEST(BooleanAlgebra, ANandB_BothTrue) { EXPECT_FALSE(check_a_NAND_b(true, true)); }

// check_a_OR_b_OR_c
TEST(BooleanAlgebra, AorBorC_AllFalse) { EXPECT_FALSE(check_a_OR_b_OR_c(false, false, false)); }
TEST(BooleanAlgebra, AorBorC_Atrue) { EXPECT_TRUE(check_a_OR_b_OR_c(true, false, false)); }
TEST(BooleanAlgebra, AorBorC_Btrue) { EXPECT_TRUE(check_a_OR_b_OR_c(false, true, false)); }
TEST(BooleanAlgebra, AorBorC_Ctrue) { EXPECT_TRUE(check_a_OR_b_OR_c(false, false, true)); }
TEST(BooleanAlgebra, AorBorC_AllTrue) { EXPECT_TRUE(check_a_OR_b_OR_c(true, true, true)); }

// check_a_OR_b_AND_c
TEST(BooleanAlgebra, AorBAndC_AllFalse) { EXPECT_FALSE(check_a_OR_b_AND_c(false, false, false)); }
TEST(BooleanAlgebra, AorBAndC_Btrue) { EXPECT_FALSE(check_a_OR_b_AND_c(false, true, false)); }
TEST(BooleanAlgebra, AorBAndC_AllTrue) { EXPECT_TRUE(check_a_OR_b_AND_c(true, true, true)); }
TEST(BooleanAlgebra, AorBAndC_Btrue_Ctrue) { EXPECT_TRUE(check_a_OR_b_AND_c(false, true, true)); }
TEST(BooleanAlgebra, AorBAndC_Atrue_Ctrue) { EXPECT_TRUE(check_a_OR_b_AND_c(true, false, true)); }

// check_a_OR__b_AND_c
TEST(BooleanAlgebra, Aor_BAndC_AllFalse) { EXPECT_FALSE(check_a_OR__b_AND_c(false, false, false)); }
TEST(BooleanAlgebra, Aor_BAndC_Atrue) { EXPECT_TRUE(check_a_OR__b_AND_c(true, false, false)); }
TEST(BooleanAlgebra, Aor_BAndC_BAndCTrue) { EXPECT_TRUE(check_a_OR__b_AND_c(false, true, true)); }
TEST(BooleanAlgebra, Aor_BAndC_BTrue_CFalse) { EXPECT_FALSE(check_a_OR__b_AND_c(false, true, false)); }

// check_a_AND_b_AND_c
TEST(BooleanAlgebra, AAndBAndC_AllTrue) { EXPECT_TRUE(check_a_AND_b_AND_c(true, true, true)); }
TEST(BooleanAlgebra, AAndBAndC_CFalse) { EXPECT_FALSE(check_a_AND_b_AND_c(true, true, false)); }
TEST(BooleanAlgebra, AAndBAndC_BFalse) { EXPECT_FALSE(check_a_AND_b_AND_c(true, false, true)); }
TEST(BooleanAlgebra, AAndBAndC_AFalse) { EXPECT_FALSE(check_a_AND_b_AND_c(false, true, true)); }

// check_a_AND_b_OR_a_AND_c
TEST(BooleanAlgebra, AAndBOrAAndC_AAndB) { EXPECT_TRUE(check_a_AND_b_OR_a_AND_c(true, true, false)); }
TEST(BooleanAlgebra, AAndBOrAAndC_AAndC) { EXPECT_TRUE(check_a_AND_b_OR_a_AND_c(true, false, true)); }
TEST(BooleanAlgebra, AAndBOrAAndC_OnlyA) { EXPECT_FALSE(check_a_AND_b_OR_a_AND_c(true, false, false)); }
TEST(BooleanAlgebra, AAndBOrAAndC_AllTrue) { EXPECT_TRUE(check_a_AND_b_OR_a_AND_c(true, true, true)); }
TEST(BooleanAlgebra, AAndBOrAAndC_OnlyB) { EXPECT_FALSE(check_a_AND_b_OR_a_AND_c(false, true, false)); }

// check_a_AND_b_XOR_a_AND_c
TEST(BooleanAlgebra, AAndBXorAAndC_AAndB) { EXPECT_TRUE(check_a_AND_b_XOR_a_AND_c(true, true, false)); }
TEST(BooleanAlgebra, AAndBXorAAndC_AAndC) { EXPECT_TRUE(check_a_AND_b_XOR_a_AND_c(true, false, true)); }
TEST(BooleanAlgebra, AAndBXorAAndC_AFalse) { EXPECT_FALSE(check_a_AND_b_XOR_a_AND_c(false, true, true)); }
TEST(BooleanAlgebra, AAndBXorAAndC_AllTrue) { EXPECT_FALSE(check_a_AND_b_XOR_a_AND_c(true, true, true)); }

// check_a_AND_b_XOR_a_AND_NOT_c
TEST(BooleanAlgebra, AAndBXorAAndNotC_AAndB_CFalse) { EXPECT_TRUE(check_a_AND_b_XOR_a_AND_NOT_c(true, true, false)); }
TEST(BooleanAlgebra, AAndBXorAAndNotC_AllTrue) { EXPECT_FALSE(check_a_AND_b_XOR_a_AND_NOT_c(true, true, true)); }
TEST(BooleanAlgebra, AAndBXorAAndNotC_AAndNotC) { EXPECT_TRUE(check_a_AND_b_XOR_a_AND_NOT_c(true, false, false)); }
TEST(BooleanAlgebra, AAndBXorAAndNotC_AFalse) { EXPECT_FALSE(check_a_AND_b_XOR_a_AND_NOT_c(false, true, false)); }

// check_a_AND_b_XOR_a_AND_NOT_c_OR_d
TEST(BooleanAlgebra, AAndBXorAAndNotCOrD_AAndB) { EXPECT_TRUE(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(true, true, false, false)); }
TEST(BooleanAlgebra, AAndBXorAAndNotCOrD_AllTrue) { EXPECT_FALSE(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(true, true, true, true)); }
TEST(BooleanAlgebra, AAndBXorAAndNotCOrD_AAndNotCOrD) { EXPECT_TRUE(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(true, false, false, true)); }
TEST(BooleanAlgebra, AAndBXorAAndNotCOrD_AAndBOrC) { EXPECT_FALSE(check_a_AND_b_XOR_a_AND_NOT_c_OR_d(true, true, true, false)); }
