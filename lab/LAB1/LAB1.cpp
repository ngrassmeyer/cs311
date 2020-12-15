// CS 311 LAB 1
// Sort Visualizer (Bubble Sort) and Random Array Generator
// Name: Noah Grassmeyer

#include <iostream>
#include <time.h>

using namespace std;

const int ARRAY_SIZE = 25, MAX_NUMBER = 15, MIN_NUMBER = 1;

void userChoice(int* arr);
void randomFillArray(int* arr);
void printArray(int* arr);
void bubbleSort(int* arr, const int choice);
void realSwap(int *inptOne, int *inptTwo);
void pretendSwap(int inptOne, int inptTwo);
void STLSwap(int *inptOne, int *inptTwo);

int main()
{
    int arr[ARRAY_SIZE] = { 0 };
    randomFillArray(arr);

    userChoice(arr);

    return 0;
}

void userChoice(int* arr)
{
    int choiceOne, choiceTwo;

    do {
        system("CLS");
        if (!cin)                                                       // From class. Stream objects have fail bits. If cin is not an integer, it will trip the fail bit.
        {                                                               // If the fail bit is set, the input stream will be cleared and we ignore the user pressing the enter key so it doesn't continue running the loop infinitely.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');        // "numeric_limits<streamsize>::max()" is the maximum amount of digits we are allowed to ignore. We stop ignoring after the delimiter "\n" which is equivalent to the enter key.
        }
        cout << "Which sort method would you like to use:\n1. Bubble Sort\n\nMake your choice: "; // I will be adding more sorts to this program as the semester goes on.
        cin >> choiceOne;
        cout << endl;
    } while (choiceOne > 1 || !cin || choiceOne < 0);

    switch (choiceOne)
    {
        case 1:
            do {
                system("CLS");
                if (!cin)                                                       // From class. Stream objects have fail bits. If cin is not an integer, it will trip the fail bit.
                {                                                               // If the fail bit is set, the input stream will be cleared and we ignore the user pressing the enter key so it doesn't continue running the loop infinitely.
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');        // "numeric_limits<streamsize>::max()" is the maximum amount of digits we are allowed to ignore. We stop ignoring after the delimiter "\n" which is equivalent to the enter key.
                }
                cout << "Which sort method would you like to use:\n1. Bubble Sort(Real Swap)\n2. Bubble Sort(Pretend Swap, Doesn't Actually Sort Anything)\n3. Bubble Sort(STL Swap)\n\nMake your choice: ";
                cin >> choiceTwo;
                cout << endl;
            } while (choiceTwo > 3 || !cin || choiceTwo < 0);
            bubbleSort(arr, choiceTwo);
            break;
    }
}

void randomFillArray(int* arr)
{
    srand(time(0));

    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand() % (MAX_NUMBER + 1 - MIN_NUMBER) + MIN_NUMBER;
}

void printArray(int* arr)                                                       // Visualizing the sort after each swap makes it immensely easier to understand how it works.
{                                                                               
    system("CLS");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << arr[i] << " ";
        for (int j = 0; j < arr[i]; j++)
            cout << "-";
        cout << endl;
    }
}

void bubbleSort(int* arr, const int choice)
{
    for (int i = 0; i < ARRAY_SIZE - 1; i++)
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                switch (choice)
                {
                    case 1:
                        realSwap(&arr[j], &arr[j + 1]);
                        break;
                    case 2:
                        pretendSwap(arr[j], arr[j + 1]);
                        break;
                    case 3:
                        STLSwap(&arr[j], &arr[j + 1]);
                        break;
                }
                printArray(arr);
            }
        }
}

void realSwap(int *inptOne, int *inptTwo)
{
    int temp = *inptOne;
    *inptOne = *inptTwo;
    *inptTwo = temp;
}

void pretendSwap(int inptOne, int inptTwo)
{
    int temp = inptOne;
    inptOne = inptTwo;
    inptTwo = temp;
}

void STLSwap(int *inptOne, int *inptTwo)
{
    swap(*inptOne, *inptTwo);
}
