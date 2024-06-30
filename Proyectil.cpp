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
void Proyectil::actualizar(sf::Vector2f Posicion)
{
	if(_cuerpo.getPosition().x> Posicion.x)
	{
		_cuerpo.move(-7,0);
	}
}
void Proyectil::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(_cuerpo, states);
}
