#include "Sonidos.h"

Sonidos::Sonidos(std::string ruta_sonido)
{
	music.openFromFile(ruta_sonido);
	music.setLoop(true);
	music.setVolume(10);

}
Sonidos::Sonidos(std::string ruta_sonido_caminar, std::string ruta_sonido_saltar, std::string ruta_sonido_atacar) {
	
	if(!sonidosBuffer[0].loadFromFile("Sonido/Salto.ogg")){
		std::cout << "ERROR SONIDO SALTO" << std::endl;
	}
	if(!sonidosBuffer[1].loadFromFile("Sonido/Caminata.ogg")){
		std::cout << "ERROR SONIDO SALTO" << std::endl;
	}
	if(!sonidosBuffer[2].loadFromFile("Sonido/Caminata.ogg")){
		std::cout << "ERROR SONIDO SALTO" << std::endl;
	}

	sonidosPersonaje[0].setBuffer(sonidosBuffer[0]);
	sonidosPersonaje[1].setBuffer(sonidosBuffer[1]);
	sonidosPersonaje[2].setBuffer(sonidosBuffer[2]);
}

void Sonidos::PlayMusic()
{
	music.play();
}
void Sonidos::PauseMusic()
{
	music.pause();
}
/*void Sonidos::PlayWalkS();*/
void Sonidos::reproducirSonidos(int numero_sonido)
{	
	sonidosPersonaje[numero_sonido].play();
}
void Sonidos::reproducirSonidosBucle(int numero_sonido)
{	
	sonidosPersonaje[numero_sonido].setLoop(true);
	sonidosPersonaje[numero_sonido].play();
	
}

