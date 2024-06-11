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
	bool clickEn(sf::RenderWindow &ventana, sf::Sprite &_sprite);
	bool entrarOpciones(sf::RenderWindow &ventana);
	void setOpcionesDefault();
	int getControles();
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
