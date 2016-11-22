// Copyright 2016
#ifndef STOCKORDER_STOCKORDER_H
#define STOCKORDER_STOCKORDER_H

#include "../food/Ingredient.hpp"

class StockOrder {
 private:
  Ingredient ingredient;
  int amount;
 public:
  StockOrder(Ingredient ingredient, int amount) : ingredient(ingredient),
    amount(amount) {}
  virtual ~StockOrder() {}

  bool operator==(const StockOrder& other) const {
    return this->ingredient == other.ingredient && this->amount == other.amount;
  }

  bool operator!=(const StockOrder& other) const {
    return !(*this == other);
  }
};

#endif  // STOCKORDER_STOCKORDER_H
