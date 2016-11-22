// Copyright 2016

#include "Table.hpp"
#include "../waiter/Waiter.hpp"

void Table::setWaiter(Waiter* waiter) {
  this->waiter = waiter;
}

void Table::order(Drink drink) {
  this->waiter->order(drink, *this);
}
