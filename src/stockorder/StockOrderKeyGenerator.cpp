// Copyright 2016

#include <string>
#include "StockOrderKeyGenerator.hpp"

int StockOrderKeyGenerator::num = 0;

std::string StockOrderKeyGenerator::generate() {
  return "SOKG-" + std::to_string(num++);
}
