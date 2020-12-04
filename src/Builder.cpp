#include "Builder.hpp"

int main() {
    Director da = Director(new BuilderA());
    Director db = Director(new BuilderB());

    auto objectA = da.Construct();
    auto objectB = db.Construct();

    objectA->Process();
    objectB->Process();
}
