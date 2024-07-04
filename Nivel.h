#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "Mapa.h"
#include "Enemigo.h"
#include "Jefe.h"
#include <Vector>

class Nivel
{
	public:
		Nivel(std::string mapa, std::string fondo, std::string plataformas, int cantidadEnemigos);
		~Nivel();
		void actualizar(float deltaTime);
		void comando(Personaje &personaje);
		void creadorDeEnemigos(float salud, float danio, std::string textura, float alto, float ancho, float altoRangoVision, float anchoRangoVision, int filaAnimacion, int columnaAnimacion);
		void creadorDeJefes(float salud, float danio, std::string textura, float alto, float ancho, float altoRangoVision, float anchoRangoVision, int filaAnimacion, int columnaAnimacion);
		sf::FloatRect getMapa(float a, float b);
		sf::FloatRect getFondo(float a, float b);
		sf::FloatRect getPlataforma(float a, float b);
		void dibujar(sf::RenderWindow& window);
		std::vector<Enemigo*> getEnemigo();
		int getCantidadEnemigos();
		void reiniciarNivel(sf::Vector2f pos1, sf::Vector2f pos2, sf::Vector2f pos3, sf::Vector2f pos4, float vida);
	private:
		int _cantidadEnemigos;
		Mapa _mapa;
		Mapa _fondo;
		Mapa _plataformas;
		Mapa _script;
		
		std::vector<Enemigo*> _vectorEnemigo;
		
};
