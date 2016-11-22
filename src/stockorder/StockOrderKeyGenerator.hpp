// Copyright 2016
#ifndef STOCKORDER_STOCKORDERKEYGENERATOR_H
#define STOCKORDER_STOCKORDERKEYGENERATOR_H

#include <string>

class StockOrderKeyGenerator {
 private:
  static int num;

 public:
  static std::string generate();
};

#endif  // STOCKORDER_STOCKORDERKEYGENERATOR_H
