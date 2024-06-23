#pragma once
#include <SFML/Graphics.hpp>
#include "Personaje.h"

class Guardado
{
	public:
		sf::Vector2f getPosicion()
		{
			return posicion;
		}
		float getVida()
		{
			return vida;
		}
		int getNMapa()
		{
			return nMapa;
		}
		bool* getObjetos()
		{
			return objetos;
		}
		void setPosicion(sf::Vector2f posicion)
		{
			this->posicion = posicion;
		}
		void setVida(float vida)
		{
			this->vida = vida;
		}
		void setNMapa(int nMapa)
		{
			this->nMapa = nMapa;
		}
		void setObjetos(bool *objetos)
		{
			for(bool objeto : this->objetos)
			{
				this->objetos[objeto] = objetos[objeto];
			}
		}
		
		
	private:
		sf::Vector2f posicion;
		float vida;
		int nMapa;
		bool objetos[3];
};

static Guardado objetoAuxiliar;

static float _tiempo = 0;

void pedirNum(float &deltaTime);

float darNum();

void getDatosPoronga(sf::Vector2f posicion, float vida, int nMapa);

void cerrarJuego();

void cargarJuego(Personaje *auxiliar, int &nMapaAux);
