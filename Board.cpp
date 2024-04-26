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

Board::Board() {

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
        << " " << bug->getSize() << " " << bug->getDirectionString()
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
            cout << "Direction: " << bug->getDirectionString() << endl;
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