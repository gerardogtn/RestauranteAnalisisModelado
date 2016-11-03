// Copyright 2016 Gerardo Teruel
#ifndef FOOD_DRINK_H
#define FOOD_DRINK_H

#include <string>

class Drink {
 private:
  std::string name = "";

 public:
  explicit Drink(std::string name) : name(name) {}
};

#endif  // FOOD_DRINK_H
