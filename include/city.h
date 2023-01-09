#pragma once
#include<iostream>
#include<vector>
#include"citizen.h"
#include<cmath>

class City
{
	private:
		int citizensNumber;
		std::string cityName;
		std::vector<Citizen> citizensList;
		int cityHappiness;
	
	public:
		City(const int _citizensNumber, const std::string _cityName);
		void populateCity();
		void calculateTotalCitizensHappiness(); // it can be outside class???
		void calculateSingleCitizenHappiness(Citizen& citizen1, Citizen& citizen2);
			// above function also to move outside???
		void calculateCityHappiness();
		void evolveCity();
		void displayCitizensInfo();
};

