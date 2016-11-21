// Copyright 2016
#ifndef STOCK_LOCALSTOCK_H
#define STOCK_LOCALSTOCK_H

#include <algorithm>
#include <vector>
#include <iterator>
#include "../food/Ingredient.hpp"

class LocalStock {
 private:
  std::vector<Ingredient> ingredients;
 public:
  bool isEmpty() {
    return ingredients.empty();
  }

  bool contains(const Ingredient& ingredient) {
    auto pos = std::find(std::begin(ingredients), std::end(ingredients), ingredient);
    return pos != std::end(ingredients);
  }

  void add(const Ingredient& ingredient) {
    ingredients.push_back(ingredient);
  }
};

#endif  // STOCK_LOCALSTOCK_H
