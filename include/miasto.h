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
    std::vector<Citizen> citizens;
    int cityHappiness, evolutionNum;

  public:
    City(std::string _cityName);
    City(int _N, int _p, std::string _cityName, int _evolutionNum);
    void populateCity();
    void calcTotCitizensHapp();
    void calcSinglCitizenHapp(Citizen& k1, Citizen& k2);
    void calcCityHapp();
    void evolve();
    
    //  Setters
    void setName(std::string _cityName);
    void setCitizensNum(int _citizensNum);
    void setProcent(double _procent);
    void setEvolutionNum(int evolutionNum);
    void resetCitizenHapp();
    
    //  Getters
    int getCityHapp();
    int getCitizensNum();
    void getCitizensPos();
    std::vector<Citizen> getCitizens();
    
    virtual ~City();
};


