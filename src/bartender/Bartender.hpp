// Copyright 2016
#ifndef BARTENDER_BARTENDER_H
#define BARTENDER_BARTENDER_H

#include <vector>
#include "../food/Drink.hpp"
#include "../orders/Shelf.hpp"

class Bartender {
 private:
  Shelf* inputShelf;
  Shelf* outputShelf;

 public:
  Bartender(Shelf* in, Shelf* out) : inputShelf(in), outputShelf(out) {}

  void prepare(const Drink& drink, const Table& table) {
    inputShelf->removeDrink(drink, table);
    outputShelf->addDrink(drink, table);
  }
};

#endif  // BARTENDER_BARTENDER_H
