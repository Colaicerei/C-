/***********************************************************************
** Program name: Zoo Tycoon
** Author:       Chen Zou
** Date:         19 April 2018
** Description:  This is the Animal class specification file, the Animal
		 class has five member variables: age, cost to purchase, 
		 number of babies, base food cost, and payoff. it also 
		 has get and set functions for the variables.
***********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
	protected:
   
		int age;  		//age of animal
		int cost;       //cost to purchase
		int numberOfBabies; //number of babies
		double baseFoodCost;	//base food cost
		double payoff;	//payoff per day of cost
				   		 
	public:
		Animal(int, int, double); //constructor takes cost, babies and payoff
		virtual ~Animal();
		int getAge();
		void setAge(int);
		int getCost();
		virtual double getFoodCost();
		int getNumberOfBabies();
		int getPayoff();
		void getOld();
		void setCost(int); 
		void setBabies(int);
		void setPayoff(double);
};
#endif
