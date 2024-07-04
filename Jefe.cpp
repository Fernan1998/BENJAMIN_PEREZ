#include "Jefe.h"

Jefe::Jefe(float salud, float danio, std::string textura, float alto, float ancho, float altoRangoVision, float anchoRangoVision, int filaAnimacion, int columnaAnimacion) : Enemigo(salud, danio, textura,  alto,  ancho, altoRangoVision, anchoRangoVision, filaAnimacion, columnaAnimacion)
{
	_piedra = new Proyectil("Textura/piedra/Piedra.png");
	_estado = ESTADOS::PATRULLANDO;
	
}

Jefe::~Jefe()
{
	
}

bool Jefe::soyEnemigo()
{
	return false;
}
sf::FloatRect Jefe::devolver()
{
	return _piedra->getCuerpo();
}
void Jefe::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_cuerpo, states);
	target.draw(*_piedra, states);
}
void Jefe::comando(Personaje personaje)
{
	if(_salud <= 0)
	{
		_estado = ESTADOS::MUERTO;
	}
	
	if(_velocidad.y != 0)
	{
		_estado = ESTADOS::CAYENDO;
	}
	
	if(_salud > 0)
	{
		if(_rangoVision.getGlobalBounds().intersects(personaje.getCuerpo().getGlobalBounds()))
		{
			_siguiendoPersonaje = true;
		}
		
		if(_siguiendoPersonaje)
		{
			_estado = ESTADOS::SIGUIENDO;
			if(_cuerpo.getPosition().x > personaje.getPosicion().x-1000)
			{
				_piedra->actualizar(2);
			}

		}
 
		if(_recibiendoDanio!=0)
		{
			if(_recibiendoDanio == 1)
			{
				_estado = ESTADOS::RDANIO;
			}
			else
			{
				_estado = ESTADOS::RDANIO;
			}
			
			_cuerpo.move(0,25);
		}
		if(_velocidad.y != 0)
		{
			_siguiendoPersonaje = false;
			_estado == ESTADOS::PATRULLANDO;
		}
	}
	if(_piedra->getPosition().x< _cuerpo.getPosition().x-2500)
	{
		_estado = ESTADOS::PATRULLANDO;
		_siguiendoPersonaje = false;
	}
}
void Jefe::actualizar(float deltaTime) 
{
	
	_barraVida->actualizar(_salud, sf::Vector2f(_cuerpo.getPosition().x, _cuerpo.getPosition().y-_cuerpo.getGlobalBounds().height/2 - 20));
	_rangoVision.setPosition(_cuerpo.getPosition());
	switch(_estado)
	{
		case CAYENDO:
			_cuerpo.move(0, _velocidad.y);
		case PATRULLANDO:
			_cuerpo.move(_velocidad);
			_animacion->Update(1, deltaTime);
			_cuerpo.setTextureRect(_animacion->uvRect);
			_piedra->setPosition(sf::Vector2f(_cuerpo.getPosition().x-25,_cuerpo.getPosition().y+10));
			break;
		case SIGUIENDO:
			_cuerpo.move(_velocidad);
			_animacion->Update(0, deltaTime);
			_cuerpo.setTextureRect(_animacion->uvRect);
			break;
		case ATACANDO:
			_cuerpo.move(0, _velocidad.y);
			_cuerpo.setTexture(&_textura);
			_animacionDanio->Update(0, deltaTime);
			_cuerpo.setTextureRect(_animacionDanio->uvRect);
			break;
		case RDANIO:
			_recibiendoDanio = 0;
			break;
		case MUERTO:
			_cuerpo.move(0,0);
			_cuerpo.setFillColor(sf::Color::Transparent);
			_barraVida->modoPausa(true);
			break;
	}
	
	
	_velocidad = sf::Vector2f(0,4);
	_velocidadCaminata = 2;
	_colisionandoDer = false;
	_colisionandoIzq = false;
	
	if( _animacionDanio->getColumna() == 2 && _animacionDanio->getFila() >= (_animacionDanio->getCantidadFila()-1))
	{
		_atacando = false;
		_animacionDanio->reiniciarFila();
	}
}
Proyectil* Jefe::getPiedra()
{
	return _piedra;
}
