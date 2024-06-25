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
	
	_cantidadEnemigos = cantidadEnemigos;
	
	for(int i = 0; i<_cantidadEnemigos; i++)
	{
		_vectorEnemigo.push_back(new Enemigo(1000, 25, "Textura/Diablo/diablo2a.png", 245, 327, 84, 800, 2, 8));
	}
	
	_sonido = new Sonidos(ruta_musica);
	_sonido->PlayMusic();

}

Nivel::~Nivel()
{
}
void Nivel::reiniciarNivel(sf::Vector2f pos1, sf::Vector2f pos2, sf::Vector2f pos3, sf::Vector2f pos4 )
{
	for(int i=0; i<_cantidadEnemigos; i++)
	{
		switch(i)
		{
			case 0:
				_vectorEnemigo[0]->reiniciar(pos1, 100);
				break;
			case 1:
				_vectorEnemigo[1]->reiniciar(pos2, 100);
				break;
			case 2:
				_vectorEnemigo[2]->reiniciar(pos3, 100);
				break;
			case 3:
				_vectorEnemigo[2]->reiniciar(pos4, 100);
				break;
		}
		
	}
	
}
void Nivel::actualizar(float deltaTime)
{
	for(int i=0; i<_cantidadEnemigos; i++)
	{
		_vectorEnemigo[i]->actualizar(deltaTime);
	}
	
}
void Nivel::comando(Personaje &personaje)
{
	for(int i=0; i<_cantidadEnemigos; i++)
	{
		_vectorEnemigo[i]->comando(1008.0f ,1920.0f, personaje);
	}

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
	for(int i=0; i<_cantidadEnemigos; i++)
	{
		window.draw(*_vectorEnemigo[i]);
		window.draw(_vectorEnemigo[i]->getBarraVida());
	}
	
}
