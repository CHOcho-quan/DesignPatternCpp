#include "ChainOfResponsibility.hpp"

int main() {
    ChainNode* root = new ChainNode1();
    auto leaf1 = new ChainNode2();
    auto leaf2 = new ChainNode3();

    root->SetNextChainNode(leaf1);
    leaf1->SetNextChainNode(leaf2);

    for (auto i = REQUEST_1; i <= REQUEST_3;
        i = static_cast<Request>(static_cast<int>(i) + 1)) {
        root->Process(i);
    }
}
