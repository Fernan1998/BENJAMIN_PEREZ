#pragma once
#include <SFML/Graphics.hpp>
#include "Personaje.h"

class Guardado
{
	public:
		Guardado()
		{
			posicion = sf::Vector2f(100, 750);
			vida = 100;
			nMapa = 1;
		}
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
			for(int i=0; i<5; i++)
			{
				this->objetos[i] = objetos[i];
			}
		}
	private:
		sf::Vector2f posicion;
		float vida;
		int nMapa;
		bool objetos[5];
};

static Guardado objetoAuxiliar;

static float _tiempo = 0;

void pedirNum(float &deltaTime);

float darNum();

void getDatos(sf::Vector2f posicion, float vida, int nMapa, bool *objetos);

void cerrarJuego();

void cargarJuego(Personaje *auxiliar, int &nMapaAux);
