#include "AbstractFactory.hpp"

int main() {
    AbstractFactory* factory1 = new Factory1();
    AbstractFactory* factory2 = new Factory2();

    factory1->createAInstance();
    factory1->createBInstance();

    factory2->createAInstance();
    factory2->createBInstance();
}
