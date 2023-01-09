#include "../include/citizen.h"

Citizen::Citizen()
{}

Citizen::Citizen(const char& _type, const double& _X, const double& _Y)
		: type(_type), X(_X), Y(_Y)
{}

Citizen::~Citizen()
{}

// getters
const char Citizen::getType() { return this->type; }
const double Citizen::getX() { return this->X; }
const double Citizen::getY() { return this->Y; }
const int Citizen::getHapp() { return this->happiness; }

// modifiers
void Citizen::increaseHappiness() { this->happiness++; }
void Citizen::decreaseHappiness() { this->happiness--; }
void Citizen::resetHappiness() { this->happiness = 0; }
void Citizen::moveCitizen(const double& _X, const double& _Y) 
{
	this->X = X + _X;
	this->Y = Y + _Y;
}

// setters
void Citizen::setCordinates(const double& _X, const double& _Y)
{
	this->X = _X;
	this->Y = _Y;
}




