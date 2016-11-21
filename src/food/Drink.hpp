// Copyright 2016 Gerardo Teruel
#ifndef FOOD_DRINK_H
#define FOOD_DRINK_H

#include <iostream>
#include <string>

class Drink {
 private:
  std::string name = "";

 public:
  explicit Drink(std::string name) : name(name) {}

  bool operator==(const Drink& other) const {
    return name == other.name;
  }

  bool operator!=(const Drink& other) const {
    return !(*this == other);
  }

  friend std::ostream& operator<<(std::ostream& os, const Drink& drink);
};

#endif  // FOOD_DRINK_H
