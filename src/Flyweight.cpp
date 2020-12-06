#include "Flyweight.hpp"

int main() {
    FlyweightFactory factory;
    auto f1 = factory.GetInstance("fly");
    auto f2 = factory.GetInstance("fly");
    auto f3 = factory.GetInstance("fly2");

    f1->Process();
    f2->Process();
    f3->Process();
}
