#include <vector>

#include "Observer.hpp"

class Subject {
 public:
    std::vector<Observer*> obs_;

    void AddObserver(Observer* obs) {
        obs_.push_back(obs);
    }

    void RemoveObserver() {
        obs_.pop_back();
    }

    void Notify() {
        for (auto &obs : obs_) {
            obs->Update();
        }
    }
};

int main() {
    Subject subjector;
    subjector.AddObserver(new ObserverA());
    subjector.AddObserver(new ObserverB());
    subjector.Notify();
}
