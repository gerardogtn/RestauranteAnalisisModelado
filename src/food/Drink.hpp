// Copyright 2016 Gerardo Teruel
#ifndef FOOD_DRINK_H
#define FOOD_DRINK_H

#include <string>

class Drink {
 private:
  std::string name = "";

 public:
  explicit Drink(std::string name) : name(name) {}

  bool operator==(const Drink& other) const {
    return this->name == other.name;
  }
};

#endif  // FOOD_DRINK_H
