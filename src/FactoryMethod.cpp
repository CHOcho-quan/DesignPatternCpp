#include "FactoryMethod.hpp"

REGISTER_FACTORY(ObjectA)
REGISTER_FACTORY(ObjectB)

class Context {
 public:
    Context(AbstractFactory* factory) : factory_(factory) {}
    void Process() {
        auto obj = factory_->NewInstance();
        obj->Process();
    }
 private:
    AbstractFactory* factory_;
};

int main() {
    auto contextA = Context(new ObjectAFactory());
    auto contextB = Context(new ObjectBFactory());

    contextA.Process();
    contextB.Process();
}
