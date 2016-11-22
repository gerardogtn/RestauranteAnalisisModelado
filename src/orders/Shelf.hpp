// Copyright 2016
#ifndef ORDERS_SHELF_H
#define ORDERS_SHELF_H

#include <vector>
#include <utility>
#include "../food/Drink.hpp"
#include "../table/Table.hpp"

class Shelf {
 protected:
  std::vector<std::pair<Drink, Table>> drinks;

 public:
  std::vector<std::pair<Drink, Table>> getDrinks() {
    return drinks;
  }

  virtual void addDrink(Drink drink, Table table) {
    drinks.push_back(std::make_pair(drink, table));
  }

  void removeDrink(Drink drink, Table table) {
    auto pair = std::make_pair(drink, table);
    auto pos = std::find(std::begin(drinks), std::end(drinks), pair);
    if (pos != std::end(drinks)) {
      drinks.erase(pos);
    }
  }
};

#endif  // ORDERS_SHELF_H
