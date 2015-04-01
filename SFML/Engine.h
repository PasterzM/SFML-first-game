#ifndef ENGINE_H
#define ENGINE_H

#include <SFML\Graphics.hpp>
#include <string.h>

class Engine{
public:
	sf::RenderWindow *window;

	Engine(sf::RenderWindow &win);
	~Engine();
private:
	//Player player;
	//Unit unit;
	//Building building;
	//Audio audio;
	//Level level;

public:		 //metody
	void run_single(void);
	void update_map(void);

//pola
	sf::Font font;	//kroj czcionki
	std::string napisy[4];	//dane ktore maja byc wyswietlane
	sf::Text text[4];	//wypisanie tekstu w oknie
};

#endif