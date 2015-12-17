#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
using namespace sf;

class Instruction
{
	Font font;
	Text tx[7];
	Texture txbg;
	Sprite sInsbg;
public:
	Instruction();
	~Instruction();
	//getters
	Sprite getInsbg();
	Text getTx(int i);
	bool back();
	void draw();
};

#endif 