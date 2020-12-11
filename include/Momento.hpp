#pragma once

#include <string>
#include <iostream>

class State;
class Momento {
 public:
    Momento() {}
    explicit Momento(const std::string& c) : content_(c) {}
    State* GetState();

 private:
    std::string content_;
};

class State {
 public:
    explicit State(const std::string& c) : content_(c) {}
    void Content() {
        std::cout << content_ << std::endl;
    }
    void SetContent(const std::string& s) {
        content_ = s;
    }
    Momento* GetMomento() {
        return new Momento(content_);
    }

 private:
    std::string content_;
};
