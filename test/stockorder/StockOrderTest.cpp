// Copyright 2016

#include "gmock/gmock.h"
#include "../../src/stockorder/IngredientOrders.hpp"
#include "../../src/stockorder/StockOrderManager.hpp"

using namespace testing;

TEST(AStockOrder, CreatedOrderIsInPending) {
  IngredientOrders* ingredientOrders = IngredientOrders::getInstance();
  StockOrderManager stockOrderManager(ingredientOrders);
  Ingredient ingredient("ham");
  int amount = 10;
  StockOrder order;
  order.add(ingredient, amount);

  stockOrderManager.order(order);

  ASSERT_THAT(ingredientOrders->contains(order), Eq(true));
}
