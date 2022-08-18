#include "kibic.h"

Kibic::Kibic()
{}

Kibic::Kibic(const char _kolor)
  : kolor(_kolor)
{
  this->X = 10. * rand()/RAND_MAX;
  this->Y = 10. * rand()/RAND_MAX;
  this->zadowolenie = 0;
}

const char Kibic::getKolor(){
  return this->kolor;
}

const double Kibic::getX(){
  return this->X;
}

const double Kibic::getY(){
  return this->Y;
}

void Kibic::zwiekszZadowolenie(){
  this->zadowolenie ++;
}

void Kibic::zmniejszZadowolenie(){
  this->zadowolenie --;
}

int Kibic::getZadowolenie(){
  return this->zadowolenie;
}

void Kibic::setX(double _X){
  this->X = _X;
}

void Kibic::setY(double _Y){
  this->Y = _Y;
}

void Kibic::zmienX(double _X){
  this->X = this->X + _X;
}

void Kibic::zmienY(double _Y){
  this->Y = this->Y + _Y;
}

void Kibic::resetZadow(){
  this->zadowolenie = 0;
}
Kibic::~Kibic()
{}
