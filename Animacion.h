#pragma once
#include <SFML/Graphics.hpp>

class Animacion
{
	public:
		Animacion(sf::Texture* textura, sf::Vector2u imageCount, float switchTime, int alto, int ancho);
		void Update(int columna, float deltaTime);
/*		void Update(int columna, float deltaTime, bool atk);*/
		sf::IntRect uvRect;
		bool getFinAnimacion(){return finAnimacion;}
		
		
	private:
		sf::Vector2u imageCount;
		sf::Vector2u imagenActual;
		
		float totalTime;
		float switchTime;
		bool finAnimacion = true;
};

