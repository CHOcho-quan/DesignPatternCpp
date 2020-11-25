#include "Strategy.hpp"

REGISTER_FACTORY(ConcreteStrategy1)
REGISTER_FACTORY(ConcreteStrategy2)

class Interface {
 public:
    void Init(std::string s) {
        auto& fac_map = GetGlobalFactoryMap();
        if (fac_map.find(s) == fac_map.end()) {
            std::cout << "Not Registered Strategy " << s << std::endl;
            return;
        }
        strategy_ = fac_map[s]->NewInstance();
    }

    void ProcessInterface() {
        if (nullptr == strategy_) {
            std::cout << "Strategy not initialized";
            return;
        }
        strategy_->Process();
    }

    ~Interface() {
        delete strategy_;
    }

 private:
    IStrategy* strategy_;
};

int main() {
    Interface interface1, interface2;
    interface1.Init("ConcreteStrategy1");
    interface2.Init("ConcreteStrategy2");
    interface1.ProcessInterface();
    interface2.ProcessInterface();
}
