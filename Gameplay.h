#pragma once
#include "Personaje.h"
#include "CamaraPrincipal.h"
#include "Mapa.h"
#include "Enemigo.h"
#include "Cinematica.h"
#include "Nivel.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <string>

class Gameplay 
{
	public:
		Gameplay(CamaraPrincipal &camaraPrincipal);
		Gameplay();
		~Gameplay();
		void actualizar(float deltaTime);
		void comando(int c);
		int draw(sf::RenderWindow& window);
		void ChequeoColisiones();
		sf::Vector2f getPosicionPersonaje();
		void cambioEscena();
		void ponerPausa();
		
	private:
		CamaraPrincipal _camaraPrincipal;
		Personaje *_personaje;
		Nivel *nivel1;
		Nivel *nivel2;
		Nivel *nivel3;
		Nivel *nivelActual;
		Nivel *listaNiveles[3];
		int numeroMapa;
		bool pausa = false;
		Menu menu = new Menu(true);
		Cinematica cinematicaPersonaje;
		sf::RectangleShape _aux;
		sf::Texture texAux;
		int i=0;

};

