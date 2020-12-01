#pragma once

#include <iostream>

class AbstractObject {
 public:
    AbstractObject() {}
    virtual void Process() {}
    virtual ~AbstractObject() {}
};

class AbstractFactory {
 public:
    virtual AbstractObject* NewInstance() { return nullptr; }
    virtual ~AbstractFactory() {}
};

class ObjectA : public AbstractObject {
 public:
    void Process() {
        std::cout << "Processing A\n";
    }
};
class ObjectB : public AbstractObject {
 public:
    void Process() {
        std::cout << "Processing B\n";
    }
};

#define REGISTER_FACTORY(clazz)                                    \
    class clazz##Factory : public AbstractFactory {                \
     public:                                                       \
        clazz* NewInstance() {                                     \
            std::cout << "Creating class " << #clazz << std::endl; \
            return new clazz();                                    \
        }                                                          \
    };
