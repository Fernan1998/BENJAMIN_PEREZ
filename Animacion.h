#pragma once
#include <SFML/Graphics.hpp>

class Animacion
{
	public:
		Animacion(sf::Texture* textura, sf::Vector2u imageCount, float switchTime, int alto, int ancho);
		void Update(int columna, float deltaTime);
		sf::IntRect uvRect;
		bool getFinAnimacion()
		{
			return finAnimacion;
		}
		int getColumna()
		{
			return imagenActual.y;
		}
		int getFila()
		{
			return imagenActual.x;
		}
		int getCantidadFila()
		{
			return imageCount.x;
		}
		int getCantidadColumna()
		{
			return imageCount.y;
		}
		void reiniciarFila()
		{
			imagenActual.x = 0;
		}
	
	private:
		sf::Vector2u imageCount;
		sf::Vector2u imagenActual;
		
		float totalTime;
		float switchTime;
		bool finAnimacion = true;
};

