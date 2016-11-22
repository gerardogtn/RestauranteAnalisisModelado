// Copyright 2016
#ifndef STOCK_REMOTESTOCK_H
#define STOCK_REMOTESTOCK_H

#include "Stock.hpp"
#include "../util/Singleton.hpp"

class RemoteStock : public Stock, public Singleton<RemoteStock> {
};
#endif  // STOCK_REMOTESTOCK_H
