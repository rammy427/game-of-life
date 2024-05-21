#include "Board.h"

Board::Tile::Tile(const sf::Vector2f& pos)
{
    rect.setFillColor(color);
    rect.setSize({dim, dim});
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(-padding);
    rect.setPosition(pos);
}

void Board::Tile::draw(sf::RenderWindow& rw)
{
    if (is_active)
        rw.draw(rect);
}

bool Board::Tile::isActive() const
{
    return is_active;
}

int Board::Tile::getDim()
{
    return dim;
}

Board::Board()
{
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            tiles.emplace_back(sf::Vector2f(x, y) * float(Tile::getDim()));
}

void Board::draw(sf::RenderWindow& rw)
{
    for (auto& t : tiles)
        t.draw(rw);
}