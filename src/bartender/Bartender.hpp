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

  void prepareNext() {
    auto drinks = inputShelf->getDrinks();
    if (!drinks.empty()) {
      auto drink = inputShelf->getDrinks()[0];
      inputShelf->removeDrink(drink.first, drink.second);
      outputShelf->addDrink(drink.first, drink.second);
    }
  }
};

#endif  // BARTENDER_BARTENDER_H
