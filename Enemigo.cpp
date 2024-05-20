#include "Enemigo.h"
#include <SFML/Graphics.hpp>

Enemigo::Enemigo(sf::Vector2f ubicacion) : _animacion(&_textura, sf::Vector2u(8,1), 0.05f, 96,96)
{
	_textura.loadFromFile("Textura/Babosa/iddle_babosa.png");
	_cuerpo.setTexture(&_textura);
	_cuerpo.setSize(sf::Vector2f(96,96));
	_cuerpo.setOrigin(_cuerpo.getGlobalBounds().width/2,_cuerpo.getGlobalBounds().height/2);
	_velocidad = sf::Vector2f(0,0);
	_cuerpo.setPosition(ubicacion);
	_estado = ESTADOS::QUIETO;
	_vivo = true;
}
Enemigo::~Enemigo()
{
	
}
void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(_cuerpo, states);
}
void Enemigo::actualizar(float deltaTime)
{
	switch(_estado)
	{
	case QUIETO:
		_animacion.Update(0, deltaTime);
		_cuerpo.setTextureRect(_animacion.uvRect);
	case CAMINANDO_ADELANTE:
		break;
	case CAMINANDO_ATRAS:
		break;
	case ATACANDO:
		break;
	}
}


