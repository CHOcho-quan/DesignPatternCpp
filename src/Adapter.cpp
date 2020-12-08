#include "Adapter.hpp"

int main() {
    Adapter* adapter = new Adapter(new Adaptee());
    adapter->Process();
}
