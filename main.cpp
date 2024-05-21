#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "Personaje.h"
#include "Gameplay.h"
#include "CamaraPrincipal.h"
#include <iostream>

void niveles(Personaje &aux, int &nivel);
	
int main(int argc, char *argv[]){
	sf::RenderWindow ventana(sf::VideoMode(1024,768),"BENJAMIN PEREZ THE GAME");
	ventana.setFramerateLimit(60);
	int nivel = 1;
	Personaje personaje;
	CamaraPrincipal camaraPrincipal(&ventana,1024,768,1920,992);
	Gameplay *nivel1 = new Gameplay(camaraPrincipal);
	Gameplay *nivel2 = new Gameplay(camaraPrincipal);
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
		niveles(personaje, nivel);
		std::cout << tiempoJuego << std::endl;
		switch(nivel)
		{
			case 1:
				nivel1->ChequeoColisiones();
				nivel1->comando();
				nivel1->actualizar(deltaTime, personaje);
				nivel1->draw(ventana);
				break;
			case 2:
				nivel2->ChequeoColisiones();
				nivel2->comando();
				nivel2->actualizar(deltaTime, personaje);
				nivel2->draw(ventana);
				break;
		
		}
		
		ventana.display();

	}
	return 0;
}

void niveles(Personaje &aux, int &nivel)
{
	if(nivel == 1)
	{
		if(aux.getPosicion().x == 1920 && aux.getPosicion().y < 352)
		{
			nivel = 2;
			aux.setPosicion(sf::Vector2f(0, 800));

		}
	}
}
