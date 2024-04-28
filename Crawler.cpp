//
// Created by D00254693 on 17/04/2024.
//

#include "Crawler.h"
#include <cstdlib>

Crawler::Crawler(int id, int x, int y, Direction direction, int size) : Bug(id, x, y, direction, size) {}

Crawler::~Crawler(){}

void Crawler::move() {

    if(isWayBlocked())
    {
        direction = static_cast<Direction>(rand() % 4);
    }
    else
    {
        switch(direction)
        {
            case Direction::NORTH:
                position.second--;
                break;

            case Direction::EAST:
                position.first++;
                break;

            case Direction::SOUTH:
                position.second++;
                break;

            case Direction::WEST:
                position.first--;
                break;
        }

        addToPath(position.first, position.second);
    }

}