#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Opciones.h"
//#include <Vector>

class Menu {
public:
	Menu();
	//Menu();
	~Menu();
	int mostrar(sf::RenderWindow &ventana);
	bool clickJugar(sf::RenderWindow &ventana);
	bool clickOpciones(sf::RenderWindow &ventana);
	bool clickSalir(sf::RenderWindow &ventana);
	bool entrarOpciones(sf::RenderWindow &ventana);
private:
	sf::Sprite _botonJugar;
	sf::Texture _texturaJugar;
	sf::Sprite _botonOpcion;
	sf::Texture _texturaOpcion;
	sf::Sprite _botonSalir;
	sf::Texture _texturaSalir;
	sf::Sprite _spriteFondo;
	sf::Texture _texturaFondo;
	Opciones opciones;
};
