#include "Character.h"
#include<iostream>
#include <string>
using namespace std;


character::character()
	{
		name = '\0';
		health = 0;
	}
character::character(string name, int health)
	{
		this->name = name;
		this->health = health;
	}
character::~character()
	{
		name = '\0';
		health = 0;
	}
	//getters
string character:: getName()const
	{
		return this->name;
	}
int character:: getHealth()const
	{
		return this->health;
	}
