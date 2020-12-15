#include "vehicle.h"

Vehicle::Vehicle() : _manufacturer{ "Undefined" }, _cylinders{ 0 } {}
Vehicle::Vehicle(string manufacturer, int cylinders, string name) : _manufacturer{ manufacturer }, _cylinders{ cylinders }, _owner{ name } {}
Vehicle::Vehicle(string manufacturer, int cylinders, Person owner) : _manufacturer{ manufacturer }, _cylinders{ cylinders }, _owner{ owner } {}
Vehicle::Vehicle(const Vehicle& v) : _manufacturer { v._manufacturer }, _cylinders{ v._cylinders }, _owner{ v._owner } {}

string Vehicle::getManufacturer() const { return _manufacturer; }
int Vehicle::getCylinders() const { return _cylinders; }
string Vehicle::getOwner() const { return _owner.getName(); }

Vehicle& Vehicle::operator = (const Vehicle& v)
{
	this->_manufacturer = v._manufacturer;
	this->_cylinders = v._cylinders;
	this->_owner = v._owner;

	return *this;
}

istream& operator >> (istream& in, Vehicle& v)
{
	in >> v._manufacturer >> v._cylinders >> v._owner;

	return in;
}

ostream& operator << (ostream& out, const Vehicle& v)
{
	out << v._manufacturer << " " << v._cylinders << " " << v._owner;

	return out;
}