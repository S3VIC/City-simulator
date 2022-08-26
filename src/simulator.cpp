#include "simulator.h"

Simulator::Simulator(){
  this->evolutionNum = 0;
}

City Simulator::initializeCity(){
  City myCity = City("test");
  
  return myCity;
}

void Simulator::startSimulation(){
  Interface myInterface;
  
  int decision = 0; 
  myInterface.initialDecision(&decision);
  if(decision == 1)
  {
    City myCity = City(" ");
    this->setCityParams(&myInterface, &myCity);
  }
  else if(decision == 2)
    exit(0);
  
}

void Simulator::setCityParams(Interface *_myInterface, City *myCity){
  _myInterface->cityNameMessage();
  std::string cityName = " ";
  std::cin >> cityName;
  myCity->setName(cityName); 
  
  _myInterface->citizensNumMessage();
  int citizensNum = 0;
  scanf("%d", &citizensNum);
  myCity->setCitizensNum(citizensNum);

  _myInterface->redPercentageMessage();
  double percentage = 0;
  scanf("%lf", &percentage);
  myCity->setProcent(percentage);

  _myInterface->evolutionsNumMessage();

}

Simulator::~Simulator(){}