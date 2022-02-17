#include "Calculator.hpp"

// gtest
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// std
#include <memory>
#include <string>
using namespace ::testing;

class CalculatorTest : public Test {
public:
  Calculator calculator;

  // Alternative
  /*******************************************************************************
    std::unique_ptr<Calculator> calculator;

  protected:

    void SetUp() override { calculator = std::make_unique<Calculator>(); }
  *******************************************************************************/
};

TEST_F(CalculatorTest, cal_ShouldReturn1_WhenInputIs1) {

  // Arrange
  auto aNumber = "1";

  // Act
  auto result = calculator.cal(aNumber);

  // Assert
  EXPECT_EQ(result, 1);
}

TEST_F(CalculatorTest, cal_ShouldReturnTheSameNumber_WhenInputIsANumber) {

  // Arrange
  auto aNumber = "123";

  // Act
  auto result = calculator.cal(aNumber);

  // Assert
  EXPECT_EQ(result, 123);
}