#ifndef CPPGAME_ACTION_HPP
#define CPPGAME_ACTION_HPP

#include <string>

enum eActionTypes {
    END = 0,
    START
};

enum eActionNames {
    TOGGLE_TEXTURE = 0,
    TOGGLE_COLLISION,
    TOGGLE_GRID,
    PAUSE,
    QUIT,
    UP,
    DOWN,
    RIGHT,
    LEFT,
    FIRE
};

class Action {
    eActionNames m_name;
    eActionTypes m_type;

public:
    Action();
    Action(eActionNames name, const eActionTypes &type);

    eActionNames name() const;
    eActionTypes type() const;
};

#endif //CPPGAME_ACTION_HPP
