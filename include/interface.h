#pragma once
#include<iostream>
#include "miasto.h"
#include "kibic.h"

class Interface{
  public:
    Interface();
    void cityNameMessage();
    void citizensNumMessage();
    void redPercentageMessage();
    void evolutionsNumMessage();
  //void saveToFile(City& _city);
  //void plotData();
    void displayWelcomeScreen();
    void initialDecision(int *decision);
    ~Interface();
};