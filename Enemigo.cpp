#include "Enemigo.h"
#include "Personaje.h"
#include <iostream>
#include "Funciones.h"
#include <SFML/Graphics.hpp>


Enemigo::Enemigo() : _animacion(&_textura, sf::Vector2u(8,3), 0.1f, 84,63)
{
	_salud = 100;
	_danio = 10;
	_textura.loadFromFile("Textura/Babosa/Baboscompleta.png");
	_cuerpo.setTexture(&_textura);
	_cuerpo.setSize(sf::Vector2f(63,84));
	_cuerpo.setOrigin(_cuerpo.getGlobalBounds().width/2,_cuerpo.getGlobalBounds().height/2);
	_velocidad = sf::Vector2f(0,0);
	_estado = ESTADOS::CAYENDO;
	_vivo = true;
	_posicionInicial = _cuerpo.getPosition();
	_rangoVision.setSize(sf::Vector2f(800,96));
	_rangoVision.setFillColor(sf::Color::Transparent);
	_rangoVision.setOrigin(_rangoVision.getGlobalBounds().width/2, _rangoVision.getGlobalBounds().height/2);

	_siguiendoPersonaje = false;
	_recibiendoDanio = 0;
	_atacando = false;

	
}
Enemigo::~Enemigo()
{
}
Enemigo::getDanio()
{
	return _danio;
}
void Enemigo::quieto()
{	
	_velocidad.y = 0;
}
void Enemigo::setDerecha()
{
	_colisionandoDer = true;
}
void Enemigo::setIzquierda()
{
	_colisionandoIzq = true;
}
void Enemigo::setAtacando()
{
	_atacando = true;
}
void Enemigo::reiniciar(sf::Vector2f position)
{
	_cuerpo.setPosition(position);
	_salud = 100;
	_estado = ESTADOS::PATRULLANDO;
	_siguiendoPersonaje = false;
}
void Enemigo::recibiendoDanio(int lado)
{
	_recibiendoDanio = lado;
}
sf::FloatRect Enemigo::getHitBox()
{
	return _cuerpo.getGlobalBounds();
}
void Enemigo::comando(float puntoA, float puntoB, Personaje personaje)
{
	if(_recibiendoDanio==1)
	{
		_estado = ESTADOS::RDANIO;
		_velocidad.x = 35;
	}
	if(_recibiendoDanio==2)
	{
		_estado = ESTADOS::RDANIO;
		_velocidad.x = -35;
	}
	
	if(_salud <= 0)
	{
		
		_estado = ESTADOS::MUERTO;
		
	}
	
	if(_velocidad.y != 0)
	{
		_estado = ESTADOS::CAYENDO;
	}
	
	if(_estado != ESTADOS::MUERTO  && _recibiendoDanio == 0)
	{
		if(!_siguiendoPersonaje)
		{
			_estado=ESTADOS::PATRULLANDO;
		}
		if(_rangoVision.getGlobalBounds().intersects(personaje.getCuerpo().getGlobalBounds()) || _siguiendoPersonaje)
		{
			if(personaje.getPosicion().x<=_cuerpo.getPosition().x && !_colisionandoIzq)
			{	
				_velocidad.x = -2;
				_cuerpo.setScale(1,1);
			}
			if(personaje.getPosicion().x>_cuerpo.getPosition().x && !_colisionandoDer)
			{
				_velocidad.x = 2;
				_cuerpo.setScale(-1,1);
			}
			_estado = ESTADOS::SIGUIENDO;
			_siguiendoPersonaje = true;
		}
	}
	if(_atacando && !_recibiendoDanio)
	{

		_estado = ESTADOS::ATACANDO;

	}

}
void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(_cuerpo, states);
}
void Enemigo::actualizar(float deltaTime)
{
	switch(_estado)
	{
		case CAYENDO:
			_cuerpo.move(0, _velocidad.y);
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
			_animacion.Update(0, deltaTime);
			_cuerpo.setTextureRect(_animacion.uvRect);
			break;
		case RDANIO:
			_cuerpo.move(_velocidad.x, _velocidad.y);
			_estado = ESTADOS::CAYENDO;
			_recibiendoDanio = 0;
			break;
		case MUERTO:
			_cuerpo.move(0,0);
			_animacion.Update(2, deltaTime, true);
			_cuerpo.setTextureRect(_animacion.uvRect);
			break;
		
	}
	_rangoVision.setPosition(_cuerpo.getPosition());
	_velocidad.y = 2;
	_colisionandoDer = false;
	_colisionandoIzq = false;
	_velocidad.x = 0;
	_atacando = false;
	
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
