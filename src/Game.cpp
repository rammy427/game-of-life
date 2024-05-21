#include "Game.h"
#include <cassert>
#include <iostream>
#include <fstream>

Game::Game(sf::RenderWindow& rw)
    :
    rw(rw)
{
}

void Game::run()
{
    processEvents();
    rw.clear();
    updateEntities();
    drawFrame();
    rw.display();
}

void Game::processEvents()
{
    sf::Event ev;
    while (rw.pollEvent(ev))
        if (ev.type == sf::Event::Closed)
            rw.close();
}

void Game::updateEntities()
{
    brd.update();
}

void Game::drawFrame()
{
    brd.draw(rw);
}