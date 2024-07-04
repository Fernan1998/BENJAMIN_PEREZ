#include "Enemigo.h"
#include <SFML/Graphics.hpp>


Enemigo::Enemigo(float salud, float danio, std::string textura, float alto, float ancho, float altoRangoVision, float anchoRangoVision, int filaAnimacion, int columnaAnimacion)
{
	_textura.loadFromFile(textura);
	_cuerpo.setTexture(&_textura);
	_cuerpo.setSize(sf::Vector2f(ancho,alto));
	_cuerpo.setOrigin(_cuerpo.getGlobalBounds().width/2,_cuerpo.getGlobalBounds().height/2);
	
	_salud = salud;
	_danio = danio;
	_recibiendoDanio = 0;
	_vivo = true;
	_atacando = false;
	_siguiendoPersonaje = false;
	
	_rangoVision.setSize(sf::Vector2f(anchoRangoVision,altoRangoVision));
	_rangoVision.setOrigin(_rangoVision.getGlobalBounds().width/2, _rangoVision.getGlobalBounds().height/2);
	
	_barraVida = new BarraVida(sf::Color::Red);
	_animacion = new Animacion(&_textura, sf::Vector2u(columnaAnimacion,filaAnimacion), 0.1f, alto,ancho);
	_animacionDanio = new Animacion(&_textura, sf::Vector2u(columnaAnimacion,filaAnimacion), 0.1f, alto,ancho);
}
Enemigo::~Enemigo()
{
}

void Enemigo::setVelocidadCaminata(float aux)
{
	_velocidadCaminata = aux;
}
void Enemigo::setColor(sf::Color color)
{
	_cuerpo.setFillColor(color);
}
BarraVida Enemigo::getBarraVida()
{
	return *_barraVida;
}
sf::RectangleShape Enemigo::getCuerpo()
{
	return _cuerpo;
}
float Enemigo::getSalud()
{
	return _salud;
}
int Enemigo::getDanio()
{
	return _danio;
}

void Enemigo::quieto()
{	
	_velocidad.y = 0;
}
bool Enemigo::soyEnemigo()
{
	return true;
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
void Enemigo::setSalud(float danio)
{
	_salud = _salud - danio;
}
void Enemigo::setPosition(sf::Vector2f aux)
{
	_cuerpo.setPosition(aux);
}

void Enemigo::reiniciar(sf::Vector2f position, float salud)
{
	_cuerpo.setPosition(position);
	_salud = salud;
	_estado = ESTADOS::PATRULLANDO;
	_cuerpo.setFillColor(sf::Color::White);
	_recibiendoDanio = false;
	_siguiendoPersonaje = false;
	_barraVida->modoPausa(false);
}
void Enemigo::recibiendoDanio(int lado)
{
	_recibiendoDanio = lado;
	_animacion->reiniciarFila();
}
sf::FloatRect Enemigo::getHitBox()
{
	return _cuerpo.getGlobalBounds();
}
void Enemigo::comando(Personaje personaje)
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
			
			if(personaje.getPosicion().x<_cuerpo.getPosition().x && !_colisionandoIzq)
			{	
				_velocidad.x = -_velocidadCaminata;
				_cuerpo.setScale(1,1);
			}
			else if(personaje.getPosicion().x>_cuerpo.getPosition().x && !_colisionandoDer)
			{
				_velocidad.x = _velocidadCaminata;
				_cuerpo.setScale(-1,1);
			}

		}
		else
		{
			_estado=ESTADOS::PATRULLANDO;
		}
		
		if(_atacando && !_recibiendoDanio)
		{
			_estado = ESTADOS::ATACANDO;
		}
		
		if(_recibiendoDanio!=0)
		{
			if(_recibiendoDanio == 1)
			{
				_estado = ESTADOS::RDANIO;
				_velocidad.x = 50;
			}
			else
			{
				_estado = ESTADOS::RDANIO;
				_velocidad.x = -50;
			}
		}
		
	}

}
void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(_cuerpo, states);
}
void Enemigo::actualizar(float deltaTime)
{
	_barraVida->actualizar(_salud, sf::Vector2f(_cuerpo.getPosition().x, _cuerpo.getPosition().y-_cuerpo.getGlobalBounds().height/2 - 20));
	_rangoVision.setPosition(_cuerpo.getPosition());
	
	switch(_estado)
	{
		case CAYENDO:
			_cuerpo.move(0, _velocidad.y);
		case PATRULLANDO:
			_cuerpo.move(_velocidad);
			_animacion->Update(0, deltaTime);
			_cuerpo.setTextureRect(_animacion->uvRect);
			break;
		case SIGUIENDO:
			_cuerpo.move(_velocidad);
			_animacion->Update(1, deltaTime);
			_cuerpo.setTextureRect(_animacion->uvRect);
			break;
		case ATACANDO:
			_cuerpo.move(0, _velocidad.y);
			_cuerpo.setTexture(&_textura);
			_animacionDanio->Update(2, deltaTime);
			_cuerpo.setTextureRect(_animacionDanio->uvRect);
			break;
		case RDANIO:
			_cuerpo.move(_velocidad.x, _velocidad.y);
			_recibiendoDanio = 0;
			break;
		case MUERTO:
			_cuerpo.move(0,0);
			_cuerpo.setTexture(&_textura);
			_animacion->Update(3, deltaTime, true);
			_cuerpo.setTextureRect(_animacion->uvRect);
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

bool Enemigo::getMuerto(){
	if (_estado == ESTADOS::MUERTO) {
		return true;
	}
	return false;
}
	
sf::FloatRect Enemigo::devolver()
{
	return _cuerpo.getGlobalBounds();
}

float Enemigo::getArmadura()
{
	return _armadura;
}
void Enemigo::setArmadura(float armadura)
{
	_armadura = armadura;
}
void Enemigo::setSize(sf::Vector2f aux)
{
	_cuerpo.setSize(aux);
}
