#include "truck.h"

Truck::Truck() : Vehicle(), _loadCapacity{ 0 }, _towCapacity{ 0 } {}
Truck::Truck(string manufacturer, int cylinders, string owner, double loadCapacity, int towCapacity) : Vehicle{ manufacturer, cylinders, owner }, _loadCapacity{ loadCapacity }, _towCapacity{ towCapacity } {}
Truck::Truck(string manufacturer, int cylinders, Person owner, double loadCapacity, int towCapacity) : Vehicle{ manufacturer, cylinders, owner }, _loadCapacity{ loadCapacity }, _towCapacity{ towCapacity } {}
Truck::Truck(const Truck& t) : Vehicle{ t._manufacturer, t._cylinders, t._owner }, _loadCapacity{ t._loadCapacity }, _towCapacity{ t._towCapacity } {}

double Truck::getLoadCapacity() const { return _loadCapacity; }
int Truck::getTowCapacity() const { return _towCapacity; }

Truck& Truck::operator = (const Truck& t)
{
	this->_manufacturer = t._manufacturer;
	this->_cylinders = t._cylinders;
	this->_owner = t._owner;

	this->_loadCapacity = t._loadCapacity;
	this->_towCapacity = t._towCapacity;

	return *this;
}

istream& operator >> (istream& in, Truck& t)
{
	in >> t._manufacturer >> t._cylinders >> t._owner >> t._loadCapacity >> t._towCapacity;

	return in;
}

ostream& operator << (ostream& out, const Truck& t)
{
	out << t._manufacturer << " " << t._cylinders << " " << t._owner << " " << t._loadCapacity << " " << t._towCapacity;

	return out;
}