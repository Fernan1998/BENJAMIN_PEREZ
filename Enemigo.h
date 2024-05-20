#pragma once
#include "Animacion.h"
#include <SFML/Graphics.hpp>

class Enemigo : public sf::Drawable
{
	public:
		Enemigo(sf::Vector2f ubicacion);
		~Enemigo();
		void setSalud();
		void setDanio();
		int getSalud();
		int getDanio();
		void actualizar(float deltaTime);
		void comando();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void colisiones();
		
		
	private:
		enum ESTADOS
		{
			QUIETO,
			CAMINANDO_ADELANTE,
			CAMINANDO_ATRAS,
			ATACANDO,
			MUERTO
		};
		ESTADOS _estado;
		sf::RectangleShape _cuerpo;
		sf::Texture _textura;
		sf::FloatRect _rangoVision;
		sf::FloatRect _rangoAtaque;
		int _salud;
		int _danio;
		sf::Vector2f _velocidad;
		bool _vivo;
		Animacion _animacion;
		
};

