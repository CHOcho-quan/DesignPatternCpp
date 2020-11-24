#include "Singleton.hpp"

int main() {
    std::cout << "Hello Singleton!\n";
    Singleton& s1 = Singleton::GetInstance();
    Singleton& s2 = Singleton::GetInstance();

    s1.SetSingleNumber(5);
    std::cout << "Now s1 Single Number: "
              << s1.GetSingleNumber() << std::endl;
    std::cout << "Same time s2 Single Number: "
              << s2.GetSingleNumber() << std::endl;
    
    return 0;
}