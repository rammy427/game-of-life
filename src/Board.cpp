#include "Board.h"
#include <random>

Board::Tile::Tile(const sf::Vector2f& pos)
{
    rect.setFillColor(color);
    rect.setSize({dim, dim});
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(-padding);
    rect.setPosition(pos);
}

void Board::Tile::toggle()
{
    is_active = !is_active;
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

Board::Board()
{
    // Construct all tiles.
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            tiles.emplace_back(sf::Vector2f(x, y) * float(Tile::dim));
    
    std::mt19937 rng{std::random_device()()};
    std::uniform_int_distribution<int> xDist(0, width - 1);
    std::uniform_int_distribution<int> yDist(0, height - 1);

    // Set initial tiles.
    for (int n = 0; n < initialTiles; n++)
    {
        sf::Vector2i gridPos;
        do
            gridPos = {xDist(rng), yDist(rng)};
        while (tileAt(gridPos).isActive());
        tileAt(gridPos).toggle();
    }
}

void Board::update()
{
    std::vector<sf::Vector2i> marked_tiles;
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            Tile& tile = tileAt({x, y});
            int count = countNeighbors({x, y});
            if ((tile.isActive() && (count < 2 || count > 3))
                || (!tile.isActive() && count == 3))
                marked_tiles.emplace_back(x, y);
        }

    for (sf::Vector2i& v : marked_tiles)
        tileAt(v).toggle();
}

void Board::draw(sf::RenderWindow& rw)
{
    for (auto& t : tiles)
        t.draw(rw);
}

Board::Tile& Board::tileAt(const sf::Vector2i& gridPos)
{
    return tiles[gridPos.y * width + gridPos.x];
}

int Board::countNeighbors(const sf::Vector2i& gridPos)
{
    const int x_start = std::max(0, gridPos.x - 1);
    const int y_start = std::max(0, gridPos.y - 1);
    const int x_end = std::min(width - 1, gridPos.x + 1);
    const int y_end = std::min(height - 1, gridPos.y + 1);

    int count = 0;
    for (int y = y_start; y <= y_end; y++)
        for (int x = x_start; x <= x_end; x++)
            if (gridPos != sf::Vector2i(x, y) && tileAt({x, y}).isActive())
                count++;
    
    return count;
}