#include "kibic.h"

Kibic::Kibic()
{}
// Konstruktor kibica, losowanie koordynatow, ustawianie poziomu zadowolenia na wartosc
// domyslna
Kibic::Kibic(const char _kolor)
  : kolor(_kolor)
{
  this->X = 10. * rand()/RAND_MAX;
  this->Y = 10. * rand()/RAND_MAX;
  this->zadowolenie = 0;
}

// zwraca oznaczenie kibica (przynaleznosc do jednej z 2 grup)
const char Kibic::getKolor(){
  return this->kolor;
}

// zwraca koordynat X
const double Kibic::getX(){
  return this->X;
}

// zwraca koordynat Y
const double Kibic::getY(){
  return this->Y;
}

// inkrementacja poziomu zadowolenia kibica
void Kibic::zwiekszZadowolenie(){
  this->zadowolenie ++;
}

// dekrementacja poziomu zadowolenia kibica
void Kibic::zmniejszZadowolenie(){
  this->zadowolenie --;
}

// zwraca wartosc poziomu zadowolenia kibica
int Kibic::getZadowolenie(){
  return this->zadowolenie;
}

// ustawia koordynat X
void Kibic::setX(double _X){
  this->X = _X;
}

// ustawia koordynat Y
void Kibic::setY(double _Y){
  this->Y = _Y;
}

// zmienia koordynat X o okreslona wartosc (podczas ewolucji miasta)
void Kibic::zmienX(double _X){
  this->X = this->X + _X;
}

// zmienia koordynat Y o okreslona wartosc (podczas ewolucji miasta)
void Kibic::zmienY(double _Y){
  this->Y = this->Y + _Y;
}

// przywraca zadowolenie kibica do wartosci domyslnej
void Kibic::resetZadow(){
  this->zadowolenie = 0;
}

Kibic::~Kibic()
{}
