#include "Personaje.h"

Personaje::Personaje() : animacion(&_textura, sf::Vector2u(16,1), 0.05f)
{
	_textura.loadFromFile("Textura/Player/CharacterWalk.PNG");
	_cuerpo.setTexture(&_textura);
	_cuerpo.setSize(sf::Vector2f(60.0f, 120.0f));
	_cuerpo.setPosition(120,150);
	_velocidad = sf::Vector2f(0,0);
	_estado = ESTADOS::CAYENDO;
	_velocidadSalto = 0;
	_cuerpo.setOrigin(_cuerpo.getGlobalBounds().width/2,_cuerpo.getGlobalBounds().height/2);
	_saltando = true;
	_colisionandoDer = false;
	_colisionandoIzq = false;
	
}
Personaje::~Personaje()
{
	
}
sf::RectangleShape Personaje::getCuerpo()
{
	return _cuerpo;
}
float Personaje::getVelocidadSalto()
{
	return _velocidadSalto;
}
void Personaje::setPosicion(sf::Vector2f posicion)
{
	_cuerpo.setPosition(posicion);
}
void Personaje::quieto(float x, float y)
{
	_estado = ESTADOS::QUIETO;
	_velocidadSalto = 0;
	_cuerpo.setPosition(x,y);
	_saltando = false;
}
sf::Vector2f Personaje::getPosicion()
{
	return _cuerpo.getPosition();
}

void Personaje::cayendo()
{
	if(_velocidadSalto > 0)
	{
		_velocidadSalto = 0;
	}
	_estado = ESTADOS::CAYENDO;
}
void Personaje::setDerecha()
{
	_colisionandoDer = true;
}
void Personaje::setIzquierda()
{
	_colisionandoIzq = true;
}
void Personaje::comandos()
{
	if(_estado == ESTADOS::QUIETO && !_colisionandoIzq ||
	   _estado == ESTADOS::CAYENDO && !_colisionandoIzq ||
	   _estado == ESTADOS::CAMINANDO_ATRAS && !_colisionandoIzq)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			_estado = ESTADOS::CAMINANDO_ATRAS;
			_velocidad.x = -4;
		};
	}
	if(_estado == ESTADOS::QUIETO && !_colisionandoDer ||
	   _estado == ESTADOS::CAYENDO && !_colisionandoDer ||
	   _estado == ESTADOS::CAMINANDO_ATRAS && !_colisionandoDer)
	{	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			_estado = ESTADOS::CAMINANDO_ADELANTE;
			_velocidad.x = 4;
		};
	}
	
	if(!_saltando)
	{
//		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
//		{
//			_estado = ESTADOS::SALTANDO_ADELANTE;
//			_jumpVelocity = 10;
//		}
//		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
//		{
//			_estado = ESTADOS::SALTANDO_ATRAS;
//			_jumpVelocity = 10;
//		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
		{
			_estado = ESTADOS::SALTANDO;
			_velocidadSalto = 10;
		}
//		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//		{
//			_velocidad = -16;
//		}
	}
	_saltando = true;	
	_colisionandoDer = false;
	_colisionandoIzq = false;
}
void Personaje::actualizar(float deltaTime)
{
	switch(_estado)
	{
		case QUIETO:
			_velocidadSalto=0;
			break;
		case CAMINANDO_ADELANTE:
			_cuerpo.setScale(1,1);
			_cuerpo.move(_velocidad.x, -_velocidadSalto);
			_estado= ESTADOS::CAYENDO;

			animacion.Update(0, deltaTime);
			_cuerpo.setTextureRect(animacion.uvRect);
			break;
		case CAMINANDO_ATRAS:
			_cuerpo.setScale(-1,1);
			_cuerpo.move(_velocidad.x, -_velocidadSalto);
			_estado= ESTADOS::CAYENDO;
			
			animacion.Update(0, deltaTime);
			_cuerpo.setTextureRect(animacion.uvRect);
			break;
		case SALTANDO:
			_cuerpo.move(0, -_velocidadSalto);
			_estado= ESTADOS::CAYENDO;
			break;
//		case SALTANDO_ADELANTE:
//			_body.setScale(1,1);
//			_body.move(10, -_jumpVelocity);
//			_estado= ESTADOS::CAYENDO;
//			break;
//		case SALTANDO_ATRAS:
//			_body.setScale(-1,1);
//			_body.move(-10, -_velocidadSalto);
//			_estado= ESTADOS::CAYENDO;
//			break; 
		case CAYENDO:
			_cuerpo.move(0, -_velocidadSalto);
			break;
			
		}
	_velocidadSalto-=0.5;
	_velocidad=sf::Vector2f(0,0);
}
void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(_cuerpo, states);
}


