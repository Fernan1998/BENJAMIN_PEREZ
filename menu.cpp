#include "menu.h"

Menu::Menu() {
	/// Jugar
	cargarSprite(_texturaJugar, "Textura/Menu/jugar.png", _botonJugar, 512, 422, 0, 4);
	/// Opcion
	cargarSprite(_texturaOpcion, "Textura/Menu/opciones.png", _botonOpcion, 512, 512, 0, 4);
	/// Salir
	cargarSprite(_texturaSalir, "Textura/Menu/salir.png", _botonSalir, 512, 602, 0, 4);
	/// Nuevo
	cargarSprite(_texturaNuevo, "Textura/Menu/nueva partida.png", _botonNuevo, 512, 512, 0, 4);
	_botonNuevo.setScale(1.2f, 1.2f);
	/// Continuar
	cargarSprite(_texturaContinuar, "Textura/Menu/continuar.png", _botonContinuar, 512, 592, 0, 4);
	/// Fondo
	cargarSprite(_texturaFondo, "Textura/Menu/fondo.png", _spriteFondo, 512, 384, 0, 4);
}

Menu::Menu(bool aux) {
	/// Jugar
	cargarSprite(_texturaJugar, "Textura/Menu/jugar.png", _botonJugar, 400, 175, 0, 4);
	/// Opcion
	cargarSprite(_texturaOpcion, "Textura/Menu/opciones.png", _botonOpcion, 370, 300, 0, 4);
	/// Salir
	cargarSprite(_texturaSalir, "Textura/Menu/salir.png", _botonSalir, 410, 512, 0, 4);
	/// Fondo
	cargarSprite(_texturaFondo, "Textura/Menu/menu transparente.png", _spriteFondo, 512, 384, 0, 4);
}

Menu::~Menu() {
}

int Menu::mostrar(sf::RenderWindow &ventana){
	ventana.draw(_spriteFondo);
	if (!jugar) {
		ventana.draw(_botonJugar);
		ventana.draw(_botonOpcion);
		ventana.draw(_botonSalir);
		bool click = clickMouse();
		if (soltarClick && !click) {
			if (contador < 3) {
				contador++;
			}else {
				contador = 0;
				clickMouse(contador);
			}
		}
		if(clickEn(ventana, _botonJugar) && soltarClick && !click){
			jugar = true;
		}else if(clickEn(ventana, _botonOpcion) && soltarClick && !click){
			return 2;
		}else if(clickEn(ventana, _botonSalir) && soltarClick && !click){
			return 3;
		}else{
			return 0;
		}
	}else {
		bool click = clickMouse();
		if (soltarClick && !click) {
			if (contador < 3) {
				contador++;
			}else {
				contador = 0;
				clickMouse(contador);
			}
		}
		if (jugar) {
			ventana.draw(_botonContinuar);
			ventana.draw(_botonNuevo);
			if(clickEn(ventana, _botonNuevo) && soltarClick && !click){
				return 1;
			}else if(clickEn(ventana, _botonContinuar) && soltarClick && !click){
				return 4;
			}else {
				return 0;
			}
		}
	}
}

int Menu::mostrar(sf::RenderWindow &ventana, sf::Vector2f _personaje){
	if (_personaje.x <= 380) {
		posicionarSprite(_personaje, _botonJugar, -530, -200);
		posicionarSprite(_personaje, _botonOpcion, -530, 54);
		posicionarSprite(_personaje, _botonSalir, -530, 300);
		posicionarSprite(_personaje, _spriteFondo, -530, 54);
	}else{
		posicionarSprite(_personaje, _botonJugar, 230, -200);
		posicionarSprite(_personaje, _botonOpcion, 230, 54);
		posicionarSprite(_personaje, _botonSalir, 230, 300);
		posicionarSprite(_personaje, _spriteFondo, 230, 54);
	}
	ventana.draw(_spriteFondo);
	ventana.draw(_botonJugar);
	ventana.draw(_botonOpcion);
	ventana.draw(_botonSalir);
	bool click = clickMouse();
	if (soltarClick && !click) {
		if (contador < 5) {
			contador++;
		}else {
			contador = 0;
			clickMouse(contador);
		}
	}
	if(clickEn(ventana, _botonJugar) && soltarClick && !click){
		return 1;
	}else if(clickEn(ventana, _botonOpcion) && soltarClick && !click){
		return 2;
	}else if(clickEn(ventana, _botonSalir) && soltarClick && !click){
		return 3;
	}else{
		return 0;
	}
}

bool Menu::clickEn(sf::RenderWindow &ventana, sf::Sprite &_sprite){
	sf::Vector2i posicionMouse = sf::Mouse::getPosition(ventana);
	sf::Vector2f posicionEnMundo = ventana.mapPixelToCoords(posicionMouse);
	if (_sprite.getGlobalBounds().contains(posicionEnMundo))
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
	if (_personaje.y < 331) {
		_boton.setPosition(-x + _personaje.x, y + 330.5f);
	}else if (_personaje.y >= 331 && _personaje.y < 427) {
		_boton.setPosition(-x + _personaje.x, y + 386);
	}else if (_personaje.y >= 427 && _personaje.y < 523) {
		_boton.setPosition(-x + _personaje.x, y + 481.5f);
	}else {
		_boton.setPosition(-x + _personaje.x, y + 552.5f);
	}
}

void Menu::cargarSprite(sf::Texture &_textura, const char * ruta, sf::Sprite &_sprite, int x, int y, int rotacion, int opcion){
	switch (opcion)
	{
	case 1:
		_textura.loadFromFile(ruta);
		_sprite.setTexture(_textura);
		_sprite.setOrigin(_sprite.getGlobalBounds().width, _sprite.getGlobalBounds().height);
		_sprite.setPosition(x, y);
		_sprite.rotate(rotacion);
		break;
	case 2:
		_textura.loadFromFile(ruta);
		_sprite.setTexture(_textura);
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
		_sprite.setPosition(x, y);
		_sprite.rotate(rotacion);
		break;
	case 3:
		_textura.loadFromFile(ruta);
		_sprite.setTexture(_textura);
		_sprite.setOrigin(_sprite.getGlobalBounds().width, _sprite.getGlobalBounds().height / 2);
		_sprite.setPosition(x, y);
		_sprite.rotate(rotacion);
		break;
	case 4:
		_textura.loadFromFile(ruta);
		_sprite.setTexture(_textura);
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
		_sprite.setPosition(x, y);
		_sprite.rotate(rotacion);
		break;
	default:
		break;
	}
}

bool Menu::clickMouse(){
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		soltarClick = true;
		return true;
	}
	return false;
}

bool Menu::clickMouse(int c){
	soltarClick = false;
	return false;
}
