#ifndef Levels_H
#define Levels_H

#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class levels
{
	string name;
	Texture txllvlbg;
	Sprite splevlbg;
	levels();
	levels(string name, Texture txllvlbg, Sprite splevlbg);
	~levels();
	//getter
	void getName();
	void getSplvlbg();
};

#endif 