#pragma once
#include<iostream>
#include<fstream>
#include "miasto.h"
#include "kibic.h"

class Interface{
  public:
  Interface();
  // void inicjalizuj();
  void setParameters(std::string* nazwaMiasta, int* liczbaMieszkancow, int* procent, int* liczbaEwolucji);
  void cityNameMessage();
  void citizensNumMessage();
  void redPercentageMessage();
  void evolutionsNumMessage();
  void saveToFile(City& _city);
  void plotData();

  ~Interface();
};