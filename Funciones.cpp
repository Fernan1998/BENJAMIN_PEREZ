#include "Funciones.h"
#include <iostream>

void pedirNum(float &deltaTime)
{
	_tiempo += deltaTime;
}
float darNum()
{
	return _tiempo;
}

void getDatosPoronga(sf::Vector2f posicion, float vida, int nMapa)
{
	objetoAuxiliar.setPosicion(posicion);
	objetoAuxiliar.setVida(vida);
	objetoAuxiliar.setNMapa(nMapa);
}

void cerrarJuego()
{
	FILE *file = fopen("Guardar.bpg", "wb");
	if(file)
	{
		fwrite(&objetoAuxiliar, sizeof(objetoAuxiliar), 1, file);
		fclose(file);
	}
}
void cargarJuego(Personaje *auxiliar, int &nMapaAux)
{
	FILE *file = fopen("Guardar.bpg", "rb");
	if(file)
	{
		fread(&objetoAuxiliar, sizeof(objetoAuxiliar), 1, file);
		fclose(file);
	}
	auxiliar->setPosicion(objetoAuxiliar.getPosicion().x, objetoAuxiliar.getPosicion().y);
	auxiliar->setSalud(objetoAuxiliar.getVida());
	nMapaAux = objetoAuxiliar.getNMapa();
	
}

