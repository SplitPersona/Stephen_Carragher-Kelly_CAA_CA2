#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    Board board;
    int choice;

    do
    {
        cout << "Welcome to Bugs Life, The Game" << endl;
        cout << "1. Initialize Bug Board" << endl;
        cout << "2. Display all bugs" << endl;
        cout << "3. Find a bug through ID" << endl;
        cout << "4. Tap the Bug Board" << endl;
        cout << "5. Display Bug Life History" << endl;
        cout << "6. Display all cells" << endl;
        cout << "7. Run Simulation" << endl;
        cout << "8. Exit & write history to file" << endl;

        cin >> choice;

        switch (choice)
        {
            case 1:
                board.initializeBugBoard("bugs.txt");
                break;
            case 2:
                board.displayAllBugs();
                break;
            case 3:
                int id;
                cout << "Enter ID: ";
                cin >> id;
                board.findBugByID(id);
                break;
            case 4:
                board.tapBuBoard();
                break;
            case 5:
                board.displayLifeHistory();
                break;
            case 6:
                board.displayAllCells();
                break;
            case 7:
                board.runSimulation();
                break;
            case 8:
                cout << "Exiting... " << endl;
                board.writeLifeHistoryToFile();
                break;
            default:
                cout << "Invalid choice please choose another" << endl;
                break;
        }
    } while(choice != 8);

    return 0;
}
