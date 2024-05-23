#include "Enemigo.h"
#include "Personaje.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Enemigo::Enemigo() : _animacion(&_textura, sf::Vector2u(8,2), 0.1f, 96,96)
{
	_salud = 100;
	_danio = 10;
	_textura.loadFromFile("Textura/Babosa/iddle_babosa.png");
	_cuerpo.setTexture(&_textura);
	_cuerpo.setSize(sf::Vector2f(96,96));
	_cuerpo.setOrigin(_cuerpo.getGlobalBounds().width/2,_cuerpo.getGlobalBounds().height/2);
	_velocidad = sf::Vector2f(0,0);
	_estado = ESTADOS::CAYENDO;
	_vivo = true;
	_posicionInicial = _cuerpo.getPosition();
	_rangoVision.setSize(sf::Vector2f(800,96));
	_rangoVision.setFillColor(sf::Color::Transparent);
	_rangoVision.setOrigin(_rangoVision.getGlobalBounds().width/2, _rangoVision.getGlobalBounds().height/2);

	
}
Enemigo::~Enemigo()
{
	
}
void Enemigo::recibiendoDanio()
{
	_estado = ESTADOS::RDANIO;
}
sf::FloatRect Enemigo::getHitBox()
{
	return _cuerpo.getGlobalBounds();
}
void Enemigo::comando(float puntoA, float puntoB, Personaje personaje)
{

	if(_salud <= 0)
	{
		_estado = ESTADOS::MUERTO;
	}
	if(_velocidad.y != 0)
	{
		_estado = ESTADOS::CAYENDO;
	}
	if(_estado != ESTADOS::MUERTO && _estado != ESTADOS::CAYENDO)
	{
		_estado = ESTADOS::PATRULLANDO;
		if(_estado == ESTADOS::PATRULLANDO)
		{
			
		}
		if(_rangoVision.getGlobalBounds().intersects(personaje.getCuerpo().getGlobalBounds()))
		{
			_estado = ESTADOS::SIGUIENDO;
			if(personaje.getPosicion().x<_cuerpo.getPosition().x)
			{
				_velocidad.x = -2;
				_cuerpo.setScale(1,1);
			}
			if(personaje.getPosicion().x>_cuerpo.getPosition().x)
			{
				_velocidad.x = 2;
				_cuerpo.setScale(-1,1);
			}
			
		}
		
	}
}
void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(_cuerpo, states);
	target.draw(_rangoVision, states);
}
void Enemigo::actualizar(float deltaTime)
{
	switch(_estado)
	{
//		case QUIETO:
//			_animacion.Update(0, deltaTime);
//			_cuerpo.setTextureRect(_animacion.uvRect);
//			_estado = ESTADOS::PATRULLANDO;
//			std::cout << "ESTAOD QUIETO\n";
		case CAYENDO:
			_cuerpo.move(0, _velocidad.y);
			_estado = ESTADOS::QUIETO;
			std::cout << "ESTAOD CAYENDO\n";
		case PATRULLANDO:
			_animacion.Update(0, deltaTime);
			_cuerpo.setTextureRect(_animacion.uvRect);
			_cuerpo.move(_velocidad);
			std::cout << "ESTAOD PATRULLANDO\n";
			break;
		case SIGUIENDO:
			_animacion.Update(1, deltaTime, true);
			_cuerpo.setTextureRect(_animacion.uvRect);
			_cuerpo.move(_velocidad);
			std::cout << "ESTAOD SIGUIENDO\n";
			break;
		case ATACANDO:
			break;
		case MUERTO:
			_cuerpo.move(0,0);
			break;
		case RDANIO:
		
		break;
	}
	_rangoVision.setPosition(_cuerpo.getPosition());
	_velocidad.y = 2;
	_colisionandoDer = false;
	_colisionandoIzq = false;
	_velocidad.x = 0;
	
}
void Enemigo::setSalud(float danio)
{
	_salud = _salud - danio;
}
sf::RectangleShape Enemigo::getCuerpo()
{
	return _cuerpo;
}
float Enemigo::getSalud()
{
	return _salud;
}
void Enemigo::setPosition(sf::Vector2f aux)
{
	_cuerpo.setPosition(aux);
}
