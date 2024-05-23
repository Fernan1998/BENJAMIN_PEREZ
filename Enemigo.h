#pragma once
#include "Animacion.h"
#include "Personaje.h"
#include <SFML/Graphics.hpp>

class Enemigo : public sf::Drawable
{
	public:
		Enemigo();
		~Enemigo();
		void setSalud(float danio);
		void setDanio();
		float getSalud();
		int getDanio();
		sf::RectangleShape getCuerpo();
		void actualizar(float deltaTime);
		void comando(float puntoA, float puntoB, Personaje personaje);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void colisiones();
		void recibiendoDanio();
		void setPosition(sf::Vector2f aux);
		sf::FloatRect getHitBox();
		sf::Vector2f getPosition(){return _cuerpo.getPosition();};
		void quieto(float x, float y)
		{	
			_velocidad.y = 0;
		}
		void setDerecha()
		{
			_colisionandoDer = true;
		}
		void setIzquierda()
		{
			_colisionandoIzq = true;
		}
		
		
	private:
		enum ESTADOS
		{
			QUIETO,
			CAYENDO,
			RDANIO,
			PATRULLANDO,
			SIGUIENDO,
			ATACANDO,
			MUERTO
		};
		ESTADOS _estado;
		sf::RectangleShape _cuerpo;
		sf::Texture _textura;
		sf::RectangleShape _rangoVision;
		sf::RectangleShape _rangoAtaque;
		int _salud;
		int _danio;
		sf::Vector2f _velocidad;
		bool _vivo;
		Animacion _animacion;
		float _gravedad;
		sf::Vector2f _posicionInicial;
		bool _colisionandoDer;
		bool _colisionandoIzq;

		
};

