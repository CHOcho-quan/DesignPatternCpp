#pragma once

#include <iostream>

class Object {
 public:
    virtual void Process() = 0;
    virtual ~Object() {}
};
class ObjectA : public Object {
 public:
    void Process() { std::cout << "Object A Processing\n"; }
};
class ObjectB : public Object {
 public:
    void Process() { std::cout << "Object B Processing\n"; }
};

class Builder {
 public:
    friend class Object;

    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual void BuildPart3() = 0;

    virtual Object* GetObject() { return obj_; }
    virtual ~Builder() { delete obj_; }

 protected:
    Object* obj_;
};

class BuilderA : public Builder {
 public:
    void BuildPart1() {
        obj_ = new ObjectA();
        std::cout << "Building Object A Part1\n";
    }

    void BuildPart2() {
        std::cout << "Building Object A Part2\n";
    }

    void BuildPart3() {
        std::cout << "Building Object A Part3\n";
    }
};

class BuilderB : public Builder {
 public:
    void BuildPart1() {
        obj_ = new ObjectB();
        std::cout << "Building Object B Part1\n";
    }

    void BuildPart2() {
        std::cout << "Building Object B Part2\n";
    }

    void BuildPart3() {
        std::cout << "Building Object B Part3\n";
    }
};

class Director {
 public:
    Director(Builder* b) : builder_(b) {}

    Object* Construct() {
        builder_->BuildPart1();
        builder_->BuildPart2();
        builder_->BuildPart3();

        return builder_->GetObject();
    }

    ~Director() { delete builder_; }

 private:
    Builder* builder_;
};
