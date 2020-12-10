#include "State.hpp"

class Context {
 public:
    Context(State* s) : state_(s) {}
    void Operation1() {
        state_->Operation1();
        state_ = State2::getInstance();
    }

    void Operation2() {
        state_->Operation2();
        state_ = State1::getInstance();
    }

 private:
    State* state_;
};

int main() {
    Context c(new State1());
    c.Operation1();
    c.Operation2();
}
