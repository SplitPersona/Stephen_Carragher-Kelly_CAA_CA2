//
// Created by D00254693 on 17/04/2024.
//

#ifndef STEPHEN_CARRAGHER_KELLY_CA2_CRAWLER_H
#define STEPHEN_CARRAGHER_KELLY_CA2_CRAWLER_H

#include "Bug.h"

class Crawler : public Bug {

public:
    Crawler(int id, int x, int y, int direction, int size);
    void move() override;

};


#endif //STEPHEN_CARRAGHER_KELLY_CA2_CRAWLER_H