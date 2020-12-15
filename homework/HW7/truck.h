#pragma once

#include "vehicle.h"

class Truck : public Vehicle
{
private:
	double _loadCapacity;
	int _towCapacity;

public:
	Truck();
	Truck(string manufacturer, int cylinders, string owner, double loadCapacity, int towCapacity);
	Truck(string manufacturer, int cylinders, Person owner, double loadCapacity, int towCapacity);
	Truck(const Truck& t);

	double getLoadCapacity() const;
	int getTowCapacity() const;

	Truck& operator = (const Truck& t);

	friend istream& operator >> (istream& in, Truck& t);
	friend ostream& operator << (ostream& out, const Truck& t);
};
