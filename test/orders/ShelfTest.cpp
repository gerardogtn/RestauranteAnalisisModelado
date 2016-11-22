// Copyright 2016

#include <utility>
#include "gmock/gmock.h"
#include "../../src/food/Drink.hpp"
#include "../../src/orders/Shelf.hpp"

using namespace testing;

class AShelf : public Test {
 public:
  Drink drink;
  Table table;
  std::pair<Drink, Table> pair = std::make_pair(drink, table);
  Shelf* aShelf = new Shelf();

  AShelf() : drink("sprite"), table(1) {}
  virtual ~AShelf() {
    delete aShelf;
  }
};

TEST_F(AShelf, AddDrink) {
  aShelf->addDrink(drink, table);

  ASSERT_THAT(aShelf->getDrinks(), Contains(pair));
}


TEST_F(AShelf, CanDeleteDrinkThatWasAdded) {
  aShelf->addDrink(drink, table);

  aShelf->removeDrink(drink, table);

  ASSERT_THAT(aShelf->getDrinks(), Not(Contains(pair)));
}

TEST_F(AShelf, DeleteDrinkDeletesFirstMatch) {
  aShelf->addDrink(drink, table);
  aShelf->addDrink(drink, table);

  aShelf->removeDrink(drink, table);

  ASSERT_THAT(aShelf->getDrinks(), Contains(pair));
  ASSERT_THAT(aShelf->getDrinks().size(), Eq(1));
}

TEST_F(AShelf, DeleteDrinkThatIsNotThereDoesNothing) {
  Drink other("coke");
  aShelf->addDrink(other, table);

  aShelf->removeDrink(drink, table);

  ASSERT_THAT(aShelf->getDrinks(), Contains(std::make_pair(other, table)));
  ASSERT_THAT(aShelf->getDrinks(), Not(Contains(pair)));
  ASSERT_THAT(aShelf->getDrinks().size(), Eq(1));
}
