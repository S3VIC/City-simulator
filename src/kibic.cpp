#include "../include/kibic.h"

Citizen::Citizen()
{}
// Citizen constructor - assigns random coordinates to created citizen instance
// and sets its' initial happiness level to default value - 0
Citizen::Citizen(const char _colour)
  : colour(_colour)
{
  this->X = 10. * rand()/RAND_MAX;
  this->Y = 10. * rand()/RAND_MAX;
  this->happiness = 0;
}

// returns type of citizen
const char Citizen::getColour()
{
  return this->colour;
}

// returns X coordinate
const double Citizen::getX()
{
  return this->X;
}

// returns Y coordinate
const double Citizen::getY()
{
  return this->Y;
}

// increments citizen happiness level
void Citizen::increaseHapp()
{
  this->happiness ++;
}

// decrements citizen happiness level
void Citizen::decreaseHapp()
{
  this->happiness--;
}

// returns citizen happiness level
int Citizen::getHapp()
{
  return this->happiness;
}

// sets X coordinate
void Citizen::setX(double _X)
{
  this->X = _X;
}

// setes Y coordinate
void Citizen::setY(double _Y)
{
  this->Y = _Y;
}

// changes X coordinate 
void Citizen::changeX(double _X)
{
  this->X = this->X + _X;
}

// changes Y coordinate
void Citizen::changeY(double _Y)
{
  this->Y = this->Y + _Y;
}

// sets happiness level to its initial level - 0
void Citizen::resetHapp()
{
  this->happiness = 0;
}

Citizen::~Citizen()
{}
