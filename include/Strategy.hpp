#include <map>
#include <string>
#include <iostream>

class IStrategy {
 public:
    virtual ~IStrategy() {}
    virtual void Process() {};
};

class ConcreteStrategy1 : public IStrategy {
 public:
    void Process() {
        std::cout << "Concrete Strategy 1\n";
    }
};

class ConcreteStrategy2 : public IStrategy {
 public:
    void Process() {
        std::cout << "Concrete Strategy 2\n";
    }
};

class AbstractStrategyFactory {
 public:
    virtual IStrategy* NewInstance() { return new IStrategy; };
    virtual ~AbstractStrategyFactory() {}
};

using FactoryMap = std::map<std::string, AbstractStrategyFactory*>;
inline FactoryMap &GetGlobalFactoryMap() {
    static FactoryMap m;
    return m;
}

#define REGISTER_FACTORY(clazz)                                  \
    class clazz##Factory : public AbstractStrategyFactory {      \
     public:                                                     \
        IStrategy* NewInstance() {                               \
            auto strategy = new clazz;                           \
            return strategy;                                     \
        }                                                        \
    };                                                           \
    __attribute__((constructor)) void RegisterFactory##clazz() { \
        auto & fac_map = GetGlobalFactoryMap();                  \
        if (fac_map.find(#clazz) == fac_map.end()) {             \
            fac_map[#clazz] = new clazz##Factory;                \
        }                                                        \
    }
    
