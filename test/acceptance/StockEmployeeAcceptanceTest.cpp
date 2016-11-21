// Copyright 2016
#include "gmock/gmock.h"
#include "../../src/stock/LocalStock.hpp"
#include "../../src/food/Ingredient.hpp"

using namespace testing;

TEST(ALocalStock, LocalStockIsEmptyWhenCreated) {
  LocalStock localStock;

  ASSERT_THAT(localStock.isEmpty(), Eq(true));
}

TEST(ALocalStock, EmptyLocalStockDoesntContainIngreidient) {
  LocalStock localStock;
  Ingredient ingredient("ham");

  ASSERT_THAT(localStock.contains(ingredient), Eq(false));
}
