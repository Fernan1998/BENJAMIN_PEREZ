#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "Personaje.h"
#include "Gameplay.h"
#include "CamaraPrincipal.h"
#include <iostream>
	
int main(int argc, char *argv[]){
	sf::RenderWindow ventana(sf::VideoMode(1366,768),"BENJAMIN PEREZ THE GAME");
	ventana.setFramerateLimit(60);
	
	Personaje personaje;
	personaje.setPosicion(120,150);
	
	CamaraPrincipal camaraPrincipal(&ventana,1366,768,1920,992);
	
	Gameplay *nivel1 = new Gameplay(camaraPrincipal, "Mapas_txt/mapa_noche.txt", "Mapas_txt/fondo_noche.txt", "Mapas_txt/mapa_noche.txt");
	
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
		
		nivel1->ChequeoColisiones();
		nivel1->comando();
		nivel1->actualizar(deltaTime);
		nivel1->draw(ventana);

		ventana.display();

	}
	return 0;
}
