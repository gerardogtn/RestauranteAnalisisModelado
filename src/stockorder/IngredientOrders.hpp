// Copyright 2016
#ifndef STOCKORDER_INGREDIENTORDERS_H
#define STOCKORDER_INGREDIENTORDERS_H

#include <utility>
#include <vector>
#include "../util/Singleton.hpp"
#include "StockOrder.hpp"

class IngredientOrders : public Singleton<IngredientOrders> {
 private:
  std::vector<StockOrder> orders;

 public:
  IngredientOrders() {}
  virtual ~IngredientOrders() {}

  void add(StockOrder order) {
    orders.push_back(order);
  }

  bool contains(StockOrder order) {
    auto it = std::find(std::begin(orders), std::end(orders), order);
    return it != std::end(orders);
  }

  void remove(StockOrder order) {
    auto it = std::find(std::begin(orders), std::end(orders), order);
    if (it != std::end(orders)) {
      orders.erase(it);
    }
  }
};

#endif  // STOCKORDER_INGREDIENTORDERS_H
