// standard SFML libs
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

// standard C++ libs
#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>

using namespace std;
using namespace sf;

// start of classes
class Levels
{
	// private variables
	string name;
	Sprite spbg;  // SFML pre-defined class
	Texture txbg; // SFML pre-defined class
public:
	// basic constructors, destructors, setters & getters
	Levels() {
		name = '\0';
	}

	Levels(string adress, string name) {
		this->name = name;
		txbg.loadFromFile(adress);
		spbg.setTexture(txbg);
	}
	
	~Levels() {
		name = '\0';
	}

	//setPosition
	void setPosition() {
		//position setting
		Vector2f targetSize(1366.0f, 768.0f);
		// get screen size
		spbg.setScale(
			targetSize.x / spbg.getLocalBounds().width,
			targetSize.y / spbg.getLocalBounds().height);
	}

	//setters
	void setName(string name) {
		this->name = name;
	}

	void setTxbg(string adress) {
		// pre-defined SFML function
		this->txbg.loadFromFile(adress);
	}

	//getters
	Sprite getspbg() {
		return spbg;
	}

	string getName() {
		return name;
	}
};
class mainmenu:public Levels
{
	// main menu class (INHERITED):
	// the first window of the game
	// show the play, instrucion and exit button
private:
	// pre-defined classes in SFML
	// composed here
	Font font;
	Text title;
	Text ply;
	Text ins;
	Text exi;
public:
	mainmenu(string adress = "Assests/mainmenubg.gif", string name = "Main Menu") :Levels(adress,name) {
		// load font file from assets directory
		// and store bg image in address
		font.loadFromFile("Assests/SouthernAire.ttf");
	}

	~mainmenu() {
		setTxbg("NULL");
		setName("NULL");
	}

	//getters
	Text gettitle() {
		return title;
	}

	Text getPlay() {
		return ply;
	}

	Text getInstruction() {
		return ins;
	}

	Text getExit() {
		return exi;
	}

	void draw() {
		// title setting
		title.setFont(font);						// set font style i.e SouthernAire.ttf
		title.setString("Balistic Fighters");		// store the title
		title.setPosition(300.0f, 50.0f);			// set the position where you want your title to be placed
		title.setColor(Color::White);				// set font color
		title.setCharacterSize(172);				// set font size

		// play setting
		ply.setFont(font);
		ply.setString("Play");
		ply.setPosition(575.0f, 300.0f);			// color will be set below because we want to achieve a hover effect
		
		// pre-defined SFML class
		// create OBJ using parameterized constructor

		// this will set an invisible rectangle border around the play text.
		// in simple HTML words, create a button and add some padding around it
		IntRect rect2(ply.getPosition().x + 5, ply.getPosition().y + 5, ply.getGlobalBounds().width + 5, ply.getGlobalBounds().height + 5);
		
		// If we hover on Play, change color
		if (rect2.contains(Mouse::getPosition()))
			ply.setColor(Color::Green);
		
		else
			ply.setColor(Color::White);
		
		ply.setCharacterSize(72);	// set font size

		// instruction setting
		// again, we want to create a button, we create a hover effect
		ins.setFont(font);
		ins.setString("Instruction");
		ins.setPosition(575.0f, 450.0f);
		sf::IntRect rect1(ins.getPosition().x + 5, ins.getPosition().y + 5, ins.getGlobalBounds().width + 5, ins.getGlobalBounds().height + 5);
		
		//If we hover on Instruction change color
		if (rect1.contains(Mouse::getPosition()))
			ins.setColor(Color::Green);
		
		else
			ins.setColor(Color::White);
		
		ins.setCharacterSize(72);
		
		//exit setting (self explanatory)
		exi.setFont(font);
		exi.setString("Exit");
		exi.setPosition(575.0f, 600.0f);
		sf::IntRect rect(exi.getPosition().x + 5, exi.getPosition().y + 5, exi.getGlobalBounds().width + 5, exi.getGlobalBounds().height + 5);
		
		//If we hover on exit change color
		if (rect.contains(Mouse::getPosition()))
			exi.setColor(Color::Green);
		
		else
			exi.setColor(Color::White);
		
		exi.setCharacterSize(72);
	}

	bool play() {
		
		IntRect rect1(ply.getPosition().x + 5, ply.getPosition().y + 5, ply.getGlobalBounds().width + 5, ply.getGlobalBounds().height + 5);
		// if left-mouse clicked, check if the cursor is inside the rectangle
		if (Mouse::isButtonPressed(Mouse::Left))
			if (rect1.contains(Mouse::getPosition()))
				return true;
		
		return false;
	}

	bool instructions() {
		// add sf:: if the function does not workk
		IntRect rect1(ins.getPosition().x + 5, ins.getPosition().y + 5, ins.getGlobalBounds().width + 5, ins.getGlobalBounds().height + 5);
		// if mouse clicked, check if it is inside the rectangle
		if (Mouse::isButtonPressed(Mouse::Left))
			if (rect1.contains(Mouse::getPosition()))
				return true;
		
		return false;
	}

	bool exit() {
		IntRect rect(exi.getPosition().x + 5, exi.getPosition().y + 5, exi.getGlobalBounds().width + 5, exi.getGlobalBounds().height + 5);
		// if exit is clicked, close window
		if (Mouse::isButtonPressed(Mouse::Left))
			if (rect.contains(Mouse::getPosition()))
				return true;

		return false;
	}
};
class Instruction:public Levels
{
	// INHERITED from levels
	// this class acts as a level
private:
	// pre-defined classes in SFML, composed
	Font font;
	Text tx[7];
	Texture txbg;
public:
	Instruction(string adress = "Assests/insbg.gif", string name = "Instructions") :Levels(adress,name) {
		font.loadFromFile("Assests/SouthernAire.ttf");
	}

	~Instruction() {
		setTxbg("NULL");
		setName("NULL");
	}

	//getters
	Text getTx(int i) {
		return tx[i];
	}

	bool back() {
		// add sf:: if function does not work
		IntRect rect(tx[6].getPosition().x + 5, tx[6].getPosition().y + 5, tx[6].getGlobalBounds().width + 5, tx[6].getGlobalBounds().height + 5);
		if (Mouse::isButtonPressed(Mouse::Left))
			if (rect.contains(Mouse::getPosition()))
				return true;
		
		return false;
	}

	void draw() {
		//strings setting
		tx[0].setFont(font);								// set font style
		tx[0].setString("Instructions");					// store the text
		tx[0].setPosition(300.0f, 50.0f);					// set position
		tx[0].setColor(Color::White);						// set font color
		tx[0].setCharacterSize(172);						// set font size, same for all below texts
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
		// If we hover on back, change color
		if (rect2.contains(Mouse::getPosition()))
			tx[6].setColor(Color::Green);
		
		else
			tx[6].setColor(Color::White);
		
		tx[6].setCharacterSize(50);
	}
};
class characters
{	
	// Characters class,
	// acts as an ABSTRACT class
	// will be INHERITED by IORI and RYU
private:
	string name;
protected:
	// create pointers that are protected
	// so that they cannot be accessed in main
	Sprite *sprite;
	Texture *texture;
public:
	characters() {
		this->name = "\0";
	}

	characters(string name) {
		this->name = name;
	}

	~characters() {
		this->name = "\0";
	}

	//getters
	string getName() {
		return this->name;
	}

	Texture geTexture(int i) {
		return texture[i];
	}
	
	Sprite getSprite(int i) {
		return sprite[i];
	}
};
class Iori :public characters
{
	// this will be our player 1
	// set health of player 1
	int health;
	// pre-defined SFML class, composed
	Vector2f targetSize;
	Vector2f pos;
public:
	Iori(string name = "IORI") :characters(name) {
		// initialize the pointer array
		texture = new Texture[116];
		sprite = new Sprite[116];
		// set position and targetSize i.e where
		// do you want your sprites (characters)
		// to be displayed
		pos.x = 100.0f;
		pos.y = 365.0f;
		targetSize.x = 250.0f;
		targetSize.y = 400.0f;
		health = 100;
		// load the characters from assets
		// using SFML loadFromFile function

		for (int i = 0; i < 7; ++i)
		{
			texture[i].loadFromFile("Assests/Iori/Ready" + std::to_string(i + 1) + ".png");
			sprite[i].setTexture(texture[i]);
		}

		texture[7].loadFromFile("Assests/Iori/Idle1.png");
		texture[8].loadFromFile("Assests/Iori/Idle2.png");
		texture[9].loadFromFile("Assests/Iori/Idle3.png");
		texture[10].loadFromFile("Assests/Iori/Idle4.png");
		texture[11].loadFromFile("Assests/Iori/Idle5.png");
		texture[12].loadFromFile("Assests/Iori/Idle6.png");
		texture[13].loadFromFile("Assests/Iori/Idle7.png");
		texture[14].loadFromFile("Assests/Iori/Idle8.png");
		texture[15].loadFromFile("Assests/Iori/Idle9.png");
		texture[16].loadFromFile("Assests/Iori/Duck1.png");
		texture[17].loadFromFile("Assests/Iori/Duck2.png");
		texture[18].loadFromFile("Assests/Iori/Duck3.png");
		texture[19].loadFromFile("Assests/Iori/Duck4.png");
		texture[20].loadFromFile("Assests/Iori/Duck5.png");
		texture[21].loadFromFile("Assests/Iori/Duck6.png");
		texture[22].loadFromFile("Assests/Iori/Duck7.png");
		texture[23].loadFromFile("Assests/Iori/Duck8.png");
		texture[24].loadFromFile("Assests/Iori/Duck9.png");
		texture[25].loadFromFile("Assests/Iori/WalkFront1.png");
		texture[26].loadFromFile("Assests/Iori/WalkFront2.png");
		texture[27].loadFromFile("Assests/Iori/WalkFront3.png");
		texture[28].loadFromFile("Assests/Iori/WalkFront4.png");
		texture[29].loadFromFile("Assests/Iori/WalkFront5.png");
		texture[30].loadFromFile("Assests/Iori/WalkFront6.png");
		texture[31].loadFromFile("Assests/Iori/WalkFront7.png");
		texture[32].loadFromFile("Assests/Iori/WalkFront8.png");
		texture[33].loadFromFile("Assests/Iori/WalkFront9.png");
		texture[34].loadFromFile("Assests/Iori/WalkFront10.png");
		texture[35].loadFromFile("Assests/Iori/WalkBack1.png");
		texture[36].loadFromFile("Assests/Iori/WalkBack2.png");
		texture[37].loadFromFile("Assests/Iori/WalkBack3.png");
		texture[38].loadFromFile("Assests/Iori/WalkBack4.png");
		texture[39].loadFromFile("Assests/Iori/WalkBack5.png");
		texture[40].loadFromFile("Assests/Iori/WalkBack6.png");
		texture[41].loadFromFile("Assests/Iori/WalkBack7.png");
		texture[42].loadFromFile("Assests/Iori/WalkBack8.png");
		texture[43].loadFromFile("Assests/Iori/WalkBack9.png");
		texture[44].loadFromFile("Assests/Iori/Jump1.png");
		texture[45].loadFromFile("Assests/Iori/Jump2.png");
		texture[46].loadFromFile("Assests/Iori/Jump3.png");
		texture[47].loadFromFile("Assests/Iori/Jump4.png");
		texture[48].loadFromFile("Assests/Iori/Jump5.png");
		texture[49].loadFromFile("Assests/Iori/Jump6.png");
		texture[50].loadFromFile("Assests/Iori/Jump7.png");
		texture[51].loadFromFile("Assests/Iori/Jump8.png");
		texture[52].loadFromFile("Assests/Iori/Jump9.png");
		texture[53].loadFromFile("Assests/Iori/Punch1.png");
		texture[54].loadFromFile("Assests/Iori/Punch2.png");
		texture[55].loadFromFile("Assests/Iori/Punch3.png");
		texture[56].loadFromFile("Assests/Iori/Punch4.png");
		texture[57].loadFromFile("Assests/Iori/Punch5.png");
		texture[58].loadFromFile("Assests/Iori/Punch6.png");
		texture[59].loadFromFile("Assests/Iori/Punch7.png");
		texture[60].loadFromFile("Assests/Iori/Punch8.png");
		texture[61].loadFromFile("Assests/Iori/Punch9.png");
		texture[62].loadFromFile("Assests/Iori/Kick1.png");
		texture[63].loadFromFile("Assests/Iori/Kick2.png");
		texture[64].loadFromFile("Assests/Iori/Kick3.png");
		texture[65].loadFromFile("Assests/Iori/Kick4.png");
		texture[66].loadFromFile("Assests/Iori/Kick5.png");
		texture[67].loadFromFile("Assests/Iori/Kick6.png");
		texture[68].loadFromFile("Assests/Iori/Kick7.png");
		texture[69].loadFromFile("Assests/Iori/Kick8.png");
		texture[70].loadFromFile("Assests/Iori/Kick9.png");
		texture[71].loadFromFile("Assests/Iori/Kick10.png");
		texture[72].loadFromFile("Assests/Iori/Combo1.png");
		texture[73].loadFromFile("Assests/Iori/Combo2.png");
		texture[74].loadFromFile("Assests/Iori/Combo3.png");
		texture[75].loadFromFile("Assests/Iori/Combo4.png");
		texture[76].loadFromFile("Assests/Iori/Combo5.png");
		texture[77].loadFromFile("Assests/Iori/Combo6.png");
		texture[78].loadFromFile("Assests/Iori/Combo7.png");
		texture[79].loadFromFile("Assests/Iori/Combo8.png");
		texture[80].loadFromFile("Assests/Iori/Combo9.png");
		texture[81].loadFromFile("Assests/Iori/Combo10.png");
		texture[82].loadFromFile("Assests/Iori/Combo11.png");
		texture[83].loadFromFile("Assests/Iori/Combo12.png");
		texture[84].loadFromFile("Assests/Iori/Combo13.png");
		texture[85].loadFromFile("Assests/Iori/Combo14.png");
		texture[86].loadFromFile("Assests/Iori/Combo15.png");
		texture[87].loadFromFile("Assests/Iori/Combo16.png");
		texture[88].loadFromFile("Assests/Iori/Combo17.png");
		texture[89].loadFromFile("Assests/Iori/Combo18.png");
		texture[90].loadFromFile("Assests/Iori/Combo19.png");
		texture[91].loadFromFile("Assests/Iori/Combo20.png");
		texture[92].loadFromFile("Assests/Iori/Combo21.png");
		texture[93].loadFromFile("Assests/Iori/Combo22.png");
		texture[94].loadFromFile("Assests/Iori/Combo23.png");
		texture[95].loadFromFile("Assests/Iori/Combo24.png");
		texture[96].loadFromFile("Assests/Iori/Combo25.png");
		texture[97].loadFromFile("Assests/Iori/Combo26.png");
		texture[98].loadFromFile("Assests/Iori/Combo27.png");
		texture[99].loadFromFile("Assests/Iori/Block1.png");
		texture[100].loadFromFile("Assests/Iori/Block2.png");
		texture[101].loadFromFile("Assests/Iori/Block3.png");
		texture[102].loadFromFile("Assests/Iori/Block4.png");
		texture[103].loadFromFile("Assests/Iori/Block5.png");
		texture[104].loadFromFile("Assests/Iori/Block6.png");
		texture[105].loadFromFile("Assests/Iori/Block7.png");
		texture[106].loadFromFile("Assests/Iori/Dead1.png");
		texture[107].loadFromFile("Assests/Iori/Dead2.png");
		texture[108].loadFromFile("Assests/Iori/Dead3.png");
		texture[109].loadFromFile("Assests/Iori/Dead4.png");
		texture[110].loadFromFile("Assests/Iori/Dead5.png");
		texture[111].loadFromFile("Assests/Iori/Dead6.png");
		texture[112].loadFromFile("Assests/Iori/Dead7.png");
		texture[113].loadFromFile("Assests/Iori/Dead8.png");
		texture[114].loadFromFile("Assests/Iori/Dead9.png");
		texture[115].loadFromFile("Assests/Iori/Dead10.png");

		for (int i = 0; i < 116; i++)
			sprite[i].setTexture(texture[i]);
	}

	~Iori() {
		health = 0;
	}

	void setHealth(int health) {
		this->health = health;
	}

	int getHealth()const {
		return health;
	}

	void Ready(bool status) {
		if (status == true)
			for (int i = 0; i < 7; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
	}

	void Idle(bool status) {
		if (status == false)
			for (int i = 7; i < 16; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
	}

	bool Duck() {
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			float tmpy = 420.0f;
			for (int i = 16; i < 25; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos.x, tmpy);
			}
			return true;
		}
		return false;
	}

	bool WalkFront() {
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (pos.x <= 1100.0f)
				pos.x = pos.x + 15;
			
			for (int i = 25; i < 35; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos.x, pos.y);
			}
			return true;
		}
		return false;
	}

	bool WalkBack(){
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			if (pos.x > 0.0f)
				pos.x = pos.x - 15;
			
			for (int i = 35; i < 45; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos.x, pos.y);
			}
			return true;
		}
		return false;
	}

	bool Jump() {
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			float tmpy = pos.y;
			sprite[44].setScale(
				targetSize.x / sprite[44].getLocalBounds().width,
				targetSize.y / sprite[4].getLocalBounds().height);
			sprite[44].setPosition(pos.x, pos.y);
			sprite[45].setScale(
				targetSize.x / sprite[45].getLocalBounds().width,
				targetSize.y / sprite[45].getLocalBounds().height);
			sprite[45].setPosition(pos.x, (tmpy - 100.0f));
			sprite[46].setScale(
				targetSize.x / sprite[46].getLocalBounds().width,
				targetSize.y / sprite[46].getLocalBounds().height);
			sprite[46].setPosition(pos.x, (tmpy - 150.0f));
			sprite[47].setScale(
				targetSize.x / sprite[47].getLocalBounds().width,
				targetSize.y / sprite[47].getLocalBounds().height);
			sprite[47].setPosition(pos.x, (tmpy - 200.0f));
			sprite[48].setScale(
				targetSize.x / sprite[48].getLocalBounds().width,
				targetSize.y / sprite[48].getLocalBounds().height);
			sprite[48].setPosition(pos.x, (tmpy - 250.0f));
			sprite[49].setScale(
				targetSize.x / sprite[49].getLocalBounds().width,
				targetSize.y / sprite[49].getLocalBounds().height);
			sprite[49].setPosition(pos.x, (tmpy + 50.0f));
			sprite[50].setScale(
				targetSize.x / sprite[50].getLocalBounds().width,
				targetSize.y / sprite[50].getLocalBounds().height);
			sprite[50].setPosition(pos.x, pos.y);
			sprite[51].setScale(
				targetSize.x / sprite[51].getLocalBounds().width,
				targetSize.y / sprite[51].getLocalBounds().height);
			sprite[51].setPosition(pos.x, pos.y);
			sprite[52].setScale(
				targetSize.x / sprite[52].getLocalBounds().width,
				targetSize.y / sprite[52].getLocalBounds().height);
			sprite[52].setPosition(pos.x, pos.y);
			return true;
		}
		return false;
	}

	bool Punch() {
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			for (int i = 53; i < 62; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}
	
	bool Kick() {
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			for (int i = 62; i < 72; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	bool Combo() {
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			for (int i = 72; i < 99; i++) {
			sprite[i].setScale(
				targetSize.x / sprite[i].getLocalBounds().width,
				targetSize.y / sprite[i].getLocalBounds().height);
			sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	bool Block() {
		if (Keyboard::isKeyPressed(Keyboard::F)) {
			for (int i = 99; i < 106; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	bool Dead() {
		if (health <= 0) {
			for (int i = 106; i < 116; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	void setPos(Vector2f pos) {
		this->pos = pos;
	}
};
class Ryo:public characters
{
	int health;
	Vector2f targetSize;
	Vector2f pos;
public:
	Ryo(string name = "RYO") :characters(name)
	{
		texture = new Texture[59];
		sprite = new Sprite[59];
		pos.x = 1100.0f;
		pos.y = 365.0f;
		targetSize.x = 250.0f;
		targetSize.y = 400.0f;
		health = 100;
		texture[0].loadFromFile("Assests/Ryo/Ready1.png");
		sprite[0].setTexture(texture[0]);
		texture[1].loadFromFile("Assests/Ryo/Ready2.png");
		sprite[1].setTexture(texture[1]);
		texture[2].loadFromFile("Assests/Ryo/Ready3.png");
		sprite[2].setTexture(texture[2]);
		texture[3].loadFromFile("Assests/Ryo/Ready4.png");
		sprite[3].setTexture(texture[3]);
		texture[4].loadFromFile("Assests/Ryo/Idle1.png");
		sprite[4].setTexture(texture[4]);
		texture[5].loadFromFile("Assests/Ryo/Idle2.png");
		sprite[5].setTexture(texture[5]);
		texture[6].loadFromFile("Assests/Ryo/Idle3.png");
		sprite[6].setTexture(texture[6]);
		texture[7].loadFromFile("Assests/Ryo/Idle4.png");
		sprite[7].setTexture(texture[7]);
		texture[8].loadFromFile("Assests/Ryo/Duck1.png");
		sprite[8].setTexture(texture[8]);
		texture[9].loadFromFile("Assests/Ryo/Duck2.png");
		sprite[9].setTexture(texture[9]);
		texture[10].loadFromFile("Assests/Ryo/WalkFront1.png");
		sprite[10].setTexture(texture[10]);
		texture[11].loadFromFile("Assests/Ryo/WalkFront2.png");
		sprite[11].setTexture(texture[11]);
		texture[12].loadFromFile("Assests/Ryo/WalkFront3.png");
		sprite[12].setTexture(texture[12]);
		texture[13].loadFromFile("Assests/Ryo/WalkFront4.png");
		sprite[13].setTexture(texture[13]);
		texture[14].loadFromFile("Assests/Ryo/WalkFront5.png");
		sprite[14].setTexture(texture[14]);
		texture[15].loadFromFile("Assests/Ryo/WalkFront6.png");
		sprite[15].setTexture(texture[15]);
		texture[16].loadFromFile("Assests/Ryo/WalkBack1.png");
		sprite[16].setTexture(texture[16]);
		texture[17].loadFromFile("Assests/Ryo/WalkBack2.png");
		sprite[17].setTexture(texture[17]);
		texture[18].loadFromFile("Assests/Ryo/WalkBack3.png");
		sprite[18].setTexture(texture[18]);
		texture[19].loadFromFile("Assests/Ryo/WalkBack4.png");
		sprite[19].setTexture(texture[19]);
		texture[20].loadFromFile("Assests/Ryo/WalkBack5.png");
		sprite[20].setTexture(texture[20]);
		texture[21].loadFromFile("Assests/Ryo/Jump1.png");
		sprite[21].setTexture(texture[21]);
		texture[22].loadFromFile("Assests/Ryo/Jump2.png");
		sprite[22].setTexture(texture[22]);
		texture[23].loadFromFile("Assests/Ryo/Jump3.png");
		sprite[23].setTexture(texture[23]);
		texture[25].loadFromFile("Assests/Ryo/Punch1.png");
		sprite[25].setTexture(texture[25]);
		texture[26].loadFromFile("Assests/Ryo/Punch2.png");
		sprite[26].setTexture(texture[26]);
		texture[27].loadFromFile("Assests/Ryo/Punch3.png");
		sprite[27].setTexture(texture[27]);
		texture[28].loadFromFile("Assests/Ryo/Punch4.png");
		sprite[28].setTexture(texture[28]);
		texture[29].loadFromFile("Assests/Ryo/Punch5.png");
		sprite[29].setTexture(texture[29]);
		texture[30].loadFromFile("Assests/Ryo/Punch6.png");
		sprite[30].setTexture(texture[30]);
		texture[31].loadFromFile("Assests/Ryo/Punch7.png");
		sprite[31].setTexture(texture[31]);
		texture[32].loadFromFile("Assests/Ryo/Punch8.png");
		sprite[32].setTexture(texture[32]);
		texture[33].loadFromFile("Assests/Ryo/Punch9.png");
		sprite[33].setTexture(texture[33]);
		texture[34].loadFromFile("Assests/Ryo/Kick1.png");
		sprite[34].setTexture(texture[34]);
		texture[35].loadFromFile("Assests/Ryo/Kick2.png");
		sprite[35].setTexture(texture[35]);
		texture[36].loadFromFile("Assests/Ryo/Kick3.png");
		sprite[36].setTexture(texture[36]);
		texture[37].loadFromFile("Assests/Ryo/Kick4.png");
		sprite[37].setTexture(texture[37]);
		texture[38].loadFromFile("Assests/Ryo/Kick5.png");
		sprite[38].setTexture(texture[38]);
		texture[39].loadFromFile("Assests/Ryo/Kick6.png");
		sprite[39].setTexture(texture[39]);
		texture[40].loadFromFile("Assests/Ryo/Kick7.png");
		sprite[40].setTexture(texture[40]);
		texture[41].loadFromFile("Assests/Ryo/Kick8.png");
		sprite[41].setTexture(texture[41]);
		texture[42].loadFromFile("Assests/Ryo/Combo1.png");
		sprite[42].setTexture(texture[42]);
		texture[43].loadFromFile("Assests/Ryo/Combo2.png");
		sprite[43].setTexture(texture[43]);
		texture[44].loadFromFile("Assests/Ryo/Combo3.png");
		sprite[44].setTexture(texture[44]);
		texture[45].loadFromFile("Assests/Ryo/Combo4.png");
		sprite[45].setTexture(texture[45]);
		texture[46].loadFromFile("Assests/Ryo/Combo5.png");
		sprite[46].setTexture(texture[46]);
		texture[47].loadFromFile("Assests/Ryo/Combo6.png");
		sprite[47].setTexture(texture[47]);
		texture[48].loadFromFile("Assests/Ryo/Combo7.png");
		sprite[48].setTexture(texture[48]);
		texture[49].loadFromFile("Assests/Ryo/Combo8.png");
		sprite[49].setTexture(texture[49]);
		texture[50].loadFromFile("Assests/Ryo/Combo9.png");
		sprite[50].setTexture(texture[50]);
		texture[51].loadFromFile("Assests/Ryo/Combo10.png");
		sprite[51].setTexture(texture[51]);
		texture[52].loadFromFile("Assests/Ryo/Block1.png");
		sprite[52].setTexture(texture[52]);
		texture[53].loadFromFile("Assests/Ryo/Block2.png");
		sprite[53].setTexture(texture[53]);
		texture[54].loadFromFile("Assests/Ryo/Block3.png");
		sprite[54].setTexture(texture[54]);
		texture[55].loadFromFile("Assests/Ryo/Dead1.png");
		sprite[55].setTexture(texture[55]);
		texture[56].loadFromFile("Assests/Ryo/Dead2.png");
		sprite[56].setTexture(texture[56]);
		texture[57].loadFromFile("Assests/Ryo/Dead3.png");
		sprite[57].setTexture(texture[57]);
		texture[58].loadFromFile("Assests/Ryo/Dead4.png");
		sprite[58].setTexture(texture[58]);
	}
	~Ryo()
	{
		health = 0;
	}
	void setHealth(int health)
	{
		this->health = health;
	}
	int getHealth()const
	{
		return this->health;
	}
	void Ready(bool status)
	{
		if (status == true)
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
		}
	}
	void Idle(bool status)
	{
		if (status == false)
		{
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
			sprite[7].setScale(
				targetSize.x / sprite[7].getLocalBounds().width,
				targetSize.y / sprite[7].getLocalBounds().height);
			sprite[7].setPosition(pos);
		}
	}
	bool Duck()
	{
		if (Keyboard::isKeyPressed(Keyboard::K))
		{
			float tmpy = pos.y + 25;
			sprite[8].setScale(
				targetSize.x / sprite[8].getLocalBounds().width,
				targetSize.y / sprite[8].getLocalBounds().height);
			sprite[8].setPosition(pos.x, tmpy);
			sprite[9].setScale(
				targetSize.x / sprite[9].getLocalBounds().width,
				targetSize.y / sprite[9].getLocalBounds().height);
			sprite[9].setPosition(pos.x, tmpy);
			return true;
		}
		return false;
	}
	bool WalkFront()
	{
		if (Keyboard::isKeyPressed(Keyboard::J))
		{
			if (pos.x >= 0.0f )
			{
				pos.x = pos.x - 15;
			}
			sprite[10].setScale(
				targetSize.x / sprite[10].getLocalBounds().width,
				targetSize.y / sprite[10].getLocalBounds().height);
			sprite[10].setPosition(pos.x, pos.y);
			sprite[11].setScale(
				targetSize.x / sprite[11].getLocalBounds().width,
				targetSize.y / sprite[11].getLocalBounds().height);
			sprite[11].setPosition(pos.x, pos.y);
			sprite[12].setScale(
				targetSize.x / sprite[12].getLocalBounds().width,
				targetSize.y / sprite[12].getLocalBounds().height);
			sprite[12].setPosition(pos.x, pos.y);
			sprite[13].setScale(
				targetSize.x / sprite[13].getLocalBounds().width,
				targetSize.y / sprite[13].getLocalBounds().height);
			sprite[13].setPosition(pos.x, pos.y);
			sprite[14].setScale(
				targetSize.x / sprite[14].getLocalBounds().width,
				targetSize.y / sprite[14].getLocalBounds().height);
			sprite[14].setPosition(pos.x, pos.y);
			sprite[15].setScale(
				targetSize.x / sprite[15].getLocalBounds().width,
				targetSize.y / sprite[15].getLocalBounds().height);
			sprite[15].setPosition(pos.x, pos.y);
			return true;
		}
		return false;
	}
	bool WalkBack()
	{
		if (Keyboard::isKeyPressed(Keyboard::L))
		{
			if (pos.x <= 1100.0f)
			{
				pos.x = pos.x + 15;
			}
			sprite[16].setScale(
				targetSize.x / sprite[16].getLocalBounds().width,
				targetSize.y / sprite[16].getLocalBounds().height);
			sprite[16].setPosition(pos.x, pos.y);
			sprite[17].setScale(
				targetSize.x / sprite[17].getLocalBounds().width,
				targetSize.y / sprite[17].getLocalBounds().height);
			sprite[17].setPosition(pos.x, pos.y);
			sprite[18].setScale(
				targetSize.x / sprite[18].getLocalBounds().width,
				targetSize.y / sprite[18].getLocalBounds().height);
			sprite[18].setPosition(pos.x, pos.y);
			sprite[19].setScale(
				targetSize.x / sprite[19].getLocalBounds().width,
				targetSize.y / sprite[19].getLocalBounds().height);
			sprite[19].setPosition(pos.x, pos.y);
			sprite[20].setScale(
				targetSize.x / sprite[20].getLocalBounds().width,
				targetSize.y / sprite[20].getLocalBounds().height);
			sprite[20].setPosition(pos.x, pos.y);
			return true;
		}
		return false;
	}
	bool Jump()
	{
		if (Keyboard::isKeyPressed(Keyboard::I))
		{
			float tmpy = pos.y;
			sprite[21].setScale(
				targetSize.x / sprite[21].getLocalBounds().width,
				targetSize.y / sprite[21].getLocalBounds().height);
			sprite[21].setPosition(pos.x, pos.y);
			sprite[22].setScale(
				targetSize.x / sprite[22].getLocalBounds().width,
				targetSize.y / sprite[22].getLocalBounds().height);
			sprite[22].setPosition(pos.x, (tmpy - 100.0f));
			sprite[23].setScale(
				targetSize.x / sprite[23].getLocalBounds().width,
				targetSize.y / sprite[23].getLocalBounds().height);
			sprite[23].setPosition(pos.x, (tmpy - 150.0f));
			return true;
		}
		return false;
	}
	bool Punch()
	{
		if (Keyboard::isKeyPressed(Keyboard::V))
		{
			sprite[25].setScale(
				targetSize.x / sprite[25].getLocalBounds().width,
				targetSize.y / sprite[25].getLocalBounds().height);
			sprite[25].setPosition(pos);
			sprite[26].setScale(
				targetSize.x / sprite[26].getLocalBounds().width,
				targetSize.y / sprite[26].getLocalBounds().height);
			sprite[26].setPosition(pos);
			sprite[27].setScale(
				targetSize.x / sprite[27].getLocalBounds().width,
				targetSize.y / sprite[27].getLocalBounds().height);
			sprite[27].setPosition(pos);
			sprite[28].setScale(
				targetSize.x / sprite[28].getLocalBounds().width,
				targetSize.y / sprite[28].getLocalBounds().height);
			sprite[28].setPosition(pos);
			sprite[29].setScale(
				targetSize.x / sprite[29].getLocalBounds().width,
				targetSize.y / sprite[29].getLocalBounds().height);
			sprite[29].setPosition(pos);
			sprite[30].setScale(
				targetSize.x / sprite[30].getLocalBounds().width,
				targetSize.y / sprite[30].getLocalBounds().height);
			sprite[30].setPosition(pos);
			sprite[31].setScale(
				targetSize.x / sprite[31].getLocalBounds().width,
				targetSize.y / sprite[31].getLocalBounds().height);
			sprite[31].setPosition(pos);
			sprite[32].setScale(
				targetSize.x / sprite[32].getLocalBounds().width,
				targetSize.y / sprite[32].getLocalBounds().height);
			sprite[32].setPosition(pos);
			sprite[33].setScale(
				targetSize.x / sprite[33].getLocalBounds().width,
				targetSize.y / sprite[33].getLocalBounds().height);
			sprite[33].setPosition(pos);
			return true;
		}
		return false;
	}
	bool Kick()
	{

		if (Keyboard::isKeyPressed(Keyboard::B))
		{
			sprite[34].setScale(
				targetSize.x / sprite[34].getLocalBounds().width,
				targetSize.y / sprite[34].getLocalBounds().height);
			sprite[34].setPosition(pos);
			sprite[35].setScale(
				targetSize.x / sprite[35].getLocalBounds().width,
				targetSize.y / sprite[35].getLocalBounds().height);
			sprite[35].setPosition(pos);
			sprite[36].setScale(
				targetSize.x / sprite[36].getLocalBounds().width,
				targetSize.y / sprite[36].getLocalBounds().height);
			sprite[36].setPosition(pos);
			sprite[37].setScale(
				targetSize.x / sprite[37].getLocalBounds().width,
				targetSize.y / sprite[37].getLocalBounds().height);
			sprite[37].setPosition(pos);
			sprite[38].setScale(
				targetSize.x / sprite[38].getLocalBounds().width,
				targetSize.y / sprite[38].getLocalBounds().height);
			sprite[38].setPosition(pos);
			sprite[39].setScale(
				targetSize.x / sprite[39].getLocalBounds().width,
				targetSize.y / sprite[39].getLocalBounds().height);
			sprite[39].setPosition(pos);
			sprite[40].setScale(
				targetSize.x / sprite[40].getLocalBounds().width,
				targetSize.y / sprite[40].getLocalBounds().height);
			sprite[40].setPosition(pos);
			sprite[41].setScale(
				targetSize.x / sprite[41].getLocalBounds().width,
				targetSize.y / sprite[41].getLocalBounds().height);
			sprite[41].setPosition(pos);
			return true;
		}
		return false;
	}
	bool Combo()
	{
		if (Keyboard::isKeyPressed(Keyboard::N))
		{
			sprite[42].setScale(
				targetSize.x / sprite[72].getLocalBounds().width,
				targetSize.y / sprite[72].getLocalBounds().height);
			sprite[42].setPosition(pos);
			sprite[43].setScale(
				targetSize.x / sprite[43].getLocalBounds().width,
				targetSize.y / sprite[43].getLocalBounds().height);
			sprite[43].setPosition(pos);
			sprite[44].setScale(
				targetSize.x / sprite[44].getLocalBounds().width,
				targetSize.y / sprite[44].getLocalBounds().height);
			sprite[44].setPosition(pos);
			sprite[45].setScale(
				targetSize.x / sprite[45].getLocalBounds().width,
				targetSize.y / sprite[45].getLocalBounds().height);
			sprite[45].setPosition(pos);
			sprite[46].setScale(
				targetSize.x / sprite[46].getLocalBounds().width,
				targetSize.y / sprite[46].getLocalBounds().height);
			sprite[46].setPosition(pos);
			sprite[47].setScale(
				targetSize.x / sprite[47].getLocalBounds().width,
				targetSize.y / sprite[47].getLocalBounds().height);
			sprite[47].setPosition(pos);
			sprite[48].setScale(
				targetSize.x / sprite[48].getLocalBounds().width,
				targetSize.y / sprite[48].getLocalBounds().height);
			sprite[48].setPosition(pos);
			sprite[49].setScale(
				targetSize.x / sprite[49].getLocalBounds().width,
				targetSize.y / sprite[49].getLocalBounds().height);
			sprite[49].setPosition(pos);
			sprite[50].setScale(
				targetSize.x / sprite[50].getLocalBounds().width,
				targetSize.y / sprite[50].getLocalBounds().height);
			sprite[50].setPosition(pos);
			sprite[51].setScale(
				targetSize.x / sprite[51].getLocalBounds().width,
				targetSize.y / sprite[51].getLocalBounds().height);
			sprite[51].setPosition(pos);
			sprite[52].setScale(
				targetSize.x / sprite[52].getLocalBounds().width,
				targetSize.y / sprite[52].getLocalBounds().height);
			sprite[52].setPosition(pos);
			sprite[53].setScale(
				targetSize.x / sprite[53].getLocalBounds().width,
				targetSize.y / sprite[53].getLocalBounds().height);
			sprite[53].setPosition(pos);
			sprite[54].setScale(
				targetSize.x / sprite[54].getLocalBounds().width,
				targetSize.y / sprite[54].getLocalBounds().height);
			sprite[54].setPosition(pos);
			sprite[55].setScale(
				targetSize.x / sprite[55].getLocalBounds().width,
				targetSize.y / sprite[55].getLocalBounds().height);
			sprite[55].setPosition(pos);
			sprite[56].setScale(
				targetSize.x / sprite[56].getLocalBounds().width,
				targetSize.y / sprite[56].getLocalBounds().height);
			sprite[56].setPosition(pos);
			return true;
		}
		return false;
	}
	bool Dead()
	{

		if (health <= 0)
		{
			sprite[55].setScale(
				targetSize.x / sprite[55].getLocalBounds().width,
				targetSize.y / sprite[55].getLocalBounds().height);
			sprite[55].setPosition(pos);
			sprite[56].setScale(
				targetSize.x / sprite[56].getLocalBounds().width,
				targetSize.y / sprite[56].getLocalBounds().height);
			sprite[56].setPosition(pos);
			sprite[57].setScale(
				targetSize.x / sprite[57].getLocalBounds().width,
				targetSize.y / sprite[57].getLocalBounds().height);
			sprite[57].setPosition(pos.x, (pos.y + 125));
			sprite[58].setScale(
				targetSize.x / sprite[58].getLocalBounds().width,
				targetSize.y / sprite[58].getLocalBounds().height);
			sprite[58].setPosition(pos.x, (pos.y + 125));
			return true;
		}
		return false;
	}
	bool Block()
	{

		if (Keyboard::isKeyPressed(Keyboard::M))
		{
			sprite[52].setScale(
				targetSize.x / sprite[52].getLocalBounds().width,
				targetSize.y / sprite[52].getLocalBounds().height);
			sprite[52].setPosition(pos);
			sprite[53].setScale(
				targetSize.x / sprite[53].getLocalBounds().width,
				targetSize.y / sprite[53].getLocalBounds().height);
			sprite[54].setPosition(pos);
			sprite[54].setScale(
				targetSize.x / sprite[54].getLocalBounds().width,
				targetSize.y / sprite[54].getLocalBounds().height);
			sprite[54].setPosition(pos);
			return true;
		}
		return false;
	}
	void setPos(Vector2f pos)
	{
		this->pos = pos;
	}
};
class Level1:public Levels
{
	Font font;
	Text txt[8];
	Iori iori;
	Ryo ryo;
public:
	Level1(string adress = "Assests/level1bg.jpg",string name = "Level 1") :Levels(adress,name)
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
		//Health
		string str = to_string(iori.getHealth());
		txt[4].setFont(font);
		if (iori.getHealth() <= 0)
		{
			str = '0';
			txt[4].setColor(Color::Red);
		}
		else
		{
			txt[4].setColor(Color::Green);
		}
		txt[4].setString(str);
		txt[4].setPosition(75.0f, 0.1f);
		txt[4].setCharacterSize(72);
		//Player 2
		txt[3].setFont(font);
		txt[3].setString("Player 2");
		txt[3].setPosition(1150.0f, 50.0f);
		txt[3].setColor(Color::Black);
		txt[3].setCharacterSize(48);
		//Helth
		string str1 = to_string(ryo.getHealth());
		txt[5].setFont(font);
		if (ryo.getHealth()<=0)
		{
			str1 = '0';
			txt[5].setColor(Color::Red);
		}
		else
		{
			txt[5].setColor(Color::Green);
		}
		txt[5].setString(str1);
		txt[5].setPosition(1150.0f, 0.1f);
		txt[5].setCharacterSize(72);
		//Player  1 WIns
		txt[6].setFont(font);
		txt[6].setString("Player 1 Wins");
		txt[6].setPosition(600.0f, 350.0f);
		txt[6].setColor(Color::Green);
		txt[6].setCharacterSize(72);
		//Player 2 Wins
		txt[7].setFont(font);
		txt[7].setString("Player 2 Wins");
		txt[7].setPosition(600.0f, 350.0f);
		txt[7].setColor(Color::Green);
		txt[7].setCharacterSize(72);
	}
	//getter
	Text gettxt(int i)
	{
		return txt[i];
	}
	//ioriwrappers
	void IW_setHealth(int health)
	{
		iori.setHealth(health);
	}
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
	bool IW_Duck()
	{
		return iori.Duck();
	}
	bool IW_WalkFront()
	{
		return iori.WalkFront();
	}
	bool IW_WalkBack()
	{
		return iori.WalkBack();
	}
	bool IW_Jump()
	{
		return iori.Jump();
	}
	bool IW_Punch()
	{
		return iori.Punch();
	}
	bool IW_Kick()
	{
		return iori.Kick();
	}
	bool IW_Combo()
	{
		return iori.Combo();
	}
	bool IW_Block()
	{
		return iori.Block();
	}
	bool IW_Dead()
	{
		return iori.Dead();
	}
	Sprite IW_getSprite(int i)
	{
		return iori.getSprite(i);
	}
	void IW_setPos(Vector2f pos)
	{
		iori.setPos(pos);
	}
	//Ryo Wrappers
	void RW_setHealth(int health)
	{
		ryo.setHealth(health);
	}
	int RW_getHealth()
	{
		return ryo.getHealth();
	}
	void RW_Ready(bool status)
	{
		ryo.Ready(status);
	}
	void RW_Idle(bool key)
	{
		ryo.Idle(key);
	}
	bool RW_Duck()
	{
		return ryo.Duck();
	}
	bool RW_WalkFront()
	{
		return ryo.WalkFront();
	}
	bool RW_WalkBack()
	{
		return ryo.WalkBack();
	}
	bool RW_Jump()
	{
		return ryo.Jump();
	}
	bool RW_Punch()
	{
		return ryo.Punch();
	}
	bool RW_Kick()
	{
		return ryo.Kick();
	}
	bool RW_Combo()
	{
		return ryo.Combo();
	}
	bool RW_Block()
	{
		return ryo.Block();
	}
	bool RW_Dead()
	{
		return ryo.Dead();
	}
	Sprite RW_getSprite(int i)
	{
		return ryo.getSprite(i);
	}
	void RW_setPos(Vector2f pos)
	{
		ryo.setPos(pos);
	}
	//Game System
	void Game(int ioriPcontroller, int iorikcontroller, int ioriCcontroller,int ryoPcontroller, int ryokcontroller, int ryoCcontroller)
	{
		//for iori
		if (ryoPcontroller == 33 )
		{
				IntRect rect(ryo.getSprite(33).getGlobalBounds());
				IntRect rect1(iori.getSprite(15).getGlobalBounds());
				if (rect.intersects(rect1))
				{
					iori.setHealth(iori.getHealth() - 5);
				}
		}
		else if (ryokcontroller == 41)
		{
			IntRect rect(ryo.getSprite(41).getGlobalBounds());
			IntRect rect1(iori.getSprite(15).getGlobalBounds());
			if (rect.intersects(rect1))
			{
				iori.setHealth(iori.getHealth() - 5);
			}
		}
		else 
		{
			if ((ryoCcontroller==51))
			{
				IntRect rect(ryo.getSprite(51).getGlobalBounds());
				IntRect rect1(iori.getSprite(15).getGlobalBounds());
				if (rect.intersects(rect1))
				{
					iori.setHealth(iori.getHealth() - 20);
				}
			}
		}
		//for ryo
		if (ioriPcontroller == 61)
		{
			IntRect rect(iori.getSprite(61).getGlobalBounds());
			IntRect rect1(ryo.getSprite(7).getGlobalBounds());
			if (rect.intersects(rect1))
			{
				ryo.setHealth(ryo.getHealth() - 5);
			}
		}
		else if (iorikcontroller == 71)
		{
			IntRect rect(iori.getSprite(71).getGlobalBounds());
			IntRect rect1(ryo.getSprite(7).getGlobalBounds());
			if (rect.intersects(rect1))
			{
				ryo.setHealth(ryo.getHealth() - 5);
			}
		}
		else
		{
			if ((ioriCcontroller == 98))
			{
				IntRect rect(iori.getSprite(98).getGlobalBounds());
				IntRect rect1(ryo.getSprite(7).getGlobalBounds());
				if (rect.intersects(rect1))
				{
					ryo.setHealth(ryo.getHealth() - 20);
				}
			}
		}
	
	}
};

int main()
{
	RenderWindow window(VideoMode(800, 640), "Balistics Fighter", Style::Fullscreen);
	window.setFramerateLimit(60);
	mainmenu menu;
	Instruction instructions;
	Level1 lvl1;
	bool iskeyPressed = false, iskeyPressed2 = false;
	int flag = 0;
	bool is_Exit = false;
	bool is_chnglevel = false;
	int IW_comboBreaker = 0, RW_comboBreaker = 0;
	int nxtlvl = 0;
	bool f = false;
	int animcontrolller[11] = { 0, 7, 17,25,35,44,53,62,72,99,106};
	int animcontrolller2[11] = { 0, 4, 9, 10,16,21,25,34,42,52,55};
	Clock clock;
	//game music
	Music music[8];
	music[0].openFromFile("Assests/sound/Track_01.ogg");
	music[1].openFromFile("Assests/sound/Track_02.ogg");
	music[2].openFromFile("Assests/sound/Track_03.ogg");
	music[3].openFromFile("Assests/sound/Crowd.ogg");
	music[4].openFromFile("Assests/sound/End.ogg");
	music[5].openFromFile("Assests/sound/Kick.ogg");
	music[6].openFromFile("Assests/sound/Punch.ogg");
	music[7].openFromFile("Assests/sound/Start.ogg");
	music[3].play();
	music[3].setVolume(0);
	while (window.isOpen())
	{
		//music playing
		if (music[2].getStatus() == SoundSource::Stopped)
		{
			music[0].play();
			music[0].setVolume(40);
		}
		if (music[0].getStatus() == SoundSource::Stopped)
		{
			music[1].play();
			music[1].setVolume(40);
		}
		if (music[1].getStatus() == SoundSource::Stopped)
		{
			music[2].play();
			music[2].setVolume(40);
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
					animcontrolller[0] = 0;
					animcontrolller2[0] = 0;
					lvl1.IW_setHealth(100);
					lvl1.RW_setHealth(100);
					animcontrolller2[10] = 55;
					animcontrolller[10] = 106;
					Vector2f v(100.0f, 365.0f);
					lvl1.IW_setPos(v);
					v.x = 1100.0f;
					v.y = 365.0f;
					lvl1.RW_setPos(v);
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
		if (flag == 2)//if level 1 is to be displayed
		{
			lvl1.setPosition();
			window.draw(lvl1.getspbg());
			lvl1.draw();
			Time t1 = clock.getElapsedTime();
			if (t1.asSeconds() < 2.0f)
			{
				if (f == false)
				{
					music[7].play();
					music[7].setVolume(100);
					music[3].setVolume(5);
				}
				for (int i = 0; i < 2; i++)
				{
					window.draw(lvl1.gettxt(i));
				}
				//Ready Animation
				lvl1.IW_Ready(true);
				if (animcontrolller[0] >= 0 && animcontrolller[0] <= 6)
				{
					window.draw(lvl1.IW_getSprite(animcontrolller[0]));
					animcontrolller[0]++;
				}
				else
				{
					window.draw(lvl1.IW_getSprite(animcontrolller[0] - 1));
				}
				//Ryo Ready Animation
				lvl1.RW_Ready(true);
				if (animcontrolller2[0] >= 0 && animcontrolller2[0] <= 3)
				{
					window.draw(lvl1.RW_getSprite(animcontrolller2[0]));
					animcontrolller2[0]++;
				}
				else
				{
					window.draw(lvl1.RW_getSprite(animcontrolller2[0] - 1));
				}
				f = true;
			}
			for (int i = 2; i < 6; i++)
			{
				window.draw(lvl1.gettxt(i));
			}
			if (t1.asSeconds() > 2.0f)
			{
				music[3].setVolume(70);
				if (lvl1.RW_getHealth() > 0 && lvl1.IW_getHealth() > 0)
				{
					lvl1.Game(animcontrolller[6], animcontrolller[7], animcontrolller[8], animcontrolller2[6], animcontrolller2[7], animcontrolller2[8]);
					//Idle Animation
					if (iskeyPressed == false)
					{
						lvl1.IW_Idle(iskeyPressed);
						if (animcontrolller[1] >= 7 && animcontrolller[1] <= 15)
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[1]));
							animcontrolller[1]++;
						}
						else
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[1] - 1));
							animcontrolller[1] = 7;
						}
					}
					//Duck Animation
					if (lvl1.IW_Duck() == true)
					{
						iskeyPressed = true;
						if (animcontrolller[2] >= 16 && animcontrolller[2] < 24)
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[2]));
							animcontrolller[2]++;
						}
						else
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[2] - 1));
							animcontrolller[2] = 17;
						}
					}
					//Walk Front Animation
					else if (lvl1.IW_WalkFront() == true)
					{
						iskeyPressed = true;
						if (animcontrolller[3] >= 25 && animcontrolller[3] < 34)
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[3]));
							animcontrolller[3]++;
						}
						else
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[3] - 1));
							animcontrolller[3] = 25;
						}
					}
					//Walk Back Animation
					else if (lvl1.IW_WalkBack() == true)
					{
						iskeyPressed = true;
						if (animcontrolller[4] >= 35 && animcontrolller[4] < 43)
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[4]));
							animcontrolller[4]++;
						}
						else
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[4] - 1));
							animcontrolller[4] = 35;
						}
					}
					//Jump Animation
					else if (lvl1.IW_Jump() == true)
					{
						iskeyPressed = true;
						if (animcontrolller[5] >= 43 && animcontrolller[5] <= 49)
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[5]));
							animcontrolller[5]++;
						}
						else
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[5] - 1));
							animcontrolller[5] = 43;
						}
					}
					//Punch Animation
					else if (lvl1.IW_Punch() == true)
					{
						music[6].play();
						music[6].setVolume(100);
						iskeyPressed = true;
						if (animcontrolller[6] >= 53 && animcontrolller[6] <= 61)
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[6]));
							animcontrolller[6]++;
						}
						else
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[6] - 1));
							animcontrolller[6] = 53;
						}
					}
					//Kick Animation
					else if (lvl1.IW_Kick() == true)
					{
						music[5].play();
						music[5].setVolume(100);
						iskeyPressed = true;
						if (animcontrolller[7] >= 62 && animcontrolller[7] <= 71)
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[7]));
							animcontrolller[7]++;
						}
						else
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[7] - 1));
							animcontrolller[7] = 62;
						}
					}
					//combo Animation
					else if (lvl1.IW_Combo() == true)
					{
						iskeyPressed = true;
						if (IW_comboBreaker >= 2) 
						{
							if (animcontrolller[8] >= 72 && animcontrolller[8] <= 98)
							{
								window.draw(lvl1.IW_getSprite(animcontrolller[8]));
								animcontrolller[8]++;
							}
							else
							{
								window.draw(lvl1.IW_getSprite(animcontrolller[8] - 1));
								animcontrolller[8] = 72;
							}
							IW_comboBreaker++;
						}
					}
					//Block Animation
					else if (lvl1.IW_Block() == true)
					{
						iskeyPressed = true;
						if (animcontrolller[9] >= 99 && animcontrolller[9] < 105)
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[9]));
							animcontrolller[9]++;
						}
						else
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[9] - 1));
							animcontrolller[9] = 99;
						}
					}
					//Dead Animation
					else if (lvl1.IW_Dead() == true)
					{
						iskeyPressed = true;
						if (animcontrolller[10] >= 106 && animcontrolller[10] < 115)
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[10]));
							animcontrolller[10]++;
							Sleep(100);
						}
						else
						{
							window.draw(lvl1.IW_getSprite(animcontrolller[10]));
						}
					}
					else
					{
						iskeyPressed = false;
					}
					//Ryo
					//Idle Animation
					if (iskeyPressed2 == false)
					{
						lvl1.RW_Idle(iskeyPressed2);
						if (animcontrolller2[1] >= 4 && animcontrolller2[1] <= 7)
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[1]));
							animcontrolller2[1]++;
						}
						else
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[1] - 1));
							animcontrolller2[1] = 4;
						}
					}
					//Duck Animation
					if (lvl1.RW_Duck() == true)
					{
						iskeyPressed2 = true;
						if (animcontrolller2[2] >= 9 && animcontrolller2[2] <10)
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[2]));
							animcontrolller2[2]++;
						}
						else
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[2] - 1));
							animcontrolller2[2] = 9;
						}
					}
					//Walk Front Animation
					else if (lvl1.RW_WalkFront() == true)
					{
						iskeyPressed2 = true;
						if (animcontrolller2[3] >= 10 && animcontrolller2[3] < 16)
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[3]));
							animcontrolller2[3]++;
						}
						else
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[3] - 1));
							animcontrolller2[3] = 10;
						}
					}
					//Walk Back Animation
					else if (lvl1.RW_WalkBack() == true)
					{
						iskeyPressed2 = true;
						if (animcontrolller2[4] >= 16 && animcontrolller2[4] <= 20)
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[4]));
							animcontrolller2[4]++;
						}
						else
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[4] - 1));
							animcontrolller2[4] = 16;
						}
					}
					//Jump Animation
					else if (lvl1.RW_Jump() == true)
					{
						iskeyPressed2 = true;
						if (animcontrolller2[5] >= 21 && animcontrolller2[5] <= 23)
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[5]));
							animcontrolller2[5]++;
						}
						else
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[5] - 1));
							animcontrolller2[5] = 21;
						}
					}
					//Punch Animation
					else if (lvl1.RW_Punch() == true)
					{
						music[6].play();
						music[6].setVolume(100);
						iskeyPressed2 = true;
						if (animcontrolller2[6] >= 25 && animcontrolller2[6] <= 33)
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[6]));
							animcontrolller2[6]++;
						}
						else
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[6] - 1));
							animcontrolller2[6] = 25;
						}
						
					}
					//Kick Animation
					else if (lvl1.RW_Kick() == true)
					{
						music[5].play();
						music[5].setVolume(100);
						iskeyPressed2 = true;
						if (animcontrolller2[7] >= 34 && animcontrolller2[7] <= 41)
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[7]));
							animcontrolller2[7]++;
						}
						else
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[7] - 1));
							animcontrolller2[7] = 34;
						}
						
					}
					//Combo Animation
					else if (lvl1.RW_Combo() == true)
					{
						iskeyPressed2 = true;
						if (RW_comboBreaker <= 2) 
						{
							if (animcontrolller2[8] >= 42 && animcontrolller2[8] <= 51)
							{
								window.draw(lvl1.RW_getSprite(animcontrolller2[8]));
								animcontrolller2[8]++;
							}
							else
							{
								window.draw(lvl1.RW_getSprite(animcontrolller2[8] - 1));
								animcontrolller2[8] = 42;
							}
							RW_comboBreaker++;
						}
					}
					//Block Animation
					else if (lvl1.RW_Block() == true)
					{
						iskeyPressed2 = true;
						if (animcontrolller2[9] >= 52 && animcontrolller2[9] < 55)
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[9]));
							animcontrolller2[9]++;
						}
						else
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[9] - 1));
							animcontrolller2[9] = 52;
						}
					}
					//Dead Animation
					else if (lvl1.RW_Dead() == true)
					{
						iskeyPressed2 = true;
						if (animcontrolller2[10] >= 55 && animcontrolller2[10] < 58)
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[10]));
							animcontrolller2[10]++;
							Sleep(70);
						}
						else
						{
							window.draw(lvl1.RW_getSprite(animcontrolller2[10]));
						}
					}
					else
					{
						iskeyPressed2 = false;
						f = false;
					}
				}
				else
				{
					lvl1.draw();
					if (f == false)
					{
						music[3].setVolume(20);
						music[4].play();
						music[4].setVolume(100);
					}
					if (lvl1.IW_getHealth() <= 0)
					{

						window.draw(lvl1.gettxt(7));
						window.draw(lvl1.RW_getSprite(6));
						window.draw(lvl1.IW_getSprite(115));
					}
					else
					{
						window.draw(lvl1.gettxt(6));
						window.draw(lvl1.IW_getSprite(3));
						window.draw(lvl1.RW_getSprite(58));
					}
					f = true;
				}
			}
		}

		window.display();
		Sleep(50);
	}
	return 0;
}