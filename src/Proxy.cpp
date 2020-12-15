#include "Proxy.hpp"

int main() {
    auto data = new ConcreteSubject();
    auto proxy = new Proxy(data);
    proxy->Request();
}
