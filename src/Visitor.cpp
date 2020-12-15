#include "Visitor.hpp"

int main() {
    auto v1 = new Visitor1();
    auto v2 = new Visitor2();

    auto eleA = new ElementA();
    auto eleB = new ElementB();
    eleA->Process(v1);
    eleA->Process(v2);
    eleB->Process(v1);
    eleB->Process(v2);
}
