// Copyright 2016
#ifndef ORDERS_ORDERS_H
#define ORDERS_ORDERS_H

#include <vector>
#include "Shelf.hpp"

class Orders : public Shelf {
 private:
  static Orders* instance;
  Orders() {}

 public:
  static Orders* getInstance() {
    if (!instance) {
      Orders::instance = new Orders();
    }
    return Orders::instance;
  }
};

Orders* Orders::instance = nullptr;

#endif  // ORDERS_ORDERS_H
