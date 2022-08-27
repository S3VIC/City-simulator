#include "simulator.h"

Simulator::Simulator(){
  this->evolutionsNum = 0;
}

void Simulator::start(){
  Interface myInterface;
  
  int decision = 0; 
  myInterface.initialDecision(&decision);
  if(decision == 1)
  {
    City myCity = City(" ");
    this->setCityParams(&myInterface, &myCity);
    this->beginSimulation(&myCity, &myInterface);
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
  int evolutions = 0;
  scanf("%d", &evolutions);
  this->evolutionsNum = evolutions;
}

void Simulator::beginSimulation(City* _myCity, Interface* _myInterface){
  _myCity->populateCity();
  _myCity->calcTotCitizensHapp();
  _myCity->calcCityHapp();

  for(int i = 0; i < this->evolutionsNum; i++){
    printf("Evolution #%d:\n", i+1);
    _myCity->evolve();
    _myCity->resetCitizenHapp();
    _myCity->calcTotCitizensHapp();
    _myCity->calcCityHapp();
    int happ = _myCity->getCityHapp();
    printf("Happiness level: %d\n", happ);
  }
}

Simulator::~Simulator(){}