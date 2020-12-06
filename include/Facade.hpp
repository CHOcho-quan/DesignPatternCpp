#pragma once

#include <iostream>

class Object {
 public:
    void Process() {
        std::cout << "Process Object\n";
    }
};

class Something {
 public:
    void Process() {
        std::cout << "Process Something\n";
    }
};

class Facade {
 public:
    Facade(Object* obj, Something* sth) : obj_(obj), sth_(sth) {}

    void ProcessObject() {
        obj_->Process();
    }

    void ProcessSomething() {
        sth_->Process();
    }

 private:
    Object* obj_;
    Something* sth_;
};
