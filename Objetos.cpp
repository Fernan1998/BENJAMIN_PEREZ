#include "Objetos.h"

Objetos::Objetos(float alto, float ancho, std::string textura)
{
	_textura.loadFromFile(textura);
	_cuerpo.setTexture(&_textura);
	_cuerpo.setSize(sf::Vector2f(ancho,alto));
	_cuerpo.setOrigin(_cuerpo.getGlobalBounds().width/2,_cuerpo.getGlobalBounds().height/2);

}

Objetos::Objetos()
{
	
}

Objetos::~Objetos() {
	
}

void Objetos::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(_cuerpo, states);
}
