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