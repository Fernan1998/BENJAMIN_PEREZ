#pragma once
#include "Animacion.h"
#include "Personaje.h"
#include "BarraVida.h"
#include <SFML/Graphics.hpp>

class Enemigo : public sf::Drawable
{
	public:
		Enemigo(float salud, float danio, std::string textura, float alto, float ancho, float altoRangoVision, float anchoRangoVision, int filaAnimacion, int columnaAnimacion);
		~Enemigo();
		virtual void actualizar(float deltaTime);
		virtual void comando(float puntoA, float puntoB, Personaje personaje);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		
		float getSalud();
		int getDanio();
		sf::RectangleShape getCuerpo();
		sf::FloatRect getHitBox();
		sf::Vector2f getPosition(){return _cuerpo.getPosition();};
		
		void setSalud(float danio);
		void setDanio();
		void setPosition(sf::Vector2f aux);
		void setVelocidadCaminata(float aux)
		{
			_velocidadCaminata = aux;
		}
	
		void colisiones();
		void recibiendoDanio(int lado);
		void quieto();
		void setDerecha();
		void setIzquierda();
		void setAtacando();
		void reiniciar(sf::Vector2f position, float salud);
		
		
		BarraVida getBarraVida()
		{
			return *_barraVida;
		}
		

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
		sf::Clock clock;
		sf::Vector2f _velocidad;
		
		int _recibiendoDanio;
		int _danio;
		
		float _salud;
		float _ultimoAtaque;
		float _velocidadCaminata;
		
		bool _vivo;
		bool _colisionandoDer;
		bool _colisionandoIzq;
		bool _siguiendoPersonaje;
		bool _atacando;
		
		Animacion *_animacion;
		BarraVida *_barraVida;

		
};

