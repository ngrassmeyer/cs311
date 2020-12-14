// CS 311 HW 1 
// Naive Array Factorial Calculator
// Name: Noah Grassmeyer

#include <iostream>

using namespace std;

const int MAX_DIGITS = 213237, MAX_NUMBER = 50000;

void getUserInput(int& input);
void getFactorial(int* factorialArray, const int input, int& distance);
void printFactorial(int* factorialArray, const int input, const int distance);

int main()
{
    int* factorialArray = new int[MAX_DIGITS](), input = 0, distance = 1;

    factorialArray[0] = 1;

    getUserInput(input);

    getFactorial(factorialArray, input, distance);

    printFactorial(factorialArray, input, distance);

    return 0;

    system("pause");
}

void getUserInput(int& input)
{

    do {
        if (!cin)                                                       // Stream objects have fail bits. If cin is not an integer, it will trip the fail bit.
        {                                                               // If the fail bit is set, the input stream will be cleared and we ignore the user pressing the enter key so it doesn't continue running the loop infdefinitely.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Enter a natural number up to " << MAX_NUMBER << ": ";
        cin >> input;
    } while (input > MAX_NUMBER || !cin);                               // If the number is either too large or the input stream fail bit is tripped (the input is not an integer), re-run the loop.
    cout << endl;
}

void getFactorial(int* factorialArray, const int input, int& distance)  // C++ cannot store integers large enough to accomodate larger factorials, so we must make use of arrays to store the values.
{                                                                       // We multiply accross the array and carry tens accross it to get to our factorial. 
    int i, j, value, tensCarry = 0;
    for (i = 2; i <= input; i++)
    {
        for (j = 0; j < distance; j++)
        {
            factorialArray[j] = (factorialArray[j] * i) + tensCarry;
            if (factorialArray[j] > 9)
            {
                tensCarry = factorialArray[j] / 10;
                factorialArray[j] %= 10;
            }
            else
                tensCarry = 0;
        }
        while (tensCarry)
        {
            factorialArray[distance] = tensCarry % 10;
            tensCarry /= 10;
            distance++;
        }
    }
}

void printFactorial(int* factorialArray, const int input, const int distance)
{
    cout << "The factorial of " << input << " is: ";

    for (int i = distance - 1; i >= 0; i--)
        cout << factorialArray[i];

    cout << "\nThis number is " << distance << " digits long!" << endl;
}
