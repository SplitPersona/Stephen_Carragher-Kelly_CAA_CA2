//
// Created by D00254693 on 17/04/2024.
//

#include "Hopper.h"
#include <cstdlib>

Hopper::Hopper(int id, int x, int y, Direction direction, int size, int hopeLength) : Bug(id, x, y, direction, size), hopLength(hopeLength) {}

Hopper::~Hopper() {}

void Hopper::move() {

    if(isWayBlocked())
    {
        direction = static_cast<Direction>(rand() % 4);
    }
    else
    {
        switch(direction)
        {
            case Direction::NORTH:
                position.second -= hopLength;
                break;

            case Direction::EAST:
                position.first += hopLength;
                break;

            case Direction::SOUTH:
                position.second += hopLength;
                break;

            case Direction::WEST:
                position.first -=hopLength;
                break;
        }

        addToPath(position.first, position.second);
    }
}