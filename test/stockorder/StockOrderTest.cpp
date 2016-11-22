// Copyright 2016

#include <string>
#include "gmock/gmock.h"
#include "../../src/stock/Stock.hpp"
#include "../../src/stockorder/IngredientOrders.hpp"
#include "../../src/stockorder/StockOrderManager.hpp"

using namespace testing;

class AStockOrderManager : public Test {
 public:
  Ingredient ingredient;
  int amount;
  StockOrder order;
  Stock* stock = new Stock();
  IngredientOrders* ingredientOrders = IngredientOrders::getInstance();
  StockOrderManager stockOrderManager;

  AStockOrderManager() : ingredient("ham"), amount(10),
    stockOrderManager(ingredientOrders, stock) {
      order.add(ingredient, amount);
    }

  virtual ~AStockOrderManager() {
    delete stock;
  }
};

TEST_F(AStockOrderManager, CreatedOrderIsInPending) {
  std::string key = stockOrderManager.order(order);

  ASSERT_THAT(ingredientOrders->getPendingOrders(), Contains(key));
}

TEST_F(AStockOrderManager, ReceivedOrderIsNotPending) {
  std::string key = stockOrderManager.order(order);

  stockOrderManager.receive(key);
  ASSERT_THAT(ingredientOrders->getPendingOrders(), Not(Contains(key)));
}

TEST_F(AStockOrderManager, ReceivedOrderModifiesStock) {
  std::string key = stockOrderManager.order(order);

  stockOrderManager.receive(key);
  ASSERT_THAT(stock->containsEnough(ingredient, amount), Eq(true)); 
}
