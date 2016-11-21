// Copyright 2016
#ifndef STOCK_LOCALSTOCK_H
#define STOCK_LOCALSTOCK_H

#include "../food/Ingredient.hpp"

class LocalStock {
 public:
  bool isEmpty() {
    return true;
  }

  bool contains(Ingredient ingredient) {
    return false;
  }
};

#endif  // STOCK_LOCALSTOCK_H
