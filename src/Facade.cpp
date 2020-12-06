#include "Facade.hpp"

int main() {
    Facade* facade = new Facade(new Object(), new Something());

    facade->ProcessObject();
    facade->ProcessSomething();
}
