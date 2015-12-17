#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include "MainMenu.h"
using namespace sf;

mainmenu::mainmenu()
{
	bg.loadFromFile("Assests/mainmenubg.gif");
	font.loadFromFile("Assests/SouthernAire.ttf");
	mainmenumusic.openFromFile("Assests/mainmenumusic.ogg");
	mainmenumusic.play();
	mainmenumusic.setLoop(true);
	mainmenumusic.setVolume(100);
}
mainmenu::~mainmenu()
{
	bg.loadFromFile("NULL");
	font.loadFromFile("NULL");
	mainmenumusic.openFromFile("NULL");
}
void mainmenu::draw()
{
	//texture setting
	sbg.setTexture(bg);
	//position setting
	Vector2f targetSize(1366.0f, 768.0f);
	sbg.setScale(
		targetSize.x / sbg.getLocalBounds().width,
		targetSize.y / sbg.getLocalBounds().height);
	//title setting
	title.setFont(font);
	title.setString("Balistic Fighters");
	title.setPosition(300.0f, 50.0f);
	title.setColor(Color::White);
	title.setCharacterSize(172);
	//play setting
	ply.setFont(font);
	ply.setString("Play");
	ply.setPosition(575.0f, 300.0f);
	sf::IntRect rect2(ply.getPosition().x + 5, ply.getPosition().y + 5, ply.getGlobalBounds().width + 5, ply.getGlobalBounds().height + 5);
	//If we hover on Play change color
	if (rect2.contains(Mouse::getPosition()))
	{
		ply.setColor(Color::Green);
	}
	else
	{
		ply.setColor(Color::White);
	}
	ply.setCharacterSize(72);
	//instruction setting
	ins.setFont(font);
	ins.setString("Instruction");
	ins.setPosition(575.0f, 450.0f);
	sf::IntRect rect1(ins.getPosition().x + 5, ins.getPosition().y + 5, ins.getGlobalBounds().width + 5, ins.getGlobalBounds().height + 5);
	//If we hover on Instruction change color
	if (rect1.contains(Mouse::getPosition()))
	{
		ins.setColor(Color::Green);
	}
	else
	{
		ins.setColor(Color::White);
	}
	ins.setCharacterSize(72);
	//exit setting
	exi.setFont(font);
	exi.setString("Exit");
	exi.setPosition(575.0f, 600.0f);
	sf::IntRect rect(exi.getPosition().x + 5, exi.getPosition().y + 5, exi.getGlobalBounds().width + 5, exi.getGlobalBounds().height + 5);
	//If we hover on exit change color
	if (rect.contains(Mouse::getPosition()))
	{
		exi.setColor(Color::Green);
	}
	else
	{
		exi.setColor(Color::White);
	}
	exi.setCharacterSize(72);
}
Sprite mainmenu::getsbg()
{

	return sbg;
}
Text mainmenu::gettitle()
{
	return title;
}
Text mainmenu::getPlay()
{
	return ply;
}
Text mainmenu::getInstruction()
{
	return ins;
}
Text mainmenu::getExit()
{
	return exi;
}
bool mainmenu::play()
{
	return true;
}
bool mainmenu::instructions()
{
	sf::IntRect rect1(ins.getPosition().x + 5, ins.getPosition().y + 5, ins.getGlobalBounds().width + 5, ins.getGlobalBounds().height + 5);
	//if mouse clicked
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		//if cursor inside rectangle
		if (rect1.contains(Mouse::getPosition()))
		{
			return true;
		}
	}
	return false;
}
bool mainmenu::exit()
{
	sf::IntRect rect(exi.getPosition().x+5, exi.getPosition().y+5, exi.getGlobalBounds().width+5, exi.getGlobalBounds().height+5);
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		//If we clicked within the exit rectangle, then exit!
		if (rect.contains(Mouse::getPosition()))
		{
			return true;
		}
	}
	return false;
}

