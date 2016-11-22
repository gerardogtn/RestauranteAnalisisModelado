// Copyright 2016
#include "gmock/gmock.h"
#include "../../src/stock/LocalStock.hpp"
#include "../../src/food/Ingredient.hpp"

using namespace testing;

class ALocalStockWithAnIngredient : public Test {
 public:
  LocalStock localStock;
  Ingredient ingredient;

  ALocalStockWithAnIngredient() : ingredient("ham") {}
};

TEST_F(ALocalStockWithAnIngredient, LocalStockIsEmptyWhenCreated) {
  ASSERT_THAT(localStock.isEmpty(), Eq(true));
}

TEST_F(ALocalStockWithAnIngredient, LocalStockIsNotEmptyAfterAddingIngredient) {
  localStock.add(ingredient);

  ASSERT_THAT(localStock.isEmpty(), Eq(false));
}

TEST_F(ALocalStockWithAnIngredient, EmptyLocalStockDoesntContainIngreidient) {
  ASSERT_THAT(localStock.contains(ingredient), Eq(false));
}

TEST_F(ALocalStockWithAnIngredient, IngredientIsInStockAfterAddingIngredient) {
  localStock.add(ingredient);

  ASSERT_THAT(localStock.contains(ingredient), Eq(true));
}
