#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
//#include "Utilidades.cpp"

class Opciones {
public:
	Opciones();
	~Opciones();
	bool mostrar(sf::RenderWindow &ventana);
	void inicializarSprite(sf::Texture &_textura, sf::Sprite &_sprite, int x, int y, float rotacion, std::string ruta, int opcion);
	bool encimaDe(sf::RenderWindow &ventana, sf::Sprite &_sprite);
	bool clickMouse();
	bool clickMouse(int c);
	
	/// getters
	int getControles();
	
	/// setters
	void setControles(int c);
	void setContador(int c);
private:
	int controles = 1, contador = 0;
	bool soltarClick = true;
	sf::Sprite _spriteAdelante;
	sf::Texture _texturaAdelante;
	sf::Sprite _spriteAtras;
	sf::Texture _texturaAtras;
	sf::Sprite _spriteSaltar;
	sf::Texture _texturaSaltar;
	sf::Sprite _spriteAtacar;
	sf::Texture _texturaAtacar;
	sf::Sprite _spriteW;
	sf::Texture _texturaW;
	sf::Sprite _spriteS;
	sf::Texture _texturaS;
	sf::Sprite _spriteA;
	sf::Texture _texturaA;
	sf::Sprite _spriteD;
	sf::Texture _texturaD;
	sf::Sprite _spriteVolver;
	sf::Texture _texturaVolver;
	sf::Sprite _spriteFlecha1;
	sf::Texture _texturaFlecha1;
	sf::Sprite _spriteFlecha2;
	sf::Texture _texturaFlecha2;
	sf::Sprite _spriteControles;
	sf::Texture _texturaControles;
	sf::Sprite _spriteNumpad1;
	sf::Texture _texturaNumpad1;
	sf::Sprite _spriteNumpad2;
	sf::Texture _texturaNumpad2;
	sf::Sprite _spriteNumpad3;
	sf::Texture _texturaNumpad3;
	sf::Sprite _spriteFlecha3;
	sf::Texture _texturaFlecha3;
	sf::Sprite _spriteFlecha4;
	sf::Texture _texturaFlecha4;
	sf::Sprite _spriteFlecha5;
	sf::Texture _texturaFlecha5;
	sf::Sprite _spriteFlecha6;
	sf::Texture _texturaFlecha6;
	sf::Sprite _spriteZ;
	sf::Texture _texturaZ;
	sf::Sprite _spriteX;
	sf::Texture _texturaX;
	sf::Sprite _spriteF;
	sf::Texture _texturaF;
	sf::Sprite _spriteE;
	sf::Texture _texturaE;
	sf::Sprite _spriteAbajo;
	sf::Texture _texturaAbajo;
};

