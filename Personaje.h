#pragma once
#include <SFML/Graphics.hpp>
#include "Animacion.h"

class Personaje : public sf::Drawable
{
	public:
		Personaje();
		~Personaje();
		void comandos();
		void actualizar(float deltaTime);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		sf::Vector2f getPosicion();
		sf::RectangleShape getCuerpo();
		sf::RectangleShape getCajaAtaque();
		sf::FloatRect getCajaCuerpo();
		float getVelocidadSalto();
		void setPosicion(float a, float b);
		void quieto(float x, float y);
		void cayendo();
		void setDerecha();
		void setIzquierda();
		bool getAtacando();
		float getDanio();
		float getSalud();

	private:
		enum ESTADOS{
			QUIETO,
			CAMINANDO_ADELANTE,
			SALTANDO_ADELANTE,
			CAMINANDO_ATRAS,
			SALTANDO_ATRAS,
			SALTANDO,
			ATACANDO,
			CAYENDO
		};
		ESTADOS _estado;
		sf::Texture _textura;
		sf::RectangleShape _cuerpo;
		sf::RectangleShape _cajaAtaque;
		sf::Vector2f _velocidad;
		float _salud;
		float _danio;
		float _velocidadSalto;
		bool _saltando;
		bool _colisionandoIzq;
		bool _colisionandoDer;		
		bool _atacando;
		float _tiempo;
		Animacion animacion;
};

