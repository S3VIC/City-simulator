#include "kibic.h"

Citizen::Citizen()
{}
// Konstruktor kibica, losowanie koordynatow, ustawianie poziomu zadowolenia na wartosc
// domyslna
Citizen::Citizen(const char _colour)
  : colour(_colour)
{
  this->X = 10. * rand()/RAND_MAX;
  this->Y = 10. * rand()/RAND_MAX;
  this->happiness = 0;
}

// zwraca oznaczenie kibica (przynaleznosc do jednej z 2 grup)
const char Citizen::getColour(){
  return this->colour;
}

// zwraca koordynat X
const double Citizen::getX(){
  return this->X;
}

// zwraca koordynat Y
const double Citizen::getY(){
  return this->Y;
}

// inkrementacja poziomu zadowolenia kibica
void Citizen::increaseHapp(){
  this->happiness ++;
}

// dekrementacja poziomu zadowolenia kibica
void Citizen::decreaseHapp(){
  this->happiness --;
}

// zwraca wartosc poziomu zadowolenia kibica
int Citizen::getHapp(){
  return this->happiness;
}

// ustawia koordynat X
void Citizen::setX(double _X){
  this->X = _X;
}

// ustawia koordynat Y
void Citizen::setY(double _Y){
  this->Y = _Y;
}

// zmienia koordynat X o okreslona wartosc (podczas ewolucji miasta)
void Citizen::zmienX(double _X){
  this->X = this->X + _X;
}

// zmienia koordynat Y o okreslona wartosc (podczas ewolucji miasta)
void Citizen::zmienY(double _Y){
  this->Y = this->Y + _Y;
}

// przywraca zadowolenie kibica do wartosci domyslnej
void Citizen::resetHapp(){
  this->happiness = 0;
}

Citizen::~Citizen()
{}
