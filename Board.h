//
// Created by D00254693 on 25/04/2024.
//

#ifndef STEPHEN_CARRAGHER_KELLY_CA2_BOARD_H
#define STEPHEN_CARRAGHER_KELLY_CA2_BOARD_H

#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include "Bug.h"

using namespace std;

class Board {
private:
    vector<Bug*> bugs;
    vector<vector<vector<Bug*>>> grid;

public:
    Board();
    ~Board();

    void initializeBugBoard(const std::string& filename);
    void displayAllBugs();
    void findBugByID(int id);
    void tapBuBoard();
    void displayLifeHistory();
    void writeLifeHistoryToFile();
    string getDateTimeString() const;
    void displayAllCells();
    void updateCellOccupancy();
    void eatBugsInCell(int x, int y);
    void fight(Bug* bug1, Bug* bug2);
    void runSimulation();
};


#endif //STEPHEN_CARRAGHER_KELLY_CA2_BOARD_H
