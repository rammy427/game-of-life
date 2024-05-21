#include "Board.h"

#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game(sf::RenderWindow& rw);
    void run();
private:
    void processEvents();
    void updateEntities();
    void drawFrame();
    /** Game Functions **/
private:
    sf::RenderWindow& rw;
    sf::Clock clock;
    /** Game Variables **/
    Board brd;
};

#endif