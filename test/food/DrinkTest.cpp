// Copyright 2016

#include "gmock/gmock.h"
#include "../../src/food/Drink.hpp"

using namespace testing;

TEST(ADrink, TwoDrinksWithSameNameAreEqual) {
  Drink sprite("sprite");
  Drink other("sprite");

  ASSERT_THAT(sprite, Eq(other));
}
