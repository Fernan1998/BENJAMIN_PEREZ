#include "Jefe.h"

Jefe::Jefe(float salud, float danio, std::string textura, float alto, float ancho, float altoRangoVision, float anchoRangoVision, int filaAnimacion, int columnaAnimacion) : Enemigo(salud, danio, textura,  alto,  ancho, altoRangoVision, anchoRangoVision, filaAnimacion, columnaAnimacion)
{
	
}

Jefe::~Jefe()
{
	
}

bool Jefe::soyEnemigo()
{
	return false;
}
