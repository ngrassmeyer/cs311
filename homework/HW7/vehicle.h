#pragma once

#include "person.h"

class Vehicle
{
protected:
	string _manufacturer;
	int _cylinders;
	Person _owner;

public:
	Vehicle();
	Vehicle(string manufacturer, int cylinders, string name);
	Vehicle(string manufacturer, int cylinders, Person owner);
	Vehicle(const Vehicle& v);

	string getManufacturer() const;
	int getCylinders() const;
	string getOwner() const;

	Vehicle& operator = (const Vehicle& v);

	friend istream& operator >> (istream& in, Vehicle& v);
	friend ostream& operator << (ostream& out, const Vehicle& v);

};