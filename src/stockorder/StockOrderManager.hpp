// Copyright 2016
#ifndef STOCKORDER_STOCKORDERMANAGER_H
#define STOCKORDER_STOCKORDERMANAGER_H

#include <vector>
#include <string>
#include "IngredientOrders.hpp"
#include "StockOrder.hpp"
#include "../stock/Stock.hpp"

class StockOrderManager {
 private:
  IngredientOrders* ingredientOrders;
  Stock* stock;

 public:
  explicit StockOrderManager(IngredientOrders* ingredientOrders, Stock* stock) :
    ingredientOrders(ingredientOrders), stock(stock) {}

  std::string order(StockOrder order) {
    return ingredientOrders->add(order);
  }

  std::vector<std::string> getPendingOrders() {
    return ingredientOrders->getPendingOrders();
  }

  void receive(std::string key) {
    for (auto it : ingredientOrders->get(key).map()) {
      stock->add(it.first, it.second);
    }
    ingredientOrders->remove(key);
  }
};

#endif  // STOCKORDER_STOCKORDERMANAGER_H
