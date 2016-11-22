// Copyright 2016

#include "gmock/gmock.h"
#include "../../src/food/Drink.hpp"
#include "../../src/orders/Shelf.hpp"

using namespace testing;

class AShelf : public Test {
 public:
  Drink drink;
  Shelf* aShelf = new Shelf();

  AShelf() : drink("sprite") {}
  virtual ~AShelf() {
    delete aShelf;
  }
};

TEST_F(AShelf, AddDrink) {
  aShelf->addDrink(drink);

  ASSERT_THAT(aShelf->getDrinks(), Contains(drink));
}


TEST_F(AShelf, CanDeleteDrinkThatWasAdded) {
  aShelf->addDrink(drink);

  aShelf->removeDrink(drink);

  ASSERT_THAT(aShelf->getDrinks(), Not(Contains(drink)));
}

TEST_F(AShelf, DeleteDrinkDeletesFirstMatch) {
  aShelf->addDrink(drink);
  aShelf->addDrink(drink);

  aShelf->removeDrink(drink);

  ASSERT_THAT(aShelf->getDrinks(), Contains(drink));
  ASSERT_THAT(aShelf->getDrinks().size(), Eq(1));
}
