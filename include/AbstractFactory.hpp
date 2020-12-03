#pragma once

#include <iostream>

class ObjectBaseA {};

class ObjectBaseB {};

class ObjectA : public ObjectBaseA {};
class ObjectA2 : public ObjectBaseA {};

class ObjectB : public ObjectBaseB {};
class ObjectB2 : public ObjectBaseB {};

class AbstractFactory {
 public:
    virtual ObjectBaseA* createAInstance() = 0;
    virtual ObjectBaseB* createBInstance() = 0;
    virtual ~AbstractFactory() {}
};

class Factory1 : public AbstractFactory {
 public:
    virtual ObjectBaseA* createAInstance() {
        std::cout << "Factory1 Creating ObjectA\n";
        return new ObjectA();
    }

    virtual ObjectBaseB* createBInstance() {
        std::cout << "Factory1 Creating ObjectB\n";
        return new ObjectB();
    }
};

class Factory2 : public AbstractFactory {
 public:
    virtual ObjectBaseA* createAInstance() {
        std::cout << "Factory2 Creating ObjectA\n";
        return new ObjectA2();
    }

    virtual ObjectBaseB* createBInstance() {
        std::cout << "Factory2 Creating ObjectB\n";
        return new ObjectB2();
    }
};
