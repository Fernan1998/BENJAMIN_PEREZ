#pragma once
#include <iostream>
#include <SFML/Audio.hpp>


class Sonidos
{
	public:
		Sonidos(std::string ruta_sonido);
		Sonidos(std::string ruta_sonido_caminar, std::string ruta_sonido_saltar, std::string ruta_sonido_atacar);
		void PlayMusic();
		void PauseMusic();
		void reproducirSonidos(int numero_sonido);
		void reproducirSonidosBucle(int numero_sonido);

		
	private:
		sf::Music music;
		sf::Sound sonidosPersonaje[3];
		sf::SoundBuffer sonidosBuffer[3];
};

