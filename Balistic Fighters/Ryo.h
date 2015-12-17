#ifndef RYO_H
#define RYO_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Character.h"
#include <iostream>
using namespace sf;
using namespace std;

class Ryo :public character
{
	Sprite sp[71];
	Texture tx[71];
	Event  movements;
public:
	Ryo();
	~Ryo();
	//getters
	Sprite getSp(int i);
	Texture getTx(int i);
	void Punch();
	void Kick();
	void Combo();
	void WalkFront();
	void WalkBack();
	void Jump();
	void Duck();
	void Ready();
	void Idle();
	void Win();
	void Dead();
	void Block();
};

#endif