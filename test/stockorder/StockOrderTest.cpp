// Copyright 2016

#include <string>
#include "gmock/gmock.h"
#include "../../src/stockorder/IngredientOrders.hpp"
#include "../../src/stockorder/StockOrderManager.hpp"

using namespace testing;

class AStockOrderManager : public Test {
 public:
  Ingredient ingredient;
  int amount;
  StockOrder order;
  IngredientOrders* ingredientOrders = IngredientOrders::getInstance();
  StockOrderManager stockOrderManager;

  AStockOrderManager() : ingredient("ham"), amount(10),
    stockOrderManager(ingredientOrders) {
      order.add(ingredient, amount);
    }
};

TEST_F(AStockOrderManager, CreatedOrderIsInPending) {
  std::string key = stockOrderManager.order(order);

  ASSERT_THAT(ingredientOrders->getPendingOrders(), Contains(key));
}
