#pragma once
#include "Animacion.h"
#include "Personaje.h"
#include "BarraVida.h"
#include <SFML/Graphics.hpp>

class Enemigo : public sf::Drawable
{
	public:
		enum ESTADOS
		{
			CAYENDO,
			RDANIO,
			PATRULLANDO,
			SIGUIENDO,
			INVOCANDO,
			ATACANDO,
			MUERTO
		};
		
		Enemigo(float salud, float danio, std::string textura, float alto, float ancho, float altoRangoVision, float anchoRangoVision, int filaAnimacion, int columnaAnimacion);
		~Enemigo();
		virtual void actualizar(float deltaTime);
		virtual void comando(Personaje personaje);
		virtual bool soyEnemigo();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		
		float getSalud();
		int getDanio();
		sf::RectangleShape getCuerpo();
		sf::FloatRect getHitBox();
		sf::Vector2f getPosition(){return _cuerpo.getPosition();};
		BarraVida getBarraVida();
		bool getDiablo()
		{
			return _diablo;
		}
		
		bool getMuerto();
		virtual sf::FloatRect devolver();
		float getArmadura();
		void setArmadura(float armadura);
		void recibiendoDanio(int lado);
		void quieto();
		void setDerecha();
		void setIzquierda();
		void setAtacando();
		void reiniciar(sf::Vector2f position, float salud);

		
		void setColor(sf::Color color);
		void setSalud(float danio);
		void setDanio();
		void setPosition(sf::Vector2f aux);
		void setVelocidadCaminata(float aux);
		void setEstado(ESTADOS estado);
		void setSize(sf::Vector2f aux);
		void setDiablo()
		{
			_diablo = true;
		}
		
		ESTADOS getEstado()
		{
			return _estado;
		}
		
	protected:
		ESTADOS _estado;
		sf::RectangleShape _cuerpo;
		sf::RectangleShape _rangoVision;
		sf::Vector2f _velocidad;
		float _salud;
		float _ultimoAtaque;
		float _velocidadCaminata;
		float _danio;
		float _armadura = 2;
		bool _vivo;
		bool _diablo = false;
		bool _colisionandoDer;
		bool _colisionandoIzq;
		bool _siguiendoPersonaje;
		bool _atacando;
		int _recibiendoDanio;
		
		Animacion *_animacion;
		Animacion *_animacionDanio;
		BarraVida *_barraVida;
		sf::Texture _textura;
		
	private:
		
		sf::Clock clock;

		
		
	
		
};

