#ifndef Game_h
#define Game_h

#include <SFML\Graphics.hpp>
#include <stdio.h>
#include <string.h>

class Game{
	//Pola klasy
public:
	int width;	//dlugosc okna
	int height;	//wysokosc okna
	FILE *setting;	//plik z ustawieniami gry
	sf::Font font;	//czcionka dla tekstu
	int volume;	//g³oœnoœæ gry
	int brightness;	//jasnoœæ okna

	enum g_st{	//stany gry
		MENU,
		LOAD,
		SINGLE,
		MULTI,
		OPTION,
		CREDITS,
		GAME_OVER,
		EXIT
	}game_state;

	//metody klasy
	bool load_game_option(void);
	void menu(void);
	void run(void);
	void single(void);
	void game_status_menu(void);
};

#endif