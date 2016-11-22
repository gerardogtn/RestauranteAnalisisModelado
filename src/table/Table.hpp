// Copyright 2016
#ifndef TABLE_TABLE_H
#define TABLE_TABLE_H

#include "../food/Drink.hpp"

class Waiter;

class Table {
 private:
  int num;
  Waiter* waiter = nullptr;

 public:
  explicit Table(int num) : num(num) {}

  void setWaiter(Waiter* waiter);

  void order(Drink drink);
};

#endif  // TABLE_TABLE_H
