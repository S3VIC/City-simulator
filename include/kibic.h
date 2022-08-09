#pragma once
#include<random>

class Kibic
{
  private:
    char kolor;
    double X, Y;
  public:
    Kibic();
    Kibic(const char _kolor);
    const double getX();
    const double getY();
    const char getKolor();
    virtual ~Kibic();
};


