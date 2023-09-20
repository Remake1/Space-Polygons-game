#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"

int main()
{
    Game g("path_to_config");
    g.run();

    return 0;
}