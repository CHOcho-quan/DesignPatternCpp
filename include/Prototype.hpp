#pragma once

#include <iostream>

class PrototypeBase {
 public:
    virtual void Proto() = 0;
    virtual PrototypeBase* Clone() = 0;
    virtual ~PrototypeBase() = default;
};

class PrototypeA : public PrototypeBase {
 public:
    void Proto() {
        std::cout << "Prototype A Processing\n";
    }

    PrototypeBase* Clone() {
        return new PrototypeA(*this);
    }
};

class PrototypeB : public PrototypeBase {
 public:
    void Proto() {
        std::cout << "Prototype B Processing\n";
    }

    PrototypeBase* Clone() {
        return new PrototypeB(*this);
    }
};
