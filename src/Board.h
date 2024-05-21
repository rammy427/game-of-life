#ifndef BOARD_H
#define BOARD_H

#include "RamWindow.h"

class Board
{
private:
    class Tile
    {
    public:
        Tile(const sf::Vector2f& pos);
        void toggle();
        void draw(sf::RenderWindow& rw);
        bool isActive() const;
    public:
        static constexpr int dim = 8;
    private:
        static constexpr int padding = 1;
        sf::Color color = sf::Color::Yellow;
        bool is_active = false;
        sf::RectangleShape rect;
    };
public:
    Board();
    void update();
    void draw(sf::RenderWindow& rw);
private:
    Tile& tileAt(const sf::Vector2i& gridPos);
    int countNeighbors(const sf::Vector2i& gridPos);
private:
    static constexpr int initialTiles = 1000;
    static constexpr int width = SCREEN_WIDTH / Tile::dim;
    static constexpr int height = SCREEN_HEIGHT / Tile::dim;
    std::vector<Tile> tiles;
};

#endif