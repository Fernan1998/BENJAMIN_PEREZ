#pragma once
#include "Animacion.h"
#include <SFML/Graphics.hpp>

class Enemigo : public sf::Drawable
{
	public:
		Enemigo();
		~Enemigo();
		void setSalud();
		void setDanio();
		int getSalud();
		int getDanio();
		void actualizar();
		void comando();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		
		
	private:
		enum ESTADOS
		{
			QUIETO,
			CAMINANDO_ADELANTE,
			CAMINANDO_ATRAS,
			ATACANDO,
			MUERTO
		};
		sf::RectangleShape _cuerpo;
		sf::Texture _textura;
		sf::FloatRect _rangoVision;
		sf::FloatRect _rangoAtaque;
		int _salud;
		int _danio;
		sf::Vector2f _velocidad;
		bool _estado;
		Animacion _animacion;
		
};

