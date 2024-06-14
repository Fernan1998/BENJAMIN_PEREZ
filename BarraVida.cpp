#include "BarraVida.h"

BarraVida::BarraVida()
{
	_contorno.setSize(sf::Vector2f(120,25));
	_centroBlanco.setSize(sf::Vector2f(100,15));
	_vida.setSize(sf::Vector2f(100,15));
	_contorno.setFillColor(sf::Color::Black);
	_centroBlanco.setFillColor(sf::Color(255, 255, 255));
	_vida.setFillColor(sf::Color::Red);
	_contorno.setOrigin(_contorno.getGlobalBounds().width/2,_contorno.getGlobalBounds().height/2); 
	_centroBlanco.setOrigin(_centroBlanco.getGlobalBounds().width/2,_centroBlanco.getGlobalBounds().height/2); 
	_vida.setOrigin(_vida.getGlobalBounds().width/2,_vida.getGlobalBounds().height/2); 
	_centroBlanco.setFillColor(sf::Color(255, 255, 255));
	_vida.setFillColor(sf::Color::Red);
	
}

BarraVida::~BarraVida()
{
	
}
void BarraVida::actualizar(float &salud, sf::Vector2f posicion)
{
	_contorno.setPosition(posicion);
	_centroBlanco.setPosition(posicion);
	_vida.setPosition(posicion);
	_vida.setSize(sf::Vector2f(salud,15));
}

void BarraVida::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(_contorno, states);
	target.draw(_centroBlanco, states);
	target.draw(_vida, states);
}


