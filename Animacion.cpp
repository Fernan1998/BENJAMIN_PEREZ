#include "Animacion.h"

Animacion::Animacion(sf::Texture* textura, sf::Vector2u imageCount, float switchTime) 
{
	this->imageCount=imageCount;
	this->switchTime=switchTime;
	totalTime=0.0f;
	imagenActual.x = 0;
	
	uvRect.width = 120;
	uvRect.height = 120;
}

void Animacion::Update(int columna, float deltaTime)
{
	imagenActual.y = columna;
	totalTime += deltaTime;
	
	if(totalTime>=switchTime)
	{
		totalTime -= switchTime;
		imagenActual.x++;
		if(imagenActual.x >= imageCount.x)
		{
			imagenActual.x = 0;
		}
	}
	
	uvRect.left = imagenActual.x * uvRect.width;
	uvRect.top = imagenActual.y * uvRect.height;
	
}
