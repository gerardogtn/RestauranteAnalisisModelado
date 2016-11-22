// Copyright 2016
#include <vector>
#include "gmock/gmock.h"
#include "../../src/stock/Stock.hpp"
#include "../../src/food/Ingredient.hpp"

using namespace testing;

class ALocalStockWithAnIngredient : public Test {
 public:
  Stock localStock;
  Ingredient ingredient;
  int notEnough = 2;
  int amount = 3;

  ALocalStockWithAnIngredient() : ingredient("ham") {}
};

TEST_F(ALocalStockWithAnIngredient, LocalStockIsEmptyWhenCreated) {
  ASSERT_THAT(localStock.isEmpty(), Eq(true));
}

TEST_F(ALocalStockWithAnIngredient, LocalStockIsNotEmptyAfterAddingIngredient) {
  localStock.add(ingredient, amount);

  ASSERT_THAT(localStock.isEmpty(), Eq(false));
}

TEST_F(ALocalStockWithAnIngredient, NotEnoughWhenNoIngredient) {
  ASSERT_THAT(localStock.containsEnough(ingredient, amount), Eq(false));
}

TEST_F(ALocalStockWithAnIngredient, EnoughWhenExactlySameAmount) {
  localStock.add(ingredient, amount);

  ASSERT_THAT(localStock.containsEnough(ingredient, amount), Eq(true));
}

TEST_F(ALocalStockWithAnIngredient, NotEnoughWhenLessAmount) {
  localStock.add(ingredient, notEnough);

  ASSERT_THAT(localStock.containsEnough(ingredient, amount), Eq(false));
}

TEST_F(ALocalStockWithAnIngredient, CannotUseMoreIngredientThanInExistence) {
  localStock.add(ingredient, notEnough);

  ASSERT_ANY_THROW(localStock.use(ingredient, amount));
}

TEST_F(ALocalStockWithAnIngredient, CanUseIngredientIfEnoughInExistence) {
  localStock.add(ingredient, amount);

  ASSERT_NO_THROW(localStock.use(ingredient, notEnough));
  ASSERT_ANY_THROW(localStock.use(ingredient, amount));
}

TEST_F(ALocalStockWithAnIngredient, IngredientsWithZeroAmountAreOutOfStock) {
  localStock.add(ingredient, 0);

  std::vector<Ingredient> ingredients = localStock.getOutOfStock();

  ASSERT_THAT(ingredients, Contains(ingredient));
  ASSERT_THAT(ingredients.size(), 1);
}

TEST_F(ALocalStockWithAnIngredient, IngredientsBelowThresholdAreLowOfStock) {
  localStock.setLowStockThreshold(amount);
  localStock.add(ingredient, notEnough);

  std::vector<Ingredient> ingredients = localStock.getLowOfStock();

  ASSERT_THAT(ingredients, Contains(ingredient));
  ASSERT_THAT(ingredients.size(), 1);
}
