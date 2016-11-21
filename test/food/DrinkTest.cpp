// Copyright 2016

#include <sstream>
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

TEST_F(SpriteDrink, TwoDrinksWithDifferentNameAreNotEqual) {
  Drink other("coke");

  ASSERT_THAT(sprite, Ne(other));
}

TEST_F(SpriteDrink, OstreamOfDrinkIsDrinksName) {
  std::stringstream stream;

  stream << sprite;

  ASSERT_THAT(stream.str(), Eq("sprite"));
}
