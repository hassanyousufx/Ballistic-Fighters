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
		for (int i = 0; i < 7; i++) {
			tx[i].setFont(font);							// set font style
			tx[i].setColor(Color::White);					// set font color
			tx[i].setCharacterSize(52);						// set font size, same for all below texts
		}

		//strings setting					
		tx[0].setString("Instructions");
		tx[0].setPosition(300.0f, 50.0f);					// set position
		tx[0].setCharacterSize(172);						
		//setting
		tx[1].setString("Arrow Keys to Move Character");
		tx[1].setPosition(300.0f, 250.0f);					// set position
		//setting
		tx[2].setString("Use A to Punch");
		tx[2].setPosition(300.0f, 300.f);					// set position
		//setting
		tx[3].setString("Use S To Kick");
		tx[3].setPosition(300.0f, 350.0f);					// set position
		//setting
		tx[4].setString("Use D To Combo : Note it will reduce your health 20% too");
		tx[4].setPosition(300.0f, 400.0f);					// set position
		//setting
		tx[5].setString("Use F To Block");
		tx[5].setPosition(300.0f, 450.0f);					// set position
		//setting
		tx[6].setString("Back to Main Menu");
		tx[6].setPosition(300.0f, 550.0f);					// set position

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
		{	// use loops to load sprites
			texture[i].loadFromFile("Assests/Iori/Ready" + std::to_string(i + 1) + ".png");
			sprite[i].setTexture(texture[i]);
		}

		// you need to load textures from assets manually
		// and load all 116 sprites manually, won't work via loops
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
		
		// load sprites via loops
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
		if (status == true)	// use loops to load sprite bounds
			for (int i = 0; i < 7; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
	}

	void Idle(bool status) {
		if (status == false) // use loops to load sprite bounds
			for (int i = 7; i < 16; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
	}

	bool Duck() {
		if (Keyboard::isKeyPressed(Keyboard::Down)) { // use loops to load sprite bounds
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
		if (Keyboard::isKeyPressed(Keyboard::Right)) { // use loops to load sprite bounds
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
		if (Keyboard::isKeyPressed(Keyboard::Left)) { // use loops to load sprite bounds
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
		if (Keyboard::isKeyPressed(Keyboard::Up)) { // manually set sprite bounds for jump
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
		if (Keyboard::isKeyPressed(Keyboard::A)) { // use loops to load sprite bounds
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
		if (Keyboard::isKeyPressed(Keyboard::S)) { // use loops to load sprite bounds
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
		if (Keyboard::isKeyPressed(Keyboard::D)) { // use loops to load sprite bounds
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
		if (Keyboard::isKeyPressed(Keyboard::F)) { // use loops to load sprite bounds
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
			for (int i = 106; i < 116; i++) { // use loops to load sprite bounds
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
	// this will be our player 2
	// set health of player 2
	int health;
	// pre-defined SFML class, composed
	Vector2f targetSize;
	Vector2f pos;
public:
	Ryo(string name = "RYO") :characters(name) {
		// initialize pointer array
		texture = new Texture[59];
		sprite = new Sprite[59];
		pos.x = 1100.0f;
		pos.y = 365.0f;
		// set position and targetSize i.e where
		// do you want your sprites (characters)
		// to be displayed
		targetSize.x = 250.0f;
		targetSize.y = 400.0f;
		health = 100;
		// load sprites from loadFromFile

		texture[0].loadFromFile("Assests/Ryo/Ready1.png");
		texture[1].loadFromFile("Assests/Ryo/Ready2.png");
		texture[2].loadFromFile("Assests/Ryo/Ready3.png");
		texture[3].loadFromFile("Assests/Ryo/Ready4.png");
		texture[4].loadFromFile("Assests/Ryo/Idle1.png");
		texture[5].loadFromFile("Assests/Ryo/Idle2.png");
		texture[6].loadFromFile("Assests/Ryo/Idle3.png");
		texture[7].loadFromFile("Assests/Ryo/Idle4.png");
		texture[8].loadFromFile("Assests/Ryo/Duck1.png");
		texture[9].loadFromFile("Assests/Ryo/Duck2.png");
		texture[10].loadFromFile("Assests/Ryo/WalkFront1.png");
		texture[11].loadFromFile("Assests/Ryo/WalkFront2.png");
		texture[12].loadFromFile("Assests/Ryo/WalkFront3.png");
		texture[13].loadFromFile("Assests/Ryo/WalkFront4.png");
		texture[14].loadFromFile("Assests/Ryo/WalkFront5.png");
		texture[15].loadFromFile("Assests/Ryo/WalkFront6.png");
		texture[16].loadFromFile("Assests/Ryo/WalkBack1.png");
		texture[17].loadFromFile("Assests/Ryo/WalkBack2.png");
		texture[18].loadFromFile("Assests/Ryo/WalkBack3.png");
		texture[19].loadFromFile("Assests/Ryo/WalkBack4.png");
		texture[20].loadFromFile("Assests/Ryo/WalkBack5.png");
		texture[21].loadFromFile("Assests/Ryo/Jump1.png");
		texture[22].loadFromFile("Assests/Ryo/Jump2.png");
		texture[23].loadFromFile("Assests/Ryo/Jump3.png");
		texture[25].loadFromFile("Assests/Ryo/Punch1.png");
		texture[26].loadFromFile("Assests/Ryo/Punch2.png");
		texture[27].loadFromFile("Assests/Ryo/Punch3.png");
		texture[28].loadFromFile("Assests/Ryo/Punch4.png");
		texture[29].loadFromFile("Assests/Ryo/Punch5.png");
		texture[30].loadFromFile("Assests/Ryo/Punch6.png");
		texture[31].loadFromFile("Assests/Ryo/Punch7.png");
		texture[32].loadFromFile("Assests/Ryo/Punch8.png");
		texture[33].loadFromFile("Assests/Ryo/Punch9.png");
		texture[34].loadFromFile("Assests/Ryo/Kick1.png");
		texture[35].loadFromFile("Assests/Ryo/Kick2.png");
		texture[36].loadFromFile("Assests/Ryo/Kick3.png");
		texture[37].loadFromFile("Assests/Ryo/Kick4.png");
		texture[38].loadFromFile("Assests/Ryo/Kick5.png");
		texture[39].loadFromFile("Assests/Ryo/Kick6.png");
		texture[40].loadFromFile("Assests/Ryo/Kick7.png");
		texture[41].loadFromFile("Assests/Ryo/Kick8.png");
		texture[42].loadFromFile("Assests/Ryo/Combo1.png");
		texture[43].loadFromFile("Assests/Ryo/Combo2.png");
		texture[44].loadFromFile("Assests/Ryo/Combo3.png");
		texture[45].loadFromFile("Assests/Ryo/Combo4.png");
		texture[46].loadFromFile("Assests/Ryo/Combo5.png");
		texture[47].loadFromFile("Assests/Ryo/Combo6.png");
		texture[48].loadFromFile("Assests/Ryo/Combo7.png");
		texture[49].loadFromFile("Assests/Ryo/Combo8.png");
		texture[50].loadFromFile("Assests/Ryo/Combo9.png");
		texture[51].loadFromFile("Assests/Ryo/Combo10.png");
		texture[52].loadFromFile("Assests/Ryo/Block1.png");
		texture[53].loadFromFile("Assests/Ryo/Block2.png");
		texture[54].loadFromFile("Assests/Ryo/Block3.png");
		texture[55].loadFromFile("Assests/Ryo/Dead1.png");
		texture[56].loadFromFile("Assests/Ryo/Dead2.png");
		texture[57].loadFromFile("Assests/Ryo/Dead3.png");
		texture[58].loadFromFile("Assests/Ryo/Dead4.png");

		for (int i = 0; i < 59; i++) 
			sprite[i].setTexture(texture[i]);
	}
	~Ryo() {
		health = 0;
	}
	
	void setHealth(int health) {
		this->health = health;
	}

	int getHealth()const {
		return this->health;
	}

	void Ready(bool status) {
		if (status == true)
			for (int i = 0; i < 4; i++) { // use loops to load sprite bounds
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
	}

	void Idle(bool status) {
		if (status == false)
			for (int i = 4; i < 8; i++) { // use loops to load sprite bounds
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
	}

	bool Duck()
	{
		float tmpy = pos.y + 25;
		if (Keyboard::isKeyPressed(Keyboard::K)) { // use loops to load sprite bounds
			for (int i = 8; i < 10; i++) {
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
		if (Keyboard::isKeyPressed(Keyboard::J)) { // use loops to load sprite bounds
			if (pos.x >= 0.0f )
				pos.x = pos.x - 15;

			for (int i = 10; i < 16; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos.x, pos.y);
			}
			return true;
		}
		return false;
	}

	bool WalkBack() {
		if (Keyboard::isKeyPressed(Keyboard::L)) { // use loops to load sprite bounds
			if (pos.x <= 1100.0f)
				pos.x = pos.x + 15;
			
			for (int i = 16; i < 21; i++) {
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
		if (Keyboard::isKeyPressed(Keyboard::I)) { // manually load sprite bounds for jump
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

	bool Punch() {
		if (Keyboard::isKeyPressed(Keyboard::V)) { // use loops to load sprite bounds
			for (int i = 25; i < 34; i++) {
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
		if (Keyboard::isKeyPressed(Keyboard::B)) { // use loops to load sprite bounds
			for (int i = 34; i < 42; i++) {
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
		if (Keyboard::isKeyPressed(Keyboard::N)) { // use loops to load sprite bounds
			for (int i = 42; i < 57; i++) {
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
			for (int i = 55; i < 59; i++) { // use loops to load sprite bounds
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
		if (Keyboard::isKeyPressed(Keyboard::M)) { // use loops to load sprite bounds
			for (int i = 52; i < 55; i++) {
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
class Level1:public Levels
{
	// pre-defined classes in SFML
	// composed and inherited
	Font font;
	Text txt[8];
	// compose characters in Level 1
	Iori iori;
	Ryo ryo;
public:
	Level1(string adress = "Assests/level1bg.jpg",string name = "Level 1") :Levels(adress,name) {
		font.loadFromFile("Assests/SouthernAire.ttf");
	}

	~Level1() {
		setTxbg("NULL");
		setName("NULL");
	}

	//Methods
	bool back() {
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			return true;
		
		return false;
	}
	void draw()
	{
		//Level name
		txt[0].setFont(font);							// set font style
		txt[0].setString(getName());					// get name
		txt[0].setPosition(600.0f, 250.0f);				// set text position
		txt[0].setColor(Color::Red);					// get font size
		txt[0].setCharacterSize(72);
		//Ready
		txt[1].setFont(font);							// set font style
		txt[1].setString("Ready");						// get name
		txt[1].setPosition(600.0f, 350.0f);				// set text position
		txt[1].setColor(Color::Red);					// get font size
		txt[1].setCharacterSize(72);
		//Player 1
		txt[2].setFont(font);							// self-explanatory
		txt[2].setString("Player 1");
		txt[2].setPosition(75.0f, 50.0f);
		txt[2].setColor(Color::Black);
		txt[2].setCharacterSize(48);
		//Health
		string str = to_string(iori.getHealth());
		txt[4].setFont(font);
		if (iori.getHealth() <= 0) {
			str = '0';
			txt[4].setColor(Color::Red);
		}

		else
			txt[4].setColor(Color::Green);
		
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

		if (ryo.getHealth()<=0) {
			str1 = '0';
			txt[5].setColor(Color::Red);
		}

		else
			txt[5].setColor(Color::Green);
		
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
	Text gettxt(int i) {
		return txt[i];
	}

	//ioriwrappers
	void IW_setHealth(int health) {
		iori.setHealth(health);
	}

	int IW_getHealth() {
		return iori.getHealth();
	}

	void IW_Ready(bool status) {
		iori.Ready(status);
	}

	void IW_Idle(bool key) {
		iori.Idle(key);
	}

	bool IW_Duck() {
		return iori.Duck();
	}

	bool IW_WalkFront() {
		return iori.WalkFront();
	}

	bool IW_WalkBack() {
		return iori.WalkBack();
	}

	bool IW_Jump() {
		return iori.Jump();
	}

	bool IW_Punch() {
		return iori.Punch();
	}
	
	bool IW_Kick() {
		return iori.Kick();
	}

	bool IW_Combo() {
		return iori.Combo();
	}

	bool IW_Block() {
		return iori.Block();
	}

	bool IW_Dead() {
		return iori.Dead();
	}

	Sprite IW_getSprite(int i) {
		return iori.getSprite(i);
	}

	void IW_setPos(Vector2f pos) {
		iori.setPos(pos);
	}

	//Ryo Wrappers
	void RW_setHealth(int health) {
		ryo.setHealth(health);
	}

	int RW_getHealth() {
		return ryo.getHealth();
	}

	void RW_Ready(bool status) {
		ryo.Ready(status);
	}

	void RW_Idle(bool key) {
		ryo.Idle(key);
	}

	bool RW_Duck() {
		return ryo.Duck();
	}

	bool RW_WalkFront() {
		return ryo.WalkFront();
	}

	bool RW_WalkBack() {
		return ryo.WalkBack();
	}
	
	bool RW_Jump() {
		return ryo.Jump();
	}

	bool RW_Punch() {
		return ryo.Punch();
	}

	bool RW_Kick() {
		return ryo.Kick();
	}

	bool RW_Combo() {
		return ryo.Combo();
	}

	bool RW_Block() {
		return ryo.Block();
	}

	bool RW_Dead() {
		return ryo.Dead();
	}

	Sprite RW_getSprite(int i) {
		return ryo.getSprite(i);
	}

	void RW_setPos(Vector2f pos) {
		ryo.setPos(pos);
	}

	//Game System
	// CONTROLLERS for
	// IORI (Kick, Punch and Combo) and
	// RYO (Kick, Punch and Combo)
	void Game(int ioriPcontroller, int iorikcontroller, int ioriCcontroller,int ryoPcontroller, int ryokcontroller, int ryoCcontroller) {
		if (ryoPcontroller == 33 ) {
				IntRect rect(ryo.getSprite(33).getGlobalBounds());
				IntRect rect1(iori.getSprite(15).getGlobalBounds());
				if (rect.intersects(rect1))	// decrement 5 from health if punch is activated
					iori.setHealth(iori.getHealth() - 5);
		}

		else if (ryokcontroller == 41) {
			IntRect rect(ryo.getSprite(41).getGlobalBounds());
			IntRect rect1(iori.getSprite(15).getGlobalBounds());
			if (rect.intersects(rect1)) // decrement 5 from health if kick is activated
				iori.setHealth(iori.getHealth() - 5);
		}

		else {
			if (ryoCcontroller == 51) {
				IntRect rect(ryo.getSprite(51).getGlobalBounds());
				IntRect rect1(iori.getSprite(15).getGlobalBounds());
				if (rect.intersects(rect1)) // decrement 20 from health if Combo is activated
					iori.setHealth(iori.getHealth() - 20);
			}
		}

		if (ioriPcontroller == 61) {
			IntRect rect(iori.getSprite(61).getGlobalBounds());
			IntRect rect1(ryo.getSprite(7).getGlobalBounds());
			if (rect.intersects(rect1))// decrement 5 from health if punch is activated
				ryo.setHealth(ryo.getHealth() - 5);
		}

		else if (iorikcontroller == 71) {
			IntRect rect(iori.getSprite(71).getGlobalBounds());
			IntRect rect1(ryo.getSprite(7).getGlobalBounds());
			if (rect.intersects(rect1))// decrement 5 from health if kick is activated
				ryo.setHealth(ryo.getHealth() - 5);
		}

		else {
			if ((ioriCcontroller == 98)) {
				IntRect rect(iori.getSprite(98).getGlobalBounds());
				IntRect rect1(ryo.getSprite(7).getGlobalBounds());
				if (rect.intersects(rect1))// decrement 20 from health if combo is activated
					ryo.setHealth(ryo.getHealth() - 20);
			}
		}
	
	}
};

int main() {
	RenderWindow window(VideoMode(800, 640), "Balistics Fighter", Style::Fullscreen);	// render a window with 800x640 and set it to full screen
	window.setFramerateLimit(60);														// set frames per second i.e 60
	mainmenu menu;																		// create menu object
	Instruction instructions;															// create instruction object
	Level1 lvl1;																		// create level 1 object
	bool iskeyPressed = false, iskeyPressed2 = false, isExit = false, changeLevel = false, f = false;		// create bool variables
	int flag = 0, nxtlvl = 0;															// create int variables
	int animcontrolller[11] = { 0, 7, 17, 25, 35, 44, 53, 62, 72, 99, 106};				// create array for sprites (P1)
	int animcontrolller2[11] = { 0, 4, 9, 10, 16, 21, 25, 34, 42, 52, 55};				// create array for sprites (P2)
	Clock clock;																		// create Clock object for sprite speed
	Music music[8];																		// create Music object for sound/audio effects
	music[0].openFromFile("Assests/sound/Track_01.ogg");								// set sounds in subscripts
	music[1].openFromFile("Assests/sound/Track_02.ogg");								// set sounds in subscripts
	music[2].openFromFile("Assests/sound/Track_03.ogg");								// set sounds in subscripts
	music[3].openFromFile("Assests/sound/Crowd.ogg");									// set sounds in subscripts
	music[4].openFromFile("Assests/sound/End.ogg");										// set sounds in subscripts
	music[5].openFromFile("Assests/sound/Kick.ogg");									// set sounds in subscripts
	music[6].openFromFile("Assests/sound/Punch.ogg");									// set sounds in subscripts
	music[7].openFromFile("Assests/sound/Start.ogg");									// set sounds in subscripts
	
	while (window.isOpen()) {
		if (music[2].getStatus() == SoundSource::Stopped) {								// check if music is stopped
			music[0].play();															// if so, play next
			music[0].setVolume(40);														// and set volume to 40
		}

		if (music[0].getStatus() == SoundSource::Stopped) {
			music[1].play();
			music[1].setVolume(40);
		}

		if (music[1].getStatus() == SoundSource::Stopped) {
			music[2].play();
			music[2].setVolume(40);
		}

		// check all the window's events that were triggered since the last iteration of the loop
		Event event;
		while (window.pollEvent(event)) {
			if (flag == 0) {									// if menu is to be displayed
				//check if exit is called
				isExit = menu.exit();
				if (isExit)
					window.close();								// if exit function returns true, close window
				
				changeLevel = menu.instructions();
				if (changeLevel)		
					flag = 1;
				
				changeLevel = menu.play();										
				if (changeLevel == true) {						// if play is clicked, simulate level
					flag = 2;
					clock.restart();							// restart clock after a loop is completed
					animcontrolller[0] = 0;						// for P1
					animcontrolller2[0] = 0;					// for P2
					lvl1.IW_setHealth(100);						// set healths
					lvl1.RW_setHealth(100);
					animcontrolller2[10] = 55;					// set arrays for sprites
					animcontrolller[10] = 106;
					Vector2f v(100.0f, 365.0f);					// set positions of vectors on where they want to be displayed
					lvl1.IW_setPos(v);							
					v.x = 1100.0f;
					v.y = 365.0f;
					lvl1.RW_setPos(v);							// now set for P2
				}
			}

			if (flag == 1) {
				changeLevel = instructions.back();				// if user clicks back, then return to main menu
				if (changeLevel == true)
					flag = 0;
			}

			if (flag == 2) {									//user pressed play Game
				changeLevel = lvl1.back();
				if (changeLevel == true)
					flag = 0;
			}			

			if (event.type == Event::Closed)					// "close requested" event: we close the window
				window.close();
		}

		window.clear();											// clear window now
		if (flag == 0) {										//if menu is to be displayed
			menu.setPosition();									// display whole menu
			menu.draw();
			window.draw(menu.getspbg());
			window.draw(menu.gettitle());
			window.draw(menu.getPlay());
			window.draw(menu.getInstruction());
			window.draw(menu.getExit());
		}

		if (flag == 1) {										// if instruction level is to be displayed
			instructions.draw();
			instructions.setPosition();							// display instructions
			window.draw(instructions.getspbg());
			for (int i = 0; i < 7; i++)
				window.draw(instructions.getTx(i));
		}
		if (flag == 2) {										// if level 1 is to be displayed
			lvl1.setPosition();
			window.draw(lvl1.getspbg());						// level 1 START
			lvl1.draw();
			Time t1 = clock.getElapsedTime();
			if (t1.asSeconds() < 2.0f) {
				if (!f) {										// add additional sounds
					music[7].play();
					music[7].setVolume(100);
					music[3].setVolume(5);
				}

				for (int i = 0; i < 2; i++)
					window.draw(lvl1.gettxt(i));				// show texts i.e Level 1, Ready
				
				lvl1.IW_Ready(true);							//Ready Animation
				if (animcontrolller[0] >= 0 && animcontrolller[0] <= 6) {	// load sprites in anim controller
					window.draw(lvl1.IW_getSprite(animcontrolller[0]));		// now draw them
					animcontrolller[0]++;									// now increment it, same for all below conditions
				}

				else
					window.draw(lvl1.IW_getSprite(animcontrolller[0] - 1));
				
																//Ryo Ready Animation
				lvl1.RW_Ready(true);
				if (animcontrolller2[0] >= 0 && animcontrolller2[0] <= 3) {
					window.draw(lvl1.RW_getSprite(animcontrolller2[0]));
					animcontrolller2[0]++;
				}

				else
					window.draw(lvl1.RW_getSprite(animcontrolller2[0] - 1));

				f = true;
			}

			for (int i = 2; i < 6; i++)
				window.draw(lvl1.gettxt(i));
			
			if (t1.asSeconds() > 2.0f) {
				music[3].setVolume(70);
				if (lvl1.RW_getHealth() > 0 && lvl1.IW_getHealth() > 0) {
					lvl1.Game(animcontrolller[6], animcontrolller[7], animcontrolller[8], animcontrolller2[6], animcontrolller2[7], animcontrolller2[8]);
					//Idle Animation
					if (iskeyPressed == false) {
						lvl1.IW_Idle(iskeyPressed);
						if (animcontrolller[1] >= 7 && animcontrolller[1] <= 15) {
							window.draw(lvl1.IW_getSprite(animcontrolller[1]));
							animcontrolller[1]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animcontrolller[1] - 1));
							animcontrolller[1] = 7;
						}
					}
					//Duck Animation
					if (lvl1.IW_Duck() == true) {
						iskeyPressed = true;
						if (animcontrolller[2] >= 16 && animcontrolller[2] < 24) {
							window.draw(lvl1.IW_getSprite(animcontrolller[2]));
							animcontrolller[2]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animcontrolller[2] - 1));
							animcontrolller[2] = 17;
						}
					}
					//Walk Front Animation
					else if (lvl1.IW_WalkFront() == true) {
						iskeyPressed = true;
						if (animcontrolller[3] >= 25 && animcontrolller[3] < 34) {
							window.draw(lvl1.IW_getSprite(animcontrolller[3]));
							animcontrolller[3]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animcontrolller[3] - 1));
							animcontrolller[3] = 25;
						}
					}
					//Walk Back Animation
					else if (lvl1.IW_WalkBack() == true) {
						iskeyPressed = true;
						if (animcontrolller[4] >= 35 && animcontrolller[4] < 43) {
							window.draw(lvl1.IW_getSprite(animcontrolller[4]));
							animcontrolller[4]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animcontrolller[4] - 1));
							animcontrolller[4] = 35;
						}
					}
					//Jump Animation
					else if (lvl1.IW_Jump() == true) {
						iskeyPressed = true;
						if (animcontrolller[5] >= 43 && animcontrolller[5] <= 49) {
							window.draw(lvl1.IW_getSprite(animcontrolller[5]));
							animcontrolller[5]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animcontrolller[5] - 1));
							animcontrolller[5] = 43;
						}
					}
					//Punch Animation
					else if (lvl1.IW_Punch() == true) {
						music[6].play();
						music[6].setVolume(100);
						iskeyPressed = true;
						if (animcontrolller[6] >= 53 && animcontrolller[6] <= 61) {
							window.draw(lvl1.IW_getSprite(animcontrolller[6]));
							animcontrolller[6]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animcontrolller[6] - 1));
							animcontrolller[6] = 53;
						}
					}
					//Kick Animation
					else if (lvl1.IW_Kick() == true) {
						music[5].play();
						music[5].setVolume(100);
						iskeyPressed = true;
						if (animcontrolller[7] >= 62 && animcontrolller[7] <= 71) {
							window.draw(lvl1.IW_getSprite(animcontrolller[7]));
							animcontrolller[7]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animcontrolller[7] - 1));
							animcontrolller[7] = 62;
						}
					}
					//combo Animation
					else if (lvl1.IW_Combo() == true) {
						iskeyPressed = true;
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
					}
					//Block Animation
					else if (lvl1.IW_Block() == true) {
						iskeyPressed = true;
						if (animcontrolller[9] >= 99 && animcontrolller[9] < 105) {
							window.draw(lvl1.IW_getSprite(animcontrolller[9]));
							animcontrolller[9]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animcontrolller[9] - 1));
							animcontrolller[9] = 99;
						}
					}
					//Dead Animation
					else if (lvl1.IW_Dead() == true) {
						iskeyPressed = true;
						if (animcontrolller[10] >= 106 && animcontrolller[10] < 115) {
							window.draw(lvl1.IW_getSprite(animcontrolller[10]));
							animcontrolller[10]++;
							Sleep(100);
						}
						else
							window.draw(lvl1.IW_getSprite(animcontrolller[10]));
					}
					else
						iskeyPressed = false;
					//Ryo
					//Idle Animation
					if (iskeyPressed2 == false) {
						lvl1.RW_Idle(iskeyPressed2);
						if (animcontrolller2[1] >= 4 && animcontrolller2[1] <= 7) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[1]));
							animcontrolller2[1]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[1] - 1));
							animcontrolller2[1] = 4;
						}
					}
					//Duck Animation
					if (lvl1.RW_Duck() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[2] >= 9 && animcontrolller2[2] <10) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[2]));
							animcontrolller2[2]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[2] - 1));
							animcontrolller2[2] = 9;
						}
					}
					//Walk Front Animation
					else if (lvl1.RW_WalkFront() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[3] >= 10 && animcontrolller2[3] < 16) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[3]));
							animcontrolller2[3]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[3] - 1));
							animcontrolller2[3] = 10;
						}
					}
					//Walk Back Animation
					else if (lvl1.RW_WalkBack() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[4] >= 16 && animcontrolller2[4] <= 20) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[4]));
							animcontrolller2[4]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[4] - 1));
							animcontrolller2[4] = 16;
						}
					}
					//Jump Animation
					else if (lvl1.RW_Jump() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[5] >= 21 && animcontrolller2[5] <= 23) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[5]));
							animcontrolller2[5]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[5] - 1));
							animcontrolller2[5] = 21;
						}
					}
					//Punch Animation
					else if (lvl1.RW_Punch() == true) {
						music[6].play();
						music[6].setVolume(100);
						iskeyPressed2 = true;
						if (animcontrolller2[6] >= 25 && animcontrolller2[6] <= 33) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[6]));
							animcontrolller2[6]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[6] - 1));
							animcontrolller2[6] = 25;
						}
						
					}
					//Kick Animation
					else if (lvl1.RW_Kick() == true) {
						music[5].play();
						music[5].setVolume(100);
						iskeyPressed2 = true;
						if (animcontrolller2[7] >= 34 && animcontrolller2[7] <= 41) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[7]));
							animcontrolller2[7]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[7] - 1));
							animcontrolller2[7] = 34;
						}
						
					}
					//Combo Animation
					else if (lvl1.RW_Combo() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[8] >= 42 && animcontrolller2[8] <= 51) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[8]));
							animcontrolller2[8]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[8] - 1));
							animcontrolller2[8] = 42;
						}
					}
					//Block Animation
					else if (lvl1.RW_Block() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[9] >= 52 && animcontrolller2[9] < 55) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[9]));
							animcontrolller2[9]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[9] - 1));
							animcontrolller2[9] = 52;
						}
					}
					//Dead Animation
					else if (lvl1.RW_Dead() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[10] >= 55 && animcontrolller2[10] < 58) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[10]));
							animcontrolller2[10]++;
							Sleep(70);
						}
						else
							window.draw(lvl1.RW_getSprite(animcontrolller2[10]));
					}
					else {
						iskeyPressed2 = false;
						f = false;
					}
				}
				else {
					lvl1.draw();
					if (!f) {
						music[3].setVolume(20);
						music[4].play();
						music[4].setVolume(100);
					}
					if (lvl1.IW_getHealth() <= 0) {
						window.draw(lvl1.gettxt(7));
						window.draw(lvl1.RW_getSprite(6));
						window.draw(lvl1.IW_getSprite(115));
					}
					else {
						window.draw(lvl1.gettxt(6));
						window.draw(lvl1.IW_getSprite(3));
						window.draw(lvl1.RW_getSprite(58));
					}
					f = true;
				}
			}
		}
		window.display();	// display it on screen
		Sleep(50);			// with some delay
	}
	return 0;
}