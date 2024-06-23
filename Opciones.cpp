#include "Opciones.h"

Opciones::Opciones() {
	// Adelante
	inicializarSprite(_texturaAdelante, _spriteAdelante, 500, 200, 0.f, "Textura/Menu/adelante.png", 1);
	// Atras
	inicializarSprite(_texturaAtras, _spriteAtras, 500, 300, 0.f, "Textura/Menu/atras.png", 1);
	// Saltar
	inicializarSprite(_texturaSaltar, _spriteSaltar, 500, 400, 0.f, "Textura/Menu/saltar.png", 1);
	// Abajo
	inicializarSprite(_texturaAbajo, _spriteAbajo, 500, 515, 0.f, "Textura/Menu/abajo.png", 1);
	// Atacar
	inicializarSprite(_texturaAtacar, _spriteAtacar, 500, 600, 0.f, "Textura/Menu/atacar.png", 1);
	// W
	inicializarSprite(_texturaW, _spriteW, 650, 400, 0.f, "Textura/Menu/w.png", 2);
	// S
	inicializarSprite(_texturaS, _spriteS, 650, 500, 0.f, "Textura/Menu/s.png", 2);
	// A
	inicializarSprite(_texturaA, _spriteA, 650, 300, 0.f, "Textura/Menu/a.png", 2);
	// D
	inicializarSprite(_texturaD, _spriteD, 650, 200, 0.f, "Textura/Menu/d.png", 2);
	// Z
	inicializarSprite(_texturaZ, _spriteZ, 670, 600, 0, "Textura/Menu/z.png", 1);
	// X
	inicializarSprite(_texturaX, _spriteX, 750, 600, 0.f, "Textura/Menu/x.png", 2);
	// F
	inicializarSprite(_texturaF, _spriteF, 650, 600, 0.f, "Textura/Menu/f.png", 2);
	// E
	inicializarSprite(_texturaE, _spriteE, 750, 600, 0.f, "Textura/Menu/e.png", 2);
	// Numpad 1
	inicializarSprite(_texturaNumpad1, _spriteNumpad1, 650, 400, 0.f, "Textura/Menu/1.png", 2);
	// Numpad 2
	inicializarSprite(_texturaNumpad2, _spriteNumpad2, 650, 600, 0.f, "Textura/Menu/2.png", 2);
	// Numpad 3
	inicializarSprite(_texturaNumpad3, _spriteNumpad3, 750, 600, 0.f, "Textura/Menu/3.png", 2);
	// Volver
	inicializarSprite(_texturaVolver, _spriteVolver, 650, 700, 0.f, "Textura/Menu/volver.png", 2);
	// Flechas <Controles>
	inicializarSprite(_texturaFlecha1, _spriteFlecha1, 300, 65, 180.f, "Textura/Menu/flecha.png", 1);
	inicializarSprite(_texturaFlecha2, _spriteFlecha2, 700, 100, 0.f, "Textura/Menu/flecha.png", 2);
	// Controles
	inicializarSprite(_texturaControles, _spriteControles, 500, 100, 0.f, "Textura/Menu/controles.png", 2);
	// Flechas controles
	inicializarSprite(_texturaFlecha3, _spriteFlecha3, 650, 200, 0.f, "Textura/Menu/flecha.png", 2);
	inicializarSprite(_texturaFlecha4, _spriteFlecha4, 670, 365, 270.f, "Textura/Menu/flecha.png", 1);
	inicializarSprite(_texturaFlecha5, _spriteFlecha5, 650, 260, 180.f, "Textura/Menu/flecha.png", 2);
	inicializarSprite(_texturaFlecha6, _spriteFlecha6, 635, 480, 90.f, "Textura/Menu/flecha.png", 2);
}

Opciones::~Opciones() {
	
}

bool Opciones::mostrar(sf::RenderWindow &ventana){
	ventana.draw(_spriteAdelante);
	ventana.draw(_spriteAtras);
	ventana.draw(_spriteAbajo);
	ventana.draw(_spriteAtacar);
	ventana.draw(_spriteSaltar);
	switch (controles){
	case 0:
		setControles(3);
	case 1:
		ventana.draw(_spriteA);
		ventana.draw(_spriteD);
		ventana.draw(_spriteS);
		ventana.draw(_spriteNumpad1);
		ventana.draw(_spriteNumpad2);
		ventana.draw(_spriteNumpad3);
		break;
	case 2:
		ventana.draw(_spriteW);
		ventana.draw(_spriteS);
		ventana.draw(_spriteF);
		ventana.draw(_spriteE);
		ventana.draw(_spriteA);
		ventana.draw(_spriteD);
		break;
	case 3:
		ventana.draw(_spriteFlecha3);
		ventana.draw(_spriteFlecha4);
		ventana.draw(_spriteFlecha5);
		ventana.draw(_spriteFlecha6);
		ventana.draw(_spriteZ);
		ventana.draw(_spriteX);
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
	bool click = clickMouse();
	if (soltarClick && !click) {
		if (contador < 3) {
			contador++;
		}else {
			contador = 0;
			clickMouse(contador);
		}
	}
	if (encimaDe(ventana, _spriteVolver) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		return false;
	}else if (encimaDe(ventana, _spriteFlecha1) && soltarClick && !click){
		controles--;
		soltarClick = false;
	}else if (encimaDe(ventana, _spriteFlecha2) && soltarClick && !click){
		controles++;
		soltarClick = false;
	}
	return true;
}

bool Opciones::encimaDe(sf::RenderWindow &ventana, sf::Sprite &_sprite){
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

int Opciones::getControles(){
	return controles;
}

void Opciones::setControles(int c){
	if (c > 0 && c <= 3) {
		controles = c;
	}
}

bool Opciones::clickMouse(){
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		soltarClick = true;
		return true;
	}
	return false;
}

bool Opciones::clickMouse(int c){
	soltarClick = false;
	return false;
}

void Opciones::setContador(int c){
	contador = c;
}

void Opciones::inicializarSprite(sf::Texture& _textura, sf::Sprite& _sprite, int x, int y, float rotacion, std::string ruta, int opcion) {
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
