#include "Proyectil.h"

Proyectil::Proyectil(std::string textura)
{
	_textura.loadFromFile(textura);
	_cuerpo.setTexture(&_textura);
	_cuerpo.setSize(sf::Vector2f(38.0f, 34.0f));
	_cuerpo.setOrigin(_cuerpo.getGlobalBounds().width/2,_cuerpo.getGlobalBounds().height/2); 
}
void Proyectil::actualizar(int other)
{
	_cuerpo.setFillColor(sf::Color::White);
	if(other == 1)
	{
		_cuerpo.move(15.0f, 0.0f);
		_cuerpo.rotate(5.0f);
		
	}
	else if(other == 2)
	{
		_cuerpo.move(-15.0f, 0.0f);
		_cuerpo.rotate(5.0f);
	}

}

void Proyectil::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(_cuerpo, states);
}
void Proyectil::setPosition(sf::Vector2f aux)
{
	_cuerpo.setPosition(aux);
}
sf::FloatRect Proyectil::getCuerpo()
{
	return _cuerpo.getGlobalBounds();
}
sf::RectangleShape Proyectil::getSprite()
{
	return _cuerpo;
}
void Proyectil::setColor(sf::Color aux)
{
	_cuerpo.setFillColor(aux);
}
sf::Vector2f Proyectil::getPosition()
{
	return _cuerpo.getPosition();
}
