//
// Created by D00254693 on 27/04/2024.
//

#include "Digger.h"

Digger::Digger(int id, int x, int y, Direction direction, int size) : Bug(id, x, y, direction, size)
{

}

void Digger::move()
{
    switch(direction)
    {
        case Direction::NORTH:
            position.second -= 2;
            break;

        case Direction::EAST:
            position.first += 2;
            break;

        case Direction::SOUTH:
            position.second += 2;
            break;

        case Direction::WEST:
            position.first -=2;
            break;
    }

    addToPath(position.first, position.second);

}
