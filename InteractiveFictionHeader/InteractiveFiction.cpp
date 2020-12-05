#include "InteractiveFiction.h"

#include <iostream> //Used to display messages to the console
#include <string>

using namespace std; //Global declaration to shorten many common commands throughout the code

void Scenario1(int currentHealth) //Tells the first part of the story
{
	cout << "You are a brave adventurer who has just entered a forest with " << currentHealth << " health.\n";
	char response = Story("All of a sudden, you are surrounded by bees. They are about to catch you! What do you do??\nA: Swat at them.\nB: Outrun them.\n");

	if (response == 'a' || response == 'A') //Deals damage to the player if they choose A
	{
		currentHealth = Health(currentHealth, 50);
		cout << "You cannot fight bees. You have taken 50 health and are now down to " << currentHealth << " health left.";
	}
	if (response == 'b' || response == 'B') //Deals damage to the player if they choose B
	{
		currentHealth = Health(currentHealth, 30);
		cout << "You cannot outrun bees. You have taken 30 health and are now down to " << currentHealth << " health left.";
	}

	DeathCheck(currentHealth); //Tests for player death

	//Passes the final amount of health from scenario 1 into scenario 2 and starts it
	Scenario2(currentHealth);
}

void Scenario2(int currentHealth) //Tells the second part of the story
{
	cout << "\n\nBarely surviving the bees, you see a glowing red potion.\n";
	char response = Story("What do you do?\nA: Drink the potion.\nB: Ignore it. It's probably evil.\n");

	if (response == 'a' || response == 'A') //Kills the player if they choose option A
	{
		currentHealth = Health(currentHealth, -20);
		cout << "\nFor once, it wasn't evil. You regain 20  health!";
		cout << "\nYou now have " << currentHealth << " health.\n";
	}
	if (response == 'b' || response == 'B') //Ends the game successfully if the player chooses option B
	{
		cout << "\nYou walk past the glowing potion.\n";
	}

	DeathCheck(currentHealth); //Tests for player death

	//Passes the final amount of health from scenario 2 into scenario 3 and starts it
	Scenario3(currentHealth);
}

void Scenario3(int currentHealth) //Tells the third part of the story
{
	cout << "\n\nWith that out of the way, you become tired.\n";
	char response = Story("What do you do?\nA: Get some sleep.\nB: Keep moving, this story is clearly dangerous.\n");

	if (response == 'a' || response == 'A') //Kills the player if they choose option A
	{
		currentHealth = Health(currentHealth, -20);
		cout << "\nYou feel rejuvenated after a good rest and gained 20 health.\n";
		cout << "You now have " << currentHealth << " health.\n";
	}
	if (response == 'b' || response == 'B') //Ends the game successfully if the player chooses option B
	{
		currentHealth = Health(currentHealth, 20);
		cout << "\nTo prove how brave you are, you stay awake and start to tire.\n";
		cout << "You lose 20 health, leaving you with " << currentHealth << " health left.\n";
	}

	DeathCheck(currentHealth); //Tests for player death

	//Passes the final amount of health from scenario 3 into scenario 4 and starts it
	Scenario4(currentHealth);
}

void Scenario4(int currentHealth) //Tells the fourth part of the story
{
	cout << "\n\nWith the worst ahead of you, you see a raging volcano.\n";
	char response = Story("What do you do?\nA: Investigate the Volcano.\nB: Go home, it's been a rough day.\n");

	if (response == 'a' || response == 'A') //Kills the player if they choose option A
	{
		currentHealth = Health(currentHealth, 100);
		cout << "\nThe volcano is a volcano. You melt, taking 100 damage.";
	}
	if (response == 'b' || response == 'B') //Ends the game successfully if the player chooses option B
	{
		cout << "\nYou go home and enjoy a peaceful life. Adventuring wasn't fun anyway.\n\n\n";
	}

	DeathCheck(currentHealth); //Tests for player death
}

/// <summary>
/// Returns player's current health after applying damage taken.
/// </summary>
/// <param name="damageTaken"></param>
/// <returns></returns>
int Health(int currentHealth, int damageTaken)
{
	return currentHealth - damageTaken; //Subtracts health taken in from damage taken in
}


/// <summary>
/// Type in story requiring choice A or B here. Awaits user input.
/// </summary>
/// <param name="story"></param>
/// <returns></returns>
char Story(string story)
{
	char response; //Creates a variable for the player's response
	do
	{
		cout << story; //Displays the story that the function is given
		cin >> response; //Awaits player response for only a or b
	} while (response != 'a' && response != 'A' && response != 'b' && response != 'B'); //Loops until proper input
	return response; //Returns the response the player gives from the function
}

/// <summary>
/// Checks for health being above 0. If not, it ends the narrative.
/// </summary>
/// <param name="currentHealth"></param>
/// <returns></returns>
bool DeathCheck(int currentHealth)
{
	if (currentHealth <= 0)
	{
		cout << "\n\nYou are dead. The end.\n\n\n";
		exit(0);
		return true;
	}
	else
	{
		return false;
	}
}