// Copyright 2016
#ifndef STOCK_LOCALSTOCK_H
#define STOCK_LOCALSTOCK_H

#include <exception>
#include <map>
#include "../food/Ingredient.hpp"

class LocalStock {
 private:
  std::map<Ingredient, int> ingredients;
 public:
  bool isEmpty() {
    return ingredients.empty();
  }

  bool containsEnough(const Ingredient& ingredient, int amount) {
    auto pos = ingredients.find(ingredient);
    if (pos != ingredients.end()) {
      return pos->second >= amount;
    }
    return false;
  }

  void add(const Ingredient& ingredient, int amount) {
    ingredients[ingredient] = amount;
  }

  void use(const Ingredient& ingredient, int amount) {
    auto pos = ingredients.find(ingredient);
    if (pos != ingredients.end() && pos->second >= amount) {
      ingredients[ingredient] -= amount;
    } else {
      throw std::runtime_error("Not enough ingredient to prepare");
    }
  }
};

#endif  // STOCK_LOCALSTOCK_H
