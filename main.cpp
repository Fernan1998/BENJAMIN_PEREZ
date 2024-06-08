#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "Personaje.h"
#include "Gameplay.h"
#include "CamaraPrincipal.h"
#include "Menu.h"
#include "Funciones.h"
#include <iostream>

int main(int argc, char *argv[])
{
	sf::RenderWindow ventana(sf::VideoMode(1024,768),"BENJAMIN PEREZ THE GAME");
	ventana.setFramerateLimit(60);

	int numeroMapa = 1;
	CamaraPrincipal camaraPrincipal(&ventana,1024,768,1920,992);
	Gameplay *juego = new Gameplay(camaraPrincipal);
	
	float tiempoJuego = 0;
	sf::Clock clock;
	while(ventana.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		pedirNum(deltaTime);
		sf::Event e;
		while(ventana.pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
				ventana.close();	
		}
		
		ventana.clear();
		juego->ChequeoColisiones();
		juego->comando();
		juego->actualizar(deltaTime);
		juego->draw(ventana);
		juego->cambioEscena();
		ventana.display();
	
	}
	return 0;
}

