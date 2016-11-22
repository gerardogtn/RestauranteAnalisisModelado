// Copyright 2016
#ifndef STOCK_LOCALSTOCK_H
#define STOCK_LOCALSTOCK_H

#include "Stock.hpp"
#include "../util/Singleton.hpp"

class LocalStock : public Stock, public Singleton<LocalStock> {
};
#endif  // STOCK_LOCALSTOCK_H
