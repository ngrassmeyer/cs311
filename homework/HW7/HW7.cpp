// CS 311 HW 7
// Class Inheritance
// Noah Grassmeyer

#include "truck.h"

int main()
{
    Truck t1;

    cout << t1 << endl;

    Truck t2{ "Toyota", 4, "John Appleseed", 0.8, 6800 };

    cout << t2 << endl;

    Truck t3{ t2 };

    cout << t3 << endl;

    t3 = t1;

    cout << t3 << endl;

}
