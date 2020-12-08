#pragma once

#include <iostream>

class Adaptee {
 public:
    void Process() {
        std::cout << "Process Adaptee\n";
    }
};

class Client {
 public:
    virtual void Process() = 0;

    virtual ~Client() {}
};

class Adapter : public Client {
 public:
    Adapter(Adaptee* a) : adaptee_(a) {}

    void Process() {
        adaptee_->Process();
    }

 private:
    Adaptee* adaptee_;
};
