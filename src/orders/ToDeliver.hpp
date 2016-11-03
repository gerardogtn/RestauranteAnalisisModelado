// Copyright 2016

#ifndef ORDERS_TODELIVER_H
#define ORDERS_TODELIVER_H

#include <vector>

class ToDeliver {
 private:
  static ToDeliver* instance;
  std::vector<Drink*> drinks;

  ToDeliver() {}

 public:
  static ToDeliver* getInstance() {
    if (!instance) {
      instance = new ToDeliver();
    }
    return instance;
  }

  std::vector<Drink*> getDrinks() {
    return drinks;
  }
};

ToDeliver* ToDeliver::instance = nullptr;

#endif  // ORDERS_TODELIVER_H
