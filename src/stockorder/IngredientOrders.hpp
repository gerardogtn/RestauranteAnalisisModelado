// Copyright 2016
#ifndef STOCKORDER_INGREDIENTORDERS_H
#define STOCKORDER_INGREDIENTORDERS_H

#include <map>
#include <string>
#include "../util/Singleton.hpp"
#include "StockOrder.hpp"
#include "StockOrderKeyGenerator.hpp"

class IngredientOrders : public Singleton<IngredientOrders> {
 private:
  std::map<std::string, StockOrder> orders;

 public:
  IngredientOrders() {}
  virtual ~IngredientOrders() {}

  std::string add(StockOrder order) {
    std::string key = StockOrderKeyGenerator::generate();
    orders[key] = order;
    return key;
  }

  bool contains(std::string orderKey) {
    auto pos = orders.find(orderKey);
    return pos != orders.end();
  }

  void remove(StockOrder order) {
    // auto it = std::find(std::begin(orders), std::end(orders), order);
    // if (it != std::end(orders)) {
    //   orders.erase(it);
    // }
  }
};

#endif  // STOCKORDER_INGREDIENTORDERS_H
