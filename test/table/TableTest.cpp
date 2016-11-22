// Copyright 2016

#include "gmock/gmock.h"
#include "../../src/food/Drink.hpp"
#include "../../src/orders/Shelf.hpp"
#include "../../src/table/Table.hpp"
#include "../../src/waiter/Waiter.hpp"

using namespace testing;

class ATable : public Test {
 public:
  Table table;
  Drink drink;
  Waiter waiter;
  Shelf* aShelf = new Shelf();

  ATable() : table(1), drink("sprite"), waiter("Alejandro") {}

  virtual ~ATable() {
    delete aShelf;
  }

  void SetUp() override {
    waiter.setOrdersShelf(aShelf);
    table.setWaiter(&waiter);
  }
};

TEST_F(ATable, CanOrderDrink) {
  table.order(drink);
  ASSERT_THAT(aShelf->getDrinks(), Contains(std::make_pair(drink, table)));
}

TEST(TwoTables, TwoTablesWithSameIdAreEqual) {
  Table table(1);
  Table other(1);

  ASSERT_THAT(table == other, Eq(true));
  ASSERT_THAT(table != other, Eq(false));
}

TEST(TwoTables, TwoTablesWithDifferentIdsAreNotEqual) {
  Table table(1);
  Table other(2);

  ASSERT_THAT(table == other, Eq(false));
  ASSERT_THAT(table != other, Eq(true));
}
