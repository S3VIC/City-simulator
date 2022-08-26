#pragma once
#include<iostream>
#include <vector>
#include "kibic.h"

class City
{
  private:
    int citizensNum;
    double procent;
    std::string cityName;
    std::vector<Citizen> citizens;
    int cityHappiness;

  public:
    City(std::string _cityName);
    City(int _N, int _p, std::string _cityName);
    void populateCity();
    void calcTotCitizensHapp();
    void calcSinglCitizenHapp(Citizen& k1, Citizen& k2);
    void calcCityHapp();
    void evolve();
    
    //  Setters
    void setName(const std::string _cityName);
    void setCitizensNum(const int _citizensNum);
    void setProcent(const double _procent);
  
    void resetCitizenHapp();
    
    //  Getters
    int getCityHapp();
    int getCitizensNum();
    void getCitizensPos();
    std::vector<Citizen> getCitizens();
    
    virtual ~City();
};


