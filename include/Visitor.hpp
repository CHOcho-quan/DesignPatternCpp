#pragma once

#include <iostream>

class Visitor;
class Element {
 public:
    virtual void Process(Visitor* v) = 0;
    virtual ~Element() {}
};

class ElementA;
class ElementB;
class Visitor {
 public:
    virtual void Process(ElementA* ele) = 0;
    virtual void Process(ElementB* ele) = 0;
};

class ElementA : public Element {
 public:
    void Process(Visitor* v) {
        v->Process(this);
    }
};

class ElementB : public Element {
 public:
    void Process(Visitor* v) {
        v->Process(this);
    }
};

class Visitor1 : public Visitor {
 public:
    void Process(ElementA* ele) {
        std::cout << "Visitor 1 processing element A\n";
    }

    void Process(ElementB* ele) {
        std::cout << "Visitor 1 processing element B\n";
    }
};

class Visitor2 : public Visitor {
 public:
    void Process(ElementA* ele) {
        std::cout << "Visitor 2 processing element A\n";
    }

    void Process(ElementB* ele) {
        std::cout << "Visitor 2 processing element B\n";
    }
};
