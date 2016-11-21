// Copyright 2016

#include <iostream>
#include "Drink.hpp"

std::ostream& operator<<(std::ostream& os, const Drink& drink) {
  os << drink.name;
  return os;
}
