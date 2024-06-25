#include "Enemigo.h"
#include <SFML/Graphics.hpp>


Enemigo::Enemigo(float salud, float danio, std::string textura, float alto, float ancho, float altoRangoVision, float anchoRangoVision, int filaAnimacion, int columnaAnimacion)
{
	_salud = salud;
	_danio = danio;
	_textura.loadFromFile(textura);
	_cuerpo.setTexture(&_textura);
	_cuerpo.setSize(sf::Vector2f(ancho,alto));
	_cuerpo.setOrigin(_cuerpo.getGlobalBounds().width/2,_cuerpo.getGlobalBounds().height/2);
	_velocidad = sf::Vector2f(0,0);
	_estado = ESTADOS::CAYENDO;
	_vivo = true;
	_rangoVision.setSize(sf::Vector2f(anchoRangoVision,altoRangoVision));
	_rangoVision.setOrigin(_rangoVision.getGlobalBounds().width/2, _rangoVision.getGlobalBounds().height/2);
	_barraVida = new BarraVida(sf::Color::Red);
	_siguiendoPersonaje = false;
	_recibiendoDanio = 0;
	_atacando = false;
	_animacion = new Animacion(&_textura, sf::Vector2u(columnaAnimacion,filaAnimacion), 0.1f, alto,ancho);
	_tiempoEspera = 5.0f;
}
Enemigo::~Enemigo()
{
}
//entiendo este metodo como para determinar si el enemigo puede o no infligir daño
//verificamos si el estado es atacando y si el tiempo que paso desde el ultimo ataque es menor al de espera
//el clock dentro del if, devuelve los segundos desde el ultimo restart()
//si este tiempo es menor que _tiempoEspera, significa que el enemigo todavía esta en su fase de ataque y
//esta "esperando" o antes de poder atacar de nuevo.

//si la condicion se cumple quiere decir que el enemigo esta esperando asi que no retorna 0 (no ataca)
int Enemigo::getDanio()
{
	if (_estado == ESTADOS::ATACANDO && clock.getElapsedTime().asSeconds() < _tiempoEspera) {
		return 0;
	}
	return _danio;
}
void Enemigo::quieto()
{	
	_velocidad.y = 0;
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
void Enemigo::reiniciar(sf::Vector2f position, float salud)
{
	_cuerpo.setPosition(position);
	_salud = salud;
	_estado = ESTADOS::PATRULLANDO;
	_siguiendoPersonaje = false;
}
void Enemigo::recibiendoDanio(int lado)
{
	_recibiendoDanio = lado;
}
sf::FloatRect Enemigo::getHitBox()
{
	return _cuerpo.getGlobalBounds();
}
void Enemigo::comando(float puntoA, float puntoB, Personaje personaje)
{
	//ejecutamos este if para que el enemigo luego de haber golpeado se quede quieto
	//ponemos un return para que no se ejecute nada mas de comando y simpelmente se quede parado
	if (_estado == ESTADOS::ATACANDO && clock.getElapsedTime().asSeconds() < _tiempoEspera)
	{
		std::cout << "ESTOY ATACANDO" << std::endl;
		return;
	}
	if(_recibiendoDanio==1)
	{
		_estado = ESTADOS::RDANIO;
		_velocidad.x = 35;
	}
	if(_recibiendoDanio==2)
	{
		_estado = ESTADOS::RDANIO;
		_velocidad.x = -35;
	}
	
	if(_salud <= 0)
	{
		
		_estado = ESTADOS::MUERTO;
		
	}
	
	if(_velocidad.y != 0)
	{
		_estado = ESTADOS::CAYENDO;
	}
	
	if(_estado != ESTADOS::MUERTO  && _recibiendoDanio == 0)
	{
		if(!_siguiendoPersonaje)
		{
			_estado=ESTADOS::PATRULLANDO;
		}
		if(_rangoVision.getGlobalBounds().intersects(personaje.getCuerpo().getGlobalBounds()) || _siguiendoPersonaje)
		{
			if(personaje.getPosicion().x<=_cuerpo.getPosition().x && !_colisionandoIzq)
			{	
				_velocidad.x = -_velocidadCaminata;
				_cuerpo.setScale(1,1);
			}
			if(personaje.getPosicion().x>_cuerpo.getPosition().x && !_colisionandoDer)
			{
				_velocidad.x = _velocidadCaminata;
				_cuerpo.setScale(-1,1);
			}
			_estado = ESTADOS::SIGUIENDO;
			_siguiendoPersonaje = true;
		}
	}
	if(_atacando && !_recibiendoDanio)
	{
		_estado = ESTADOS::ATACANDO;
		clock.restart();
	}
	if(_salud < 0)
	{
		_salud = 0;
	}
}
void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(_cuerpo, states);
}
void Enemigo::actualizar(float deltaTime)
{
	_barraVida->actualizar(_salud, sf::Vector2f(_cuerpo.getPosition().x, _cuerpo.getPosition().y-_cuerpo.getGlobalBounds().height/2 - 20));
	switch(_estado)
	{
		case CAYENDO:
			_cuerpo.move(0, _velocidad.y);
		case PATRULLANDO:
			_animacion->Update(0, deltaTime);
			_cuerpo.setTextureRect(_animacion->uvRect);
			_cuerpo.move(_velocidad);
			break;
		case SIGUIENDO:
			_animacion->Update(1, deltaTime);
			_cuerpo.setTextureRect(_animacion->uvRect);
			_cuerpo.move(_velocidad);
			break;
		case ATACANDO:
			_velocidad = sf::Vector2f(0, 0);
			_animacion->Update(0, deltaTime);
			_cuerpo.setTextureRect(_animacion->uvRect);
			break;
		case RDANIO:
			_cuerpo.move(_velocidad.x, _velocidad.y);
			_estado = ESTADOS::CAYENDO;
			_recibiendoDanio = 0;
			break;
		case MUERTO:
			_cuerpo.move(0,0);
			_animacion->Update(2, deltaTime);
			_cuerpo.setTextureRect(_animacion->uvRect);
			break;
		
	}
	_rangoVision.setPosition(_cuerpo.getPosition());
	_velocidad.y = 2;
	_colisionandoDer = false;
	_colisionandoIzq = false;
	_velocidad.x = 0;
	_atacando = false;
	_velocidadCaminata = 2;
	
}
void Enemigo::setSalud(float danio)
{
	_salud = _salud - danio;
}
sf::RectangleShape Enemigo::getCuerpo()
{
	return _cuerpo;
}
float Enemigo::getSalud()
{
	return _salud;
}
void Enemigo::setPosition(sf::Vector2f aux)
{
	_cuerpo.setPosition(aux);
}
