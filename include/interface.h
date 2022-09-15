#pragma once
#include<iostream>

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