// Copyright 2016
#ifndef UTIL_OBSERVABLE_H
#define UTIL_OBSERVABLE_H

#include <vector>
#include "Observer.hpp"

class Observable {
 private:
  std::vector<Observer*> observers;

 public:
  void addObserver(Observer* observer) {
    observers.push_back(observer);
  }

  void removeObserver(Observer* observer) {
    auto pos = std::find(std::begin(observers), std::end(observers), observer);
    if (pos != std::end(observers)) {
      observers.erase(pos);
    }
  }

  void notify() {
    for (Observer* : observers) {
      observer.notify();
    }
  }
};

#endif  // UTIL_OBSERVABLE_H
