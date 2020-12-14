#include <iostream>
#include <time.h>

using namespace std;

short int getUserInput(char& input);
short int returnRandom(const short int maxNumber, const short int minNumber);
void gameEnd(const short int input);

int main()
{
    srand(time(0));
    char input, input2;

    do
    {
        gameEnd(getUserInput(input) + returnRandom(3, 1));

        do {
            cout << "Would you like to go again? (Y, N): ";
                cin >> input2;
            input2 = toupper(input2);
        } while (input2 != 'Y' && input2 != 'N');

    } while (input2 == 'Y');

    return 0;
}

short int returnRandom(const short int maxNumber, const short int minNumber)
{
    return rand() % (maxNumber + 1 - minNumber) + minNumber;
}

short int getUserInput(char& input)
{
    do {
        cout << "Rock (R), Scissors (S), or Paper (P): ";
            cin >> input;
        input = toupper(input);
    } while (input != 'R' && input != 'S' && input != 'P');

    switch (input)
    {
        case 'R':
            return 10;
            break;
        case 'S':
            return 20;
            break;
        case 'P':
            return 30;
            break;
        default:
            cout << "\nError!\n";
            exit(0);
    }
}

void gameEnd(const short int input)
{
    switch (input)
    {
        case 11:
            cout << "\nTie!  Player: Rock  Computer: Rock\n\n";
            break;
        case 12:
            cout << "\nWin!  Player: Rock  Computer: Scissors\n\n";
            break;
        case 13:
            cout << "\nLose!  Player: Rock  Computer: Paper\n\n";
            break;
        case 21:
            cout << "\nLose!  Player: Scissors  Computer: Rock\n\n";
            break;
        case 22:
            cout << "\nTie!  Player: Scissors  Computer: Scissors\n\n";
            break;
        case 23:
            cout << "\nWin!  Player: Scissors  Computer: Paper\n\n";
            break;
        case 31:
            cout << "\nWin!  Player: Paper  Computer: Rock\n\n";
            break;
        case 32:
            cout << "\nLose!  Player: Paper  Computer: Scissors\n\n";
            break;
        case 33:
            cout << "\nTie!  Player: Paper  Computer: Paper\n\n";
            break;
        default:
            cout << "\nError!\n";
            exit(0);
    }
}
