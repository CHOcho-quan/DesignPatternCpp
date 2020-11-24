#pragma once

#include <iostream>

class Singleton {
 public:
    static Singleton& GetInstance() {
        static Singleton singleton;
        return singleton;
    }

    inline int GetSingleNumber() { return single_number_; }

    inline void SetSingleNumber(int sn) { single_number_ = sn; }

 private:
    Singleton() {
        std::cout << "Constructing Singleton\n";
        single_number_ = 0; 
    }
    Singleton(const Singleton& s) {}
    int single_number_;
};