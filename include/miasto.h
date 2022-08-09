#pragma once
#include <iostream>
#include <vector>
#include "kibic.h"

class Miasto
{
  private:
    int liczbaMieszkancow;
    double procent;
    std::string nazwaMiasta;
    std::vector<Kibic> kibice;

  public:
    Miasto(std::string _nazwaMiasta);
    Miasto(int _N, int _p, std::string _nazwaMiasta);
    void zaludnijMiasto();
    void getPozycjeKibicow();
    virtual ~Miasto();
};


