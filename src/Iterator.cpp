#include "Iterator.hpp"

int main() {
    auto agg = new ConcreteAggregator<int>();

    auto iter = agg->GetIterator();
    agg->Push(2);
    agg->Push(4);
    agg->Push(6);
    agg->Push(8);
    agg->Push(9);

    for (iter->Begin(); !iter->End(); iter->Next()) {
        auto cur = iter->Current();
        if (cur != nullptr) {
            std::cout << *cur << ' ';
        }
    }

    std::cout << '\n';
}
