#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>


class Proyectil : public sf::Drawable
{
	public:
		Proyectil (std::string textura);
		void actualizar(int other);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void setPosition(sf::Vector2f aux);
		sf::FloatRect getCuerpo();
		sf::RectangleShape getSprite();
		void setColor(sf::Color aux);
		sf::Vector2f getPosition();

		
	private:
		sf::Texture _textura;
		sf::RectangleShape _cuerpo;
		sf::Vector2f _direction;
		sf::Clock clock;
};

