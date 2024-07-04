#pragma once
#include <SFML/Graphics.hpp>
#include "Animacion.h"
#include "Sonidos.h"
#include "BarraVida.h"

class Personaje : public sf::Drawable
{
	public:
		Personaje();
		~Personaje();
		void comandos(int c);
		void actualizar(float deltaTime);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void quieto(float x, float y);
		void estadoQuieto();
		void cayendo();
		void saltoInvertido();
		bool getObjetos(int numeroObjeto);
		
		/// Setters
		void setDerecha();
		void setIzquierda();
		void setControles(int c);
		void setPosicion(float a, float b);
		void setObjetos(int numeroObjeto);
		void setBoleadora(bool other);
		void setSalud(float vida);

		
		/// Getters
		sf::Keyboard::Key getControlIzq();
		sf::Keyboard::Key getControlDer();
		sf::Keyboard::Key getControlAtq();
		sf::Keyboard::Key getControlSaltar();
		sf::Keyboard::Key getControlSaltarInvertido();
		bool getAtacando();
		float getDanio();
		float getSalud();
		float getVelocidadSalto();
		sf::Vector2f getPosicion();
		sf::RectangleShape getCuerpo();
		sf::RectangleShape getCajaAtaque();
		sf::FloatRect getCajaCuerpo();
		void recibiendoDanio(int danio, int empuje);
		void reiniciar(sf::Vector2f posicion);
		void modoPausa();
		float getScale();
		BarraVida getBarraVida();
		bool getBoleadora();
		void limpiarObjetos();
		bool* getObjeto();
		void setOBjeto(bool *objetos);


	private:
		enum ESTADOS{
			QUIETO,
			CAMINANDO_ADELANTE,
			CAMINANDO_ATRAS,
			SALTANDO,
			CAYENDO,
			ATACANDO,
			BOLEADORA,
			RDANIO,
			MUERTO
		};
		ESTADOS _estado;
		sf::Texture _textura;
		sf::Texture _texturaAtaque;
		sf::RectangleShape _cuerpo;
		sf::RectangleShape _cajaAtaque;
		sf::Vector2f _velocidad;
		int _empuje;
		float _salud;
		float _danio;
		float _velocidadSalto;
		bool _saltando;
		bool _saltoInvertido;
		bool _colisionandoIzq;
		bool _colisionandoDer;		
		bool _atacando;
		bool _pausa;
		bool _boleadora;
		bool _objetos[5] = {false};
		float _ultimoAtaque;
		float _ultimoAtaqueBoleadora;
		sf::Clock clock;
		Animacion *animacion;
		Animacion *animacionAtaque;
		bool terminoAnimacion = true;
		Sonidos *_sonido;
		BarraVida *_barraVida;
		
		// Controles
		sf::Keyboard::Key controlIzq = sf::Keyboard::A;
		sf::Keyboard::Key controlDer = sf::Keyboard::D;
		sf::Keyboard::Key controlSaltar = sf::Keyboard::Numpad1;
		sf::Keyboard::Key controlSaltarInvertido = sf::Keyboard::S;
		sf::Keyboard::Key controlAtq = sf::Keyboard::Numpad2;
		sf::Keyboard::Key controlBoleadora = sf::Keyboard::Numpad3;
};

