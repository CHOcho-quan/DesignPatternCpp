#include "Composite.hpp"

int main() {
    auto root = new Composite();
    root->AddComponent(new Leaf());
    root->Process();
}
