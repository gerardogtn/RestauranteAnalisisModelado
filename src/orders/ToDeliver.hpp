// Copyright 2016

#ifndef ORDERS_TODELIVER_H
#define ORDERS_TODELIVER_H

#include <vector>
#include "../util/Singleton.hpp"
#include "Shelf.hpp"

class ToDeliver : public Singleton<ToDeliver>, public Shelf {
};


#endif  // ORDERS_TODELIVER_H
