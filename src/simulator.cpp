#include "../include/simulator.h"
#include <fstream>
#include <string>

// Contstructor, defaults number of evolutions to 0;
Simulator::Simulator() : evolutionsNum(0) 
{}

// Creates Interface instance and takes first input from user which 
// defines whether the simulation will begin or the program will be closed
void Simulator::start()
{
  Interface myInterface;
  
  int decision = 0; 
  myInterface.initialDecision(decision);
  if(decision == 1)
  {
    City myCity = City(" ");
    this->setCityParams(&myInterface, &myCity);
    this->beginSimulation(&myCity, &myInterface);
  }
  else if(decision == 2)
    exit(0);
}

void Simulator::setCityParams(Interface *_myInterface, City *_myCity)
{
  _myInterface->cityNameMessage();
  std::string cityName = " ";
  std::cin >> cityName;
  _myCity->setName(cityName); 
  
  _myInterface->citizensNumMessage();
  int citizensNum = 0;
  scanf("%d", &citizensNum);
  _myCity->setCitizensNum(citizensNum);

  _myInterface->redPercentageMessage();
  double percentage = 0;
  scanf("%lf", &percentage);
  _myCity->setProcent(percentage);

  _myInterface->evolutionsNumMessage();
  int evolutions = 0;
  scanf("%d", &evolutions);
  this->evolutionsNum = evolutions;
}

// takes each step required to fully proceed evolution process, and 
// displays information about each step of evolution - its' number and
// calculated city happiness
void Simulator::proceedEvolution(City *_myCity, int &evolutionNumber)
{
  printf("Evolution #%d:\n", evolutionNumber);
  _myCity->evolve();
  _myCity->resetCitizenHapp();
  _myCity->calcTotCitizensHapp();
  _myCity->calcCityHapp();
  int happ = _myCity->getCityHapp();
  printf("Happiness level: %d\n", happ);
}

// initializes city and if needed handles calls for evolution process
void Simulator::beginSimulation(City *_myCity, Interface *_myInterface)
{ 
  int decision = 0;
  decision = _myInterface->plottingDecision();
  switch(decision)
  {
    case 1:
      simulateWithFullPlotting(_myCity);
      break;
    case 2: 
      simulateWithPartialPlotting(_myCity);
      break;
    case 3: 
      simulateWithoutPlotting(_myCity);
      break;
    default: 
      printf("Wrong choice!");
      exit(0);
  }  
}

void Simulator::saveToFile(City &myCity)
{
  std::string greenFileName = "green.txt", redFileName = "red.txt";
  std::ofstream green;
  std::ofstream red;

  green.open(greenFileName);
  red.open(redFileName);

  if(green.good() && red.good())
  {
    for(int i = 0; i < myCity.getCitizensNum(); i++)
    {
      if(myCity.getCitizens()[i].getColour() == 'r')
        red << myCity.getCitizens()[i].getX() << "\t" << 
          myCity.getCitizens()[i].getY() << std::endl;
      else if(myCity.getCitizens()[i].getColour() == 'g')
        green << myCity.getCitizens()[i].getX() << "\t" << 
          myCity.getCitizens()[i].getY() << std::endl;
    }
  }
  green.close();
  red.close();
}

void Simulator::plotData()
{
  std::ofstream script;
  std::string scriptFileName = "script.gp";
  script.open(scriptFileName);

  if(script.good())
  {
    script << "plot \"red.txt\" with points pointtype 7,\"green.txt\" with points pointtype 7 \npause -1\"Press ENTER\"";
    script.close();
    system("gnuplot script.gp");
  }
}

void Simulator::simulateWithFullPlotting(City *myCity)
{
  myCity->populateCity();
  myCity->calcTotCitizensHapp();
  myCity->calcCityHapp();
  printf("Initial city happiness: %d\n", myCity->getCityHapp());
  saveToFile(*myCity);
  plotData();
  
  for(int i = 1; i <= this->evolutionsNum; i++)
  {  
    this->proceedEvolution(myCity, i);
    saveToFile(*myCity);
    plotData();
  }
}

void Simulator::simulateWithPartialPlotting(City *myCity)
{
  myCity->populateCity();
  myCity->calcTotCitizensHapp();
  myCity->calcCityHapp();
  printf("Initial city happiness: %d\n", myCity->getCityHapp());
  saveToFile(*myCity);
  plotData();

  for(int i = 1; i <= this->evolutionsNum; i++)
    this->proceedEvolution(myCity, i);
    
  saveToFile(*myCity);
  plotData();
}

void Simulator::simulateWithoutPlotting(City *myCity)
{
  myCity->populateCity();
  myCity->calcTotCitizensHapp();
  myCity->calcCityHapp();
  printf("Initial city happiness: %d\n", myCity->getCityHapp());

  for(int i = 1; i <= this->evolutionsNum; i++)
    this->proceedEvolution(myCity, i);
}

// destructor
Simulator::~Simulator()
{}