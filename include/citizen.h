#pragma once
#include<random>

class Citizen
{
	private:
		char type;	//citizen type
		double X, Y; //coordinates
		int happiness = 0; //citizens' wealth descriptor
	
	public:
		Citizen();
		Citizen(const char _type, const double _X, const double Y);
		virtual ~Citizen();

		//getters
		const char getType();
		const double getX();
		const double getY();
		const int getHapp();

		//setters
		void setX(const double _X);
		void setY(const double _Y);

		//modifiers
		void increaseHapp();
		void decreaseHapp();
		void resetHapp();
		void moveCitizen(const double _X, const double _Y)
		
}
