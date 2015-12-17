#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Character.h"
#include <iostream>
#include "Ryo.h"
using namespace sf;
using namespace std;

Ryo::Ryo() :character("Ryo Sakazaki",100)
{
	tx[0].loadFromFile("Assests/Ryo/Idle/Ryo Sakazaki_0.png");
	tx[1].loadFromFile("Assests/Ryo/Idle/Ryo Sakazaki_1.png");
	tx[2].loadFromFile("Assests/Ryo/Idle/Ryo Sakazaki_2.png");
	tx[3].loadFromFile("Assests/Ryo/Idle/Ryo Sakazaki_3.png");
	tx[4].loadFromFile("Assests/Ryo/Walk-Front/Ryo Sakazaki_4.png");
	tx[5].loadFromFile("Assests/Ryo/Walk-Front/Ryo Sakazaki_5.png");
	tx[6].loadFromFile("Assests/Ryo/Walk-Front/Ryo Sakazaki_6.png");
	tx[7].loadFromFile("Assests/Ryo/Walk-Front/Ryo Sakazaki_7.png");
	tx[8].loadFromFile("Assests/Ryo/Walk-Front/Ryo Sakazaki_8.png");
	tx[9].loadFromFile("Assests/Ryo/Walk-Front/Ryo Sakazaki_9.png");
	tx[10].loadFromFile("Assests/Ryo/Walk-Back/Ryo Sakazaki_10.png");
	tx[11].loadFromFile("Assests/Ryo/Walk-Back/Ryo Sakazaki_11.png");
	tx[12].loadFromFile("Assests/Ryo/Walk-Back/Ryo Sakazaki_12.png");
	tx[13].loadFromFile("Assests/Ryo/Walk-Back/Ryo Sakazaki_13.png");
	tx[14].loadFromFile("Assests/Ryo/Walk-Back/Ryo Sakazaki_14.png");
	tx[15].loadFromFile("Assests/Ryo/Duck/Ryo Sakazaki_15.png");
	tx[16].loadFromFile("Assests/Ryo/Duck/Ryo Sakazaki_16.png");
	tx[17].loadFromFile("Assests/Ryo/Jump/Ryo Sakazaki_17.png");
	tx[18].loadFromFile("Assests/Ryo/Jump/Ryo Sakazaki_18.png");
	tx[19].loadFromFile("Assests/Ryo/Jump/Ryo Sakazaki_19.png");
	tx[20].loadFromFile("Assests/Ryo/Block/Ryo Sakazaki_20.png");
	tx[21].loadFromFile("Assests/Ryo/Block/Ryo Sakazaki_21.png");
	tx[22].loadFromFile("Assests/Ryo/Block/Ryo Sakazaki_22.png");
	tx[23].loadFromFile("Assests/Ryo/Punch/Ryo Sakazaki_23.png");
	tx[24].loadFromFile("Assests/Ryo/Punch/Ryo Sakazaki_24.png");
	tx[25].loadFromFile("Assests/Ryo/Punch/Ryo Sakazaki_25.png");
	tx[26].loadFromFile("Assests/Ryo/Punch/Ryo Sakazaki_26.png");
	tx[27].loadFromFile("Assests/Ryo/Punch/Ryo Sakazaki_27.png");
	tx[28].loadFromFile("Assests/Ryo/Punch/Ryo Sakazaki_28.png");
	tx[29].loadFromFile("Assests/Ryo/Punch/Ryo Sakazaki_29.png");
	tx[30].loadFromFile("Assests/Ryo/Punch/Ryo Sakazaki_30.png");
	tx[31].loadFromFile("Assests/Ryo/Punch/Ryo Sakazaki_31.png");
	tx[32].loadFromFile("Assests/Ryo/Punch/Ryo Sakazaki_32.png");
	tx[33].loadFromFile("Assests/Ryo/Punch/Ryo Sakazaki_33.png");
	tx[34].loadFromFile("Assests/Ryo/Ready/Ryo Sakazaki_34.png");
	tx[35].loadFromFile("Assests/Ryo/Ready/Ryo Sakazaki_35.png");
	tx[36].loadFromFile("Assests/Ryo/Ready/Ryo Sakazaki_36.png");
	tx[37].loadFromFile("Assests/Ryo/Ready/Ryo Sakazaki_37.png");
	tx[38].loadFromFile("Assests/Ryo/Kick/Ryo Sakazaki_38.png");
	tx[39].loadFromFile("Assests/Ryo/Kick/Ryo Sakazaki_39.png");
	tx[40].loadFromFile("Assests/Ryo/Kick/Ryo Sakazaki_40.png");
	tx[41].loadFromFile("Assests/Ryo/Kick/Ryo Sakazaki_41.png");
	tx[42].loadFromFile("Assests/Ryo/Kick/Ryo Sakazaki_42.png");
	tx[43].loadFromFile("Assests/Ryo/Kick/Ryo Sakazaki_43.png");
	tx[44].loadFromFile("Assests/Ryo/Kick/Ryo Sakazaki_44.png");
	tx[45].loadFromFile("Assests/Ryo/Kick/Ryo Sakazaki_45.png");
	tx[46].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_46.png");
	tx[47].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_47.png");
	tx[48].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_48.png");
	tx[49].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_49.png");
	tx[50].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_50.png");
	tx[51].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_51.png");
	tx[52].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_52.png");
	tx[53].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_53.png");
	tx[54].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_54.png");
	tx[55].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_55.png");
	tx[56].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_56.png");
	tx[57].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_57.png");
	tx[58].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_58.png");
	tx[59].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_59.png");
	tx[60].loadFromFile("Assests/Ryo/Combo/Ryo Sakazaki_60.png");
	tx[61].loadFromFile("Assests/Ryo/Power/Ryo Sakazaki_61.png");
	tx[62].loadFromFile("Assests/Ryo/Power/Ryo Sakazaki_62.png");
	tx[63].loadFromFile("Assests/Ryo/Power/Ryo Sakazaki_63.png");
	tx[64].loadFromFile("Assests/Ryo/Win/Ryo Sakazaki_64.png");
	tx[65].loadFromFile("Assests/Ryo/Win/Ryo Sakazaki_65.png");
	tx[66].loadFromFile("Assests/Ryo/Win/Ryo Sakazaki_66.png");
	tx[67].loadFromFile("Assests/Ryo/Dead/Ryo Sakazaki_67.png");
	tx[68].loadFromFile("Assests/Ryo/Dead/Ryo Sakazaki_68.png");
	tx[69].loadFromFile("Assests/Ryo/Dead/Ryo Sakazaki_69.png");
	tx[70].loadFromFile("Assests/Ryo/Dead/Ryo Sakazaki_70.png");
	for (int i = 0; i < 71; i++)
	{
		sp[i].setTexture(tx[i]);
	}

}
Ryo::~Ryo()
{
	tx[0].loadFromFile("NULL");
	tx[1].loadFromFile("NULL");
	tx[2].loadFromFile("NULL");
	tx[3].loadFromFile("NULL");
	tx[4].loadFromFile("NULL");
	tx[5].loadFromFile("NULL");
	tx[6].loadFromFile("NULL");
	tx[7].loadFromFile("NULL");
	tx[8].loadFromFile("NULL");
	tx[9].loadFromFile("NULL");
	tx[10].loadFromFile("NULL");
	tx[11].loadFromFile("NULL");
	tx[12].loadFromFile("NULL");
	tx[13].loadFromFile("NULL");
	tx[14].loadFromFile("NULL");
	tx[15].loadFromFile("NULL");
	tx[16].loadFromFile("NULL");
	tx[17].loadFromFile("NULL");
	tx[18].loadFromFile("NULL");
	tx[19].loadFromFile("NULL");
	tx[20].loadFromFile("NULL");
	tx[21].loadFromFile("NULL");
	tx[22].loadFromFile("NULL");
	tx[23].loadFromFile("NULL");
	tx[24].loadFromFile("NULL");
	tx[25].loadFromFile("NULL");
	tx[26].loadFromFile("NULL");
	tx[27].loadFromFile("NULL");
	tx[28].loadFromFile("NULL");
	tx[29].loadFromFile("NULL");
	tx[30].loadFromFile("NULL");
	tx[31].loadFromFile("NULL");
	tx[32].loadFromFile("NULL");
	tx[33].loadFromFile("NULL");
	tx[34].loadFromFile("NULL");
	tx[35].loadFromFile("NULL");
	tx[36].loadFromFile("NULL");
	tx[37].loadFromFile("NULL");
	tx[38].loadFromFile("NULL");
	tx[39].loadFromFile("NULL");
	tx[40].loadFromFile("NULL");
	tx[41].loadFromFile("NULL");
	tx[42].loadFromFile("NULL");
	tx[43].loadFromFile("NULL");
	tx[44].loadFromFile("NULL");
	tx[45].loadFromFile("NULL");
	tx[46].loadFromFile("NULL");
	tx[47].loadFromFile("NULL");
	tx[48].loadFromFile("NULL");
	tx[49].loadFromFile("NULL");
	tx[50].loadFromFile("NULL");
	tx[51].loadFromFile("NULL");
	tx[52].loadFromFile("NULL");
	tx[53].loadFromFile("NULL");
	tx[54].loadFromFile("NULL");
	tx[55].loadFromFile("NULL");
	tx[56].loadFromFile("NULL");
	tx[57].loadFromFile("NULL");
	tx[58].loadFromFile("NULL");
	tx[59].loadFromFile("NULL");
	tx[60].loadFromFile("NULL");
	tx[61].loadFromFile("NULL");
	tx[62].loadFromFile("NULL");
	tx[63].loadFromFile("NULL");
	tx[64].loadFromFile("NULL");
	tx[65].loadFromFile("NULL");
	tx[66].loadFromFile("NULL");
	tx[67].loadFromFile("NULL");
	tx[68].loadFromFile("NULL");
	tx[69].loadFromFile("NULL");
	tx[70].loadFromFile("NULL");
}