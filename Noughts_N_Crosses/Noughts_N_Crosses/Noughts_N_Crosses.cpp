#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Player
{
public:
    string name;
    bool isX = false;
    bool isO = false;
};

string input;

int main()
{
    char board[3][3] = { { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' } };    //Thanks GeeksForGeeks!

    Player player1;
    Player player2;

    cout << "          1       2       3       " << endl
        << "             |  /---\\  |         " << endl
        << "             |  |   |  |          " << endl
        << " A           |  |   |  |          " << endl
        << "             |  \\---/  |         " << endl
        << "    ---------+---------+--------- " << endl
        << "             |         |          " << endl
        << "             |         |          " << endl
        << " B           |         |          " << endl
        << "             |         |          " << endl
        << "    ---------+---------+--------- " << endl
        << "      \\  /   |         |         " << endl
        << " C     \\/    |         |         " << endl
        << "       /\\    |         |         " << endl
        << "      /  \\   |         |         \n\n" << endl;
  cout  << " _   _                   _     _          ___     \n"
        << "| \\ | | ___  _   _  __ _| |__ | |_ ___   ( _ )         \n"
        << "|  \\| |/ _ \\| | | |/ _` | '_ \\| __/ __|  / _ \\/     \n"
        << "| |\\  | (_) | |_| | (_| | | | | |_\\__ \\ | (_>  <     \n"
        << "|_|_\\_|\\___/ \\__,_|\\__, |_| |_|\__|___/  \\___/\\/  \n"
        << " / ___|_ __ ___  __|___/  ___  ___                      \n"
        << "| |   | '__/ _ \\/ __/ __|/ _ \\/ __|                   \n"
        << "| |___| | | (_) \\__ \\__ \\  __/\\__ \\                \n"
        << " \\____|_|  \\___/|___/___/\\___||___/                  \n\n"
        << "           Jacob McGrath 2024 \n\n\n";

    cout << "Hello Players, what would you like to be called?\n";
    cout << "Player 1, enter your name\n";
    cout << "> ";
    getline(cin, player1.name);

    cout << player1.name << "\n\n";

    cout << "Player 2, enter your name\n";
    cout << "> ";
    getline(cin, player2.name);

    cout << player2.name << "\n\n";

    cout << player1.name << " Is X\n";
    cout << player2.name << " is O\n\n ";
    
    cout << "    1  2  3 \n"
        << "A     |  |   \n"
        << "    --+--+-- \n"
        << "B     |  |   \n"
        << "    --+--+-- \n"
        << "C     |  |   \n";


    cout << player1.name << "'s turn!\n" << "Please select a grid position (A1-C3) to start\n" << "> ";
    cin >> input;
    
      //Storing the data in the grid pos is easy because we can just put a boolean on if somethings in there, then we can assign that another bool of X or O depending whose turn it is
      //The difficult part is making a dynamic grid, we'd possibly need 2 grids, one saved in memory and another blank one to overlay on top
}
