#include "Game.h"

int main()
{
    // Create window.
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "John Conway's Game of Life", sf::Style::Close);

    // Window settings.
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    // Start game loop.
    Game game(window);
    while (window.isOpen())
        game.run();

    return 0;
}