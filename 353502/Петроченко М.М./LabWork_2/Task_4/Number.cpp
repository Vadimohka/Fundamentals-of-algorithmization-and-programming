//
// Created by acryoz on 14.3.24.
//

#include "../headers/Number.h"


Number::Number(double val) {
    this->value = val;
}

double Number::evaluate() const {
    return this->value;
}
