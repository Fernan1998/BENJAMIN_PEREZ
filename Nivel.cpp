#include "Nivel.h"

Nivel::Nivel(std::string mapa, std::string fondo, std::string plataformas, std::string ruta_musica, int cantidadEnemigos)
{
	std::ifstream file_mapa;
	file_mapa.open(mapa);
	_mapa.CreadorMapa(file_mapa);
	
	std::ifstream file_fondo;
	file_fondo.open(fondo);
	_fondo.CreadorMapa(file_fondo);
	
	std::ifstream file_plataformas;
	file_plataformas.open(plataformas);
	_plataformas.CreadorMapa(file_plataformas);

	_enemigo = new Enemigo(1000, 25, "Textura/Diablo/Diablo.png",246,327,84,800,1,4);
	
	
	_cantidadEnemigos = cantidadEnemigos;
	
	for(int i = 0; i<cantidadEnemigos; i++)
	{
		_vectorEnemigo.push_back(_enemigo);
	}
	
	_sonido = new Sonidos(ruta_musica);
	_sonido->PlayMusic();

}

Nivel::~Nivel()
{
}
void Nivel::reiniciarNivel()
{
	_vectorEnemigo[0]->reiniciar(sf::Vector2f(1200,550), 100);
}
void Nivel::actualizar(float deltaTime)
{
	_vectorEnemigo[0]->actualizar(deltaTime);
}
void Nivel::comando(Personaje &personaje)
{
	_vectorEnemigo[0]->comando(1008.0f ,1920.0f, personaje);
}
sf::FloatRect Nivel::getMapa(float a, float b)
{
	return _mapa.getSprite(a,b).getGlobalBounds();
}
sf::FloatRect Nivel::getFondo(float a, float b)
{
	return _fondo.getSprite(a,b).getGlobalBounds();
}
sf::FloatRect Nivel::getPlataforma(float a, float b)
{
	return _plataformas.getSprite(a,b).getGlobalBounds();
}
void Nivel::dibujar(sf::RenderWindow& window)
{
	for(int i=0; i<31; i++)
	{
		for(int j=0; j<60; j++)
		{	
			
			window.draw(_fondo.getSprite(i,j));
			window.draw(_mapa.getSprite(i,j));
			window.draw(_plataformas.getSprite(i,j));
			
		}
	}	

	window.draw(_vectorEnemigo[0]->getBarraVida());
}
