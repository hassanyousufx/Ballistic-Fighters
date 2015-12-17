#ifndef CHARACTER_H
#define CHARACTER_H
#include<iostream>
#include <string>
using namespace std;

class character
{
	string name;
	int health;
public:
	character();
	character(string name, int health);
	~character();
	//getters
	string getName()const;
	int getHealth()const;
};

#endif 