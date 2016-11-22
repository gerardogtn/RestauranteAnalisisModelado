// Copyright 2016
#ifndef STOCKORDER_STOCKORDERMANAGER_H
#define STOCKORDER_STOCKORDERMANAGER_H

#include <string>
#include "IngredientOrders.hpp"
#include "StockOrder.hpp"

class StockOrderManager {
 private:
  IngredientOrders* ingredientOrders;

 public:
  explicit StockOrderManager(IngredientOrders* ingredientOrders) :
    ingredientOrders(ingredientOrders) {}

  std::string order(StockOrder order) {
    return ingredientOrders->add(order);
  }

  std::vector<std::string> getPendingOrders() {
    return ingredientOrders->getPendingOrders();
  }
};

#endif  // STOCKORDER_STOCKORDERMANAGER_H
