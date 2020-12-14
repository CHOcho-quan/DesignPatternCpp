#pragma once

#include <vector>
#include <iostream>

class Command {
 public:
    virtual void Process() = 0;
    virtual ~Command() {}
};

class ConcreteCommand1 : public Command {
 public:
    void Process() {
        std::cout << "Command 1 Executing\n";
    }
};

class ConcreteCommand2 : public Command {
 public:
    void Process() {
        std::cout << "Command 2 Executing\n";
    }
};

class VectorCommander : public Command {
 public:
    void PushCommand(Command* c) {
        commands_.push_back(c);
    }

    void Process() {
        for (auto& command : commands_) {
            command->Process();
        }
    }

 private:
    std::vector<Command*> commands_;
};

class Invoker {
 public:
    Invoker() {}
    
    void Process(Command* command) {
        command->Process();
    }
};
