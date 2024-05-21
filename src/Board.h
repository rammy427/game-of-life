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
        void draw(sf::RenderWindow& rw);
        bool isActive() const;
        static int getDim();
    private:
        static constexpr int dim = 20;
        static constexpr int padding = 1;
        sf::Color color = sf::Color::Yellow;
        bool is_active = true;
        sf::RectangleShape rect;
    };
public:
    Board();
    void draw(sf::RenderWindow& rw);
private:
    static constexpr int width = 10;
    static constexpr int height = 10;
    std::vector<Tile> tiles;
};

#endif