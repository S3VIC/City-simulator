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
    void setX(double _X);
    void setY(double _Y);
    void zmienX(double _X);
    void zmienY(double _Y);
    const char getKolor();
    void zwiekszZadowolenie();
    void zmniejszZadowolenie();
    void resetZadow();
    int getZadowolenie();
    virtual ~Kibic();
};


