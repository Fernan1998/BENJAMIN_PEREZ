#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Opciones {
public:
	Opciones();
	~Opciones();
	bool mostrar(sf::RenderWindow &ventana);
	int cambiarControles();
	bool encimaDeVolver(sf::RenderWindow &ventana);
	bool encimaDeFlecha1(sf::RenderWindow &ventana);
	bool encimaDeFlecha2(sf::RenderWindow &ventana);
	/// getters
	int getControles();
	
	/// setters
	void setControles(int c);
private:
	int controles = 1;
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
};

