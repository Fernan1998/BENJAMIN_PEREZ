#include "menu.h"

Menu::Menu() {
	_texturaJugar.loadFromFile("Textura/Menu/jugar.png");
	_botonJugar.setTexture(_texturaJugar);
	_texturaOpcion.loadFromFile("Textura/Menu/opciones.png");
	_botonOpcion.setTexture(_texturaOpcion);
	_texturaSalir.loadFromFile("Textura/Menu/salir.png");
	_botonSalir.setTexture(_texturaSalir);
	_texturaFondo.loadFromFile("Textura/Menu/fondo.png");
	_spriteFondo.setTexture(_texturaFondo);
	_botonJugar.setOrigin(_botonJugar.getGlobalBounds().width / 2, _botonJugar.getGlobalBounds().height / 2);
	_botonJugar.setPosition(512,422);
	_botonOpcion.setOrigin(_botonOpcion.getGlobalBounds().width / 2, _botonOpcion.getGlobalBounds().height / 2);
	_botonOpcion.setPosition(512,512);
	_botonSalir.setOrigin(_botonSalir.getGlobalBounds().width / 2, _botonSalir.getGlobalBounds().height / 2);
	_botonSalir.setPosition(512,602);
}

Menu::~Menu() {
}

int Menu::mostrar(sf::RenderWindow &ventana){
	ventana.draw(_spriteFondo);
	ventana.draw(_botonJugar);
	ventana.draw(_botonOpcion);
	ventana.draw(_botonSalir);
	if(clickJugar(ventana) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return 1;
	}else if(clickOpciones(ventana) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return 2;
	}else if(clickSalir(ventana) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return 3;
	}else{
		return 0;
	}
}
bool Menu::clickJugar(sf::RenderWindow &ventana){
	if (_botonJugar.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(ventana))))
	{
		_botonJugar.setColor(sf::Color::Red);
		return true;
	}else{
		_botonJugar.setColor(sf::Color::White);
		return false;
	}
}

bool Menu::clickOpciones(sf::RenderWindow &ventana){
	if (_botonOpcion.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(ventana))))
	{
		_botonOpcion.setColor(sf::Color::Red);
		return true;
	}else{
		_botonOpcion.setColor(sf::Color::White);
		return false;
	}
}
bool Menu::clickSalir(sf::RenderWindow &ventana){
	if (_botonSalir.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(ventana))))
	{
		_botonSalir.setColor(sf::Color::Red);
		return true;
	}else{
		_botonSalir.setColor(sf::Color::White);
		return false;
	}
}

bool Menu::entrarOpciones(sf::RenderWindow &ventana){
	if(opciones.mostrar(ventana)){
		return false;
	}
	return true;
}
