//
// Created by D00254693 on 25/04/2024.
//

#include "Board.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"

using namespace std;

Board::Board()
{
    grid.resize(10, vector<vector<Bug*>>(10));
}

Board::~Board() {
    for(Bug* bug:bugs)
    {
        delete bug;
    }
}

void Board::initializeBugBoard(const string &filename) {
    ifstream file(filename);
    if(!file.is_open())
    {
        cerr << "failed to open the file" << filename << endl;
        return;
    }

    string line;
    while(getline(file, line))
    {
        istringstream iss(line);
        string typeStr, idStr, xStr, yStr, directionStr, sizeStr, hopLengthStr;
        if(!(getline(iss, typeStr, ';') && getline(iss, idStr, ';') && getline(iss, xStr, ';') && getline(iss, yStr, ';') && getline(iss, directionStr, ';') && getline(iss, sizeStr, ';'))) {
            cerr << "Error loading bug settings" << line << endl;
            continue;
        }

        char type = typeStr[0];
        int id = stoi(idStr);
        int x = stoi(xStr);
        int y = stoi(yStr);
        Direction direction = static_cast<Direction>(stoi(directionStr));
        int size = stoi(sizeStr);

        Bug* bug = nullptr;

        if(type == 'C')
        {
            bug = new Crawler(id, x, y, direction, size);
        }
        else if (type == 'H')
        {
            if(!(getline(iss, hopLengthStr, ';')))
            {
                cerr << "Error reading bug settings " << line << endl;
                continue;
            }
            int hopLength = stoi(hopLengthStr);
            bug = new Hopper(id, x, y, direction, size, hopLength);
        }
        else
        {
            cerr << "Invalid bug type: " << type << endl;
            continue;
        }

        bugs.push_back(bug);
    }

    file.close();
}

void Board::displayAllBugs()
{
    for(const Bug* bug: bugs)
    {
        cout << bug-> getID() << " " << (bug->getType() == BugType::CRAWLER ? "Crawler" : "Hopper")
        << " (" << bug->getPosition().first << "," << bug->getPosition().second << ")"
        << " " << bug->getSize() << " " << bug->getDirectionasString()
        << (bug->getType() == BugType::HOPPER ? " " + to_string(static_cast<const Hopper*>(bug)->getHopLength()): "")
        << (bug->isAlive() ? "Alive" : "Dead") << endl;
        //i hate this ^ so much.
    }
}

void Board::findBugByID(int id)
{
    bool found = false;
    for(const Bug* bug : bugs)
    {
        if(bug->getID() == id)
        {
            cout << "Bug Found: " << endl;
            cout << "ID: " << bug->getID() << endl;
            cout << "Type: " << (bug->getType() == BugType::CRAWLER ? "Crawler" : "Hopper") << endl;
            cout << "Position: (" << bug->getPosition().first << ", " << bug->getPosition().second << ")" << endl;
            cout << "Size: " << bug->getSize() << endl;
            cout << "Direction: " << bug->getDirectionasString() << endl;
            if (bug->getType() == BugType::HOPPER)
            {
                cout << "Hop Length: " << static_cast<const Hopper*>(bug)->getHopLength() << endl;
            }
            cout << "Status: " << (bug->isAlive() ? "Alive" : "Dead") << endl;
            found = true;
            break;
        }
    }
    if(!found)
    {
        cout << "Bug " << id << " not found" << endl;
    }
}

void Board::tapBuBoard()
{
    for(Bug* bug: bugs)
    {
        bug->move();
    }
}

void Board::displayLifeHistory() {
    for(const Bug* bug: bugs)
    {
        cout << bug->getID() << " ";
        if(bug->getType() == BugType::CRAWLER)
        {
            cout << "Crawler ";
        }
        else
        {
            cout << "Hopper ";
        }
        cout << "Path: ";
        for(const auto& position : bug ->getPath())
        {
            cout << "(" << position.first << "," << position.second << ")";
        }
        if(!bug->isAlive())
        {
            cout << " Eaten by " << bug->gotEatenBy();
        }
        cout << endl;
    }
}

void Board::writeLifeHistoryToFile()
{
    ofstream outFile("bugs_life_history_"+getDateTimeString() + ".out");
    if(!outFile)
    {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    for(const Bug* bug: bugs)
    {
        outFile << bug->getID() << " ";
        if(bug->getType() == BugType::CRAWLER)
        {
            outFile<<"Crawler ";
        }
        else
        {
            outFile << "Hopper ";
        }
        outFile << "Path: ";
        for(const auto& position : bug ->getPath())
        {
            outFile << "(" << position.first << "," << position.second << ")";
        }
        if(!bug->isAlive())
        {
            outFile << " Eaten by " << bug->gotEatenBy();
        }
        outFile << endl;
    }
}

void Board::displayAllCells()
{
    updateCellOccupancy();

    for(int i = 0; i < grid.size(); ++i)
    {
        for(int j = 0; j < grid[i].size(); ++j)
        {
            cout << "(" << i << "," << j << "): ";
            if(grid[i][j].empty())
            {
                cout << "Empty";
            }
            else
            {
                for(Bug* bug: grid[i][j])
                {
                    cout << bug->getTypeasString() << " " << bug->getID() << ", ";
                }
            }
            cout << endl;
        }
    }
}

void Board::updateCellOccupancy()
{
    for(auto& row: grid)
    {
        for(auto& cell:row)
        {
            cell.clear();
        }
    }
}

std::string Board::getDateTimeString() const
{
    time_t now = time(0);
    tm* timeInfo = localtime(&now);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d_%H-%M-%S", timeInfo);
    return string(buffer);
}

