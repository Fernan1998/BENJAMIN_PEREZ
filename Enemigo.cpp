#include "Enemigo.h"
#include "Personaje.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Enemigo::Enemigo(sf::Vector2f ubicacion) : _animacion(&_textura, sf::Vector2u(8,2), 0.1f, 96,96)
{
	_salud = 100;
	_danio = 10;
	_textura.loadFromFile("Textura/Babosa/iddle_babosa.png");
	_cuerpo.setTexture(&_textura);
	_cuerpo.setSize(sf::Vector2f(96,96));
	_cuerpo.setOrigin(_cuerpo.getGlobalBounds().width/2,_cuerpo.getGlobalBounds().height/2);
	_velocidad = sf::Vector2f(0,0);
	_cuerpo.setPosition(ubicacion);
	_estado = ESTADOS::PATRULLANDO;
	_vivo = true;
	_posicionInicial = _cuerpo.getPosition();
	_rangoVision.setSize(sf::Vector2f(800,96));
	_rangoVision.setFillColor(sf::Color::Transparent);
	_rangoVision.setOrigin(_rangoVision.getGlobalBounds().width/2, _rangoVision.getGlobalBounds().height/2);
	_cuerpo.setFillColor(sf::Color::Red);
	
}
Enemigo::~Enemigo()
{
	
}
void Enemigo::recibiendoDanio()
{
	_estado = ESTADOS::RDANIO;
}
void Enemigo::comando(float puntoA, float puntoB, Personaje personaje)
{
	if(_salud <= 0)
	{
		_estado = ESTADOS::MUERTO;
	}
	if(_estado != ESTADOS::MUERTO)
	{
		_estado = ESTADOS::PATRULLANDO;
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
		if(_estado == ESTADOS::PATRULLANDO)
		{
			_estado = ESTADOS::PATRULLANDO;
			if(_cuerpo.getPosition().x <= puntoA)
			{
				_velocidad.x = 2;
			}
			if(_cuerpo.getPosition().x >= puntoB)
			{
				_velocidad.x = -2;
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
		case QUIETO:
			_animacion.Update(0, deltaTime);
			_cuerpo.setTextureRect(_animacion.uvRect);
		case PATRULLANDO:
			_animacion.Update(0, deltaTime);
			_cuerpo.setTextureRect(_animacion.uvRect);
			_cuerpo.move(_velocidad);
			break;
		case SIGUIENDO:
			_animacion.Update(1, deltaTime, true);
			_cuerpo.setTextureRect(_animacion.uvRect);
			_cuerpo.move(_velocidad);
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

