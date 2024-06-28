#pragma once
#include "Enemigo.h"

class Jefe : public Enemigo
{
	public:
		Jefe(float salud, float danio, std::string textura, float alto, float ancho, float altoRangoVision, float anchoRangoVision, int filaAnimacion, int columnaAnimacion);
		~Jefe();

		bool soyEnemigo() override;
	private:

};
