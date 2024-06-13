#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "Personaje.h"
#include "Gameplay.h"
#include "CamaraPrincipal.h"
#include "Menu.h"
#include "Funciones.h"
#include "Menu.h"
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
	
	bool jugando = false, enOpciones = false, enOpcionesDesdeJugando = false, opcionesJugando = false;
	
	Menu menu;
	
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
		
		if (jugando) {
			juego->ChequeoColisiones();
			juego->comando(menu.getControles());
			juego->actualizar(deltaTime);
			switch (juego->draw(ventana)) {
			case 1:
				jugando = true;
				enOpciones = false;
				enOpcionesDesdeJugando = false;
				break;
			case 2:
				jugando = false;
				enOpcionesDesdeJugando = true;
				enOpciones = true;
				break;
			case 3:
				jugando = false;
				enOpciones = false;
				break;
			}
			juego->cambioEscena();
		}
		else if (enOpciones) {
			camaraPrincipal.setCamera(0,0);
			if (menu.entrarOpciones(ventana) && !enOpcionesDesdeJugando) {
				enOpciones = false;
				menu.setOpcionesDefault();
			}else if (menu.entrarOpciones(ventana) && enOpcionesDesdeJugando) {
				enOpciones = false;
				enOpcionesDesdeJugando = false;
				jugando = true;
				menu.setOpcionesDefault();
			}
		}
		else {
			//std::cout << camaraPrincipal.getCameraPosition().x << std::endl;
			//std::cout << camaraPrincipal.getCameraPosition().y << std::endl;
			camaraPrincipal.setCamera(0,0);
			switch (menu.mostrar(ventana)) {
			case 1:
				jugando = true;
				enOpciones = false;
				break;
			case 2:
				jugando = false;
				enOpciones = true;
				break;
			case 3:
				if (opcionesJugando){
					jugando = false;
					enOpciones = false;
				}else{
					ventana.close();
				}
				break;
			default:
				break;
			}
		}
		
		ventana.display();
	
	}
	return 0;
}

