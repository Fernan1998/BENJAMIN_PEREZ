#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Opciones.h"
#include "Personaje.h"

class Menu {
public:
	Menu();
	Menu(bool aux);
	~Menu();
	
	void posicionarSprite(sf::Vector2f _personaje, sf::Sprite &_boton, int x, int y);
	void cargarSprite(sf::Texture &_textura, const char * ruta, sf::Sprite &_sprite, int x, int y, int rotacion, int opcion);
	
	int mostrar(sf::RenderWindow &ventana);
	int mostrar(sf::RenderWindow &ventana, sf::Vector2f _personaje);
	
	bool clickEn(sf::RenderWindow &ventana, sf::Sprite &_sprite);
	
	bool entrarOpciones(sf::RenderWindow &ventana);
	
	bool clickMouse();
	bool clickMouse(int c);
	
	/// Getters
	int getControles();
	
	/// Setters
	void setContador(int c);
	void setOpcionesDefault();
private:
	int contador = 0;
	bool soltarClick = false, jugar = false;
	sf::Sprite _botonJugar;
	sf::Texture _texturaJugar;
	sf::Sprite _botonOpcion;
	sf::Texture _texturaOpcion;
	sf::Sprite _botonSalir;
	sf::Texture _texturaSalir;
	sf::Sprite _spriteFondo;
	sf::Texture _texturaFondo;
	sf::Sprite _botonContinuar;
	sf::Texture _texturaContinuar;
	sf::Sprite _botonNuevo;
	sf::Texture _texturaNuevo;
	Opciones opciones;
};
