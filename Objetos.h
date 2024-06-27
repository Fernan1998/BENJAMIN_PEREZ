#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Objetos : public sf::Drawable
{
	public:
		Objetos(float alto, float ancho, std::string textura);
		Objetos();
		~Objetos();
		void setPosition(sf::Vector2f posicion)
		{
			_cuerpo.setPosition(posicion);
		}
		void setPause()
		{
			_cuerpo.setFillColor(sf::Color::Transparent);
		}
		sf::FloatRect getCuerpo()
		{
			return _cuerpo.getGlobalBounds();
		}
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		sf::RectangleShape _cuerpo;
		sf::Texture _textura;
};

