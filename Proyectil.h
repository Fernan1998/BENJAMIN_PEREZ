#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>


class Proyectil : public sf::Drawable
{
	public:
		Proyectil (std::string textura);
		void actualizar(int other);
		void actualizar(sf::Vector2f posicion);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void setPosition(sf::Vector2f aux)
		{
			_cuerpo.setPosition(aux);
		}
		sf::FloatRect getCuerpo()
		{
			return _cuerpo.getGlobalBounds();
		}
		sf::RectangleShape getSprite()
		{
			return _cuerpo;
		}
		void setColor(sf::Color aux)
		{
			_cuerpo.setFillColor(aux);
		}
		sf::Vector2f getPosition()
		{
			return _cuerpo.getPosition();
		}
		
	private:
		sf::Texture _textura;
		sf::RectangleShape _cuerpo;
		sf::Vector2f _direction;
		sf::Clock clock;
};

