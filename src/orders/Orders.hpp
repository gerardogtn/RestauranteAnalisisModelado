// Copyright 2016
#ifndef ORDERS_ORDERS_H
#define ORDERS_ORDERS_H

#include <vector>
#include "../food/Drink.hpp"

class Orders {
 private:
  static Orders* instance;
  std::vector<Drink> drinks;

  Orders() {}

 public:
  static Orders* getInstance() {
    if (!instance) {
      Orders::instance = new Orders();
    }
    return Orders::instance;
  }

  std::vector<Drink> getDrinks() const {
    return this->drinks;
  }

  void addDrink(Drink drink) {
    drinks.push_back(drink);
  }
};

Orders* Orders::instance = nullptr;

#endif  // ORDERS_ORDERS_H
