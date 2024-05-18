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
		float getVelocidadSalto();
		void setPosicion(sf::Vector2f posicion);
		void quieto(float x, float y);
		void cayendo();
		void setDerecha();
		void setIzquierda();
		
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
		sf::Vector2f _velocidad;
		float _velocidadSalto;
		bool _saltando;
		bool _colisionandoIzq;
		bool _colisionandoDer;
		Animacion animacion;
};

