// Copyright 2016
#ifndef UTIL_OBSERVABLE_H
#define UTIL_OBSERVABLE_H

#include <vector>
#include "Observer.hpp"

template <class ObserverParam>
class Observable {
 private:
  std::vector<Observer<ObserverParam>*> observers;

 public:
  void addObserver(Observer<ObserverParam>* observer) {
    observers.push_back(observer);
  }

  void removeObserver(Observer<ObserverParam>* observer) {
    auto pos = std::find(std::begin(observers), std::end(observers), observer);
    if (pos != std::end(observers)) {
      observers.erase(pos);
    }
  }

  void notify(ObserverParam param) {
    for (Observer<ObserverParam>* observer : observers) {
      observer->notify(param);
    }
  }
};

#endif  // UTIL_OBSERVABLE_H
