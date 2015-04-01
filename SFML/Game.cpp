#include "Game.h"
#include "Engine.h"

sf::RenderWindow WindowAplication(sf::VideoMode(1360,768),"Mechanized Techno Explorer",sf::Style::Resize);
/*
	W zale¿nosci od statusu robi jakas czynnosc
*/
void Game::game_status_menu(void){
	game_state = MENU;
	while(game_state != EXIT)
	switch (game_state){
	case SINGLE:
			Game::single();
		break;
	
	case MENU:
			Game::menu();
		break;
	}
}
/*
	metoda wczytujaca do programu wszystkie niezbedne pliki do gry
*/
void Game::run(void){
	
	//Wczytywanie plików do programu
	printf("Linking file to project, please wait...\n\n");

	//if(!font.loadFromFile("data/Mecha.ttf"))
	

	if(!font.loadFromFile("data/fonts/Menu_fonts.ttf"))
		printf("Menu fonts wasnt Linked to project\n");
	else	printf("Menu fonts was Linked to game\n");

	//

	if(!load_game_option())	// Zmiana statusu programu na MENU
		printf("Menu settings wasnt linked to project\n");
	else	printf("Settings for menu was linked\n");
	
	//KONIEC WCZYTYWANIA PLIKOW
}
	/*
		Wczytywanie z pliku tekstowego poczatkowych ustawien gry
	*/
bool Game::load_game_option(void){
	setting = fopen("data/game_settings/stg.txt","r");

	if(!setting){
			printf("WARNING: File with settings are broke, Loading standard settings...\n");
			this->width = 800;
			this->height = 600;
			this->volume = 3;
			this->brightness = 10;
			game_state = MENU;
			return false;
	}else{
			fscanf(setting,"rozdzielczosc: %d x %d ;\n",&width,&height);
			fscanf(setting,"glosnosc: %d ;\n",&volume);
			fscanf(setting,"brightness: %d ;",&brightness);
			game_state = MENU;
			fclose(setting);
		//Sprawdzenie czy przypisania sie udaly
			//printf("rodzielczocs: %d %d\n",width,height);
			//printf("glosnosc: %d\n",volume);
			//printf("brightness: %d\n",brightness);
			return true;
		}
}
/*
	Wyœwietla menu gry
*/
void Game::menu(){
	const int num_txt = 5; //liczba tekstow w menu
	sf::Text txt_menu[num_txt];	// przyciski
	std::string tekst[num_txt] = {	//tekst do menu gry
		"Single player",
		"Multi player",
		"Option",
		"Credits",
		"Exit"
	};

	//Zmiana rozdzielczosci na ta z settings
	WindowAplication.setSize(sf::Vector2u(width, height));

	sf::Text title("TYTUL GRY",font,80);	//tytu³ wyœwietlanego nad menu
	title.setPosition(width/2,height/3-90);

	for(int i=0;i<num_txt;i++){		//Ustawianie prxzyciskow menu
		txt_menu[i].setFont(font);
		txt_menu[i].setCharacterSize(50);
		txt_menu[i].setString(tekst[i]);
		txt_menu[i].setPosition(width/2,height/3+i*60);
		txt_menu[i].setColor(sf::Color::White);
	}

	while(game_state == MENU){	//gra
		sf::Vector2f mouse(sf::Mouse::getPosition());
		sf::Event event;

		//Obsluga zdarzen w menu
		while(WindowAplication.pollEvent(event))
		{
			// Wylaczanie okna
			if(event.type == sf::Event::Closed || 
				event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ||	//Wcisniecie ESC na klawiaturze
				txt_menu[4].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left	//wcisniecie przycisku EXIT
			)
				game_state = EXIT;

			//Obsluga zmiany rozdzielczosci
			if(event.type == sf::Event::Resized){
				for(int i=0;i<num_txt;i++){
					txt_menu[i].setPosition(width/2,height/3+i*60);
				}
			}
		}
		for(int i=0;i<num_txt;i++)	//Zmiana koloru po nakiereowaniu na przycisk
			if(txt_menu[i].getGlobalBounds().contains(mouse))
				txt_menu[i].setColor(sf::Color::Cyan);
			else txt_menu[i].setColor(sf::Color::White);
		
			WindowAplication.clear();

		WindowAplication.draw(title);

		for(int i=0;i<num_txt;i++)
			WindowAplication.draw(txt_menu[i]);

		WindowAplication.display();
	}
}

void Game::single(void){
	Engine engine(WindowAplication);
	
	engine.run_single();
}