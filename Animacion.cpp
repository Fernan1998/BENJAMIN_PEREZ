#include "Animacion.h"

Animacion::Animacion(sf::Texture* textura, sf::Vector2u imageCount, float switchTime, int alto, int ancho) 
{
	this->imageCount=imageCount;
	this->switchTime=switchTime;
	totalTime=0.0f;
	imagenActual.x = 0;
	
	uvRect.width = ancho;
	uvRect.height = alto;
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
			finAnimacion=true;
		}else {finAnimacion=false;}
	}
	
	uvRect.left = imagenActual.x * uvRect.width;
	uvRect.top = imagenActual.y * uvRect.height;
}
void Animacion::Update(int columna, float deltaTime, bool atk)
{
	imagenActual.y = columna;
	totalTime += deltaTime;
	
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		imagenActual.x++;
		if (imagenActual.x >= imageCount.x)
		{
			finAnimacion = true;
			imagenActual.x = imageCount.x - 1;
		}
	}
	
	uvRect.left = imagenActual.x * uvRect.width;
	uvRect.top = imagenActual.y * uvRect.height;
}

bool Animacion::getFinAnimacion()
{
	return finAnimacion;
}
int Animacion::getColumna()
{
	return imagenActual.y;
}
int Animacion::getFila()
{
	return imagenActual.x;
}
int Animacion::getCantidadFila()
{
	return imageCount.x;
}
int Animacion::getCantidadColumna()
{
	return imageCount.y;
}
void Animacion::reiniciarFila()
{
	imagenActual.x = 0;
}
