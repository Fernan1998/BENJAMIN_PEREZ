#pragma once
#include <SFML/Graphics.hpp>

class Animacion
{
	public:
		Animacion(sf::Texture* textura, sf::Vector2u imageCount, float switchTime, int alto, int ancho);
		
		void Update(int columna, float deltaTime);
		
		sf::IntRect uvRect;
		
	private:
		sf::Vector2u imageCount;
		sf::Vector2u imagenActual;
		
		float totalTime;
		float switchTime;
};

