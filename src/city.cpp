#include"../include/city.h"

City::City(const int _citizensNumber, const std::string _cityName)
	:	citizensNumber(_citizensNumber), cityName(_cityName)
{}

void City::populateCity()
{
	return;
}

void City::displayCitizensInfo()
{
	for(unsigned int i = 0; i < this->citizensList.size(); i++)
		std::cout << citizensList[i].getX() << "\t" << citizensList[i].getY() 
			<< "\t" << citizensList[i].getType() << std::endl;
}

void City::calculateSingleCitizenHappiness(Citizen& citizen1, Citizen& citizen2)
{
	const double c1Cord[] = {citizen1.getX(), citizen1.getY()};
	const double c2Cord[] = {citizen2.getX(), citizen2.getY()};
	double diffX = c2Cord[0] - c1Cord[0];
	double diffY = c2Cord[1] - c1Cord[1];

	double distanceSquared = diffX * diffX + diffY * diffY;
	double distance = sqrt(distanceSquared);
	bool ifTheSameType = citizen1.getType() == citizen2.getType();
	if(distance <= 2 && ifTheSameType)
	{
		citizen1.increaseHappiness();
		citizen2.increaseHappiness();
	}
	else if(distance <= 2 && !ifTheSameType)
	{
		citizen1.decreaseHappiness();
		citizen2.decreaseHappiness();
	}
	else
		return;
}




