#include "Bridge.hpp"

int main() {
    ObjectImpl *a;
    ObjectImpl *b;

    a = new ImplA(new ObjectA());
    b = new ImplB(new ObjectB());

    a->ProcessImpl();
    b->ProcessImpl();
}
