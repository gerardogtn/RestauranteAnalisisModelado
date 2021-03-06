// Copyright 2016
#ifndef STOCKORDER_INGREDIENTORDERS_H
#define STOCKORDER_INGREDIENTORDERS_H

#include <vector>
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

  void remove(std::string key) {
    auto it = orders.find(key);
    if (it != orders.end()) {
      orders.erase(it);
    }
  }

  StockOrder get(std::string key) {
    return orders[key];
  }

  std::vector<std::string> getPendingOrders() {
    std::vector<std::string> out;
    for (auto order : orders) {
      out.push_back(order.first);
    }
    return out;
  }
};

#endif  // STOCKORDER_INGREDIENTORDERS_H
