//
// Created by D00254693 on 27/04/2024.
//

#ifndef STEPHEN_CARRAGHER_KELLY_CA2_DIGGER_H
#define STEPHEN_CARRAGHER_KELLY_CA2_DIGGER_H


#include "Bug.h"

class Digger : public Bug
        {
        public:
            Digger(int id, int x, int y, Direction direction, int size);
            virtual void move() override;

            virtual BugType getType() const override
            {
                return BugType::DIGGER;
            }
        };


#endif //STEPHEN_CARRAGHER_KELLY_CA2_DIGGER_H
