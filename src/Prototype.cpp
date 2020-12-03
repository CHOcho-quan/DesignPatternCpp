#include "Prototype.hpp"

class Context {
 public:
    Context(PrototypeBase* base) : prototype_(base) {}
    void Process() {
        // We cannot use prototype to do proto
        auto proto = prototype_->Clone();
        proto->Proto();
        delete proto;
    }

 private:
    PrototypeBase* prototype_;
};

int main() {
    Context a = Context(new PrototypeA());
    Context b = Context(new PrototypeB());

    a.Process();
    b.Process();
}
