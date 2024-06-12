#include "menu.h"

Menu::Menu() {
	/// Jugar
	cargarSprite(_texturaJugar, "Textura/Menu/jugar.png", _botonJugar, 512, 422, 1);
	/// Opcion
	cargarSprite(_texturaOpcion, "Textura/Menu/opciones.png", _botonOpcion, 512, 512, 1);
	/// Salir
	cargarSprite(_texturaSalir, "Textura/Menu/salir.png", _botonSalir, 512, 602, 1);
	/// Fondo
	cargarSprite(_texturaFondo, "Textura/Menu/fondo.png", _spriteFondo, 512, 384, 1);
}

Menu::Menu(bool aux) {
	/// Jugar
	cargarSprite(_texturaJugar, "Textura/Menu/jugar.png", _botonJugar, 400, 175, 1);
	/// Opcion
	cargarSprite(_texturaOpcion, "Textura/Menu/opciones.png", _botonOpcion, 370, 300, 1);
	/// Salir
	cargarSprite(_texturaSalir, "Textura/Menu/salir.png", _botonSalir, 410, 512, 1);
	/// Fondo
	cargarSprite(_texturaFondo, "Textura/Menu/menu transparente.png", _spriteFondo, 512, 384, 2);
}

Menu::~Menu() {
}

int Menu::mostrar(sf::RenderWindow &ventana){
	ventana.draw(_spriteFondo);
	ventana.draw(_botonJugar);
	ventana.draw(_botonOpcion);
	ventana.draw(_botonSalir);
	if(clickEn(ventana, this->_botonJugar) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return 1;
	}else if(clickEn(ventana, this->_botonOpcion) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return 2;
	}else if(clickEn(ventana, this->_botonSalir) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return 3;
	}else{
		return 0;
	}
}

int Menu::mostrar(sf::RenderWindow &ventana, sf::Vector2f _personaje){
	posicionarSprite(_personaje, _botonJugar, 230, -200);
	posicionarSprite(_personaje, _botonOpcion, 230, 54);
	posicionarSprite(_personaje, _botonSalir, 230, 300);
	posicionarSprite(_personaje, _spriteFondo, 80, 54);
	ventana.draw(_spriteFondo);
	ventana.draw(_botonJugar);
	ventana.draw(_botonOpcion);
	ventana.draw(_botonSalir);
	if(clickEn(ventana, this->_botonJugar) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return 1;
	}else if(clickEn(ventana, this->_botonOpcion) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return 2;
	}else if(clickEn(ventana, this->_botonSalir) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
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

void Menu::posicionarSprite(sf::Vector2f _personaje, sf::Sprite &_boton, int x, int y){
	_boton.setPosition( -x + _personaje.x, y + _personaje.y);
}

void Menu::cargarSprite(sf::Texture &_textura, const char * ruta, sf::Sprite &_boton, int x, int y, int opcion){
	switch (opcion){
	case 1:
		_textura.loadFromFile(ruta);
		_boton.setTexture(_textura);
		_boton.setOrigin(_boton.getGlobalBounds().width / 2, _boton.getGlobalBounds().height / 2);
		_boton.setPosition(x,y);
		break;
	case 2:
		_textura.loadFromFile(ruta);
		_boton.setTexture(_textura);
		_boton.setOrigin(_boton.getGlobalBounds().width, _boton.getGlobalBounds().height / 2);
		_boton.setPosition(x,y);
		break;
	case 3:
		_textura.loadFromFile(ruta);
		_boton.setTexture(_textura);
		_boton.setOrigin(_boton.getGlobalBounds().width / 2, _boton.getGlobalBounds().height);
		_boton.setPosition(x,y);
		break;
	case 4:
		_textura.loadFromFile(ruta);
		_boton.setTexture(_textura);
		_boton.setOrigin(_boton.getGlobalBounds().width, _boton.getGlobalBounds().height);
		_boton.setPosition(x,y);
		break;
	}
}
