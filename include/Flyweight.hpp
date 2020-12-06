#pragma once

#include <map>
#include <string>
#include <iostream>

class Flyweight {
 public:
    explicit Flyweight(const std::string& s) : key_(s) {}

    void Process() {
        std::cout << "key: " << key_ << " with address "
                  << static_cast<void*>(this) << std::endl;
    }

 private:
    std::string key_;
};

class FlyweightFactory {
 public:
    Flyweight* GetInstance(const std::string& key) {
        if (flyweight_map_.find(key) == flyweight_map_.end()) {
            flyweight_map_[key] = new Flyweight(key);
            return flyweight_map_[key];
        }

        return flyweight_map_.at(key);
    }

 private:
    static std::map<std::string, Flyweight*> flyweight_map_;
};

std::map<std::string, Flyweight*> FlyweightFactory::flyweight_map_ = {};
