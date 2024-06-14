#pragma once
#include <SFML/Graphics.hpp>

class BarraVida : public sf::Drawable
{
	public:
		BarraVida();
		~BarraVida();
		void actualizar(float &salud, sf::Vector2f posicion);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		sf::RectangleShape _contorno;
		sf::RectangleShape _centroBlanco;
		sf::RectangleShape _vida;
};
