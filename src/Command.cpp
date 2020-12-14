#include "Command.hpp"

int main() {
    Invoker invoker;
    auto c1 = new ConcreteCommand1();
    auto c2 = new ConcreteCommand2();
    auto c3 = new VectorCommander();
    c3->PushCommand(c1);
    c3->PushCommand(c2);

    c1->Process();
    c2->Process();
    c3->Process();
}
