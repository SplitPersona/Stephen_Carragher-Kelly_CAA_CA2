//
// Created by D00254693 on 17/04/2024.
//

#include <iostream>
#include "Bug.h"

using namespace std;

Bug::Bug(int id, int x, int y, Direction direction, int size) : id(id), position(make_pair(x, y)), direction(direction), size(size), alive(true)
{

}


void Bug::move() {}

bool Bug::isWayBlocked() {
    return false;
}

void Bug::updatePosition(int x, int y) {
    position.first = x;
    position.second = y;
}

void Bug::addToPath(int x, int y) {
    path.push_back(make_pair(x, y));
}

void Bug::printPath() {
    for(const auto& p : path)
    {
        cout << "(" << p.first << "," << p.second << ")";
    }

    cout << endl;
}

std::string  Bug::getDirectionasString() const {
    switch (direction) {
        case Direction::NORTH:
            return "North";
        case Direction::EAST:
            return "East";
        case Direction::SOUTH:
            return "South";
        case Direction::WEST:
            return "West";
        default:
            return "Unknown";
    }
}

std::string Bug::getTypeasString() const
{
    return (getType() == BugType::CRAWLER) ? "Crawler" : "Hopper";
}

Bug::~Bug(){}

