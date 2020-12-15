#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string _name;

public:
    Person();
    Person(string name);
    Person(const Person& p);

    string getName() const;

    Person& operator = (const Person& p);

    friend istream& operator >> (istream& in, Person& p);
    friend ostream& operator << (ostream& out, const Person& p);
};