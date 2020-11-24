#pragma once

#include <iostream>

class TemplateMethod {
 public:
    TemplateMethod() = default;

    // Process Main Function
    inline void Process() {
        this->Step1();
        this->Step2();
        this->Step3();
        this->Step4();
    }

    // Algorithm Steps
    inline void Step1() {
        std::cout << "Hello I am Step 1\n";
    }
    virtual void Step2() = 0;
    virtual void Step3() = 0;
    inline void Step4() {
        std::cout << "Hello I am Step 4\n";
    }

    virtual ~TemplateMethod() {}
};
