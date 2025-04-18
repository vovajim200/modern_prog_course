#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "long_number.hpp"

using oia::LongNumber;

// Тесты для конструкторов и базовых операций
TEST(LongNumberBasic, DefaultConstructorIsZero) {
    LongNumber num;
    ASSERT_EQ(num.get_digits_number(), 1);
    ASSERT_EQ(num.get_rank_number(0), 0);
    ASSERT_FALSE(num.is_negative());
}

TEST(LongNumberBasic, StringConstructorForNull) {
    LongNumber num("0");
    ASSERT_EQ(num.get_digits_number(), 1);
    ASSERT_EQ(num.get_rank_number(0), 0);
    ASSERT_FALSE(num.is_negative());
}

TEST(LongNumberBasic, StringConstructorForNulls) {
    LongNumber num("0000");
    ASSERT_EQ(num.get_digits_number(), 1);
    ASSERT_EQ(num.get_rank_number(0), 0);
    ASSERT_FALSE(num.is_negative());
}

TEST(LongNumberBasic, StringConstructorForNegativeNull) {
    LongNumber num("-0");
    ASSERT_EQ(num.get_digits_number(), 1);
    ASSERT_EQ(num.get_rank_number(0), 0);
    ASSERT_FALSE(num.is_negative());
}

TEST(LongNumberBasic, StringConstructorPositive) {
    LongNumber num("12345");
    ASSERT_EQ(num.get_digits_number(), 5);
    ASSERT_EQ(num.get_rank_number(0), 5);
    ASSERT_EQ(num.get_rank_number(4), 1);
    ASSERT_FALSE(num.is_negative());
}

TEST(LongNumberBasic, StringConstructorNegative) {
    LongNumber num("-67890");
    ASSERT_EQ(num.get_digits_number(), 5);
    ASSERT_EQ(num.get_rank_number(0), 0);
    ASSERT_TRUE(num.is_negative());
}

TEST(LongNumberComparasion, ZeroEqualZero) {
    LongNumber a("0");
    LongNumber b("0");
    ASSERT_TRUE(a == b);
}

TEST(LongNumberComparasion, PositiveEqualPositive) {
    LongNumber a("100");
    LongNumber b("100");
    ASSERT_TRUE(a == b);
}

TEST(LongNumberComparasion, NegativeEqualNegative) {
    LongNumber a("-100");
    LongNumber b("-100");
    ASSERT_TRUE(a == b);
}

TEST(LongNumberComparasion, PositiveNotEqualNegative) {
    LongNumber a("100");
    LongNumber b("-100");
    ASSERT_TRUE(a != b);
}

TEST(LongNumberComparasion, PositiveGreaterThanPositive) {
    LongNumber a("100");
    LongNumber b("99");
    ASSERT_TRUE(a > b);
}

TEST(LongNumberComparasion, PositiveGreaterThanZero) {
    LongNumber a("100");
    LongNumber b("0");
    ASSERT_TRUE(a > b);
}

TEST(LongNumberComparasion, PositiveGreaterThanNegative) {
    LongNumber a("100");
    LongNumber b("-100");
    ASSERT_TRUE(a > b);
}

TEST(LongNumberComparasion, ZeroGreaterThanNegative) {
    LongNumber a("0");
    LongNumber b("-12");
    ASSERT_TRUE(a > b);
}

TEST(LongNumberComparasion, NegativeGreaterThanNegative) {
    LongNumber a("-99");
    LongNumber b("-100");
    ASSERT_TRUE(a > b);
}

TEST(LongNumberConstructors, CopyConstructor) {
    LongNumber original("-12345");
    LongNumber copy(original);    
    ASSERT_TRUE(original == copy)
        << original << " " << copy;
}

TEST(LongNumberConstructors, CopyConstructorExtended) {
    LongNumber original("-12345");
    LongNumber copy(original);
    
    EXPECT_EQ(original.get_digits_number(), copy.get_digits_number());
    EXPECT_EQ(original.is_negative(), copy.is_negative());
    for (int i = 0; i < original.get_digits_number(); ++i) {
        EXPECT_EQ(original.get_rank_number(i), copy.get_rank_number(i));
    }
}

TEST(LongNumberArithmetic, SimpleAddition) {
    LongNumber a("123");
    LongNumber b("1234");
    ASSERT_TRUE(a + b == LongNumber("1357"));
}

TEST(LongNumberArithmetic, PositivePlusZero) {
    LongNumber a("123");
    LongNumber b("0");
    ASSERT_TRUE(a + b == a);
}

TEST(LongNumberArithmetic, NegativePlusZero) {
    LongNumber a("-123");
    LongNumber b("0");
    ASSERT_TRUE(a + b == a);
}

TEST(LongNumberArithmetic, AdditionOpposite) {
    LongNumber a("-52");
    LongNumber b("52");
    ASSERT_TRUE(a + b == LongNumber());
}

TEST(LongNumberArithmetic, AdditionNegatives) {
    LongNumber a("-753");
    LongNumber b("-314");
    ASSERT_TRUE(a + b == LongNumber("-1067"));
}

TEST(LongNumberArithmetic, CommutativeAdditionTest) {
    LongNumber a("531");
    LongNumber b("-43");
    ASSERT_TRUE(a + b == b + a);
}

// TEST(LongNumberArithMetic, SimpleSubstraction) {
//     LongNumber a = "1234";
//     LongNumber b = "123";
//     ASSERT_TRUE(a - b == LongNumber("1111"));
// }

// TEST(LongNumberArithMetic, AddSubAllCases) {
//     LongNumber n123("123");
//     LongNumber n1234("1234");
//     ASSERT_TRUE(n123 + n1234 == LongNumber("1357")) << "123 + 1234 = 1357";

//     LongNumber n1("1");
//     LongNumber nminus1("-1");
//     LongNumber n0("0");
//     LongNumber n999("999");
//     LongNumber n1000("1000");
//     LongNumber nminus1000("-1000");
//     ASSERT_TRUE(nminus1 + n1 == n0) << "-1 + 1 = 0";
//     ASSERT_TRUE(nminus1 + n0 == nminus1) << "-1 + 0 = -1";
//     ASSERT_TRUE(n1 + n0 == n1) << "1 + 0 == 1";
//     ASSERT_TRUE(n1000 - n999 == n1) << "1000 - 999 = 1";
//     ASSERT_TRUE(nminus1000 + n999 == nminus1) << "-1000 + 999 = -1";
//     ASSERT_TRUE(n999 - n1000 == nminus1) << "999 - 1000 = -1";
//     ASSERT_TRUE(n1 + n999 == n1000) << "1 + 999 = 1000";
// }