// Copyright 2016
#include "gmock/gmock.h"
#include "../../src/stock/LocalStock.hpp"

using namespace testing;

TEST(AStockEmployee, LocalStockIsEmptyWhenCreated) {
  LocalStock localStock;

  ASSERT_THAT(localStock.isEmpty(), Eq(true));
}
