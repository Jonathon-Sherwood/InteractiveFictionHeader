#pragma once

#include <iostream> //Used to display messages to the console

using namespace std; //Global declaration to shorten many common commands throughout the code

//Function prototypes
int Health(int currentHealth, int damageTaken); //Used to hold the players health and accept damage taken
char Story(string story); //Adjustable function for different story elements
bool DeathCheck(int currentHealth); //Ends game on current health dropping to 0
void Scenario1(int currentHealth); //Holds all functions for the first scenario in the story
void Scenario2(int currentHealth); //Holds all functions for the second scenario in the story
void Scenario3(int currentHealth); //Holds all functions for the third scenario in the story
void Scenario4(int currentHealth); //Holds all functions for the fourth scenario in the story
