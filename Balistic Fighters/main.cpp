#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
using namespace sf;

//classes
class Levels
{
	string name;
	Sprite spbg;
	Texture txbg;
public:
	Levels()
	{
		name = '\0';
	}
	Levels(string adress, string name)
	{
		this->name = name;
		txbg.loadFromFile(adress);
		spbg.setTexture(txbg);
	}
	~Levels()
	{
		name = '\0';
	}
	//setPosition
	void setPosition()
	{
		//position setting
		Vector2f targetSize(1366.0f, 768.0f);
		spbg.setScale(
			targetSize.x / spbg.getLocalBounds().width,
			targetSize.y / spbg.getLocalBounds().height);
	}
	//setter
	void setName(string name)
	{
		this->name = name;
	}
	void setTxbg(string adress)
	{
		this->txbg.loadFromFile(adress);
	}
	//getter
	Sprite getspbg()
	{
		return spbg;
	}
	string getName()
	{
		return name;
	}
};
class mainmenu :public Levels
{
	Font font;
	Text title;
	Text ply;
	Text ins;
	Text exi;
public:
	mainmenu(string adress = "Assests/mainmenubg.gif", string name = "Main Menu") :Levels(adress, name)
	{
		font.loadFromFile("Assests/SouthernAire.ttf");
	}
	~mainmenu()
	{
		setTxbg("NULL");
		setName("NULL");
	}
	//getters
	Text gettitle()
	{
		return title;
	}
	Text getPlay()
	{
		return ply;
	}
	Text getInstruction()
	{
		return ins;
	}
	Text getExit()
	{
		return exi;
	}
	void draw()
	{
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
	bool play()
	{

		sf::IntRect rect1(ply.getPosition().x + 5, ply.getPosition().y + 5, ply.getGlobalBounds().width + 5, ply.getGlobalBounds().height + 5);
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
	bool instructions()
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
	bool exit()
	{
		sf::IntRect rect(exi.getPosition().x + 5, exi.getPosition().y + 5, exi.getGlobalBounds().width + 5, exi.getGlobalBounds().height + 5);
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
};
class Instruction :public Levels
{
	Font font;
	Text tx[7];
	Texture txbg;
public:
	Instruction(string adress = "Assests/insbg.gif", string name = "Instructions") :Levels(adress, name)
	{
		font.loadFromFile("Assests/SouthernAire.ttf");
	}
	~Instruction()
	{
		setTxbg("NULL");
		setName("NULL");
	}
	//getters
	Text getTx(int i)
	{
		return tx[i];
	}
	bool back()
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
	void draw()
	{
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
		tx[6].setPosition(300.0f, 550.0f);
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
};
class characters
{
	string name;
protected:
	Sprite sprite[16];
	Texture texture[16];
public:
	characters()
	{
		this->name = "\0";
	}
	characters(string name)
	{
		this->name = name;
	}
	~characters()
	{
		this->name = "\0";
	}
	//getters
	string getName()
	{
		return this->name;
	}
	Texture geTexture(int i)
	{
		return texture[i];
	}
	Sprite getSprite(int i)
	{
		return sprite[i];
	}
};
class Iori :public characters
{
	int health;
	Vector2f targetSize;
	Vector2f pos;
public:
	Iori(string name = "IORI") :characters(name)
	{
		pos.x = 100.0f;
		pos.y = 365.0f;
		targetSize.x = 250.0f;
		targetSize.y = 400.0f;
		health = 100;
		texture[0].loadFromFile("Assests/Iori/Ready1.png");
		sprite[0].setTexture(texture[0]);
		texture[1].loadFromFile("Assests/Iori/Ready2.png");
		sprite[1].setTexture(texture[1]);
		texture[2].loadFromFile("Assests/Iori/Ready3.png");
		sprite[2].setTexture(texture[2]);
		texture[3].loadFromFile("Assests/Iori/Ready4.png");
		sprite[3].setTexture(texture[3]);
		texture[4].loadFromFile("Assests/Iori/Ready5.png");
		sprite[4].setTexture(texture[4]);
		texture[5].loadFromFile("Assests/Iori/Ready6.png");
		sprite[5].setTexture(texture[5]);
		texture[6].loadFromFile("Assests/Iori/Ready7.png");
		sprite[6].setTexture(texture[6]);
		texture[7].loadFromFile("Assests/Iori/Idle1.png");
		sprite[7].setTexture(texture[7]);
		texture[8].loadFromFile("Assests/Iori/Idle2.png");
		sprite[8].setTexture(texture[8]);
		texture[9].loadFromFile("Assests/Iori/Idle3.png");
		sprite[9].setTexture(texture[9]);
		texture[10].loadFromFile("Assests/Iori/Idle4.png");
		sprite[10].setTexture(texture[10]);
		texture[11].loadFromFile("Assests/Iori/Idle5.png");
		sprite[11].setTexture(texture[11]);
		texture[12].loadFromFile("Assests/Iori/Idle6.png");
		sprite[12].setTexture(texture[12]);
		texture[13].loadFromFile("Assests/Iori/Idle7.png");
		sprite[13].setTexture(texture[13]);
		texture[14].loadFromFile("Assests/Iori/Idle8.png");
		sprite[14].setTexture(texture[14]);
		texture[15].loadFromFile("Assests/Iori/Idle9.png");
		sprite[15].setTexture(texture[15]);
	}
	~Iori()
	{
		health = 0;
	}
	int getHealth()
	{
		return health;
	}
	void Ready(bool status)
	{
		if (status == false)
		{
			sprite[0].setScale(
				targetSize.x / sprite[0].getLocalBounds().width,
				targetSize.y / sprite[0].getLocalBounds().height);
			sprite[0].setPosition(pos);
			sprite[1].setScale(
				targetSize.x / sprite[1].getLocalBounds().width,
				targetSize.y / sprite[1].getLocalBounds().height);
			sprite[1].setPosition(pos);
			sprite[2].setScale(
				targetSize.x / sprite[2].getLocalBounds().width,
				targetSize.y / sprite[2].getLocalBounds().height);
			sprite[2].setPosition(pos);
			sprite[3].setScale(
				targetSize.x / sprite[3].getLocalBounds().width,
				targetSize.y / sprite[3].getLocalBounds().height);
			sprite[3].setPosition(pos);
			sprite[4].setScale(
				targetSize.x / sprite[4].getLocalBounds().width,
				targetSize.y / sprite[4].getLocalBounds().height);
			sprite[4].setPosition(pos);
			sprite[5].setScale(
				targetSize.x / sprite[5].getLocalBounds().width,
				targetSize.y / sprite[5].getLocalBounds().height);
			sprite[5].setPosition(pos);
			sprite[6].setScale(
				targetSize.x / sprite[6].getLocalBounds().width,
				targetSize.y / sprite[6].getLocalBounds().height);
			sprite[6].setPosition(pos);
		}
	}
	void Idle(bool key)
	{
		if (key == false)
		{
			sprite[7].setScale(
				targetSize.x / sprite[7].getLocalBounds().width,
				targetSize.y / sprite[7].getLocalBounds().height);
			sprite[7].setPosition(pos);
			sprite[8].setScale(
				targetSize.x / sprite[8].getLocalBounds().width,
				targetSize.y / sprite[8].getLocalBounds().height);
			sprite[8].setPosition(pos);
			sprite[9].setScale(
				targetSize.x / sprite[9].getLocalBounds().width,
				targetSize.y / sprite[9].getLocalBounds().height);
			sprite[9].setPosition(pos);
			sprite[10].setScale(
				targetSize.x / sprite[10].getLocalBounds().width,
				targetSize.y / sprite[10].getLocalBounds().height);
			sprite[10].setPosition(pos);
			sprite[11].setScale(
				targetSize.x / sprite[11].getLocalBounds().width,
				targetSize.y / sprite[11].getLocalBounds().height);
			sprite[11].setPosition(pos);
			sprite[12].setScale(
				targetSize.x / sprite[12].getLocalBounds().width,
				targetSize.y / sprite[12].getLocalBounds().height);
			sprite[12].setPosition(pos);
			sprite[13].setScale(
				targetSize.x / sprite[13].getLocalBounds().width,
				targetSize.y / sprite[13].getLocalBounds().height);
			sprite[13].setPosition(pos);
			sprite[14].setScale(
				targetSize.x / sprite[14].getLocalBounds().width,
				targetSize.y / sprite[14].getLocalBounds().height);
			sprite[14].setPosition(pos);
			sprite[15].setScale(
				targetSize.x / sprite[15].getLocalBounds().width,
				targetSize.y / sprite[15].getLocalBounds().height);
			sprite[15].setPosition(pos);
		}
	}
	void Duck()
	{
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			//
		}
	}
	void WalkFront()
	{
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			//
		}
	}
	void WalkBack()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			//
		}
	}
	void Jump()
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			//
		}
	}
	void Punch()
	{
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			//
		}
	}
	void Kick()
	{

		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			//
		}
	}
	void Combo()
	{
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			//
		}
	}
	void Dead()
	{

		if (health <= 0)
		{
			//
		}
	}
	void Block()
	{

		if (Keyboard::isKeyPressed(Keyboard::F))
		{
			//
		}
	}

};
class Level1 :public Levels
{
	Font font;
	Text txt[4];
	Iori iori;
public:
	Level1(string adress = "Assests/insbg.gif", string name = "Level 1") :Levels(adress, name)
	{
		font.loadFromFile("Assests/SouthernAire.ttf");
	}
	~Level1()
	{
		setTxbg("NULL");
		setName("NULL");
	}
	//Methods
	bool back()
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			return true;
		}
		return false;
	}
	void draw()
	{
		//Level name
		txt[0].setFont(font);
		txt[0].setString(getName());
		txt[0].setPosition(600.0f, 250.0f);
		txt[0].setColor(Color::Red);
		txt[0].setCharacterSize(72);
		//Ready
		txt[1].setFont(font);
		txt[1].setString("Ready");
		txt[1].setPosition(600.0f, 350.0f);
		txt[1].setColor(Color::Red);
		txt[1].setCharacterSize(72);
		//Player 1
		txt[2].setFont(font);
		txt[2].setString("Player 1");
		txt[2].setPosition(75.0f, 50.0f);
		txt[2].setColor(Color::Black);
		txt[2].setCharacterSize(48);
		//Player 2
		txt[3].setFont(font);
		txt[3].setString("CPU");
		txt[3].setPosition(1150.0f, 50.0f);
		txt[3].setColor(Color::Black);
		txt[3].setCharacterSize(48);
	}
	//getter
	Text gettxt(int i)
	{
		return txt[i];
	}
	//ioriwrappers
	int IW_getHealth()
	{
		return iori.getHealth();
	}
	void IW_Ready(bool status)
	{
		iori.Ready(status);
	}
	void IW_Idle(bool key)
	{
		iori.Idle(key);
	}
	Sprite IW_getSprite(int i)
	{
		return iori.getSprite(i);
	}
};

int main()
{
	RenderWindow window(VideoMode(800, 640), "Balistics Fighter", Style::Fullscreen);
	window.setFramerateLimit(60);
	mainmenu menu;
	Instruction instructions;
	Level1 lvl1;
	int flag = 0, curr = 0;
	bool is_Exit = false;
	bool is_chnglevel = false, isKeyPressed = false;
	int nxtlvl = 0;
	Clock clock;
	float speed = 80.f;
	//game music
	Music music, music2, music3;
	if (!music.openFromFile("Assests/sound/Track_01.ogg"))
	{
		//return EXIT_FAILURE;
	}
	if (!music2.openFromFile("Assests/sound/Track_02.ogg"))
	{
		//return EXIT_FAILURE;
	}
	if (!music3.openFromFile("Assests/sound/Track_03.ogg"))
	{
		//return EXIT_FAILURE;
	}
	while (window.isOpen())
	{
		//music playing
		if (music3.getStatus() == SoundSource::Stopped)
		{
			music.play();
			music.setVolume(100);
		}
		if (music.getStatus() == SoundSource::Stopped)
		{
			music2.play();
			music2.setVolume(100);
		}
		if (music2.getStatus() == SoundSource::Stopped)
		{
			music3.play();
			music3.setVolume(100);
		}
		// check all the window's events that were triggered since the last iteration of the loop
		Event event;
		while (window.pollEvent(event))
		{
			if (flag == 0)//if menu is to be displayed
			{
				//check if exit is called
				is_Exit = menu.exit();
				if (is_Exit == true)
				{
					window.close();
				}
				is_chnglevel = menu.instructions();
				if (is_chnglevel == true)
				{
					flag = 1;
				}
				is_chnglevel = menu.play();
				if (is_chnglevel == true)
				{
					flag = 2;
					clock.restart();
					curr = 0;
				}
			}
			if (flag == 1)
			{
				is_chnglevel = instructions.back();
				if (is_chnglevel == true)
				{
					flag = 0;
				}
			}
			if (flag == 2)
			{
				//user pressed play Game
				is_chnglevel = lvl1.back();
				if (is_chnglevel == true)
				{
					flag = 0;
				}
			}
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		if (flag == 0)//if menu is to be displayed
		{
			menu.setPosition();
			menu.draw();
			window.draw(menu.getspbg());
			window.draw(menu.gettitle());
			window.draw(menu.getPlay());
			window.draw(menu.getInstruction());
			window.draw(menu.getExit());
		}
		if (flag == 1)//if instruction level is to be displayed
		{
			instructions.draw();
			instructions.setPosition();
			window.draw(instructions.getspbg());
			for (int i = 0; i < 7; i++)
			{
				window.draw(instructions.getTx(i));
			}
		}
		if (flag == 2)
		{
			lvl1.setPosition();
			window.draw(lvl1.getspbg());
			lvl1.draw();
			lvl1.IW_Idle(isKeyPressed);
			Time t1 = clock.getElapsedTime();
			if (t1.asSeconds() < 3.0f)
			{
				lvl1.IW_Ready(isKeyPressed);
				for (int i = 0; i < 2; i++)
				{
					window.draw(lvl1.gettxt(i));
				}
				if (curr < 7)
				{
					window.draw(lvl1.IW_getSprite(curr));
					Sleep(500);
					curr++;
					isKeyPressed = true;
				}
			}
			for (int i = 2; i < 4; i++)
			{
				window.draw(lvl1.gettxt(i));
			}
			if (curr < 14 && curr >= 7)
			{
				isKeyPressed = false;
				window.draw(lvl1.IW_getSprite(curr));
				Sleep(200);
				curr++;
				isKeyPressed = true;
			}
			else
			{
				isKeyPressed = false;
				window.draw(lvl1.IW_getSprite(curr));
				Sleep(200);
				curr = 7;
			}
		}
		window.display();
	}
	return 0;
}