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
		void recibiendoDanio(int lado);
		void setPosition(sf::Vector2f aux);
		sf::FloatRect getHitBox();
		sf::Vector2f getPosition(){return _cuerpo.getPosition();};
		void quieto();
		void setDerecha();
		void setIzquierda();
		void setAtacando();
		void reiniciar(sf::Vector2f position);

	private:
		enum ESTADOS
		{
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
		int _salud;
		int _danio;
		sf::Vector2f _velocidad;
		bool _vivo;
		Animacion _animacion;
		float _gravedad;
		sf::Vector2f _posicionInicial;
		bool _colisionandoDer;
		bool _colisionandoIzq;
		bool _siguiendoPersonaje;
		bool _atacando;
		int _recibiendoDanio;
		float _ultimoAtaque;
		sf::Clock clock;

		
};

