// Copyright 2016

#include "gmock/gmock.h"
#include "../../src/food/Drink.hpp"
#include "../../src/orders/Shelf.hpp"
#include "../../src/table/Table.hpp"
#include "../../src/waiter/Waiter.hpp"

using namespace testing;

TEST(ATable, CanOrderDrink) {
  Table table(1);
  Drink drink("sprite");
  Shelf* aShelf = new Shelf();
  Waiter waiter("Alejandro");
  waiter.setOrdersShelf(aShelf);
  table.setWaiter(&waiter);

  table.order(drink);

  ASSERT_THAT(aShelf->getDrinks(), Contains(drink));
  delete aShelf;
}
