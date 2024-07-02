#pragma once
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include "CamaraPrincipal.h"
#include "Mapa.h"
#include "Enemigo.h"
#include "Cinematica.h"
#include "Nivel.h"
#include "Menu.h"
#include "Proyectil.h"
#include "Funciones.h"
#include <string>
#include "Objetos.h"

class Gameplay 
{
	public:
		Gameplay(CamaraPrincipal &camaraPrincipal);
		Gameplay();
		~Gameplay();
		void actualizar(float deltaTime);
		void comando(int c);
		int draw(sf::RenderWindow& window);
		void ChequeoColisiones();
		sf::Vector2f getPosicionPersonaje();
		void cambioEscena();
		void ponerPausa();
		void cargarPartida();
	private:
		CamaraPrincipal _camaraPrincipal;
		Personaje *_personaje;
		Nivel *nivel1;
		Nivel *nivel2;
		Nivel *nivel10;
		Nivel *nivel3;
		Nivel *nivel12;
		Nivel *nivel4;
		Nivel *nivel5;
		Nivel *nivel6;
		Nivel *nivel7;
		Nivel *nivel11;
		Nivel *nivel8;
		Nivel *nivel9;
		Nivel *nivelActual;
		Nivel *listaNiveles[12];
		Objetos *_objetoOjo;
		Objetos *_objetoLobizon;
		Objetos *_cabezaDiablo;
		Objetos *_cabezaPombero;
		Objetos *_objetoLuz;
		int escala;
		int numeroMapa;
		bool pausa = false;
		bool camaraBloqueada = false;
		bool _boleando;
		Menu menu = new Menu(true);
		Cinematica *cinematicaPersonaje;
		Cinematica *nocheADia;
		Cinematica *introJuego;
		Cinematica *cinematicaDesaparece;
		sf::RectangleShape _aux;
		sf::Texture texAux;
		
		sf::RectangleShape _tutorial;
		sf::Texture texTutorial;

		
		int i=0;
		float _ultimoAtaque;
		sf::Clock clock;
		Proyectil _boleadora;
};

