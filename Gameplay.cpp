#include "Gameplay.h"
#include "Personaje.h"
#include "CamaraPrincipal.h"
#include "Mapa.h"
#include "Enemigo.h"
#include <SFML/Graphics.hpp>
#include <fstream>

Gameplay::Gameplay(CamaraPrincipal &camaraPrincipal) : _enemigo1(sf::Vector2f(600,310))
{
	_camaraPrincipal = camaraPrincipal;
	std::ifstream file_map;
	file_map.open("Mapas_txt/mapa_cueva1.txt");
	_mapa.CreadorMapa(file_map);
	
	std::ifstream file_fondo;
	file_fondo.open("Mapas_txt/mapa_cueva1_fondo.txt");
	_fondo.CreadorMapa(file_fondo);
	
	std::ifstream file_obstacle;
	file_obstacle.open("Mapas_txt/mapa_cueva1_plataformas.txt");
	_plataformas.CreadorMapa(file_obstacle);
	
	std::ifstream file_dead;
	file_dead.open("Mapas_txt/mapa_cueva1_plataformas.txt");
	_muerte.CreadorMapa(file_dead);
	
	
}
Gameplay::~Gameplay()
{
	
}
void Gameplay::actualizar(float deltaTime)
{	
	_personaje.actualizar(deltaTime);
	_enemigo1.actualizar(deltaTime);
	_camaraPrincipal.FollowAndUpdate(_personaje.getPosicion(), &_camaraPrincipal);
	
}
void Gameplay::comando()
{
	_personaje.comandos();
}
void Gameplay::ChequeoColisiones()
{
	sf::FloatRect hitBoxPlayer(_personaje.getCuerpo().getGlobalBounds().left, _personaje.getCuerpo().getGlobalBounds().top + _personaje.getCuerpo().getGlobalBounds().height -16,_personaje.getCuerpo().getGlobalBounds().width , 16);
	auto playerGlobalBounds = _personaje.getCuerpo().getGlobalBounds();
	
	sf::FloatRect hitBoxMap;
	sf::FloatRect hitBoxMapIzq;
	sf::FloatRect hitBoxMapDer;
	sf::FloatRect hitBoxMapPlatform;
	sf::FloatRect hitBoxPlayerHead;
	sf::FloatRect hitBoxMapHead;
	
	for(int i=0; i<31; i++)
	{
		for(int j=0; j<60; j++)
		{	
			hitBoxMap = sf::FloatRect(_mapa.getSprite(i, j).getGlobalBounds().left, _mapa.getSprite(i, j).getGlobalBounds().top - 16, _mapa.getSprite(i, j).getGlobalBounds().width, 16);
			hitBoxMapIzq = sf::FloatRect(_mapa.getSprite(i, j).getGlobalBounds().left - 4, _mapa.getSprite(i, j).getGlobalBounds().top, _mapa.getSprite(i, j).getGlobalBounds().width + 4, _mapa.getSprite(i, j).getGlobalBounds().height);
			hitBoxMapDer = sf::FloatRect(_mapa.getSprite(i, j).getGlobalBounds().left + 32, _mapa.getSprite(i, j).getGlobalBounds().top, 4, _mapa.getSprite(i, j).getGlobalBounds().height);
			hitBoxPlayerHead = sf::FloatRect(playerGlobalBounds.left, playerGlobalBounds.top, playerGlobalBounds.width, 16);
			hitBoxMapHead = sf::FloatRect(_mapa.getSprite(i, j).getGlobalBounds().left, _mapa.getSprite(i, j).getGlobalBounds().top + 32, _mapa.getSprite(i, j).getGlobalBounds().width , 2);
			hitBoxMapPlatform = sf::FloatRect(_plataformas.getSprite(i, j).getGlobalBounds().left, _plataformas.getSprite(i, j).getGlobalBounds().top - 16, _plataformas.getSprite(i, j).getGlobalBounds().width, 16);
			hitBoxMapHead = sf::FloatRect(_mapa.getSprite(i, j).getGlobalBounds().left, _mapa.getSprite(i, j).getGlobalBounds().top + 32, _mapa.getSprite(i, j).getGlobalBounds().width , 2);
			
			if(playerGlobalBounds.top - playerGlobalBounds.height < _mapa.getSprite(i,j).getGlobalBounds().top
			   && hitBoxPlayer.intersects(hitBoxMap)
			   && _personaje.getVelocidadSalto() < 0)
			{
				_personaje.quieto(_personaje.getPosicion().x, _mapa.getSprite(i,j).getGlobalBounds().top - _personaje.getCuerpo().getGlobalBounds().height/2);
			}
			if(playerGlobalBounds.left + playerGlobalBounds.width <= _mapa.getSprite(i,j).getGlobalBounds().left
			   && playerGlobalBounds.intersects(hitBoxMapIzq))
			{
				_personaje.setDerecha();
			}
			   if(playerGlobalBounds.left > _mapa.getSprite(i,j).getGlobalBounds().left + _mapa.getSprite(i,j).getGlobalBounds().width
				  && playerGlobalBounds.intersects(hitBoxMapDer))
			   {
				   _personaje.setIzquierda();
			   }
				  if(playerGlobalBounds.intersects(_muerte.getSprite(i,j).getGlobalBounds()))
				  {
					  _personaje.setPosicion(sf::Vector2f(0,0));
				  }
				  if(playerGlobalBounds.top - playerGlobalBounds.height < _plataformas.getSprite(i,j).getGlobalBounds().top
					 && hitBoxPlayer.intersects(hitBoxMapPlatform)
					 && _personaje.getVelocidadSalto() < 0)
				  {
					  _personaje.quieto(_personaje.getPosicion().x, _plataformas.getSprite(i,j).getGlobalBounds().top - _personaje.getCuerpo().getGlobalBounds().height/2);
				  }
				  if(hitBoxPlayerHead.intersects(hitBoxMapHead))
				  {
					  _personaje.cayendo();
				  }
		}
	}
	
}
sf::Vector2f Gameplay::getPosicionPersonaje()
{
	return _personaje.getPosicion();
}	

void Gameplay::draw(sf::RenderWindow& window)
{	
	for(int i=0; i<31; i++)
	{
		for(int j=0; j<60; j++)
		{	
			
			window.draw(_fondo.getSprite(i,j));
			window.draw(_mapa.getSprite(i,j));
			window.draw(_plataformas.getSprite(i,j));
			window.draw(_muerte.getSprite(i,j));
			
		}
	}	
	window.draw(_personaje);
	window.draw(_enemigo1);
}

