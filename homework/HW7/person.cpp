#include "person.h"

Person::Person() : _name{ "Undefined" } {}
Person::Person(string name) : _name{ name } {}
Person::Person(const Person& p) : _name{ p._name } {}

string Person::getName() const { return _name; }

Person& Person::operator = (const Person& p)
{
	this->_name = p._name;
	return *this;
}

istream& operator >> (istream& in, Person& p)
{
	getline(in, p._name);

	return in;
}

ostream& operator << (ostream& out, const Person& p)
{
	out << p._name;

	return out;
}