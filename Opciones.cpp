#include "Opciones.h"

Opciones::Opciones() {
	// Adelante
	_texturaAdelante.loadFromFile("Textura/Menu/adelante.png");
	_spriteAdelante.setTexture(_texturaAdelante);
	_spriteAdelante.setOrigin(_spriteAdelante.getGlobalBounds().width, _spriteAdelante.getGlobalBounds().height);
	_spriteAdelante.setPosition(500,300);
	// Atras
	_texturaAtras.loadFromFile("Textura/Menu/atras.png");
	_spriteAtras.setTexture(_texturaAtras);
	_spriteAtras.setOrigin(_spriteAtras.getGlobalBounds().width, _spriteAtras.getGlobalBounds().height);
	_spriteAtras.setPosition(500,400);
	// Saltar
	_texturaSaltar.loadFromFile("Textura/Menu/saltar.png");
	_spriteSaltar.setTexture(_texturaSaltar);
	_spriteSaltar.setOrigin(_spriteSaltar.getGlobalBounds().width, _spriteSaltar.getGlobalBounds().height);
	_spriteSaltar.setPosition(500,500);
	// Atacar
	_texturaAtacar.loadFromFile("Textura/Menu/atacar.png");
	_spriteAtacar.setTexture(_texturaAtacar);
	_spriteAtacar.setOrigin(_spriteAtacar.getGlobalBounds().width, _spriteAtacar.getGlobalBounds().height);
	_spriteAtacar.setPosition(500,600);
	// W
	_texturaW.loadFromFile("Textura/Menu/w.png");
	_spriteW.setTexture(_texturaW);
	_spriteW.setOrigin(_spriteW.getGlobalBounds().width / 2, _spriteW.getGlobalBounds().height);
	//_spriteW.rotate(180.0f);
	_spriteW.setPosition(650,500);
	// S
	_texturaS.loadFromFile("Textura/Menu/s.png");
	_spriteS.setTexture(_texturaS);
	_spriteS.setOrigin(_spriteS.getGlobalBounds().width / 2, _spriteS.getGlobalBounds().height);
	_spriteS.setPosition(650,600);
	// A
	_texturaA.loadFromFile("Textura/Menu/a.png");
	_spriteA.setTexture(_texturaA);
	_spriteA.setOrigin(_spriteA.getGlobalBounds().width / 2, _spriteA.getGlobalBounds().height);
	_spriteA.setPosition(650,400);
	// D
	_texturaD.loadFromFile("Textura/Menu/d.png");
	_spriteD.setTexture(_texturaD);
	_spriteD.setOrigin(_spriteD.getGlobalBounds().width / 2, _spriteD.getGlobalBounds().height);
	_spriteD.setPosition(650,300);
	// Numpad 1
	_texturaNumpad1.loadFromFile("Textura/Menu/1.png");
	_spriteNumpad1.setTexture(_texturaNumpad1);
	_spriteNumpad1.setOrigin(_spriteNumpad1.getGlobalBounds().width / 2, _spriteNumpad1.getGlobalBounds().height);
	_spriteNumpad1.setPosition(650,500);
	// Numpad 2
	_texturaNumpad2.loadFromFile("Textura/Menu/2.png");
	_spriteNumpad2.setTexture(_texturaNumpad2);
	_spriteNumpad2.setOrigin(_spriteNumpad2.getGlobalBounds().width / 2, _spriteNumpad2.getGlobalBounds().height);
	_spriteNumpad2.setPosition(650,600);
	// Volver
	_texturaVolver.loadFromFile("Textura/Menu/volver.png");
	_spriteVolver.setTexture(_texturaVolver);
	_spriteVolver.setOrigin(_spriteVolver.getGlobalBounds().width / 2, _spriteVolver.getGlobalBounds().height);
	_spriteVolver.setPosition(650,700);
	// Flechas
	_texturaFlecha1.loadFromFile("Textura/Menu/flecha.png");
	_spriteFlecha1.setTexture(_texturaFlecha1);
	_spriteFlecha1.setOrigin(_spriteFlecha1.getGlobalBounds().width, _spriteFlecha1.getGlobalBounds().height);
	_spriteFlecha1.setPosition(300,65);
	_spriteFlecha1.rotate(180.f);
	_texturaFlecha2.loadFromFile("Textura/Menu/flecha.png");
	_spriteFlecha2.setTexture(_texturaFlecha2);
	_spriteFlecha2.setOrigin(_spriteFlecha2.getGlobalBounds().width / 2, _spriteFlecha2.getGlobalBounds().height);
	_spriteFlecha2.setPosition(700,100);
	// Controles
	_texturaControles.loadFromFile("Textura/Menu/controles.png");
	_spriteControles.setTexture(_texturaControles);
	_spriteControles.setOrigin(_spriteControles.getGlobalBounds().width / 2, _spriteControles.getGlobalBounds().height);
	_spriteControles.setPosition(500,100);
}

Opciones::~Opciones() {
	
}

bool Opciones::mostrar(sf::RenderWindow &ventana){
	ventana.draw(_spriteAdelante);
	ventana.draw(_spriteAtras);
	ventana.draw(_spriteAtacar);
	ventana.draw(_spriteSaltar);
	switch (controles){
	case 0:
		setControles(3);
	case 1:
		ventana.draw(_spriteA);
		ventana.draw(_spriteD);
		ventana.draw(_spriteNumpad1);
		ventana.draw(_spriteNumpad2);
		break;
	case 2:
		break;
	case 3:
		ventana.draw(_spriteW);
		ventana.draw(_spriteS);
		ventana.draw(_spriteA);
		ventana.draw(_spriteD);
		break;
	case 4:
		setControles(1);
		break;
	default:
		break;
	}
	ventana.draw(_spriteVolver);
	ventana.draw(_spriteControles);
	ventana.draw(_spriteFlecha1);
	ventana.draw(_spriteFlecha2);
	if (encimaDeVolver(ventana) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return false;
	}else if (encimaDeFlecha1(ventana) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		controles--;
	}else if (encimaDeFlecha2(ventana) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		controles++;
	}
	return true;
}

bool Opciones::encimaDeVolver(sf::RenderWindow &ventana){
	if (_spriteVolver.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(ventana))))
	{
		_spriteVolver.setColor(sf::Color::Red);
		return true;
	}else{
		_spriteVolver.setColor(sf::Color::White);
		return false;
	}
}
bool Opciones::encimaDeFlecha1(sf::RenderWindow &ventana){
	if (_spriteFlecha1.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(ventana))))
	{
		_spriteFlecha1.setColor(sf::Color::Red);
		return true;
	}else{
		_spriteFlecha1.setColor(sf::Color::White);
		return false;
	}
}
bool Opciones::encimaDeFlecha2(sf::RenderWindow &ventana){
	if (_spriteFlecha2.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(ventana))))
	{
		_spriteFlecha2.setColor(sf::Color::Red);
		return true;
	}else{
		_spriteFlecha2.setColor(sf::Color::White);
		return false;
	}
}

int Opciones::getControles(){
	return controles;
}

void Opciones::setControles(int c){
	if (c > 0 && c <= 3) {
		controles = c;
	}
}
