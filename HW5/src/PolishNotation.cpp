#include "PolishNotation.h"
#include <cctype>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

bool is_number(const std::string &s) {
  try {
    size_t pos;
    std::stoi(s, &pos);     // Try converting to int
    return pos == s.size(); // Ensure entire string was consumed
  } catch (...) {
    return false;
  }
}

template <typename InputType>
int RPNCalculator<InputType>::evaluate(const InputType &expression) {
  // First gotta ensure everything is tokensized
  std::vector<std::string> tokens;
  if constexpr (std::is_same_v<InputType, std::string>) {
    tokens = tokenize(expression);
  } else if constexpr (std::is_same_v<InputType, std::vector<std::string>>) {
    tokens = expression;
  } else {
    throw std::runtime_error("Invalid Type");
  }
  // Check if tokens are empty or single
  if (tokens.size() == 0) {
    return 0;
  } else if (tokens.size() == 1) {
    return std::stoi(tokens[0]);
  }
  // How it works: it pushes onto the stack recursively until it hits an
  // operator when it hits an operator it pops the previous two, does that
  // operation, then pushes that value back onto the stack. Repeat until
  // complete
  for (std::string token : tokens) {
    if (is_number(token)) {
      stack.push(token);
    } else {
      int v2 = std::stoi(stack.top());
      stack.pop();
      if (stack.empty()) {
        throw std::runtime_error("Stack insufficiently filled");
      }
      int v1 = std::stoi(stack.top());
      stack.pop();
      if (token == "+") {
        stack.push(std::to_string((v1 + v2)));
      } else if (token == "-") {
        stack.push(std::to_string((v1 - v2)));
      } else if (token == "*") {
        stack.push(std::to_string((v1 * v2)));
      } else if (token == "/") {
        stack.push(std::to_string((v1 / v2)));
      } else {
        throw std::runtime_error("Invalid character: " + token);
      }
    }
  }
  return std::stoi(stack.top());
}
template <typename InputType>
std::vector<std::string>
RPNCalculator<InputType>::tokenize(const std::string &expr) {
  std::vector<std::string> tokens = {};
  std::string running = "";
  for (int i = 0; i < expr.length(); i++) {
    std::string token(1, expr.at(i));
    if (token != " ") {
      running += token;
    } else if (running != "") {
      tokens.push_back(running);
      running = "";
    }
  }
  if (running != "") {
    tokens.push_back(running);
  }
  return tokens;
}
// Explicit template instantiations
template class RPNCalculator<std::string>;
template class RPNCalculator<std::vector<std::string>>;
