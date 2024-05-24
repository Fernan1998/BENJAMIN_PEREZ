#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "Personaje.h"
#include "Gameplay.h"
#include "CamaraPrincipal.h"
#include "Menu.h"
#include <iostream>

void cambioMapa(Personaje *personaje, int &numeroMapa);

int main(int argc, char *argv[]){
	sf::RenderWindow ventana(sf::VideoMode(1024,768),"BENJAMIN PEREZ THE GAME");
	ventana.setFramerateLimit(60);
	
	Personaje* personaje = new Personaje;
	personaje->setPosicion(120,150);
	
	int numeroMapa = 1;
	CamaraPrincipal camaraPrincipal(&ventana,1024,768,1920,992);
	Gameplay *nivel1 = new Gameplay(personaje, camaraPrincipal, "Mapas_txt/mapa_noche.txt", "Mapas_txt/fondo_noche.txt", "Mapas_txt/mapa_cueva1_plataformas.txt");
	Gameplay *nivel2 = new Gameplay(personaje, camaraPrincipal, "Mapas_txt/mapa_cueva2.txt", "Mapas_txt/mapa_cueva1_fondo.txt", "Mapas_txt/mapa_cueva2_plataformas.txt");
	
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
			cambioMapa(personaje, numeroMapa);
			switch(numeroMapa)
			{
				case 1:
					nivel1->ChequeoColisiones();
					nivel1->comando();
					nivel1->actualizar(deltaTime);
					nivel1->draw(ventana);
					break;
				case 2:
					nivel2->ChequeoColisiones();
					nivel2->comando();
					nivel2->actualizar(deltaTime);
					nivel2->draw(ventana);
					break;
			}

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
void cambioMapa(Personaje *personaje, int &numeroMapa)
{
	if(numeroMapa == 1)
	{
		if(personaje->getPosicion().x >= 1920)
		{
			numeroMapa = 2;
			personaje->setPosicion(50,personaje->getPosicion().y);
		}
	}
	if(numeroMapa == 2)
	{
		if(personaje->getPosicion().x <= 10)
		{
			numeroMapa = 1;
			personaje->setPosicion(1870,personaje->getPosicion().y);
		}
		
	}
}
