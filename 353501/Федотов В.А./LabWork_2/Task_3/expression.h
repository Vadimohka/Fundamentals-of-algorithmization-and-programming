#pragma once

class Expression {
public:
  virtual double getValue() = 0;
  virtual ~Expression() = default;
};