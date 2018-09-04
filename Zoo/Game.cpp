/****************************************************************************
** Program name: Zoo Tycoon
** Author:       Chen Zou 
** Date:         20 April 2018
** Description:  This is the function impliementation file of the class Game,
         which asks user to purchase 1 or 2 animal types to start the 
		 business, it also allows user to buy and set new animal type
		 in addition to tiger, penguin and turtle. It will let user to 
		 run the zoo on daily basis, including feeding animals, having 
		 random events, then calculate the profit for the day. It then
		 promotes user to continue for next day or exit. The game is 
		 over if user has no money.
****************************************************************************/

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Game.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "NewAnimal.hpp"
#include "inputValidation.hpp"


// constructor
Game::Game()
{ 
	money = 100000;
	expense = 0;
	income = 0;
	bonus = 0;
	tigerSize = 10; // set the start capacity to 10
	penguinSize = 10;
	turtleSize = 10;
	newAniSize = 10;
	tigers = new Animal*[tigerSize];   //initialize with array of 10
	penguins = new Animal*[penguinSize];
	turtles = new Animal*[turtleSize];
	newAnimals = new Animal*[newAniSize];
	tigerCount = 0;
	penguinCount = 0;
	turtleCount = 0;
	newAnimalCount = 0;
	foodType = "";
	// initialize parameters for the new Animal 
	newAniType = " "; 
	newAniCost = 0;
	newAniBabies = 0;
	newAniFoodMP = 0;
	newAniPayoff = 0; 
}	


// destructor
Game::~Game()
{
	for(int i = 0; i < tigerCount; i++)
	{
		delete tigers[i];
	}
	delete [] tigers;

	for(int i = 0; i < penguinCount; i++)
	{
		delete penguins[i];
	}
	delete [] penguins;

	for(int i = 0; i < turtleCount; i++)
	{
		delete turtles[i];
	}
	delete [] turtles;

	for(int i = 0; i < newAnimalCount; i++)
	{
		delete newAnimals[i];
	}
	delete [] newAnimals;
	
}	


/***************************************************************************
** This function displays the instruction of the game.
***************************************************************************/
void Game::showInstruction()
{
	std::cout << "			WELCOME TO THE ZOO TYCOON GAME! \n"
		  << "You will run a zoo business with cute tigers, penguins and "
		  << "turtles, plus an animal you like. \nYou will have 100K to "
		  << "start the business. Let's see how much you can make!" 
		  << "\nRemember, you lose the game if you went bancrupt!\n"
		  << "Now, the game is starting now, enjoy playing!\n\n";

}


/***************************************************************************
** This function takes the number of animals to purchse from the user and 
   create those animals to start the business. The newly bought animals are
   one day old.
***************************************************************************/
void Game::startZoo()
{
	int tigerStart,		// start number of animals for the zoo
		penguinStart, 
		turtleStart, 
		newAnimalStart;  
		
	// promote user to buy animals to start the business
	std::cout << "We need 1 or 2 tigers, how many would you like to purchase?\n";
	getIntFromTwo(&tigerStart, 1, 2);
	
	std::cout << "We need 1 or 2 penguins, how many would you like to purchase?\n";
	getIntFromTwo(&penguinStart, 1, 2);
	
	std::cout << "We need 1 or 2 turtles, how many would you like to purchase?\n";
	getIntFromTwo(&turtleStart, 1, 2);

	std::cout << "What animal would you like to add to the zoo?\n";
	getWord(&newAniType);

	std::cout << "We need 1 or 2 of them, how many would you like to purchase?\n";
	getIntFromTwo(&newAnimalStart, 1, 2);
	
	std::cout << "How much does a " << newAniType << " cost?\n";
	getInt(&newAniCost);  

	std::cout << "How many babies does a " << newAniType << " have?\n";
	getInt(&newAniBabies);

	std::cout << "What is the multiplier of food cost for " << newAniType << "\n";
	getDouble(&newAniFoodMP);

	std::cout << "What is the payoff rate for " << newAniType << "\n";
	getDouble(&newAniPayoff);

	std::cout << "\nWhat food type will you use? Comparing to the generic food we are using,"
			  << "cheap food costs you half but doubles the chance of sickness for animals, "
			  << "premium food cost you twice but halves the chance of sickness for animals.\n"
			  << "Please enter your choice between cheap, generic or premium. ";
	getWord(&foodType);	
	
	// pay money and add animals of user specified numbers	
	for(int i = 0; i < tigerStart; i++)
	{
		tigers[i] = new Tiger();
	 	tigers[i]->setAge(1); 
		tigerCount++; 
	}
		money -= tigerCount * tigers[0]->getCost(); 
	
	for(int i = 0; i < penguinStart; i++)
	{
		penguins[i] = new Penguin();
	 	penguins[i]->setAge(1);
		penguinCount++;  
	}	
		money -= penguinCount * penguins[0]->getCost(); 
	
	for(int i = 0; i < turtleStart; i++)
	{

		turtles[i] = new Turtle();
	 	turtles[i]->setAge(1);
		turtleCount++;
	}	
		money -= turtleCount * turtles[0]->getCost(); 
	
	for(int i = 0; i < newAnimalStart; i++)
	{

		newAnimals[i] = new NewAnimal(newAniFoodMP);
	 	newAnimals[i]->setAge(1);
		newAnimals[i]->setCost(newAniCost); 
		newAnimals[i]->setBabies(newAniBabies);
		newAnimals[i]->setPayoff(newAniPayoff);
		
		newAnimalCount++;
	}
		money -= newAnimalCount * newAnimals[0]->getCost(); 


	/*for testing
	std::cout << "Tigers:\n"<< tigers[0]->getNumberOfBabies()<<std::endl;
	std::cout << tigers[0]->getFoodCost() << "\n\n";	
	std::cout << "Penguins: \n"<< penguins[0]->getNumberOfBabies()<<std::endl;
	std::cout<< penguins[0]->getFoodCost() << "\n\n";
	std::cout << "Turtles: \n"<< turtles[0]->getNumberOfBabies()<<std::endl;
	std::cout<< turtles[0]->getFoodCost() << "\n\n";
	std::cout << "New Animal: \n"<< newAnimals[0]->getCost()<<std::endl;
	std::cout<< newAnimals[0]->getFoodCost() <<"\n"
			  << newAnimals[0]->getPayoff() << "\n\n";
	*/		  
			  
}


/***************************************************************************
** This function asks user for choices, then validates and returns the choice
   until a valid input is entered.
***************************************************************************/ 	  
void Game::ageIncrease()
{
	//loop through the anumal lists and add age
	for(int i = 0; i < tigerCount; i++)
	{
		tigers[i]->getOld();
	}
	for(int i = 0; i < penguinCount; i++)
	{
		penguins[i]->getOld();
	}
	for(int i = 0; i < turtleCount; i++)
	{
		turtles[i]->getOld();
	}
	for(int i = 0; i < newAnimalCount; i++)
	{
		newAnimals[i]->getOld();
	}
}

/***************************************************************************
** This function calculates the expense in a day of the business
***************************************************************************/
void Game::feeding()
{
	expense = 0; //reset the daily expense to 0
	if(tigerCount > 0)
	{
		expense += tigerCount * tigers[0]->getFoodCost();	
	}
	
	if(penguinCount > 0)
	{
		expense += penguinCount * penguins[0]->getFoodCost();
	}
	
	if(turtleCount > 0)
	{
		expense += turtleCount * turtles[0]->getFoodCost();
	}

	if(newAnimalCount > 0)
	{
		expense += newAnimalCount * newAnimals[0]->getFoodCost();
	}
	
	// adjust food cost based on user specified foodtype
	if(foodType == "cheap")
	{
		expense = expense / 2.0;
	}
	else if(foodType == "premium")
	{
		expense = expense * 2;
	}
	else
	{
		expense = expense;
	}
	
	money -= expense;

}


/***************************************************************************
** This function randomly pick an event for the game, including 
   output the detailed results of each rounds. The function also displays
   the final score count and final winner at the end of the game.
***************************************************************************/
void Game::event()
{
	int event;
	// behave normal if feeding with generic food
	if(foodType == "generic")
	{
		event = rand() % 4 + 1;
		// for testing std::cout << "\nThe random event index is " << event << std::endl;
		switch(event)
		{
			case 1: sickness();
					break;
			case 2: boom();
					break;
			case 3: birth();
					break;
			case 4: std::cout << "It has been a quiet day and nothing happened!\n";						
		}
	}
	// twice the chance of sickness if feeding cheap food
	else if(foodType == "cheap")
	{
		event = rand() % 5 + 1;
		// for testig std::cout << "\nThe random event index is " << event << std::endl;
		switch(event)
		{
			case 1: sickness();
					break;
			case 2: sickness();		
					break;
			case 3: boom();
					break;
			case 4: birth();
					break;
			case 5: std::cout << "It has been a quiet day and nothing happened!\n";						
		}
	}
	// half the chance of sickness if feeding premium food
	else if(foodType == "premium")
	{
		event = rand() % 7 + 1;
		// for testig std::cout << "\nThe random event index is " << event << std::endl;
		switch(event)
		{
			case 1: sickness();
					break;
			case 2: boom();		
					break;
			case 3: boom();
					break;
			case 4: birth();
					break;
			case 5: birth();
					break;
			case 6: std::cout << "It has been a quiet day and nothing happened!\n";
					break;				
			case 7: std::cout << "It has been a quiet day and nothing happened!\n";	
		}					
	}
}	


/***************************************************************************
** This function randomly pick an animal and notify the user it is died of 
   sickness, and removes it from the list.
***************************************************************************/
void Game::sickness()
{
	// display message form file
	readFile("sickness.txt");
	
	// pick a random animal and remove from the list of its type
	// generate a random index from 0 to total animal number in the zoo
	int randomAnimal = rand() % (tigerCount + penguinCount + turtleCount);  
	
	// if the index <= tigercount, remove a tiger
	if(randomAnimal < tigerCount)
	{
		std::cout <<"We lost a tiger which died of sickness!\n";
		// tigers after the random tiger move a space forward 
		delete tigers[tigerCount - 1];		
		tigerCount--;
		std::cout<<"tiger numbers are now:" << tigerCount << "\n";
	} 
	// else if the index < total tiger and penguin, remove a penguin
	else if(randomAnimal < tigerCount + penguinCount)
	{
		std::cout <<"We lost a penguin which died of sickness!\n";
		// penguins after the random penguin move a space forward 
		delete penguins[penguinCount - 1];		
		penguinCount--;
		std::cout<<"penguin numbers are now:" << penguinCount << "\n";
	} 
	// else if the index < tiger and penguin and turtle counts, remove a turtle
	else if(randomAnimal < tigerCount + penguinCount + turtleCount)
	{
		std::cout <<"We lost a turtle which died of sickness!\n";
		// turtles after the random turtle move a space forward 
		delete turtles[turtleCount - 1];		
		turtleCount--;
		std::cout<<"turtle numbers are now:" << turtleCount << "\n";
	} 
	// else remove a newAnimal
	else
	{
		// convert index of animal to index of the newAnimal
		//int randomNewAni = randomAnimal - tigerCount - penguinCount - turtleCount; 
		std::cout <<"We lost a " << newAniType << " which died of sickness!\n";
		// newAnimals after the random new animal move a space forward 
		/*for(int i = randomNewAni; i < newAnimalCount-1; i++)
		{
			newAnimals[i] = newAnimals[i+1];
		}*/
		delete newAnimals[newAnimalCount - 1];		
		newAnimalCount--;
		std::cout<<"newAnimal numbers are now:" << newAnimalCount << "\n";
	} 	

	// 4testing: std::cout << "The random sickness index is " << randomAnimal << std::endl;
}


/***************************************************************************
** This function displays message about a boom in the zoo, and randomly 
   generates a bonus between 250 and 500 for each tiger as profit.
***************************************************************************/
void Game::boom()
{
	// display message form file
	readFile("boom.txt");
	
	// generate random bonus and multiplies tiger count
	bonus = tigerCount * (rand() % 251 + 250); 		
	std::cout << "You made " << bonus << " extra dollars for the "
			  << tigerCount << " tigers you own!\n";
}


/***************************************************************************
** This function randomly pick an adult animal to have babies and add the 
   number of babies specified for the animal type to the zoo.
***************************************************************************/
void Game::birth()
{
	// display message form file
	readFile("birth.txt");

	// check if there is an adult of any type in the zoo
	if(hasAdult("Tiger") || hasAdult("Penguin") || hasAdult("Turtle") || 
		  hasAdult(newAniType))
	{	  
		// pick a random animal type
		int type = rand() % 4 + 1;  
		//check if the type has adult, loop the random pick until find adult 
		while(true)
		{
			if(type == 1 && hasAdult("Tiger"))
			{
				std::cout <<"A baby tiger is born today!\n";
				addAnimal("Tiger", 0);		
				std::cout<<"tiger numbers are now:" << tigerCount <<"\n";
				break;
			}
			if(type == 2 && hasAdult("Penguin"))
			{
				std::cout <<"Five baby penguins are born today!\n";
				for(int i = 0; i < 5; i++)
				{
					addAnimal("Penguin", 0);					
				}
				std::cout<<"penguin numbers are now:" << penguinCount <<"\n";
				break;	
			}
			if(type == 3 && hasAdult("Turtle"))
			{
				std::cout <<"Ten baby turtles are born today!\n";
				for(int i = 0; i < 10; i++)
				{
					addAnimal("Turtle", 0);	
				}
				std::cout<<"turtle numbers are now:" << turtleCount <<"\n";
				break;	
			}
			if(type == 4 && hasAdult(newAniType))
			{
				std::cout << newAnimals[0]->getNumberOfBabies() << " baby " 
						  << newAniType << " are born today!\n";
				for(int i = 0; i < newAnimals[0]->getNumberOfBabies(); i++)
				{
					addAnimal(newAniType, 0);
				}			
				std::cout << newAniType << " numbers are now:" 
				  		  << newAnimalCount << "\n";
				break;	
			}
			type = rand() % 4 + 1;
		}	
	}
	else
	{
		std::cout << "Oops, there is no animal old enough to have baby!\n";
	}
}


/***************************************************************************
** This function calculates the income of the day.
***************************************************************************/
void Game::profit()
{
	income = 0; // reset the bonus for a new day
	if(tigerCount > 0)
	{
		income += tigerCount * tigers[0]->getPayoff();
	}
	if(penguinCount > 0)
	{
		income += penguinCount * penguins[0]->getPayoff();
	}
	if(turtleCount > 0)
	{
		income += turtleCount * turtles[0]->getPayoff();
	}
	if(newAnimalCount > 0)
	{
		income += newAnimalCount * newAnimals[0]->getPayoff();
	}
	
	income += bonus;  
}


/***************************************************************************
** This function takes an animal type and its age as parameter, and creates 
   a new animal based on the parameter, if the current capacity is reached,
   the function will double the capacity before create the new animal.
***************************************************************************/
void Game::addAnimal(std::string type, int age)
{
	if(type == "Tiger")
	{
		// check if current capacty is reached
		if(tigerCount == tigerSize)
		{
			// create new array with double size and 
			// copy existing tigers from the old array
			Animal** newTigers = new Animal*[tigerSize * 2];
			for(int i = 0; i < tigerSize; i++)
			{
				newTigers[i] = tigers[i];
			}
			// delete old array, old array point to new array
			delete[] tigers;
			tigers = newTigers;
			// update the maximum capacity
			tigerSize *= 2;	 
			std::cout << "tiger size is now " << tigerSize << "\n";
		}
		// add new tiger to the list
		tigers[tigerCount] = new Tiger();
		tigers[tigerCount]->setAge(age);
		tigerCount++;
	}
	else if(type == "Penguin")
	{
		// check if current capacty is reached
		if(penguinCount == penguinSize)
		{
			// create new array with double size and 
			// copy existing penguins from the old array
			Animal** newPenguins = new Animal*[penguinSize * 2];
			for(int i = 0; i < penguinSize; i++)
			{
				newPenguins[i] = penguins[i];
			}
			// delete old array, old array point to new array
			delete[] penguins;
			penguins = newPenguins;
			// update the maximum capacity
			penguinSize *= 2;	
			std::cout << "penguin size is now " << penguinSize << "\n"; 
		}
		// add new penguin to the list
		penguins[penguinCount] = new Penguin();
		penguins[penguinCount]->setAge(age);
		penguinCount++;
	}
	else if(type == "Turtle")
	{
		// check if current capacty is reached
		if(turtleCount == turtleSize)
		{
			// create new array with double size and 
			// copy existing turtles from the old array
			Animal** newTurtles = new Animal*[turtleSize * 2];
			for(int i = 0; i < turtleSize; i++)
			{
				newTurtles[i] = turtles[i];
			}
			// delete old array, old array point to new array
			delete[] turtles;
			turtles = newTurtles;
			// update the maximum capacity
			turtleSize *= 2;
			std::cout << "turtle size is now " << turtleSize << "\n";	 
		}
		// add new turtle to the list
		turtles[turtleCount] = new Turtle();
		turtles[turtleCount]->setAge(age);
		turtleCount++;
	}
	else
	{
		// check if current capacty is reached
		if(newAnimalCount == newAniSize)
		{
			// if no capacity, create new array with double size and 
			// copy existing turtles from the old array
			Animal** tempNewAnimals = new Animal*[newAniSize * 2];
			for(int i = 0; i < newAniSize; i++)
			{
				tempNewAnimals[i] = newAnimals[i];
			}
			// delete old array, old array point to new array
			delete[] newAnimals;
			newAnimals = tempNewAnimals;
			// update the maximum capacity
			newAniSize *= 2;	 
			std::cout << newAniType << " size is now " << newAniSize << "\n";
		}
		// add another newAnimal to the list
		newAnimals[newAnimalCount] = new NewAnimal(newAniFoodMP);
		newAnimals[newAnimalCount]->setAge(age);
		newAnimals[newAnimalCount]->setCost(newAniCost); 
		newAnimals[newAnimalCount]->setBabies(newAniBabies);
		newAnimals[newAnimalCount]->setPayoff(newAniPayoff);
		newAnimalCount++;
	}
}


/***************************************************************************
** This function displays the income and expense before the day ends, then 
   asks the player if they would like to buy an adult animal. If they do, 
   asks for the type of animal they would like, then adds the animal to the
   zoo and subtract that cost from the bank. 
***************************************************************************/
void Game::dayClose()
{
	money = money + income;
	int choice;
	int type;
	std::cout << "\nWe have reached the end of the day.\n"
			  << "\nToday's feeding costed $" << expense << ".\n"
			  << "Today's income is $" << income << ".\n"
			  << "You now have $" << money << " in the bank!\n"
			  << "\nWould you like to buy an adult animal? "
			  << "Enter 1 for Yes, 2 for No.\n";
	
	getIntFromTwo(&choice, 1, 2);
	if(choice == 1)
	{
		std::cout << "what type of animal would you like to buy?\n"
				  << "Enter 1 for tiger, 2 for penguin, 3 for turtle, 4 for "
				  << newAniType << ".\n";

		getIntInRange(&type, 1, 4);
		switch(type)
		{
			case 1: addAnimal("Tiger", 3);
					money -= 10000;
					break;
			case 2: addAnimal("Penguin", 3);
					money -= 1000;
					break;
			case 3: addAnimal("Turtle", 3);
					money -= 100;
					break;
			case 4: addAnimal(newAniType, 3);
					money -= newAniCost;		
		}
						
	}
	else	
	{
		std::cout << "You have chosn not to buy any animal today.\n";
	}
}


/***************************************************************************
** This function checks if user has money and return the financial status.
***************************************************************************/
void Game::play()
{
	ageIncrease();
	
	feeding();
	event();
	
	profit();
	dayClose();

	/* for testing
	std::cout << "Tiger count: " << tigerCount <<" Penguin count: " << penguinCount
			<< " Turtle count: " << turtleCount << " New Ani Count " << newAnimalCount;
	std::cout<<"\nArray size" << tigerSize << "," << penguinSize << "," 
			  << turtleSize << "," << newAniSize << std::endl; */
			  		
}


/***************************************************************************
** This function checks if user has money and return the financial status.
***************************************************************************/
bool Game::hasMoney()
{
	if(money > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}	


/***************************************************************************
** This function takes an animal type as parameter and checks and returns 
   true if there is an adult of that type.
***************************************************************************/
bool Game::hasAdult(std::string type)
{
	bool oldEnough = false;
	if(type == "Tiger")
	{
		for(int i = 0; i < tigerCount; i++)
		{
			if(tigers[i]->getAge() >= 3)
			{
				oldEnough =  true;
			}	
		}
	}
	else if(type == "Penguin")
	{
		for(int i = 0; i < penguinCount; i++)
		{
			if(penguins[i]->getAge() >= 3)
			{
				oldEnough =  true;
			}	
		}
	}
	else if(type == "Turtle")
	{
		for(int i = 0; i < turtleCount; i++)
		{
			if(turtles[i]->getAge() >= 3)
			{
				oldEnough =  true;
			}	
		}
	}
	else if(type == newAniType)
	{
		for(int i = 0; i < newAnimalCount; i++)
		{
			if(newAnimals[i]->getAge() >= 3)
			{
				oldEnough =  true;
			}	
		}	
	}
	else
	{
		std::cout << "We donot have this animal type, please check!\n";
	}
	return oldEnough; 
}



/***************************************************************************
** This function takes a filename as parameter and displays message reading 
   from the file.
***************************************************************************/
void Game::readFile(std::string fileName)
{
	// open input file of the birth event
	std::ifstream inputFile;
	inputFile.open(fileName);

	// check if file is sucessfully opened
	if(!inputFile)
	{	
		std::cout << fileName << " could not be opened! "
				  << "It's about a great news." << std::endl;
	}	

	// read and display characters from file until the end of file 
	char ch = inputFile.get();
	while(ch != EOF)
	{ 
		std::cout << ch;
		ch = inputFile.get();
	}

	inputFile.close(); //close input file
}