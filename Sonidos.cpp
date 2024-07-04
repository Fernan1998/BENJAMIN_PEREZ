#include "Sonidos.h"

Sonidos::Sonidos(std::string ruta_sonido)
{
	music.openFromFile(ruta_sonido);
	music.setLoop(true);
	music.setVolume(10);
}
Sonidos::Sonidos(std::string ruta_sonido_caminar, std::string ruta_sonido_saltar, std::string ruta_sonido_atacar)
{
	
	if(!sonidosBuffer[0].loadFromFile(ruta_sonido_caminar)){
		std::cout << "ERROR SONIDO SALTO" << std::endl;
	}
	if(!sonidosBuffer[1].loadFromFile(ruta_sonido_saltar)){
		std::cout << "ERROR SONIDO SALTO" << std::endl;
	}
	if(!sonidosBuffer[2].loadFromFile(ruta_sonido_atacar)){
		std::cout << "ERROR SONIDO SALTO" << std::endl;
	}

	sonidosPersonaje[0].setBuffer(sonidosBuffer[0]);
	sonidosPersonaje[1].setBuffer(sonidosBuffer[1]);
	sonidosPersonaje[2].setBuffer(sonidosBuffer[2]);
}
Sonidos::Sonidos(std::string sonido1, std::string sonido2, std::string sonido3, std::string sonido4, std::string sonido5, std::string sonido6)
{
	
	if(!sonidosBufferGenerales[0].loadFromFile(sonido1)){
		std::cout << "ERROR SONIDO" << std::endl;
	}
	if(!sonidosBufferGenerales[1].loadFromFile(sonido2)){
		std::cout << "ERROR SONIDO" << std::endl;
	}
	if(!sonidosBufferGenerales[2].loadFromFile(sonido3)){
		std::cout << "ERROR SONIDO" << std::endl;
	}
	if(!sonidosBufferGenerales[3].loadFromFile(sonido4)){
		std::cout << "ERROR SONIDO" << std::endl;
	}
	if(!sonidosBufferGenerales[4].loadFromFile(sonido5)){
		std::cout << "ERROR SONIDO " << std::endl;
	}
	if(!sonidosBufferGenerales[5].loadFromFile(sonido6)){
		std::cout << "ERROR SONIDO " << std::endl;
	}
	
	sonidosGenerales[0].setBuffer(sonidosBufferGenerales[0]);
	sonidosGenerales[1].setBuffer(sonidosBufferGenerales[1]);
	sonidosGenerales[2].setBuffer(sonidosBufferGenerales[2]);
	sonidosGenerales[3].setBuffer(sonidosBufferGenerales[3]);
	sonidosGenerales[4].setBuffer(sonidosBufferGenerales[4]);
	sonidosGenerales[5].setBuffer(sonidosBufferGenerales[5]);
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
void Sonidos::reproducirSonidosGenerales(int numero_sonido)
{	
	sonidosGenerales[numero_sonido].play();
}
void Sonidos::reproducirSonidosBucle(int numero_sonido)
{	
	sonidosPersonaje[numero_sonido].setLoop(true);
	sonidosPersonaje[numero_sonido].play();
}

