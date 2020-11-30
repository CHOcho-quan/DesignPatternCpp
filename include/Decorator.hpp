#pragma once

#include <iostream>

class ObjectBase {
 public:
    virtual void Process() {}
    virtual ~ObjectBase() {}
};

class ConcreteObjA : public ObjectBase {
 public:
    void Process() {
        std::cout << "Processing Object A\n";
    }
};

class ConcreteObjB : public ObjectBase {
 public:
    void Process() {
        std::cout << "Processing Object B\n";
    }
};

class ObjectDecorator : public ObjectBase {
 public:
    explicit ObjectDecorator(ObjectBase* base) : obj_(base) {}
    virtual ~ObjectDecorator() { delete obj_; }
 protected:
    ObjectBase *obj_;
};

class ConcreteObjectDecoratorA : public ObjectDecorator {
 public:
    explicit ConcreteObjectDecoratorA(ObjectBase* base)
        : ObjectDecorator(base) {}
    void Process() {
        std::cout << "Decorated by A\n";
        obj_->Process();
    }
};

class ConcreteObjectDecoratorB : public ObjectDecorator {
 public:
    explicit ConcreteObjectDecoratorB(ObjectBase* base)
        : ObjectDecorator(base) {}
    void Process() {
        std::cout << "Decorated by B\n";
        obj_->Process();
    }
};
