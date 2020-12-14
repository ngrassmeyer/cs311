// CS 311 HW 2 P2
// Vector Tic Tac Toe
// Name: Noah Grassmeyer

#include <iostream>
#include <vector>

using namespace std;

void printVectorUpdate(vector<vector<char>>& ticTacToeTable, short int& input, const short int player);
void playerInput(short int &input, const short int player);
bool gameState(vector<vector<char>> ticTacToeTable, const short int player, const short int moves);


int main()
{
    short int input = 0, i = 0;
    vector<vector<char>>  ticTacToeTable{ { '1', '2', '3' },
                                      { '4', '5', '6' },
                                      { '7', '8', '9' } };

    printVectorUpdate(ticTacToeTable, input, 0);

    while (1)
    {
        playerInput(input, 1);
        printVectorUpdate(ticTacToeTable, input, 1);
        if (gameState(ticTacToeTable, 1, ++i))
            break;

        playerInput(input, 2);
        printVectorUpdate(ticTacToeTable, input, 2);
        if (gameState(ticTacToeTable, 2, ++i))
            break;
    }

    return 0;
}

void printVectorUpdate(vector<vector<char>>& ticTacToeTable, short int& input, const short int player)
{
    short int playerInputColumn = ((input - 1) % 3), playerInputRow = ((input - 1) / 3);

    switch(player)
    {
        case 0:
            break;
        case 1:
            while (ticTacToeTable[playerInputRow][playerInputColumn] == 'O' || ticTacToeTable[playerInputRow][playerInputColumn] == 'X')
            {
                cout << "\nThat space is already occupied.\n";
                playerInput(input, player);
                playerInputColumn = ((input - 1) % 3);                                                                                      // Maps 1-9 onto the 2d vector.
                playerInputRow = ((input - 1) / 3);
            }
            ticTacToeTable[playerInputRow][playerInputColumn] = 'X';
            break;
        case 2:
            while (ticTacToeTable[playerInputRow][playerInputColumn] == 'O' || ticTacToeTable[playerInputRow][playerInputColumn] == 'X')
            {
                cout << "\nThat space is already occupied.\n";
                playerInput(input, player);
                playerInputColumn = ((input - 1) % 3);
                playerInputRow = ((input - 1) / 3);
            }
            ticTacToeTable[playerInputRow][playerInputColumn] = 'O';
            break;
        default:
            cout << "\nError\n";
            exit(0);
    }

    cout << endl;

    for (short int i = 0; i < 3; i++)
    {
        for (short int j = 0; j < 3; j++)
        {
            cout << ticTacToeTable[i][j] << " ";
        }
        cout << endl;
    }
}

void playerInput(short int& input, const short int player)
{
    do {
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch(player)
        {
            case 1:
                cout << "\nYou are Player 1 with pieces X. Enter where on the board you would like to place your piece: ";
                break;
            case 2:
                cout << "\nYou are Player 2 with pieces O. Enter where on the board you would like to place your piece: ";
                break;
            default:
                cout << "\nError\n";
                exit(0);
        }
            cin >> input;
    } while (input > 9 || input < 0 || !cin);
}

bool gameState(vector<vector<char>> a, const short int player, const short int moves)
{
    if (moves == 9)                                                                                     // Check if tie.
    {
        cout << "\nDraw!\n";
        return 1;
    }

    if ((a[0][0] == a[1][1]) && (a[1][1] == a[2][2]) || (a[0][2] == a[1][1]) && (a[1][1] == a[2][0]))   // Check diagonals.
    {
        cout << "\nPlayer " << player << " wins! Moves: " << moves << endl;
        return 1;
    }

    for (short int i = 0; i < 3; i++)
    {
        if ((a[i][0] == a[i][1]) && (a[i][1] == a[i][2]))                                               // Check rows.
        {
            cout << "\nPlayer " << player << " wins! Moves: " << moves << endl;
            return 1;
        }
    }

    for (short int i = 0; i < 3; i++)
    {
        if ((a[0][i] == a[1][i]) && (a[1][i] == a[2][i]))                                               // Check columns.
        {
            cout << "\nPlayer " << player << " wins! Moves: " << moves << endl;
            return 1;
        }
    }

    return 0;
}
