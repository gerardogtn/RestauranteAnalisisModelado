// Copyright 2016

#ifndef ORDERS_TODELIVER_H
#define ORDERS_TODELIVER_H

#include <vector>
#include "Shelf.hpp"

class ToDeliver : public Shelf {
 private:
  static ToDeliver* instance;

  ToDeliver() {}

 public:
  static ToDeliver* getInstance() {
    if (!instance) {
      instance = new ToDeliver();
    }
    return instance;
  }

};

ToDeliver* ToDeliver::instance = nullptr;

#endif  // ORDERS_TODELIVER_H
