//
// Created by D00254693 on 17/04/2024.
//

#ifndef STEPHEN_CARRAGHER_KELLY_CA2_HOPPER_H
#define STEPHEN_CARRAGHER_KELLY_CA2_HOPPER_H

#include "Bug.h"

class Hopper : public Bug {

private:
    int hopLength;

public:
    Hopper(int id, int x, int y, Direction direction, int size, int hopeLength);


    virtual ~Hopper();
    int getHopLength() const
    {
        return hopLength;
    }
    virtual BugType getType() const override
    {
        return BugType::HOPPER;
    }

    virtual void move() override;
};


#endif //STEPHEN_CARRAGHER_KELLY_CA2_HOPPER_H
