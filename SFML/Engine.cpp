#include "Engine.h"

/*
	konstruktor
*/
Engine::Engine(sf::RenderWindow &win){
	window = &win;
	
	//dane wyswietlane podczas gry
	font.loadFromFile("data/fonts/Menu_fonts.ttf");	//wczytywanie czcionki

	napisy[0] = "zloto: ";
	napisy[1] = "drewno: ";
	napisy[2] = "kamien: ";
	napisy[3] = "populacja: ";
	for(int i=0;i<4;i++){
		text[i].setFont(font);	//kroj czcionki
		text[i].setCharacterSize(20);	//wielkosc czcionki
		text[i].setColor(sf::Color::White);	//kolor czcionki
		
		text[i].setString(napisy[i]);
		text[i].setPosition(i*10+10,10);
	
	}

}
/*
	destruktor
*/
Engine::~Engine(void)
{
	//audio.stopMusic();
}
/*
	Odpalanie gry
*/
void Engine::run_single(void){
	bool menu = false;
	//Generowanie mapy

	while(!menu){
		//granie

		update_map();	//updatowanie pozycji obiektow na mapie
	}
}

void Engine::update_map(){

}