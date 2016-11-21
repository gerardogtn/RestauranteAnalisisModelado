// Copyright 2016

#include "gmock/gmock.h"
#include "../../src/food/Drink.hpp"

using namespace testing;

class SpriteDrink : public Test {
 public:
  Drink sprite;

  SpriteDrink() : sprite("sprite") {}
};

TEST_F(SpriteDrink, TwoDrinksWithSameNameAreEqual) {
  Drink other("sprite");

  ASSERT_THAT(sprite, Eq(other));
}
