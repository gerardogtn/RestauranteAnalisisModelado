// Copyright 2016
#ifndef UTIL_OBSERVER_H
#define UTIL_OBSERVER_H

template <class Param>
class Observer {
 public:
  virtual void notify(Param param) = 0;
};

#endif  // UTIL_OBSERVER_H
