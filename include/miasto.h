#pragma once
#include <iostream>
#include <vector>
#include "kibic.h"
#include <cmath>

class Miasto
{
  private:
    int liczbaMieszkancow;
    double procent;
    std::string nazwaMiasta;
    std::vector<Kibic> kibice;
    int zadowolenieMiasta;

  public:
    Miasto(std::string _nazwaMiasta);
    Miasto(int _N, int _p, std::string _nazwaMiasta);
    void zaludnijMiasto();
    void getPozycjeKibicow();
    void wyznaczCalkZadowKibicow();
    void wyznaczZadowKibica(Kibic& k1, Kibic& k2);
    void wyznaczZadowMiasta();
    int getZadowolenieMiasta();
    virtual ~Miasto();
};


