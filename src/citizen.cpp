#include "../include/citizen.h"

Citien::Citizen()
{}

Citizen::Citizen(const char _type, const double _X, const double Y)
		: type(_type), X(_X), Y(_Y)
{}

// getters
const char Citizen::getType() { return this->type; }
const double Citizen::getX() { return this->X; }
const double Citizen::getY() { return this->Y; }
const int Citizen::getHapp() { return this->happiness; }

// modifiers
void Citizen::increaseHapp() { this->happiness++; }
void Citizen::decreaseHapp() { this->happiness--; }
void Citizen::resetHapp() { this->happiness = 0; }
void Citizen::moveCitizen(const double _X, const double _Y) 
{
	this->X = X + _X;
	this->Y = Y + _Y;
}

// setters
void Citizen::setCoordinates(const double _X, const double _Y)
{
	this->X = _X;
	this->Y = _Y;
}




