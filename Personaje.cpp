#include "Personaje.h"


Personaje::Personaje() : animacion(&_textura, sf::Vector2u(16,2), 0.05f, 108,73)
{
	_textura.loadFromFile("Textura/Player/BenjaminPerez.png");
	_cuerpo.setTexture(&_textura);
	_cuerpo.setPosition(sf::Vector2f(130,150));
	_cuerpo.setSize(sf::Vector2f(78.0f, 107.0f));
	_velocidad = sf::Vector2f(0,0);
	_estado = ESTADOS::CAYENDO;
	_velocidadSalto = 0;
	_cuerpo.setOrigin(_cuerpo.getGlobalBounds().width/2,_cuerpo.getGlobalBounds().height/2); 
	_saltando = true;
	_cajaAtaque.setSize(sf::Vector2f(90.0f, 120.0f));
	_cajaAtaque.setOrigin(_cajaAtaque.getGlobalBounds().width/2, _cajaAtaque.getGlobalBounds().height/2);
	_colisionandoDer = false;
	_colisionandoIzq = false;
	_atacando = false;
	_danio = 10;
	_salud = 100;
 
}
Personaje::~Personaje()
{
	
}
sf::RectangleShape Personaje::getCuerpo()
{
	return _cuerpo;
}
sf::RectangleShape Personaje::getCajaAtaque()
{
	return _cajaAtaque;
}
sf::FloatRect Personaje::getCajaCuerpo()
{
	return _cuerpo.getGlobalBounds();
}
float Personaje::getVelocidadSalto()
{
	return _velocidadSalto;
}
void Personaje::setPosicion(float a, float b)
{
	_cuerpo.setPosition(a,b);
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
	if(_estado == ESTADOS::QUIETO)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
		{
			_estado = ESTADOS::ATACANDO;
		}
	}
	
	if(!_saltando)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
		{
			_estado = ESTADOS::SALTANDO;
			_velocidadSalto = 10;
		}
	}
	_saltando = true;	
	_colisionandoDer = false;
	_colisionandoIzq = false;
	_atacando = false;
}
void Personaje::actualizar(float deltaTime)
{
	switch(_estado)
	{
		case QUIETO:
			_velocidadSalto=0;
			
			animacion.Update(1, deltaTime);
			_cuerpo.setTextureRect(animacion.uvRect);
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
		case CAYENDO:
			_cuerpo.move(0, -_velocidadSalto);
			break;
		case ATACANDO:
			_atacando = true;
			break;
	
		}
	_velocidadSalto-=0.5;
	_velocidad=sf::Vector2f(0,0);
	_cajaAtaque.setPosition(_cuerpo.getPosition());
}
void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(_cuerpo, states);
	//target.draw(_cajaAtaque, states);
}


bool Personaje::getAtacando()
{
	return _atacando;
}
float Personaje::getDanio()
{
	return _danio;
}
