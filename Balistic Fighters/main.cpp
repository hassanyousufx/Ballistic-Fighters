#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
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
		texture[16].loadFromFile("Assests/Iori/Duck1.png");
		sprite[16].setTexture(texture[16]);
		texture[17].loadFromFile("Assests/Iori/Duck2.png");
		sprite[17].setTexture(texture[17]);
		texture[18].loadFromFile("Assests/Iori/Duck3.png");
		sprite[18].setTexture(texture[18]);
		texture[19].loadFromFile("Assests/Iori/Duck4.png");
		sprite[19].setTexture(texture[19]);
		texture[20].loadFromFile("Assests/Iori/Duck5.png");
		sprite[20].setTexture(texture[20]);
		texture[21].loadFromFile("Assests/Iori/Duck6.png");
		sprite[21].setTexture(texture[21]);
		texture[22].loadFromFile("Assests/Iori/Duck7.png");
		sprite[22].setTexture(texture[22]);
		texture[23].loadFromFile("Assests/Iori/Duck8.png");
		sprite[23].setTexture(texture[23]);
		texture[24].loadFromFile("Assests/Iori/Duck9.png");
		sprite[24].setTexture(texture[24]);
		texture[25].loadFromFile("Assests/Iori/WalkFront1.png");
		sprite[25].setTexture(texture[25]);
		texture[26].loadFromFile("Assests/Iori/WalkFront2.png");
		sprite[26].setTexture(texture[26]);
		texture[27].loadFromFile("Assests/Iori/WalkFront3.png");
		sprite[27].setTexture(texture[27]);
		texture[28].loadFromFile("Assests/Iori/WalkFront4.png");
		sprite[28].setTexture(texture[28]);
		texture[29].loadFromFile("Assests/Iori/WalkFront5.png");
		sprite[29].setTexture(texture[29]);
		texture[30].loadFromFile("Assests/Iori/WalkFront6.png");
		sprite[30].setTexture(texture[30]);
		texture[31].loadFromFile("Assests/Iori/WalkFront7.png");
		sprite[31].setTexture(texture[31]);
		texture[32].loadFromFile("Assests/Iori/WalkFront8.png");
		sprite[32].setTexture(texture[32]);
		texture[33].loadFromFile("Assests/Iori/WalkFront9.png");
		sprite[33].setTexture(texture[33]);
		texture[34].loadFromFile("Assests/Iori/WalkFront10.png");
		sprite[34].setTexture(texture[34]);
		texture[35].loadFromFile("Assests/Iori/WalkBack1.png");
		sprite[35].setTexture(texture[35]);
		texture[36].loadFromFile("Assests/Iori/WalkBack2.png");
		sprite[36].setTexture(texture[36]);
		texture[37].loadFromFile("Assests/Iori/WalkBack3.png");
		sprite[37].setTexture(texture[37]);
		texture[38].loadFromFile("Assests/Iori/WalkBack4.png");
		sprite[38].setTexture(texture[38]);
		texture[39].loadFromFile("Assests/Iori/WalkBack5.png");
		sprite[39].setTexture(texture[39]);
		texture[40].loadFromFile("Assests/Iori/WalkBack6.png");
		sprite[40].setTexture(texture[40]);
		texture[41].loadFromFile("Assests/Iori/WalkBack7.png");
		sprite[41].setTexture(texture[41]);
		texture[42].loadFromFile("Assests/Iori/WalkBack8.png");
		sprite[42].setTexture(texture[42]);
		texture[43].loadFromFile("Assests/Iori/WalkBack9.png");
		sprite[43].setTexture(texture[43]);
		texture[44].loadFromFile("Assests/Iori/Jump1.png");
		sprite[44].setTexture(texture[44]);
		texture[45].loadFromFile("Assests/Iori/Jump2.png");
		sprite[45].setTexture(texture[45]);
		texture[46].loadFromFile("Assests/Iori/Jump3.png");
		sprite[46].setTexture(texture[46]);
		texture[47].loadFromFile("Assests/Iori/Jump4.png");
		sprite[47].setTexture(texture[47]);
		texture[48].loadFromFile("Assests/Iori/Jump5.png");
		sprite[48].setTexture(texture[48]);
		texture[49].loadFromFile("Assests/Iori/Jump6.png");
		sprite[49].setTexture(texture[49]);
		texture[50].loadFromFile("Assests/Iori/Jump7.png");
		sprite[50].setTexture(texture[50]);
		texture[51].loadFromFile("Assests/Iori/Jump8.png");
		sprite[51].setTexture(texture[51]);
		texture[52].loadFromFile("Assests/Iori/Jump9.png");
		sprite[52].setTexture(texture[52]);
		texture[53].loadFromFile("Assests/Iori/Punch1.png");
		sprite[53].setTexture(texture[53]);
		texture[54].loadFromFile("Assests/Iori/Punch2.png");
		sprite[54].setTexture(texture[54]);
		texture[55].loadFromFile("Assests/Iori/Punch3.png");
		sprite[55].setTexture(texture[55]);
		texture[56].loadFromFile("Assests/Iori/Punch4.png");
		sprite[56].setTexture(texture[56]);
		texture[57].loadFromFile("Assests/Iori/Punch5.png");
		sprite[57].setTexture(texture[57]);
		texture[58].loadFromFile("Assests/Iori/Punch6.png");
		sprite[58].setTexture(texture[58]);
		texture[59].loadFromFile("Assests/Iori/Punch7.png");
		sprite[59].setTexture(texture[59]);
		texture[60].loadFromFile("Assests/Iori/Punch8.png");
		sprite[60].setTexture(texture[60]);
		texture[61].loadFromFile("Assests/Iori/Punch9.png");
		sprite[61].setTexture(texture[61]);
		texture[62].loadFromFile("Assests/Iori/Kick1.png");
		sprite[62].setTexture(texture[62]);
		texture[63].loadFromFile("Assests/Iori/Kick2.png");
		sprite[63].setTexture(texture[63]);
		texture[64].loadFromFile("Assests/Iori/Kick3.png");
		sprite[64].setTexture(texture[64]);
		texture[65].loadFromFile("Assests/Iori/Kick4.png");
		sprite[65].setTexture(texture[65]);
		texture[66].loadFromFile("Assests/Iori/Kick5.png");
		sprite[66].setTexture(texture[66]);
		texture[67].loadFromFile("Assests/Iori/Kick6.png");
		sprite[67].setTexture(texture[67]);
		texture[68].loadFromFile("Assests/Iori/Kick7.png");
		sprite[68].setTexture(texture[68]);
		texture[69].loadFromFile("Assests/Iori/Kick8.png");
		sprite[69].setTexture(texture[69]);
		texture[70].loadFromFile("Assests/Iori/Kick9.png");
		sprite[70].setTexture(texture[70]);
		texture[71].loadFromFile("Assests/Iori/Kick10.png");
		sprite[71].setTexture(texture[71]);
		texture[72].loadFromFile("Assests/Iori/Combo1.png");
		sprite[72].setTexture(texture[72]);
		texture[73].loadFromFile("Assests/Iori/Combo2.png");
		sprite[73].setTexture(texture[73]);
		texture[74].loadFromFile("Assests/Iori/Combo3.png");
		sprite[74].setTexture(texture[74]);
		texture[75].loadFromFile("Assests/Iori/Combo4.png");
		sprite[75].setTexture(texture[75]);
		texture[76].loadFromFile("Assests/Iori/Combo5.png");
		sprite[76].setTexture(texture[76]);
		texture[77].loadFromFile("Assests/Iori/Combo6.png");
		sprite[77].setTexture(texture[77]);
		texture[78].loadFromFile("Assests/Iori/Combo7.png");
		sprite[78].setTexture(texture[78]);
		texture[79].loadFromFile("Assests/Iori/Combo8.png");
		sprite[79].setTexture(texture[79]);
		texture[80].loadFromFile("Assests/Iori/Combo9.png");
		sprite[80].setTexture(texture[80]);
		texture[81].loadFromFile("Assests/Iori/Combo10.png");
		sprite[81].setTexture(texture[81]);
		texture[82].loadFromFile("Assests/Iori/Combo11.png");
		sprite[82].setTexture(texture[82]);
		texture[83].loadFromFile("Assests/Iori/Combo12.png");
		sprite[83].setTexture(texture[83]);
		texture[84].loadFromFile("Assests/Iori/Combo13.png");
		sprite[84].setTexture(texture[84]);
		texture[85].loadFromFile("Assests/Iori/Combo14.png");
		sprite[85].setTexture(texture[85]);
		texture[86].loadFromFile("Assests/Iori/Combo15.png");
		sprite[86].setTexture(texture[86]);
		texture[87].loadFromFile("Assests/Iori/Combo16.png");
		sprite[87].setTexture(texture[87]);
		texture[88].loadFromFile("Assests/Iori/Combo17.png");
		sprite[88].setTexture(texture[88]);
		texture[89].loadFromFile("Assests/Iori/Combo18.png");
		sprite[89].setTexture(texture[89]);
		texture[90].loadFromFile("Assests/Iori/Combo19.png");
		sprite[90].setTexture(texture[90]);
		texture[91].loadFromFile("Assests/Iori/Combo20.png");
		sprite[91].setTexture(texture[91]);
		texture[92].loadFromFile("Assests/Iori/Combo21.png");
		sprite[92].setTexture(texture[92]);
		texture[93].loadFromFile("Assests/Iori/Combo22.png");
		sprite[93].setTexture(texture[93]);
		texture[94].loadFromFile("Assests/Iori/Combo23.png");
		sprite[94].setTexture(texture[94]);
		texture[95].loadFromFile("Assests/Iori/Combo24.png");
		sprite[95].setTexture(texture[95]);
		texture[96].loadFromFile("Assests/Iori/Combo25.png");
		sprite[96].setTexture(texture[96]);
		texture[97].loadFromFile("Assests/Iori/Combo26.png");
		sprite[97].setTexture(texture[97]);
		texture[98].loadFromFile("Assests/Iori/Combo27.png");
		sprite[98].setTexture(texture[98]);
		texture[99].loadFromFile("Assests/Iori/Block1.png");
		sprite[99].setTexture(texture[99]);
		texture[100].loadFromFile("Assests/Iori/Block2.png");
		sprite[100].setTexture(texture[100]);
		texture[101].loadFromFile("Assests/Iori/Block3.png");
		sprite[101].setTexture(texture[101]);
		texture[102].loadFromFile("Assests/Iori/Block4.png");
		sprite[102].setTexture(texture[102]);
		texture[103].loadFromFile("Assests/Iori/Block5.png");
		sprite[103].setTexture(texture[103]);
		texture[104].loadFromFile("Assests/Iori/Block6.png");
		sprite[104].setTexture(texture[104]);
		texture[105].loadFromFile("Assests/Iori/Block7.png");
		sprite[105].setTexture(texture[105]);
		texture[106].loadFromFile("Assests/Iori/Dead1.png");
		sprite[106].setTexture(texture[106]);
		texture[107].loadFromFile("Assests/Iori/Dead2.png");
		sprite[107].setTexture(texture[107]);
		texture[108].loadFromFile("Assests/Iori/Dead3.png");
		sprite[108].setTexture(texture[108]);
		texture[109].loadFromFile("Assests/Iori/Dead4.png");
		sprite[109].setTexture(texture[109]);
		texture[110].loadFromFile("Assests/Iori/Dead5.png");
		sprite[110].setTexture(texture[110]);
		texture[111].loadFromFile("Assests/Iori/Dead6.png");
		sprite[111].setTexture(texture[111]);
		texture[112].loadFromFile("Assests/Iori/Dead7.png");
		sprite[112].setTexture(texture[112]);
		texture[113].loadFromFile("Assests/Iori/Dead8.png");
		sprite[113].setTexture(texture[113]);
		texture[114].loadFromFile("Assests/Iori/Dead9.png");
		sprite[114].setTexture(texture[114]);
		texture[115].loadFromFile("Assests/Iori/Dead10.png");
		sprite[115].setTexture(texture[115]);
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
	bool Duck()
	{
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			float tmpy = 420.0f;
			sprite[16].setScale(
				targetSize.x / sprite[16].getLocalBounds().width,
				targetSize.y / sprite[16].getLocalBounds().height);
			sprite[16].setPosition(pos.x, tmpy);
			sprite[17].setScale(
				targetSize.x / sprite[17].getLocalBounds().width,
				targetSize.y / sprite[17].getLocalBounds().height);
			sprite[17].setPosition(pos.x, tmpy);
			sprite[18].setScale(
				targetSize.x / sprite[18].getLocalBounds().width,
				targetSize.y / sprite[18].getLocalBounds().height);
			sprite[18].setPosition(pos.x, tmpy);
			sprite[19].setScale(
				targetSize.x / sprite[19].getLocalBounds().width,
				targetSize.y / sprite[19].getLocalBounds().height);
			sprite[19].setPosition(pos.x, tmpy);
			sprite[20].setScale(
				targetSize.x / sprite[20].getLocalBounds().width,
				targetSize.y / sprite[20].getLocalBounds().height);
			sprite[20].setPosition(pos.x, tmpy);
			sprite[21].setScale(
				targetSize.x / sprite[21].getLocalBounds().width,
				targetSize.y / sprite[21].getLocalBounds().height);
			sprite[21].setPosition(pos.x, tmpy);
			sprite[22].setScale(
				targetSize.x / sprite[22].getLocalBounds().width,
				targetSize.y / sprite[22].getLocalBounds().height);
			sprite[22].setPosition(pos.x, tmpy);
			sprite[23].setScale(
				targetSize.x / sprite[23].getLocalBounds().width,
				targetSize.y / sprite[23].getLocalBounds().height);
			sprite[23].setPosition(pos.x, tmpy);
			sprite[24].setScale(
				targetSize.x / sprite[24].getLocalBounds().width,
				targetSize.y / sprite[24].getLocalBounds().height);
			sprite[24].setPosition(pos.x, tmpy);
			return true;
		}
		return false;
	}
	bool WalkFront()
	{
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			pos.x = pos.x + 15;
			sprite[25].setScale(
				targetSize.x / sprite[25].getLocalBounds().width,
				targetSize.y / sprite[25].getLocalBounds().height);
			sprite[25].setPosition(pos.x, pos.y);
			sprite[26].setScale(
				targetSize.x / sprite[26].getLocalBounds().width,
				targetSize.y / sprite[26].getLocalBounds().height);
			sprite[26].setPosition(pos.x, pos.y);
			sprite[27].setScale(
				targetSize.x / sprite[27].getLocalBounds().width,
				targetSize.y / sprite[27].getLocalBounds().height);
			sprite[27].setPosition(pos.x, pos.y);
			sprite[28].setScale(
				targetSize.x / sprite[28].getLocalBounds().width,
				targetSize.y / sprite[28].getLocalBounds().height);
			sprite[28].setPosition(pos.x, pos.y);
			sprite[29].setScale(
				targetSize.x / sprite[29].getLocalBounds().width,
				targetSize.y / sprite[29].getLocalBounds().height);
			sprite[29].setPosition(pos.x, pos.y);
			sprite[30].setScale(
				targetSize.x / sprite[30].getLocalBounds().width,
				targetSize.y / sprite[30].getLocalBounds().height);
			sprite[30].setPosition(pos.x, pos.y);
			sprite[31].setScale(
				targetSize.x / sprite[31].getLocalBounds().width,
				targetSize.y / sprite[31].getLocalBounds().height);
			sprite[31].setPosition(pos.x, pos.y);
			sprite[32].setScale(
				targetSize.x / sprite[32].getLocalBounds().width,
				targetSize.y / sprite[32].getLocalBounds().height);
			sprite[32].setPosition(pos.x, pos.y);
			sprite[33].setScale(
				targetSize.x / sprite[33].getLocalBounds().width,
				targetSize.y / sprite[33].getLocalBounds().height);
			sprite[33].setPosition(pos.x, pos.y);
			sprite[34].setScale(
				targetSize.x / sprite[34].getLocalBounds().width,
				targetSize.y / sprite[34].getLocalBounds().height);
			sprite[34].setPosition(pos.x, pos.y);
			return true;
		}
		return false;
	}
	bool WalkBack()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			pos.x = pos.x - 15;
			sprite[35].setScale(
				targetSize.x / sprite[35].getLocalBounds().width,
				targetSize.y / sprite[35].getLocalBounds().height);
			sprite[35].setPosition(pos.x, pos.y);
			sprite[36].setScale(
				targetSize.x / sprite[36].getLocalBounds().width,
				targetSize.y / sprite[36].getLocalBounds().height);
			sprite[36].setPosition(pos.x, pos.y);
			sprite[37].setScale(
				targetSize.x / sprite[37].getLocalBounds().width,
				targetSize.y / sprite[37].getLocalBounds().height);
			sprite[37].setPosition(pos.x, pos.y);
			sprite[38].setScale(
				targetSize.x / sprite[38].getLocalBounds().width,
				targetSize.y / sprite[38].getLocalBounds().height);
			sprite[38].setPosition(pos.x, pos.y);
			sprite[39].setScale(
				targetSize.x / sprite[39].getLocalBounds().width,
				targetSize.y / sprite[39].getLocalBounds().height);
			sprite[39].setPosition(pos.x, pos.y);
			sprite[40].setScale(
				targetSize.x / sprite[40].getLocalBounds().width,
				targetSize.y / sprite[40].getLocalBounds().height);
			sprite[40].setPosition(pos.x, pos.y);
			sprite[41].setScale(
				targetSize.x / sprite[41].getLocalBounds().width,
				targetSize.y / sprite[41].getLocalBounds().height);
			sprite[41].setPosition(pos.x, pos.y);
			sprite[42].setScale(
				targetSize.x / sprite[42].getLocalBounds().width,
				targetSize.y / sprite[42].getLocalBounds().height);
			sprite[42].setPosition(pos.x, pos.y);
			sprite[43].setScale(
				targetSize.x / sprite[43].getLocalBounds().width,
				targetSize.y / sprite[43].getLocalBounds().height);
			sprite[43].setPosition(pos.x, pos.y);
			return true;
		}
		return false;
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
	Level1(string adress = "Assests/level1bg.jpg", string name = "Level 1") :Levels(adress, name)
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