#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>

class Player: public sf::Drawable, sf::Transformable{
public:
	//pola
	sf::ConvexShape shape;	
	float vx;	//pozycja x
	float vy;	//pozycja y
	float speed;	//aktualna predkosc
	unsigned static const int max_speed = 3;	//maksymalna przedkosc
	size_t lifes;	//ilosc zycia
	sf::Vector2f getPosition(size_t index);

	//konstruktory
	Player(void);

	//metody
	virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;
	
	void enemy_coll();

	int getLifes(){return lifes;}
	int getSpecialEffectTime();

	void immortal();
	void addLifes();
	void update();
	void playAnimation(bool play);
	void setVelocity(int x, int y);
	void accelerate();
	void rotate(int angle);
	sf::Vector2f getAngle(void);
	sf::Vector2f getNextPosition();
};

#endif