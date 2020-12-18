#include "Interpreter.hpp"

int main() {
    AbstractExpression* a1 = new TerminalExpression(1);
    AbstractExpression* a2 = new TerminalExpression(2);
    AbstractExpression* a3 = new NormalExpression(a1, a2);

    std::cout << "Result: " << a3->Interpret() << std::endl;
}
