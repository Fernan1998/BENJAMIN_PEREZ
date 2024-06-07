#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>

class Cinematica{
public:
	Cinematica(std::string ruta, int cantFrames);
	sf::Texture cargarImagenes(int &i);
		
private:
	std::string _ruta;
	int _cantFrames;
};


