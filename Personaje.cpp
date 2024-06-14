#include "Personaje.h"

Personaje::Personaje()
{
	_textura.loadFromFile("Textura/Player/BenjaminPerez.png");
	_texturaAtaque.loadFromFile("Textura/Player/BPAtaque.png");
	_cuerpo.setTexture(&_textura);
	_cuerpo.setPosition(sf::Vector2f(130,150));
	_cuerpo.setSize(sf::Vector2f(78.0f, 107.0f));
	_velocidad = sf::Vector2f(0,0);
	_estado = ESTADOS::CAYENDO;
	_velocidadSalto = 0;
	_cuerpo.setOrigin(_cuerpo.getGlobalBounds().width/2,_cuerpo.getGlobalBounds().height/2); 
	_saltando = true;
	_cajaAtaque.setSize(sf::Vector2f(150.0f, 107.0f));
	_cajaAtaque.setOrigin(_cajaAtaque.getGlobalBounds().width/2, _cajaAtaque.getGlobalBounds().height/2);
	_cajaAtaque.setFillColor(sf::Color::Blue);
	_colisionandoDer = false;
	_colisionandoIzq = false;
	_atacando = false;
	_danio = 35;
	_salud = 100;
	_saltoInvertido = false;
	animacion = new Animacion(&_textura, sf::Vector2u(16,2), 0.05f, 108,73);
	animacionAtaque = new Animacion(&_texturaAtaque, sf::Vector2u(8,1), 0.065f, 108,91);
	_sonido = new Sonidos("Sonido/Salto.ogg","Sonido/Salto.ogg","Sonido/Salto.ogg");
	_ultimoAtaque = 0;
	_pausa = false;
}
Personaje::~Personaje()
{
	
}
sf::RectangleShape Personaje::getCuerpo()
{
	return _cuerpo;
}
void Personaje::modoPausa()
{
	_pausa = true;
	_cuerpo.setFillColor(sf::Color::Transparent);
}
void Personaje::saltoInvertido()
{
	_saltoInvertido = true;
}
void Personaje::recibiendoDanio(int danio)
{
	_estado = ESTADOS::RDANIO;
	_salud -= danio;
}
void Personaje::reiniciar(sf::Vector2f posicion)
{
	_cuerpo.setPosition(posicion);
	_salud = 100;
	_estado = ESTADOS::CAYENDO;
	_cuerpo.setFillColor(sf::Color::White);
}
float Personaje::getSalud()
{
	return _salud;
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
void Personaje::comandos(int c)
{
	if(_salud <= 0)
	{
		_estado = ESTADOS::MUERTO;
	}
	setControles(c);
	if(_estado == ESTADOS::QUIETO && !_colisionandoIzq && !_pausa ||
	   _estado == ESTADOS::CAYENDO && !_colisionandoIzq && !_pausa ||
	   _estado == ESTADOS::CAMINANDO_ATRAS && !_colisionandoIzq && !_pausa)
	{
		if(sf::Keyboard::isKeyPressed(controlIzq))
		{
			_estado = ESTADOS::CAMINANDO_ATRAS;
			_velocidad.x = -4;
		};
	}
	if(_estado == ESTADOS::QUIETO && !_colisionandoDer && !_pausa || 
	   _estado == ESTADOS::CAYENDO && !_colisionandoDer && !_pausa ||
	   _estado == ESTADOS::CAMINANDO_ATRAS && !_colisionandoDer && !_pausa)
	{	
		if(sf::Keyboard::isKeyPressed(controlDer))
		{
			_estado = ESTADOS::CAMINANDO_ADELANTE;
			_velocidad.x = 4;
		};
	}
	if(_estado == ESTADOS::QUIETO)
	{
		if(sf::Keyboard::isKeyPressed(controlAtq) && !_pausa)
		{
			if (clock.getElapsedTime().asSeconds() - _ultimoAtaque >= 0.0f) {
				_estado = ESTADOS::ATACANDO;
				_ultimoAtaque = clock.getElapsedTime().asSeconds();
			}
			
		}
	}
	
	if(!_saltando&& !_pausa)
	{
		if(sf::Keyboard::isKeyPressed(controlSaltar))
		{
	
			_estado = ESTADOS::SALTANDO;
			_velocidadSalto = 10;
		}
	}
	if(_saltoInvertido&& !_pausa)
	{
		if(sf::Keyboard::isKeyPressed(controlSaltarInvertido))
		{
			_velocidadSalto = -16;
			_estado = ESTADOS::SALTANDO;
		}
	}
	_saltando = true;	
	_colisionandoDer = false;
	_colisionandoIzq = false;
	_atacando = false;
	_saltoInvertido = false;
}
void Personaje::actualizar(float deltaTime)
{
	_barraVida.actualizar(_salud, sf::Vector2f(_cuerpo.getPosition().x, _cuerpo.getPosition().y-80));
	switch(_estado)
	{
		case QUIETO:
			_velocidadSalto=0;
			_cuerpo.setTexture(&_textura);
			animacion->Update(2, deltaTime);
			_cuerpo.setTextureRect(animacion->uvRect);
			break;
		case CAMINANDO_ADELANTE:
			_cuerpo.setScale(1,1);
			_cuerpo.move(_velocidad.x, -_velocidadSalto);
			_estado= ESTADOS::CAYENDO;
			_cuerpo.setTexture(&_textura);
			animacion->Update(0, deltaTime);
			_cuerpo.setTextureRect(animacion->uvRect);
			break;
		case CAMINANDO_ATRAS:
			_cuerpo.setScale(-1,1);
			_cuerpo.move(_velocidad.x, -_velocidadSalto);
			_estado= ESTADOS::CAYENDO;
			_cuerpo.setTexture(&_textura);
			animacion->Update(0, deltaTime);
			_cuerpo.setTextureRect(animacion->uvRect);
			break;
		case SALTANDO:
			_sonido->reproducirSonidos(0);
			_cuerpo.move(0, -_velocidadSalto);
			_estado= ESTADOS::CAYENDO;
			break;
		case CAYENDO:
			_cuerpo.move(0, -_velocidadSalto);
			break;
		case ATACANDO:
			_cuerpo.setTexture(&_texturaAtaque);
			animacionAtaque->Update(0, deltaTime, true);
			_cuerpo.setTextureRect(animacionAtaque->uvRect);
			_atacando = true;
			break;
		case RDANIO:
			_cuerpo.move(-35,-_velocidadSalto);
			_estado = ESTADOS::CAYENDO;
			break;
		case MUERTO:
			_cuerpo.move(0,0);
			_cuerpo.setFillColor(sf::Color::Red);
			break;
			
		}
	_velocidadSalto-=0.5;
	_velocidad=sf::Vector2f(0,0);
	_cajaAtaque.setPosition(_cuerpo.getPosition());
	_pausa = false;
	_cuerpo.setFillColor(sf::Color::White);
	
}
void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(_cuerpo, states);
}


bool Personaje::getAtacando()
{
	return _atacando;
}
float Personaje::getDanio()
{
	return _danio;
}

void Personaje::setControles(int c)
{
	if (c == 1) {
		controlIzq = sf::Keyboard::A;
		controlDer = sf::Keyboard::D;
		controlSaltar = sf::Keyboard::Numpad1;
		controlSaltarInvertido = sf::Keyboard::S;
		controlAtq = sf::Keyboard::Numpad2;
	}else if (c == 2) {
		controlIzq = sf::Keyboard::A;
		controlDer = sf::Keyboard::D;
		controlSaltar = sf::Keyboard::W;
		controlSaltarInvertido = sf::Keyboard::S;
		controlAtq = sf::Keyboard::F;
	}else {
		controlIzq = sf::Keyboard::Left;
		controlDer = sf::Keyboard::Right;
		controlSaltar = sf::Keyboard::Up;
		controlSaltarInvertido = sf::Keyboard::Down;
		controlAtq = sf::Keyboard::Z;
	}
}

sf::Keyboard::Key Personaje::getControlIzq(){
	return controlIzq;
}

sf::Keyboard::Key Personaje::getControlDer(){
	return controlDer;
}

sf::Keyboard::Key Personaje::getControlSaltar(){
	return controlSaltar;
}

sf::Keyboard::Key Personaje::getControlAtq(){
	return controlAtq;
}

sf::Keyboard::Key Personaje::getControlSaltarInvertido(){
	return controlSaltarInvertido;
}
