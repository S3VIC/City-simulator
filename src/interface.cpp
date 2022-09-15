#include "../include/interface.h"


Interface::Interface(){
  this->displayWelcomeScreen();
}

void Interface::displayWelcomeScreen(){
  system("clear");
  printf("##### City Simulator #####\n1. Initialize city\n2. exit");
}
void Interface::evolutionsNumMessage(){
    printf("Number of evolutions: ");
}

void Interface::redPercentageMessage(){
  printf("Red citizens percentage: ");
}

void Interface::citizensNumMessage(){
  printf("Citizens number: ");
}

void Interface::cityNameMessage(){
  printf("City name: ");
}

void Interface::initialDecision(int *decision){ 
  printf("\nSelect an option: ");
  scanf("%d", decision);
}

Interface::~Interface(){}