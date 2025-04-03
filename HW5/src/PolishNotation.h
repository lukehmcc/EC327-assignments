#ifndef POLISHNOTATION_H
#define POLISHNOTATION_H

#include <stack>
#include <string>
#include <vector>

template <typename InputType> class RPNCalculator {
public:
  // Evaluates the given reverse polish notation. You should be checking whether
  // the expression is a string or a vector of strings.
  int evaluate(const InputType &expression);

private:
  // Tokenizes a string into vector<string> if the input is a string.
  std::vector<std::string> tokenize(const std::string &expr);

  // Choose appropriate STL container(s) for storage
  // Example: std::stack<std::string>
  std::stack<std::string> stack;
};

#endif // POLISHNOTATION_H
