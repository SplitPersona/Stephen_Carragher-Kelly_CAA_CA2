//
// Created by D00254693 on 17/04/2024.
//

#ifndef STEPHEN_CARRAGHER_KELLY_CA2_BUG_H
#define STEPHEN_CARRAGHER_KELLY_CA2_BUG_H

#include <list>

enum class Direction
        {
    NORTH,
    EAST,
    SOUTH,
    WEST
        };

enum class BugType
        {
    CRAWLER,
    HOPPER
        };

class Bug {

protected:
    int id;
    std::pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    std::list<std::pair<int,int>> path;

public:
    Bug(int id, int x, int y, Direction direct, int size);

    virtual ~Bug();

    int getID() const
    {
        return id;
    }
    std::pair<int, int> getPosition() const
    {
        return position;
    }
    Direction getDirection() const
    {
        return direction;
    }
    int getSize() const
    {
        return size;
    }
    bool isAlive() const {
        return alive;
    }
    std::string getDirectionString() const;

    virtual BugType getType() const = 0;

    virtual void move() = 0;

    bool isWayBlocked();

    void updatePosition(int x, int y);

    void addToPath(int x, int y);

    void printPath();

};

#endif //STEPHEN_CARRAGHER_KELLY_CA2_BUG_H
