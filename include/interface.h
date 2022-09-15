#pragma once
#include<iostream>

class Interface
{
  
  public:
    Interface();
    void cityNameMessage();
    void citizensNumMessage();
    void redPercentageMessage();
    void evolutionsNumMessage();
    void displayWelcomeScreen();
    void initialDecision(int &decision);
    int plottingDecision();
    ~Interface();
};