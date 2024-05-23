#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "Personaje.h"
#include "Gameplay.h"
#include "CamaraPrincipal.h"
#include "menu.h"
#include <iostream>
	
int main(int argc, char *argv[]){
	sf::RenderWindow ventana(sf::VideoMode(1024,768),"BENJAMIN PEREZ THE GAME");
	ventana.setFramerateLimit(60);
	
	Personaje personaje;
	personaje.setPosicion(120,150);
	
	//CamaraPrincipal camaraPrincipal(&ventana,1024,768,0,0);
	CamaraPrincipal camaraPrincipal(&ventana,1024,768,1920,992);
	Gameplay *nivel1 = new Gameplay(camaraPrincipal, "Mapas_txt/mapa_cueva1.txt", "Mapas_txt/mapa_cueva1_fondo.txt", "Mapas_txt/mapa_cueva1_plataformas.txt");
	
	bool jugando = false;
	bool enOpciones = false;
	
	Menu menu;
	
	float tiempoJuego = 0;
	
	sf::Clock clock;
	while(ventana.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		tiempoJuego += deltaTime;
		sf::Event e;
		while(ventana.pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
				ventana.close();	
		}
		
		ventana.clear();
		
		if (jugando){
			nivel1->ChequeoColisiones();
			nivel1->comando();
			nivel1->actualizar(deltaTime);
			nivel1->draw(ventana);
		}else if (enOpciones){
			if (menu.entrarOpciones(ventana)){
				enOpciones = false;
			}
		}else {
			switch(menu.mostrar(ventana)){
			case 1:
				jugando = true;
				enOpciones = false;
				break;
			case 2:
				jugando = false;
				enOpciones = true;
				break;
			case 3:
				ventana.close();
				break;
			default:
				break;
			}
		}
		
		ventana.display();

	}
	return 0;
}
