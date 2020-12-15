#pragma once

#include <iostream>

class Subject {
 public:
    virtual void Request() = 0;
    virtual ~Subject() {}
};

class ConcreteSubject : public Subject {
 public:
    void Request() {
        std::cout << "Concrete Subject Request\n";
    }
};

class Proxy : public Subject {
 public:
    Proxy(Subject* sub) : sub_(sub) {}
    void Request() {
        std::cout << "Request From Proxy\n";
        sub_->Request();
    }

 private:
    Subject* sub_;
};
