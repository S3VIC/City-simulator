#pragma once
#include<random>

class Citizen
{
  private:
    char colour;
    double X, Y;
    int happiness;
  public:
    Citizen();
    Citizen(const char _colour);
    const double getX();
    const double getY();
    void setX(double _X);
    void setY(double _Y);
    void changeX(double _X);
    void changeY(double _Y);
    const char getColour();
    void increaseHapp();
    void decreaseHapp();
    void resetHapp();
    int getHapp();
    virtual ~Citizen();
};


