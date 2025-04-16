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