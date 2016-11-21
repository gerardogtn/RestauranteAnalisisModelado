// Copyright 2016
#ifndef ORDERS_ORDERS_H
#define ORDERS_ORDERS_H

#include <vector>
#include "Shelf.hpp"
#include "../util/Singleton.hpp"

class Orders : public Singleton<Orders>, public Shelf {
 public:
  Orders() {}
};

#endif  // ORDERS_ORDERS_H
