// Copyright 2016
#ifndef FOOD_INGREDIENT_H
#define FOOD_INGREDIENT_H

#include <string>

class Ingredient {
 private:
  std::string name;
 public:
  explicit Ingredient(std::string name) : name(name) {}
};

#endif  // FOOD_INGREDIENT_H
