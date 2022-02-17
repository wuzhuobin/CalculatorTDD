#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

// std
#include <string>
class Calculator {
public:
  int cal(const std::string &input);

private:
  static int stringToInt(const std::string &input);
};

#endif // CALCULATOR_HPP