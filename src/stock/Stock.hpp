// Copyright 2016
#ifndef STOCK_STOCK_H
#define STOCK_STOCK_H

#include <vector>
#include <exception>
#include <map>
#include <iostream>
#include "../food/Ingredient.hpp"
#include "../util/Observable.hpp"

class Stock {
 private:
  std::map<Ingredient, int> ingredients;
  Observable<Ingredient> lowStockObservable;
  Observable<Ingredient> noStockObservable;
  int LOW_STOCK_THRESHOLD = 2;

  void onIngredientAmountChanged() {
    std::cout << "On Ingredient amount changed \n";
    for (auto i : ingredients) {
      int amount = i.second;
      if (amount == 0) {
        // TODO:
      } else if (amount < LOW_STOCK_THRESHOLD) {
        lowStockObservable.notify(i.first);
      }
    }
  }

 public:
  bool isEmpty() {
    return ingredients.empty();
  }

  void setLowStockThreshold(int threshold) {
    LOW_STOCK_THRESHOLD = threshold;
  }

  void addLowStockObserver(Observer<Ingredient>* observer) {
    lowStockObservable.addObserver(observer);
  }

  void removeLowStockObserver(Observer<Ingredient>* observer) {
    lowStockObservable.removeObserver(observer);
  }

  bool containsEnough(const Ingredient& ingredient, int amount) {
    auto pos = ingredients.find(ingredient);
    if (pos != ingredients.end()) {
      return pos->second >= amount;
    }
    return false;
  }

  void add(const Ingredient& ingredient, int amount) {
    ingredients[ingredient] += amount;
    onIngredientAmountChanged();
  }

  void use(const Ingredient& ingredient, int amount) {
    auto pos = ingredients.find(ingredient);
    if (pos != ingredients.end() && pos->second >= amount) {
      ingredients[ingredient] -= amount;
      onIngredientAmountChanged();
    } else {
      throw std::runtime_error("Not enough ingredient to prepare");
    }
  }

  std::vector<Ingredient> getLowOfStock() {
    std::vector<Ingredient> out;
    for (auto i : ingredients) {
      if (i.second < LOW_STOCK_THRESHOLD && i.second > 0) {
        out.push_back(i.first);
      }
    }
    return out;
  }

  std::vector<Ingredient> getOutOfStock() {
    std::vector<Ingredient> out;
    for (auto it : ingredients) {
      if (it.second == 0) {
        out.push_back(it.first);
      }
    }
    return out;
  }
};

#endif  // STOCK_STOCK_H
