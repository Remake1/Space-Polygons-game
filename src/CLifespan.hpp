#ifndef CPPGAME_CLIFESPAN_HPP
#define CPPGAME_CLIFESPAN_HPP


class CLifespan {
public:
    int total = 0; // total amount of lifespan
    int remaining = 0; // remaining amount of lifespan on the entity
    CLifespan(int t)
    : total(t), remaining(t) {}
};


#endif //CPPGAME_CLIFESPAN_HPP
