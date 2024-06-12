#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "Mapa.h"
#include "Enemigo.h"
#include <Vector>

class Nivel
{
	public:
		Nivel(std::string mapa, std::string fondo, std::string plataformas, std::string ruta_musica);
		~Nivel();
		void actualizar(float deltaTime);
		void comando(Personaje &personaje);
		sf::FloatRect getMapa(float a, float b);
		sf::FloatRect getFondo(float a, float b);
		sf::FloatRect getPlataforma(float a, float b);
		void dibujar(sf::RenderWindow& window);
		Enemigo *getEnemigo()
		{
			return _enemigo;
		}
	private:
		Mapa _mapa;
		Mapa _fondo;
		Mapa _plataformas;
		Mapa _script;
		Enemigo* _enemigo;
		Sonidos *_sonido;

};
