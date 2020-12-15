#include "complex.h"

using namespace std;

int main()
{
    complex c1;
    complex c2;

    cout << "Please enter two numbers, one real part and one complex part, separated by a space: ";
    cin >> c1;

    cout << "Please enter two numbers, one real part and one complex part, separated by a space: ";
    cin >> c2;

    cout << "\nMultiplied:\n" << c1 * c2 << endl;
    cout << "\nMultiplied and multiplied again against i (90 degrees about zero):\n" << c1 * c2 * i << endl;
    cout << "\nMultiplied and multiplied again against i^2 (180 degrees about zero):\n" << c1 * c2 * i * i << endl;
    cout << "\nMultiplied and multiplied again against i^3 (270 degrees about zero):\n" << c1 * c2 * i * i * i << endl;
    cout << "\nMultiplied and multiplied again against i^4 (360 degrees about zero):\n" << c1 * c2 * i * i * i * i << endl;
    cout << "\nAdded:\n" << c1 + c2 << endl;
    cout << "\nSubtracted:\n" << c1 - c2 << endl;

    cout << "\nAre They Equal?:\n";
    switch (c1 == c2)
    {
    case 0:
        cout << "No\n";
        break;
    case 1:
        cout << "Yes\n";
        break;
    }

    return 0;
}
