#pragma once

#include <iostream>

class State {
 public:
    virtual void Operation1() = 0;
    virtual void Operation2() = 0;
    virtual ~State() {}
};

class State1 : public State {
 public:
    static State* getInstance() {
        if (cur_state_ == nullptr) {
            cur_state_ = new State1();
        }
        return cur_state_;
    }
    void Operation1() {
        std::cout << "State 1 Operation 1\n";
    }
    void Operation2() {
        std::cout << "State 1 Operation 2\n";
    }

 private:
    static State* cur_state_;
};

State* State1::cur_state_ = new State1();

class State2 : public State {
 public:
    static State* getInstance() {
        if (cur_state_ == nullptr) {
            cur_state_ = new State2();
        }
        return cur_state_;
    }
    void Operation1() {
        std::cout << "State 2 Operation 1\n";
    }
    void Operation2() {
        std::cout << "State 2 Operation 2\n";
    }

 private:
    static State* cur_state_;
};

State* State2::cur_state_ = new State2();
