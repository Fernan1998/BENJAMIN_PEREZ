#pragma once
#include "Personaje.h"
#include "CamaraPrincipal.h"
#include "Mapa.h"
#include <SFML/Graphics.hpp>

class Gameplay 
{
	public:
		Gameplay(CamaraPrincipal &camaraPrincipal);
		Gameplay();
		~Gameplay();
		void actualizar(float deltaTime);
		void comando();
		void draw(sf::RenderWindow& window);
		void ChequeoColisiones();
		sf::Vector2f getPosicionPersonaje();
		
	private:
		CamaraPrincipal _camaraPrincipal;
		Personaje _personaje;
		Mapa _mapa;
		Mapa _fondo;
		Mapa _plataformas;
		Mapa _muerte;

};

