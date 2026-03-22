#ifndef BOOLEAN_ALGEBRA_H
#define BOOLEAN_ALGEBRA_H

int return_0(void);
int return_1(void);
bool return_a(bool a);
bool return_NOT_a(bool a);
bool check_a_OR_b(bool a, bool b);
bool check_a_XOR_b(bool a, bool b);
bool check_a_NOR_b(bool a, bool b);
bool check_a_AND_b(bool a, bool b);
bool check_a_NAND_b(bool a, bool b);
bool check_a_OR_b_OR_c(bool a, bool b, bool c);
bool check_a_OR_b_AND_c(bool a, bool b, bool c);
bool check_a_OR__b_AND_c(bool a, bool b, bool c);
bool check_a_AND_b_AND_c(bool a, bool b, bool c);
bool check_a_AND_b_OR_a_AND_c(bool a, bool b, bool c);
bool check_a_AND_b_XOR_a_AND_c(bool a, bool b, bool c);
bool check_a_AND_b_XOR_a_AND_NOT_c(bool a, bool b, bool c);
bool check_a_AND_b_XOR_a_AND_NOT_c_OR_d(bool a, bool b, bool c, bool d);

#endif
