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
	if(clickEn(ventana, _botonJugar) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return 1;
	}else if(clickEn(ventana, _botonOpcion) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return 2;
	}else if(clickEn(ventana, _botonSalir) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return 3;
	}else{
		return 0;
	}
}

bool Menu::clickEn(sf::RenderWindow &ventana, sf::Sprite &_sprite){
	if (_sprite.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(ventana))))
	{
		_sprite.setColor(sf::Color::Red);
		return true;
	}else{
		_sprite.setColor(sf::Color::White);
		return false;
	}
}

bool Menu::entrarOpciones(sf::RenderWindow &ventana){
	if(opciones.mostrar(ventana)){
		return false;
	}
	return true;
}

void Menu::setOpcionesDefault(){
	opciones.setContador(0);
}

int Menu::getControles(){
	return opciones.getControles();
}
