#include "Enemigo.h"
#include <SFML/Graphics.hpp>

Enemigo::Enemigo() : _animacion(&_textura, sf::Vector2u(16,1), 0.05f)
{
	
}
Enemigo::~Enemigo()
{
	
}
void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(_cuerpo, states);
}


