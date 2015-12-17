
#include "Instructions.h"
#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
using namespace sf;

Instruction::Instruction()
{
	txbg.loadFromFile("Assests/insbg.gif");
	font.loadFromFile("Assests/SouthernAire.ttf");
}
Instruction::~Instruction()
{
	txbg.loadFromFile("NULL");
	font.loadFromFile("NULL");
}
//getters
Sprite Instruction::getInsbg()
{
	return sInsbg;
}
Text Instruction::getTx(int i)
{
	return tx[i];
}
bool Instruction::back()
{
	sf::IntRect rect(tx[6].getPosition().x + 5, tx[6].getPosition().y + 5, tx[6].getGlobalBounds().width + 5, tx[6].getGlobalBounds().height + 5);
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		//If we clicked within the Back rectangle, then Back!
		if (rect.contains(Mouse::getPosition()))
		{
			return true;
		}
	}
	return false;
}
void Instruction::draw()
{
	//texture setting
	sInsbg.setTexture(txbg);
	Vector2f targetSize(1366.0f, 768.0f);
	sInsbg.setScale(
		targetSize.x / sInsbg.getLocalBounds().width,
		targetSize.y / sInsbg.getLocalBounds().height);
	//strings setting
	tx[0].setFont(font);
	tx[0].setString("Instructions");
	tx[0].setPosition(300.0f, 50.0f);
	tx[0].setColor(Color::White);
	tx[0].setCharacterSize(172);
	//setting
	tx[1].setFont(font);
	tx[1].setString("Arrow Keys to Move Character");
	tx[1].setPosition(300.0f, 250.0f);
	tx[1].setColor(Color::White);
	tx[1].setCharacterSize(52);
	//setting
	tx[2].setFont(font);
	tx[2].setString("Use A to Punch");
	tx[2].setPosition(300.0f, 300.f);
	tx[2].setColor(Color::White);
	tx[2].setCharacterSize(52);
	//setting
	tx[3].setFont(font);
	tx[3].setString("Use S To Kick");
	tx[3].setPosition(300.0f, 350.0f);
	tx[3].setColor(Color::White);
	tx[3].setCharacterSize(52);
	//setting
	tx[4].setFont(font);
	tx[4].setString("Use D To Combo : Note it will reduce your health 20% too");
	tx[4].setPosition(300.0f, 400.0f);
	tx[4].setColor(Color::White);
	tx[4].setCharacterSize(52);
	//setting
	tx[5].setFont(font);
	tx[5].setString("Use F To Block");
	tx[5].setPosition(300.0f, 450.0f);
	tx[5].setColor(Color::White);
	tx[5].setCharacterSize(52);
	//setting
	tx[6].setFont(font);
	tx[6].setString("Back to Main Menu");
	tx[6].setPosition(300.0f, 500.0f);
	sf::IntRect rect2(tx[6].getPosition().x + 5, tx[6].getPosition().y + 5, tx[6].getGlobalBounds().width + 5, tx[6].getGlobalBounds().height + 5);
	//If we hover on Play change color
	if (rect2.contains(Mouse::getPosition()))
	{
		tx[6].setColor(Color::Green);
	}
	else
	{
		tx[6].setColor(Color::White);
	}
	tx[6].setCharacterSize(50);
}
