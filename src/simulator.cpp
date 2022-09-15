#include "../include/simulator.h"

// Contstructor, defaults number of evolutions to 0;
Simulator::Simulator() : evolutionsNum(0) 
{}

// Creates Interface instance and takes first input from user which 
// defines whether the simulation will begin or the program will be closed
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

// takes each step required to fully proceed evolution process, and 
// displays information about each step of evolution - its' number and
// calculated city happiness
void Simulator::proceedEvolution(City* _myCity, int &evolutionNumber){
  printf("Evolution #%d:\n", evolutionNumber);
  _myCity->evolve();
  _myCity->resetCitizenHapp();
  _myCity->calcTotCitizensHapp();
  _myCity->calcCityHapp();
  int happ = _myCity->getCityHapp();
  printf("Happiness level: %d\n", happ);
}

// initializes city and if needed handles calls for evolution process
void Simulator::beginSimulation(City* _myCity, Interface* _myInterface){
  _myCity->populateCity();
  _myCity->calcTotCitizensHapp();
  _myCity->calcCityHapp();

  printf("Initial city happiness: %d\n", _myCity->getCityHapp());

  for(int i = 1; i <= this->evolutionsNum; i++)
    this->proceedEvolution(_myCity, i);
}

// destructor
Simulator::~Simulator(){}