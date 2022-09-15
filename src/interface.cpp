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
















/*void Interface::saveToFile(City& _city ){
  std::ofstream green;
  std::ofstream red;
  green.open("green.txt");
  red.open("red.txt");
  if(green.good() && red.good()){
    for(int i = 0; i < _city.getCitizensNum(); i++)
    {
      if(_city.getCitizens()[i].getColour() == 'r')
        red << _city.getCitizens()[i].getX() << "\t" << _city.getCitizens()[i].getY() << std::endl;
      else if(_city.getCitizens()[i].getColour() == 'g')
        green << _city.getCitizens()[i].getX() << "\t" << _city.getCitizens()[i].getY() << std::endl;
    } 
  }
  green.close();
  red.close();
}
*/
/*void Interface::plotData(){
  std::ofstream script;
  script.open("script.gp");
  if(script.good()){
    script << "plot \"red.txt\" with points pointtype 7,\"green.txt\" with points pointtype 7 \npause -1\"Press ENTER\"";
    script.close();
    system("gnuplot script.gp");
  }
}
*/
Interface::~Interface(){}