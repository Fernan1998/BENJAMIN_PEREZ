#include "Mapa.h"
#include "Personaje.h"
#include "Gameplay.h"
#include "CamaraPrincipal.h"
#include <SFML/Graphics.hpp>

int main(int argc, char *argv[]){
	sf::RenderWindow ventana(sf::VideoMode(1024,768),"BENJAMIN PEREZ");
	CamaraPrincipal camaraPrincipal(&ventana,1024,768,1920,992);
	
	Gameplay nivel1(camaraPrincipal);
	
	sf::Clock clock;
	while(ventana.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		sf::Event e;
		while(ventana.pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
				ventana.close();	
		}
		
		ventana.clear();
		nivel1.ChequeoColisiones();
		nivel1.comando();
		nivel1.actualizar(deltaTime);
		nivel1.draw(ventana);
		ventana.display();
	}
	return 0;
}

