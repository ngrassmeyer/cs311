// CS 311 HW 4
// ZipCode Class
// Noah Grassmeyer

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class ZipCode
{
    private:
        unsigned _zipcodeInteger;

        unsigned convertZipcodeStringToInteger(const string zipcodeString) const;
        string convertZipcodeIntegerToString(const unsigned zipcodeInteger) const;

    public:
        ZipCode() :
            _zipcodeInteger{ 00000 } {}

        ZipCode(const unsigned zipcodeInteger) :
            _zipcodeInteger{ zipcodeInteger } 
        {
            if ((zipcodeInteger > 99999) || (zipcodeInteger < 0))       // Makes sure the integer zip code passed is within the valid range.
            {
                cerr << "\nException ((zipcodeInteger > 99999) || (zipcodeInteger < 0))! ZipCode input not within valid range! Exiting program!\n";
                exit(1);
            }
        
        }

        ZipCode(const string zipcodeString) :
            _zipcodeInteger{ convertZipcodeStringToInteger(zipcodeString) } 
        {
            if (zipcodeString.length() != 27)        // Makes sure the string passed is 27 characters long.
            {
                cerr << "\nException zipcodeString.length() != 27! Invalid POSTNET input string! Exiting program!\n";
                exit(1);
            }
        }

        unsigned getZipcodeInteger() { return _zipcodeInteger; };
        string getZipcodeString() { return convertZipcodeIntegerToString(_zipcodeInteger); };
};

unsigned ZipCode::convertZipcodeStringToInteger(const string zipcodeString) const
{
    unsigned tens = 10000, zipcodeInteger = 0;
    vector<string> lookup{ "11000" , "00011" , "00101" , "00110" , "01001" , "01010" , "01100" , "10001", "10010" , "10100" };

    for (unsigned i = 1; i < 26; i += 5)
    {
        auto substringLocationInPOSTNETLookup = find(lookup.begin(), lookup.end(), zipcodeString.substr(i, 5));

        if (substringLocationInPOSTNETLookup == lookup.end())       // Makes sure the string passed is valid for every group of five chars before and after the trailing and leading ones.
        {
            cerr << "\nException substringLocationInPOSTNETLookup == lookup.end()! Invalid POSTNET input string! Exiting program!\n";
            exit(1);
        }

        zipcodeInteger += (substringLocationInPOSTNETLookup - lookup.begin()) * tens;

        tens /= 10;
    }

    return zipcodeInteger;
}

string ZipCode::convertZipcodeIntegerToString(const unsigned zipcodeInteger) const
{
    string zipcodeString = "1";
    unsigned tens = 10000;
    vector<string> lookup{ "11000" , "00011" , "00101" , "00110" , "01001" , "01010" , "01100" , "10001", "10010" , "10100" };

    for (unsigned i = 0; i < 5; i++)
    {
        zipcodeString += lookup[(zipcodeInteger / tens) - ((zipcodeInteger / (tens * 10)) * 10)];
        tens /= 10;
    }

    return zipcodeString + '1';
}

int main()
{
    string zipcodeString = "101010000110011000101000111";
    unsigned zipcodeInteger = 51321; // DO NOT WRITE LEADING ZEROES

    ZipCode z1{ zipcodeString };

    ZipCode z2{ zipcodeInteger };

    cout << setw(5) << setfill('0') << z1.getZipcodeInteger() << endl;

    cout << z1.getZipcodeString() << endl << endl;

    cout << setw(5) << setfill('0') << z2.getZipcodeInteger() << endl;

    cout << z2.getZipcodeString() << endl;

    return 0;
}
