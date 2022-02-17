#include <Calculator.hpp>

int Calculator::cal(const std::string &input) { return stringToInt(input); }

int Calculator::stringToInt(const std::string &input) {
  return std::stoi(input);
}