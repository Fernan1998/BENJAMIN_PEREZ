#pragma once
#include <SFML/Graphics.hpp>


class Proyectil : public sf::Drawable
{
	public:
		Proyectil();
		void actualizar(int other);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void setPosition(sf::Vector2f aux)
		{
			_cuerpo.setPosition(aux);
		}
		sf::FloatRect getCuerpo()
		{
			return _cuerpo.getGlobalBounds();
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
		sf::Texture textura;
		sf::RectangleShape _cuerpo;
};
