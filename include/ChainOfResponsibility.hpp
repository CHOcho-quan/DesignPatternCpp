#pragma once

#include <iostream>

enum Request {
    REQUEST_1 = 0,
    REQUEST_2,
    REQUEST_3
};

class ChainNode {
 public:
    ChainNode() {}
    explicit ChainNode(ChainNode* n) : next_(n) {}

    void Process(Request r) {
        if (CanProcess(r)) {
            Execute(r);
        } else {
            next_->Execute(r);
        }
    }

    void SetNextChainNode(ChainNode* n) {
        next_ = n;
    }

 protected:
    virtual bool CanProcess(Request r) = 0;
    virtual void Execute(Request r) = 0;
    ChainNode* next_;
};

class ChainNode1 : public ChainNode {
 public:
    ChainNode1() {}
    explicit ChainNode1(ChainNode* n) : ChainNode(n) {}

 protected:
    bool CanProcess(Request r) {
        return (r == REQUEST_1);
    }

    void Execute(Request r) {
        std::cout << "Processing Request " << r << std::endl;
    }
};

class ChainNode2 : public ChainNode {
 public:
    ChainNode2() {}
    explicit ChainNode2(ChainNode* n) : ChainNode(n) {}

 protected:
    bool CanProcess(Request r) {
        return (r == REQUEST_2);
    }

    void Execute(Request r) {
        std::cout << "Processing Request " << r << std::endl;
    }
};

class ChainNode3 : public ChainNode {
 public:
    ChainNode3() {}
    explicit ChainNode3(ChainNode* n) : ChainNode(n) {}

 protected:
    bool CanProcess(Request r) {
        return (r == REQUEST_1);
    }

    void Execute(Request r) {
        std::cout << "Processing Request " << r << std::endl;
    }
};
