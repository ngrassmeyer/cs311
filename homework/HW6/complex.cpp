#include "complex.h"

complex::complex() : _realPart{ 0 }, _complexPart{ 0 } {}                    // Default constructor.
complex::complex(double realPart) : _realPart{ realPart }, _complexPart{ 0 } {}  // Parameterized Constructors
complex::complex(double realPart, double complexPart) : _realPart{ realPart }, _complexPart{ complexPart } {}

ostream& operator << (ostream& out, const complex& c)
{
    out << c._realPart << " + " << c._complexPart << "i";
    return out;
}

istream& operator >> (istream& in, complex& c)
{
    in >> c._realPart >> c._complexPart;
    return in;
}

complex operator + (const complex& c1, const complex& c2)
{
    return complex{ (c1._realPart + c2._realPart), (c1._complexPart + c2._complexPart) };
}

complex operator - (const complex& c1, const complex& c2)
{
    return complex{ (c1._realPart - c2._realPart), (c1._complexPart - c2._complexPart) };
}

complex operator * (const complex& c1, const complex& c2)
{
    return complex{ ((c1._realPart * c2._realPart) - (c1._complexPart * c2._complexPart)), ((c1._realPart * c2._complexPart) + (c1._complexPart * c2._realPart)) };
}

bool operator == (const complex& c1, const complex& c2)
{
    return ((c1._realPart == c2._realPart) && (c1._complexPart == c2._complexPart));
}

