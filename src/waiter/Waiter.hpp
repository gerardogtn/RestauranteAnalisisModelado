// Copyright 2016
#ifndef WAITER_WAITER_H
#define WAITER_WAITER_H

#include <string>
#include <utility>
#include "../orders/Shelf.hpp"
#include "../orders/Orders.hpp"
#include "../table/Table.hpp"

class Waiter {
 private:
  std::string name;
  Shelf* toDeliver;

  void deliver(std::pair<Drink, Table> pair) {
    pair.second.deliver(pair.first);
  }

 public:
  explicit Waiter(std::string name) : name(name) {
    toDeliver = new Shelf();
  }

  void setDeliveryShelf(Shelf* toDeliver) {
    this->toDeliver = toDeliver;
  }

  void order(Drink drink, Table table) {
    Orders::getInstance()->addDrink(drink, table);
  }

  void deliverAll() {
    for (auto it : toDeliver->getDrinks()) {
      deliver(it);
    }
  }
};

#endif  // WAITER_WAITER_H
