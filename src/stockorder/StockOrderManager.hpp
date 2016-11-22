// Copyright 2016
#ifndef STOCKORDER_STOCKORDERMANAGER_H
#define STOCKORDER_STOCKORDERMANAGER_H

#include "IngredientOrders.hpp"
#include "StockOrder.hpp"

class StockOrderManager {
 private:
  IngredientOrders* ingredientOrders;

 public:
  explicit StockOrderManager(IngredientOrders* ingredientOrders) :
    ingredientOrders(ingredientOrders) {}

  void order(StockOrder order) {
    ingredientOrders->add(order);
  }
};

#endif  // STOCKORDER_STOCKORDERMANAGER_H
