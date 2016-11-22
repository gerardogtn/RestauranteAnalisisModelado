// Copyright 2016

#ifndef ORDERS_TODELIVER_H
#define ORDERS_TODELIVER_H

#include <vector>
#include "../util/Singleton.hpp"
#include "Shelf.hpp"
#include "../util/Observable.hpp"

class ToDeliver : public Singleton<ToDeliver>, public Shelf {
public:
  Observable<std::pair<Drink, Table>> toDeliverObservable;

  void addToDeliverObserver(Observer<std::pair<Drink, Table>>* observer) {
    toDeliverObservable.addObserver(observer);
  }

  void removeToDeliverObserver(Observer<std::pair<Drink, Table>>* observer) {
    toDeliverObservable.removeObserver(observer);
  }

  virtual void addDrink(Drink drink, Table table) {
    Shelf::addDrink(drink, table);
    toDeliverObservable.notify(std::make_pair(drink, table));
    Shelf::removeDrink(drink, table);
  }
};


#endif  // ORDERS_TODELIVER_H
