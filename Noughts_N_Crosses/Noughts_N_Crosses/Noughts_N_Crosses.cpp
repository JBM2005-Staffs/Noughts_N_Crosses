#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
ASCII Art
\\  /
 \\/
 /\\
/  \\

/---\\
|    |
|    |
\\---/
*/

//Player 1 and Player 2

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
    Player player1;
    Player player2;
 

    cout << "          1       2       3   " << endl;
    cout << "             |  /---\\  |       " << endl;
    cout << "             |  |   |  |       " << endl;
    cout << " A           |  |   |  |       " << endl;
    cout << "             |  \\---/  |       " << endl;
    cout << "    ---------+---------+---------" << endl;
    cout << "             |         |       " << endl;
    cout << "             |         |       " << endl;
    cout << " B           |         |       " << endl;
    cout << "             |         |       " << endl;
    cout << "    ---------+---------+---------" << endl;
    cout << "      \\  /   |         |       " << endl;
    cout << " C     \\/    |         |       " << endl;
    cout << "       /\\    |         |       " << endl;
    cout << "      /  \\   |         |       " << endl;
    cout << " _   _                   _     _          ___   \n"
        << "| \\ | | ___  _   _  __ _| |__ | |_ ___   ( _ )  \n"
        << "|  \\| |/ _ \\| | | |/ _` | '_ \\| __/ __|  / _ \\/\n"
        << "| |\\  | (_) | |_| | (_| | | | | |_\\__ \\ | (_>  <\n"
        << "|_|_\\_|\\___/ \\__,_|\\__, |_| |_|\__|___/  \\___/\\/ \n"
        << " / ___|_ __ ___  __|___/  ___  ___              \n"
        << "| |   | '__/ _ \\/ __/ __|/ _ \\/ __|             \n"
        << "| |___| | | (_) \\__ \\__ \\  __/\\__ \\             \n"
        << " \\____|_|  \\___/|___/___/\\___||___/             \n\n"
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

    cout << player1.name << " would you like to be Xs or Os? (Type X or O)\n";
    cout << "> ";
    cin >> input;

    while (input != "X" || "x" || "O" || "o")
    {
        //on while Exit run this code
        if (input == "X" || "x")
        {
            player1.isX = true;
            player2.isO = true;
            cout << player1.name << " is X\n" << player2.name << "is O\n";
            break;
        }
        else if (input == "O" || "o")
        {
            player1.isO = true;
            player2.isX = true;
            cout << player1.name << " is O\n" << player2.name << "is X\n";
            break;
        }
        else
        {
            cin.clear();
            cout << "\n\nSorry I don't know what that is!\n" << "Please enter your prefered symbol\n" << "> ";
            cin >> input;
        }
    }

    cout << "         1        2        3     \n"
        << "             |         |         \n"
        << "             |         |         \n"
        << " A           |         |         \n"
        << "             |         |         \n"
        << "    ---------+---------+---------\n"
        << "             |         |         \n"
        << "             |         |         \n"
        << " B           |         |         \n"
        << "             |         |         \n"
        << "    ---------+---------+---------\n"
        << "             |         |         \n"
        << "             |         |         \n"
        << " C           |         |         \n"
        << "             |         |         \n"
        << "             |         |         \n\n";
    cout << player1.name << "'s turn!\n" << "Please select a grid position to start\n" << "> ";
    cin >> input;
    

}

