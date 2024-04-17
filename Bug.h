//
// Created by D00254693 on 17/04/2024.
//

#ifndef STEPHEN_CARRAGHER_KELLY_CA2_BUG_H
#define STEPHEN_CARRAGHER_KELLY_CA2_BUG_H

#include <list>

class Bug {

    enum direction{NORTH, EAST, SOUTH, WEST};

private:
    int ID;
    std::pair<int, int> position;
    direction direct;
    int size;
    bool alive;
    std::list<std::pair<int,int>> path;

public:
    Bug();
    Bug(int id, int x, int y, int direction, int size);
    virtual void move() = 0;

    bool isWayBlocked();

    void updatePosition(int x, int y);

    void addToPath(int x, int y);

    void printPath();

    virtual ~Bug();

};

#endif //STEPHEN_CARRAGHER_KELLY_CA2_BUG_H
