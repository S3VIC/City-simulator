#pragma once
#include <iostream>
#include <vector>
#include "kibic.h"
#include <cmath>

class City
{
  private:
    int citizenNum;
    double procent;
    std::string cityName;
    std::vector<Kibic> citizens;
    int cityHappiness;

  public:
    City(std::string _cityName);
    City(int _N, int _p, std::string _cityName);
    void populateCity();
    void getCitizensPos();
    void calcTotCitizensHapp();
    void calcSinglCitizenHapp(Kibic& k1, Kibic& k2);
    void calcCityHapp();
    void resetCitizenHapp();
    int getCityHapp();
    void evolve();
    virtual ~City();
};


