#pragma once
#include "Animacion.h"
#include "Personaje.h"
#include <SFML/Graphics.hpp>

class Enemigo : public sf::Drawable
{
	public:
		Enemigo(sf::Vector2f ubicacion);
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
		
		
	private:
		enum ESTADOS
		{
			QUIETO,
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

		
};

