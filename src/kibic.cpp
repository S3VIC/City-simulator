#include "kibic.h"

Kibic::Kibic()
{}

Kibic::Kibic(const char _kolor)
  : kolor(_kolor)
{
  this->X = 25. * rand()/RAND_MAX;
  this->Y = 25. * rand()/RAND_MAX;
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


Kibic::~Kibic()
{}
