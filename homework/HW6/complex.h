#pragma once

#include <iostream>

using namespace std;

class complex
{

protected:

    double _realPart;
    double _complexPart;

public:

    complex();
    complex(double realPart);
    complex(double realPart, double complexPart);

    friend ostream& operator << (ostream& out, const complex& c);       // Operator overloading.
    friend istream& operator >> (istream& in, complex& c);

    friend complex operator + (const complex& c1, const complex& c2);
    friend complex operator - (const complex& c1, const complex& c2);
    friend complex operator * (const complex& c1, const complex& c2);

    friend bool operator == (const complex& c1, const complex& c2);
};

const complex i(0, 1);                                                  // Defined constant i which is equivalent to sqrt(-1)

