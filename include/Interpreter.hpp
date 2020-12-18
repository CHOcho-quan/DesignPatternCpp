#pragma once

#include <iostream>

class AbstractExpression {
 public:
    virtual int Interpret() = 0;
    virtual ~AbstractExpression() {}
};

class NormalExpression : public AbstractExpression {
 public:
    NormalExpression(AbstractExpression* l, AbstractExpression* r)
        : left_(l),
          right_(r) {}
    int Interpret() {
        return left_->Interpret() + right_->Interpret();
    }

 private:
    AbstractExpression* left_;
    AbstractExpression* right_;
};

class TerminalExpression : public AbstractExpression {
 public:
    TerminalExpression(int i) : data_(i) {}
    int Interpret() {
        return data_;
    }

 private:
    int data_;
};
