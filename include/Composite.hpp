#pragma once

#include <vector>
#include <iostream>

class Component {
 public:
    virtual void Process() = 0;
    virtual void AddComponent(const Component*) {};
    virtual void RemoveComponent() {};
    virtual ~Component() {}
};

class Composite : public Component {
 public:
    Composite() {}
    void Process() {
        std::cout << "Processing Composite\n";
        for (auto& leaf : leafs_) {
            if (leaf != nullptr) {
                leaf->Process();
            }
        }
    }

    void AddComponent(const Component* c) {
        leafs_.push_back(const_cast<Component*>(c));
    }

    void RemoveComponent() {
        leafs_.pop_back();
    }

 private:
    std::vector<Component*> leafs_;
};

class Leaf : public Component {
 public:
    void Process() {
        std::cout << "Processing Leaf\n";
    }
};
