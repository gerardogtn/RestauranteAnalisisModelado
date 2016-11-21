// Copyright 2016
#ifndef UTIL_SINGLETON_H
#define UTIL_SINGLETON_H

template <class Actual>
class Singleton {
 private:
  static Actual* instance;

 public:
  static Actual* getInstance() {
    if (instance == nullptr) {
      instance = new Actual();
    }
    return instance;
  }
};

template <class Actual>
Actual* Singleton<Actual>::instance = nullptr;

#endif  // UTIL_SINGLETON_H
