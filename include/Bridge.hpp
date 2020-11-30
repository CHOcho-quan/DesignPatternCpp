#pragma once

#include <iostream>

class ObjectBase {
 public:
    virtual void Process() {}
    virtual ~ObjectBase() {}
};

class ObjectImpl {
 public:
    explicit ObjectImpl(ObjectBase* base) : obj_(base) {}
    virtual void ProcessImpl() {}
    virtual ~ObjectImpl() {}
 protected:
    ObjectBase* obj_;
};

class ObjectA : public ObjectBase {
 public:
    void Process() {
        std::cout << "Process Object A\n";
    }
};

class ObjectB : public ObjectBase {
 public:
    void Process() {
        std::cout << "Process Object B\n";
    }
};

class ImplA : public ObjectImpl {
 public:
    explicit ImplA(ObjectBase* base)
        : ObjectImpl(base) {}
    void ProcessImpl() {
        obj_->Process();
        std::cout << "Impl A Functions\n";
    }
};

class ImplB : public ObjectImpl {
 public:
    explicit ImplB(ObjectBase* base)
        : ObjectImpl(base) {}
    void ProcessImpl() {
        obj_->Process();
        std::cout << "Impl B Functions\n";
    }
};
