#include "Decorator.hpp"

int main() {
    ObjectDecorator *decoratorA;
    ObjectDecorator *decoratorB;
    ObjectDecorator *decoratorAB;

    decoratorA = new ConcreteObjectDecoratorA(new ConcreteObjA());
    decoratorB = new ConcreteObjectDecoratorB(new ConcreteObjB());
    decoratorAB = new ConcreteObjectDecoratorB(decoratorA);

    decoratorA->Process();
    decoratorB->Process();
    decoratorAB->Process();
}
