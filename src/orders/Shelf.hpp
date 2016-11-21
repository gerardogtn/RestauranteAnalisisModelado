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
};

#endif  // ORDERS_SHELF_H
