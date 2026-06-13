#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Hero {
private:
	int strength;
	int courage;
	string name;

public:

Hero(string heroName) //CONSTRUCTOR for heroName, strength and courage. initialized hero
{ 
	name = heroName;

	strength = rand() % 100 + 1; // Random strength between 1 and 100
	courage = rand() % 100 + 1; // Random courage between 1 and 100
}

int getStrength() //GETTERS for the three that were just constructed
{
	return strength;
}

int getCourage()
{
	return courage;
}
	
string getName() 
{ 
	return name; 
}

void setCourage (int c) // SETTER for courage without returning, since it only needs to be stored
{
	courage = c;
}

void training(int hours) //SETTER function for increasing strength
{
	strength += hours * 5; // Each hour of training increases strength by 5
}

void therapy () //SETTER function for increasing courage
{
	courage += rand() % 11 + 5; // thrapy randomly increases courage by 5 to 15 points
}
};




void quest (Hero &hero) //QUEST function to test hero 
{
	int roll = rand() % 100;
	int strength = hero.getStrength();

if (roll < hero.getStrength() / 2) //successful quest
{
	hero.setCourage(hero.getCourage() - 5); // decrease courage by 5 points for a successful quest
	
	
	cout << hero.getName() << " successfully completed the quest!" << endl;
}
else if (roll < hero.getStrength()) //neutral quest
{
	hero.setCourage(hero.getCourage() - 10); // decrease courage by 10 points for a neutral quest


	cout << hero.getName() << " completed the quest, but it was a tough one." << endl;
}
else //failed quest
{
	hero.setCourage(hero.getCourage() - 20); // decrease courage by 20 points for a failed quest

	cout << hero.getName() << " failed the quest." << endl;
}


};






int main() 
{
	Hero hero1("Alex"); // Create a hero named Alex
	Hero hero2("Sneji"); // Create a hero named Sneji
	Hero hero3("Daniel"); // Create a hero named Daniel
	Hero hero4("Kevin"); // Create a hero named Kevin

	//Training the four heroes
	hero1.training(4); // Alex trains for 4 hours
	hero2.training(3); // Sneji trains for 3 hours
	hero3.training(5); // Daniel trains for 5 hours
	hero4.training(2); // Kevin trains for 2 hours

	//Therapy for the four heroes
	hero1.therapy();
	hero2.therapy();
	hero3.therapy();
	hero4.therapy();

	// Quests
	quest(hero1);
	quest(hero2);
	quest(hero3);
	quest(hero4);

	// More actions to show repeated use
	hero1.training(2);
	hero2.therapy();
	quest(hero2);
	quest(hero1);

	//Final Stats
	cout << "\nFinal Hero Stats:\n";

	cout << hero1.getName()
		<< " | Strength: " << hero1.getStrength()
		<< " | Courage: " << hero1.getCourage()
		<< endl;

	cout << hero2.getName()
		<< " | Strength: " << hero2.getStrength()
		<< " | Courage: " << hero2.getCourage()
		<< endl;

	cout << hero3.getName()
		<< " | Strength: " << hero3.getStrength()
		<< " | Courage: " << hero3.getCourage()
		<< endl;

	cout << hero4.getName()
		<< " | Strength: " << hero4.getStrength()
		<< " | Courage: " << hero4.getCourage()
		<< endl;

   return 0;
}