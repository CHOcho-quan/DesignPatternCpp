#include "Momento.hpp"

State* Momento::GetState() {
    return new State(content_);
}

int main() {
    State* state = new State("Initial");
    auto momento1 = state->GetMomento();
    state->SetContent("Next");
    auto momento2 = state->GetMomento();

    momento1->GetState()->Content();
    momento2->GetState()->Content();
}
