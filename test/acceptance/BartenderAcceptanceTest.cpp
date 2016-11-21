// Copyright 2016

#include <list>
#include "gmock/gmock.h"
#include "../../src/bartender/Bartender.hpp"
#include "../../src/food/Drink.hpp"
#include "../../src/orders/ToDeliver.hpp"
#include "../../src/orders/Orders.hpp"

using namespace testing;

TEST(ABartender, PreparedDrinkIsNotInDrinkOrdersAndIsOnReadyToDeliver) {
  Bartender bartender;
  Orders* orders = Orders::getInstance();
  Drink drink("sprite");
  orders->addDrink(drink);

  bartender.prepare(drink);

  ASSERT_THAT(orders->getDrinks(), Not(Contains(drink)));
  ASSERT_THAT(ToDeliver::getInstance()->getDrinks(), Contains(drink));
}
