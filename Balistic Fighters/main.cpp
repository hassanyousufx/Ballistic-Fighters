#include <SFML/Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include "MainMenu.h"
#include "Instructions.h"
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 640), "Balistics Fighter" ,Style::Fullscreen);
	window.setFramerateLimit(60);
	mainmenu menu;
	Instruction instructions;
	int flag = 0;
	bool is_Exit = false;
	bool is_chnglevel = false;
	while (window.isOpen())
	{
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
			}
			if (flag == 1)
			{
				is_chnglevel = instructions.back();
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
			window.clear();
			if (flag == 0)//if menu is to be displayed
			{
				menu.draw();
				window.draw(menu.getsbg());
				window.draw(menu.gettitle());
				window.draw(menu.getPlay());
				window.draw(menu.getInstruction());
				window.draw(menu.getExit());
			}
			if (flag == 1)//if instruction level is to be displayed
			{
				instructions.draw();
				window.draw(instructions.getInsbg());
				for (int i = 0; i < 7; i++)
				{
					window.draw(instructions.getTx(i));
				}
			}
			window.display();
		}
	}
	return 0;
}