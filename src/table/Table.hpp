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

  void deliver(Drink drink) {
    // stub
  }

  bool operator==(const Table& other) const {
    return this->num == other.num;
  }

  bool operator!=(const Table& other) const {
    return !(*this == other);
  }
};

#endif  // TABLE_TABLE_H
