#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
using namespace sf;

class mainmenu
{
	Texture bg;
	Sprite sbg;
	Font font;
	Text title;
	Text ply;
	Text ins;
	Text exi;
	Music mainmenumusic;
public:
	mainmenu();
	~mainmenu();
	//getters
	Sprite getsbg();
	Text gettitle();
	Text getPlay();
	Text getInstruction();
	Text getExit();
	void draw();
	bool play();
	bool instructions();
	bool exit();
};

#endif 