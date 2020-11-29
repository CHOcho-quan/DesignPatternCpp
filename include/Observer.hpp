#pragma once

#include <iostream>

class Observer {
 public:
    virtual void Update() {}
};

class ObserverA : public Observer {
 public:
    void Update() { std::cout << "Updating Observer A\n"; }
};

class ObserverB : public Observer {
 public:
    void Update() { std::cout << "Updating Observer B\n"; }
};
