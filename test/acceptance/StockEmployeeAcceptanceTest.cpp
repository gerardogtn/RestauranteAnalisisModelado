// Copyright 2016
#include "gmock/gmock.h"
#include "../../src/stock/LocalStock.hpp"
#include "../../src/food/Ingredient.hpp"

using namespace testing;

class ALocalStock : public Test {
 public:
  LocalStock localStock;
};

TEST_F(ALocalStock, LocalStockIsEmptyWhenCreated) {
  ASSERT_THAT(localStock.isEmpty(), Eq(true));
}

TEST_F(ALocalStock, EmptyLocalStockDoesntContainIngreidient) {
  Ingredient ingredient("ham");

  ASSERT_THAT(localStock.contains(ingredient), Eq(false));
}

TEST_F(ALocalStock, IngredientIsInStockAfterAddingIngredient) {
  Ingredient ingredient("ham");

  localStock.add(ingredient);

  ASSERT_THAT(localStock.contains(ingredient), Eq(true));
}
