#pragma once
#include <iostream>
#include <SFML/Audio.hpp>


class Sonidos
{
	public:
		Sonidos(std::string ruta_sonido);
		Sonidos(std::string ruta_sonido_caminar, std::string ruta_sonido_saltar, std::string ruta_sonido_atacar);
		Sonidos(std::string sonido1, std::string sonido2, std::string sonido3, std::string sonido4, std::string sonido5, std::string sonido6);
		void PlayMusic();
		void PauseMusic();
		void reproducirSonidos(int numero_sonido);
		void reproducirSonidosGenerales(int numero_sonido);
		void reproducirSonidosBucle(int numero_sonido);
		void cambiarMusica(std::string cancion)
		{
			music.openFromFile(cancion);
		}

		
	private:
		sf::Music music;
		sf::Sound sonidosPersonaje[3];
		sf::Sound sonidosGenerales[6];
		sf::SoundBuffer sonidosBuffer[3];
		sf::SoundBuffer sonidosBufferGenerales[6];
};

