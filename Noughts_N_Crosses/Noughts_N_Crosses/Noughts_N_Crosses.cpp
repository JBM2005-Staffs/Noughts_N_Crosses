#include <iostream>
#include <string>
using namespace std;

struct Player 
{
    string name;
    bool isX = false;
    bool isO = false;
};

char board[3][3] = { {'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'} };
 
char symbol = 'X'; // Current turn: 'X' or 'O'
int moves = 0;     // Count the number of moves made
bool draw = false;

void printGameBoard() {
    cout << "    |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "_____|_____|_____\n";
    cout << "    |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";       //Geeks for geeks had a different way to this, this concept I picked up from https://www.simplilearn.com/tutorials/cpp-tutorial/game-in-cpp
    cout << "_____|_____|_____\n";                                                                  // Lots of the methods I've found in my time researching how to make this,
    cout << "    |     |     \n";                                                                   // are very similar, this grid being quite popular which is why I'm also using it
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "    |     |     \n\n";
}

// Convert user input (1-9) into board coordinates
bool inputConversion(int choice, int& row, int& col) 
{
    if (choice < 1 || choice > 9) {
        return false; // Invalid input
    }
    row = (choice - 1) / 3; // Calculate row index
    col = (choice - 1) % 3; // Calculate column index
    return true;
}

// Check if the selected cell is empty
bool isMoveValid(int row, int col) 
{
    return board[row][col] != 'X' && board[row][col] != 'O';
}

// Update the board with the current player's symbol
void updateBoard(int row, int col) 
{
    board[row][col] = symbol;
}


void nextTurn() 
{
    symbol = (symbol == 'X') ? 'O' : 'X';       // Alternate between X and O (If X last turn, then O, and vice versa
}

bool checkWin() 
{

    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
        {
            return true;
        }
    }
    
    //Vertical Checks
    for (int i = 0; i < 3; i++) 
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
        {
            return true;
        }
    }
    
    //Horizontals too
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
    {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
    {
        return true;
    }
    return false;
}

int main() 
{
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
    cout << " _   _                   _     _          ___     \n"
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

    player1.isX = true;
    player2.isO = true;

    cout << player1.name << " will play as 'X'.\n";
    cout << player2.name << " will play as 'O'.\n";

    // Game Loop
    while (moves < 9) {
        printGameBoard();
        cout << "It's " << ((symbol == 'X') ? player1.name : player2.name) << "'s turn (" << symbol << ").\n";
        cout << "Enter the position (1-9): ";

        int choice;
        cin >> choice;

        int row, col;
        if (!inputConversion(choice, row, col) || !isMoveValid(row, col)) {
            cout << "Invalid move. Try again.\n";
            continue; // Retry the turn
        }

        // Make the move
        updateBoard(row, col);
        moves++;

        // Check for a winner
        if (checkWin()) 
        {
            printGameBoard();
            cout << ((symbol == 'X') ? player1.name : player2.name) << " WON!\n";
            cout << "Better luck next time " << ((symbol == 'X') ? player2.name : player1.name) << "!\n";   // Reverse them to get the inverse output. 
            return 0; // End the game
        }

        // Switch turns
        nextTurn();
    }

    printGameBoard();
    cout << "Game over! It's a draw.\n";
    return 0;
}
