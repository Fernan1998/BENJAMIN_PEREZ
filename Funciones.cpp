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
void getDatos(sf::Vector2f posicion, float vida, int nMapa, bool *objetos)
{
	objetoAuxiliar.setPosicion(posicion);
	objetoAuxiliar.setVida(vida);
	objetoAuxiliar.setNMapa(nMapa);
	objetoAuxiliar.setObjetos(objetos);
}
void cerrarJuego()
{
	FILE *file = fopen("data/Guardar.bpg", "wb");
	if(file)
	{
		fwrite(&objetoAuxiliar, sizeof(objetoAuxiliar), 1, file);
		fclose(file);
	}
}
void cargarJuego(Personaje *auxiliar, int &nMapaAux)
{
	FILE *file = fopen("data/Guardar.bpg", "rb");
	if(file)
	{
		fread(&objetoAuxiliar, sizeof(objetoAuxiliar), 1, file);
		fclose(file);
	}
	if(objetoAuxiliar.getNMapa() != 1 && objetoAuxiliar.getNMapa() != 2)
	{
		auxiliar->setPosicion(objetoAuxiliar.getPosicion().x, objetoAuxiliar.getPosicion().y);
	}
	else
	{
		auxiliar->setPosicion(100,750);
	}
	auxiliar->setSalud(objetoAuxiliar.getVida());
	auxiliar->setOBjeto(objetoAuxiliar.getObjetos());
	if(objetoAuxiliar.getNMapa() != 11)
	{
		nMapaAux = objetoAuxiliar.getNMapa();
	}
	else
	{
		nMapaAux = 1;
	}
}

