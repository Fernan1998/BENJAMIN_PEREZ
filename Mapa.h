#pragma once
#include <fstream>
#include <SFML/Graphics.hpp>

class Mapa {
public:
	Mapa();
	~Mapa();
	void CreadorMapa(std::ifstream& file);
	sf::Sprite getSprite(int i, int j);
	sf::FloatRect getOrigen(int i, int j);
	sf::Vector2f getPosicion(int i, int j);
	
private:
		int nFilas;
		int nColumnas;
		std::vector<std::vector <sf::Sprite>> _bloque;
		sf::Texture *_textura = new sf::Texture [61];
};

