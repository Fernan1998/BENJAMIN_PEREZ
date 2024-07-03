#pragma once
#include "Proyectil.h"
#include "Enemigo.h"

class Jefe : public Enemigo
{
	public:
		Jefe(float salud, float danio, std::string textura, float alto, float ancho, float altoRangoVision, float anchoRangoVision, int filaAnimacion, int columnaAnimacion);
		~Jefe();
		void actualizar(float deltaTime) override;
		void comando(Personaje personaje) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		bool soyEnemigo() override;
		sf::FloatRect devolver() override;
		Proyectil *getPiedra();
	private:
		Proyectil *_piedra;
		int i=0;

};
