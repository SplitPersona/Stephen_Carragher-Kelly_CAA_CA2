//
// Created by D00254693 on 25/04/2024.
//

#ifndef STEPHEN_CARRAGHER_KELLY_CA2_BOARD_H
#define STEPHEN_CARRAGHER_KELLY_CA2_BOARD_H

#include <vector>
#include <string>
#include "Bug.h"

using namespace std;

class Board {
private:
    vector<Bug*> bugs;

public:
    Board();
    ~Board();

    void initializeBugBoard(const std::string& filename);
    void displayAllBugs();
    void findBugByID(int id);
    void tapBuBoard();
};


#endif //STEPHEN_CARRAGHER_KELLY_CA2_BOARD_H
