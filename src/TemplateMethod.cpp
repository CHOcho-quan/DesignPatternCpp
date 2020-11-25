#include "TemplateMethod.hpp"

class ConcreteMethod1 : public TemplateMethod {
 public:
    void Step2() override {
        std::cout << "Concrete 1 Step 2\n";
    }

    void Step3() override {
        std::cout << "Concrete 1 Step 3\n";
    }
};

class ConcreteMethod2 : public TemplateMethod {
 public:
    void Step2() override {
        std::cout << "Concrete 2 Step 2\n";
    }

    void Step3() override {
        std::cout << "Concrete 2 Step 3\n";
    }
};

class Interface {
 public:
    Interface(TemplateMethod* method) {
        method_ = method;
    }

    void Process() {
        if (nullptr == method_) {
            std::cout << "Template Method not Initialized\n";
            return;
        }
        method_->Process();
    }

    ~Interface() { delete method_; }
 private:
    TemplateMethod *method_;
};

int main() {
    Interface face1(new ConcreteMethod1);
    Interface face2(new ConcreteMethod2);
    face1.Process();
    std::cout << "=====Face 1 Process Done=====\n";
    face2.Process();
}