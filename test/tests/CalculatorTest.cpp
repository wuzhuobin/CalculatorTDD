#include "Calculator.hpp"

// gtest
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// std
#include <string>
using namespace ::testing;

TEST(CalculatorTest, cal_ShouldReturn1_WhenInputIs1) {

  // Arrange
  auto aNumber = "1";
  Calculator calculator;

  // Act
  auto result = calculator.cal(aNumber);

  // Assert
  EXPECT_EQ(result, 1);
}

TEST(CalculatorTest, cal_ShouldReturnTheSameNumber_WhenInputIsANumber) {

  // Arrange
  auto aNumber = "123";
  Calculator calculator;

  // Act
  auto result = calculator.cal(aNumber);

  // Assert
  EXPECT_EQ(result, 123);
}