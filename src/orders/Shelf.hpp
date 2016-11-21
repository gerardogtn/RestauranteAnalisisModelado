// Copyright 2016
#ifndef ORDERS_SHELF_H
#define ORDERS_SHELF_H

#include <vector>
#include "../food/Drink.hpp"

class Shelf {
 protected:
  std::vector<Drink> drinks;

 public:
  std::vector<Drink> getDrinks() {
    return drinks;
  }

  void addDrink(Drink drink) {
    drinks.push_back(drink);
  }

  void removeDrink(Drink drink) {
    auto pos = std::find(std::begin(drinks), std::end(drinks), drink);
    if (pos != std::end(drinks)) {
      drinks.erase(pos);
    }
  }
};

#endif  // ORDERS_SHELF_H
