#pragma once
#include<random>

class Kibic
{
  private:
    char kolor;
    double X, Y;
    int zadowolenie;
  public:
    Kibic();
    Kibic(const char _kolor);
    const double getX();
    const double getY();
    const char getKolor();
    void zwiekszZadowolenie();
    void zmniejszZadowolenie();
    int getZadowolenie();
    virtual ~Kibic();
};


