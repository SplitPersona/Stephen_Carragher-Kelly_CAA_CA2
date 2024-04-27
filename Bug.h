//
// Created by D00254693 on 17/04/2024.
//

#ifndef STEPHEN_CARRAGHER_KELLY_CA2_BUG_H
#define STEPHEN_CARRAGHER_KELLY_CA2_BUG_H

#include <utility>
#include <String>
#include <list>

enum class Direction
        {
    NORTH = 1,
    EAST,
    SOUTH,
    WEST
        };

enum class BugType
        {
    CRAWLER,
    HOPPER
        };

class pair;

class Bug {

protected:
    int id;
    std::pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    std::list<std::pair<int,int>> path;
    int eatenBy;

public:
    Bug(int id, int x, int y, Direction direct, int size);

    virtual ~Bug();

    //Getters
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
    std::string getDirectionasString() const;

    virtual BugType getType() const = 0;

    const std::list<std::pair<int, int>>& getPath() const
    {
        return path;
    }

    int gotEatenBy() const
    {
        return eatenBy;
    }
    std::string getTypeasString() const;

    //Setters
    void setSize(int newSize)
    {
        size = newSize;
    }
    void setAlivetoDead(bool alive)
    {
        alive = isAlive();
    }
    void setEatenBy(int ID)
    {
        eatenBy = ID;
    }



    //Other fuctions

    virtual void move() = 0;

    bool isWayBlocked();

    void updatePosition(int x, int y);

    void addToPath(int x, int y);

    void printPath();

};

#endif //STEPHEN_CARRAGHER_KELLY_CA2_BUG_H
