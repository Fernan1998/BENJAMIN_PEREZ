#pragma once
#include "Personaje.h"
#include "CamaraPrincipal.h"
#include "Mapa.h"
#include "Enemigo.h"
#include <string>
#include "Nivel.h"
#include <SFML/Graphics.hpp>

class Gameplay 
{
	public:
		Gameplay(CamaraPrincipal &camaraPrincipal, std::string mapa, std::string fondo, std::string plataformas);
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
		Nivel *nivel1;

};

