// Copyright 2016
#ifndef WAITER_WAITER_H
#define WAITER_WAITER_H

#include <string>
#include "../orders/Shelf.hpp"
#include "../table/Table.hpp"

class Waiter {
 private:
  std::string name;
  Shelf* orders;
  Shelf* toDeliver;

 public:
  explicit Waiter(std::string name) : name(name) {}

  void setOrdersShelf(Shelf* orders) {
    this->orders = orders;
  }

  void setDeliveryShelf(Shelf* toDeliver) {
    this->toDeliver = toDeliver;
  }

  void order(Drink drink, Table table) {
    orders->addDrink(drink, table);
  }
};

#endif  // WAITER_WAITER_H
