//
// Created by federico on 09/04/2020.
//

#include "TimeFunction.h"

#include <utility>

TimeFunction::TimeFunction(TimeFunction::data_type value) : value(std::move(value)) {}

double TimeFunction::get(double time) const {
    return value(time);
}

TimeFunction::TimeFunction(double value) {
    this->value = [=](double t) { return value; };
}
