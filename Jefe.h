#pragma once
#include "Enemigo.h"

class Jefe : public Enemigo
{
	public:
		Jefe(std::string textura);
		~Jefe();
		void actualizar(float deltaTime) override;
		void comando(float puntoA, float puntoB, Personaje personaje) override;
	private:
};
