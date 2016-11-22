// Copyright 2016
#ifndef STOCKORDER_STOCKORDER_H
#define STOCKORDER_STOCKORDER_H

#include <map>
#include "../food/Ingredient.hpp"

class StockOrder {
 private:
  std::map<Ingredient, int> ingredients;
 public:
  StockOrder() {}
  virtual ~StockOrder() {}

  void add(Ingredient ingredient, int amount) {
    ingredients[ingredient] += amount;
  }

  bool operator==(const StockOrder& other) const {
    return this->ingredients == other.ingredients;
  }

  bool operator!=(const StockOrder& other) const {
    return !(*this == other);
  }
};

#endif  // STOCKORDER_STOCKORDER_H
