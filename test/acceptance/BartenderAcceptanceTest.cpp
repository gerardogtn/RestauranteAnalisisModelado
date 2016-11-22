// Copyright 2016

#include <list>
#include "gmock/gmock.h"
#include "../../src/bartender/Bartender.hpp"
#include "../../src/food/Drink.hpp"
#include "../../src/orders/ToDeliver.hpp"
#include "../../src/orders/Orders.hpp"

using namespace testing;

TEST(ABartender, PreparedDrinkIsNotInOrders) {
  Orders* orders = Orders::getInstance();
  ToDeliver* toDeliver = ToDeliver::getInstance();
  Bartender bartender(orders, toDeliver);
  Table table(1);

  Drink drink("sprite");
  orders->addDrink(drink, table);

  bartender.prepareNext();

  ASSERT_THAT(orders->getDrinks(), Not(Contains(std::make_pair(drink, table))));
}
