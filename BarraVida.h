#pragma once
#include <SFML/Graphics.hpp>

class BarraVida : public sf::Drawable
{
	public:
		BarraVida(sf::Color aux);
		~BarraVida();
		void actualizar(float &salud, sf::Vector2f posicion);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void modoPausa(bool aux);
	private:
		sf::RectangleShape _contorno;
		sf::RectangleShape _centroBlanco;
		sf::RectangleShape _vida;
		sf::Color _colorVida;
};
