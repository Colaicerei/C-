/*********************************************************************
**Program name: Zoo Tycoon
**Author:       Chen Zou
**Date: 	16 April 2018
**Description:  This is the header file for class Game, the Game class
		has functions to promote and get inputs to start the zoo, 
		and functions to simulate the activities including aging, 
		feeding, random events (sick, boom and birth) for the zoo. 
		It also calculates the expense and income for the day and
		promotes user to continue for next day or exit. The game is
		over if user has no money..      
**********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <cstdlib>
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "NewAnimal.hpp"

class Game
{
	private:
		double money;
		double expense;	// daily expense
		int income;		// daily income	
		int bonus;		// bonus for the day
		int tigerSize;	// current capacity of array
		int penguinSize;
		int turtleSize;
		int newAniSize; 
		Animal** tigers;	// array of pointers to hold tigers     
		Animal** penguins;  // array of pointers to penguins
		Animal** turtles;	// array of pointers to turtles
		Animal** newAnimals;// array of pointers to newAnis
		int tigerCount;		// current number of tigers
		int penguinCount;	// current number of penguins
		int turtleCount;	// current number of turtles 
		int newAnimalCount; // current number of newAnimals
		std::string newAniType; // new animal type of user choice
		int newAniCost;		// cost to purchase new animal
		int newAniBabies;	// babies the new animal will have each time
		double newAniFoodMP;	// food cost multiplier of new animal
		double newAniPayoff; 	// payoff rate of new animal
		std::string foodType;	// feed type of cheap, generic or premium
				

	public:
		Game();
		~Game();
		void showInstruction();
		void startZoo();	// get user input to start game 
		void ageIncrease();	// all animals increase age by 1
		void feeding();	// subtract feeding cost from money
		void event();	// select random events
		void sickness();	// an event which removes a sick animal 
		void boom();	// an event which generates bonus for each tiger 
		void birth();	// an event which a random animal give birth	
		void profit();   // calculate money made in a day
		void addAnimal(std::string, int); // add anumal to the array of its type
		void dayClose(); // accouting for the day and ask if buy new animal
		void play();     // run business for a day
		bool hasMoney(); // return if user has money
		bool hasAdult(std::string); // return if the animal type has adult
		void readFile(std::string); // displays message from file
			
};


#endif
