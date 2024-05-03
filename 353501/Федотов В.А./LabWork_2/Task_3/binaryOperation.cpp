#include "binaryOperation.h"
#include "expression.h"
#include <cstddef>
#include <exception>
#include <stdexcept>

BinaryOperation::BinaryOperation(Expression *left, char operationType, Expression *right) {

  left_ = left;
  right_ = right;

  switch (operationType) {
  case '+':
    operationType_ = '+';
    break;
  case '-':
    operationType_ = '-';
    break;
  case '*':
    operationType_ = '*';
    break;
  case '/':
    operationType_ = '/';
    break;
  default:
    throw std::invalid_argument("Incorrect type");
  }
}

double BinaryOperation::getValue() {
  if (left_ == nullptr || right_ == nullptr) {
    throw std::runtime_error("huh");
  }

  double res = 0;

  switch (operationType_) {
  case '+':
    res = left_->getValue() + right_->getValue();
    break;
  case '-':
    res = left_->getValue() - right_->getValue();
    break;
  case '*':
    res = left_->getValue() * right_->getValue();
    break;
  case '/':
    res = left_->getValue() / right_->getValue();
    break;
  }

  return res;
}

BinaryOperation::~BinaryOperation() {
  if (left_) {
    delete left_;
    left_ = nullptr;
  }
  if (right_) {
    delete right_;
    right_ = nullptr;
  }
}