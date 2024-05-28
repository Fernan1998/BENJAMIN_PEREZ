#include "Gameplay.h"
#include <iostream>


Gameplay::Gameplay(CamaraPrincipal &camaraPrincipal)
{
	numeroMapa = 1;
	_camaraPrincipal = camaraPrincipal;
	_personaje = new Personaje();
	_personaje->setPosicion(700.0f, 300.0f);
	nivel1 = new Nivel("Mapas_txt/mapa_cueva1.txt", "Mapas_txt/mapa_cueva1_fondo.txt", "Mapas_txt/mapa_cueva1_plataformas.txt");	
	nivel2 = new Nivel("Mapas_txt/mapa_cueva2.txt", "Mapas_txt/mapa_cueva1_fondo.txt", "Mapas_txt/mapa_cueva2_plataformas.txt");	
	nivel3 = new Nivel("Mapas_txt/mapa_cueva3.txt", "Mapas_txt/mapa_cueva1_fondo.txt", "Mapas_txt/mapa_cueva3_plataformas.txt");	
	listaNiveles[0] = nivel1;
	listaNiveles[1] = nivel2;
	listaNiveles[2] = nivel3;
	
}
Gameplay::~Gameplay()
{
	
}
void Gameplay::actualizar(float deltaTime)
{	
	_personaje->actualizar(deltaTime);
	
	switch(numeroMapa)
	{
	case 1:
		nivel1->actualizar(deltaTime);
		break;
	case 2:
		nivel2->actualizar(deltaTime);
		break;
	case 3:
		nivel3->actualizar(deltaTime);
		break;
	}
	_camaraPrincipal.FollowAndUpdate(_personaje->getPosicion(), &_camaraPrincipal);
	
	
}
void Gameplay::cambioEscena()
{
	if(numeroMapa == 1)
	{
		if(_personaje->getPosicion().x >= 1920)
		{
			numeroMapa = 2;
			_personaje->setPosicion(20,_personaje->getPosicion().y);
		}
		if(_personaje->getPosicion().x <= 10)
		{
			numeroMapa = 3;
			_personaje->setPosicion(1900,_personaje->getPosicion().y);
		}
	}
	if(numeroMapa == 2)
	{
		if(_personaje->getPosicion().x <= 10)
		{
			numeroMapa = 1;
			_personaje->setPosicion(1900,_personaje->getPosicion().y);
		}
		
	}
	if(numeroMapa == 3)
	{
		if(_personaje->getPosicion().x >= 1920)
		{
			numeroMapa = 1;
			_personaje->setPosicion(20,_personaje->getPosicion().y);
		}
		
	}
	

}
void Gameplay::comando()
{
	_personaje->comandos();
	switch(numeroMapa)
	{
	case 1:
		nivel1->comando(*_personaje);
		break;
	case 2:
		nivel2->comando(*_personaje);
		break;
	case 3:
		nivel3->comando(*_personaje);
		break;
	}
	
}
void Gameplay::ChequeoColisiones()
{
	sf::FloatRect hitBoxPlayer(_personaje->getCajaCuerpo().left, _personaje->getCajaCuerpo().top + _personaje->getCajaCuerpo().height -16,_personaje->getCajaCuerpo().width , 16);
	auto playerGlobalBounds = _personaje->getCajaCuerpo();
	sf::FloatRect hitBoxMap;
	sf::FloatRect hitBoxMapIzq;
	sf::FloatRect hitBoxMapDer;
	sf::FloatRect hitBoxMapPlatform;
	sf::FloatRect hitBoxPlayerHead;
	sf::FloatRect hitBoxMapHead;
	Nivel *nivelActual = listaNiveles[numeroMapa-1];
	Enemigo *enemigo = nivelActual->getEnemigo();
	for(int i=0; i<31; i++)
	{
		for(int j=0; j<60; j++)
		{	
			
			hitBoxMap = sf::FloatRect(nivelActual->getMapa(i,j).left, nivelActual->getMapa(i,j).top - 16, nivelActual->getMapa(i,j).width, 16);
			hitBoxMapIzq = sf::FloatRect(nivelActual->getMapa(i,j).left - 4, nivelActual->getMapa(i,j).top+4, nivelActual->getMapa(i,j).width + 4, nivelActual->getMapa(i,j).height);
			hitBoxMapDer = sf::FloatRect(nivelActual->getMapa(i,j).left + 32, nivelActual->getMapa(i,j).top, 4, nivelActual->getMapa(i,j).height);
			hitBoxPlayerHead = sf::FloatRect(playerGlobalBounds.left, playerGlobalBounds.top, playerGlobalBounds.width, 16);
			hitBoxMapHead = sf::FloatRect(nivelActual->getMapa(i,j).left, nivelActual->getMapa(i,j).top + 32, nivelActual->getMapa(i,j).width , 2);
			hitBoxMapPlatform = sf::FloatRect(nivelActual->getPlataforma(i,j).left, nivelActual->getPlataforma(i,j).top - 16, nivelActual->getPlataforma(i,j).width, 16);
			hitBoxMapHead = sf::FloatRect(nivelActual->getMapa(i,j).left, nivelActual->getMapa(i,j).top + 32, nivelActual->getMapa(i,j).width , 2);
			
			if(playerGlobalBounds.top - playerGlobalBounds.height < nivelActual->getMapa(i,j).top
			   && hitBoxPlayer.intersects(hitBoxMap) && _personaje->getVelocidadSalto() < 0)
			{
				_personaje->quieto(_personaje->getPosicion().x, nivelActual->getMapa(i,j).top - _personaje->getCajaCuerpo().height/2);
			}
			if(playerGlobalBounds.top - playerGlobalBounds.height < nivelActual->getPlataforma(i,j).top
			   && hitBoxPlayer.intersects(hitBoxMapPlatform))
			{
				_personaje->saltoInvertido();
			}
			if(playerGlobalBounds.left + playerGlobalBounds.width <= nivelActual->getMapa(i,j).left
			   && playerGlobalBounds.intersects(hitBoxMapIzq))
			{
				_personaje->setDerecha();
			}
		    if(playerGlobalBounds.left > nivelActual->getMapa(i,j).left + nivelActual->getMapa(i,j).width
			  && playerGlobalBounds.intersects(hitBoxMapDer))
		    {
			   _personaje->setIzquierda();
		    }
			if(playerGlobalBounds.top - playerGlobalBounds.height < nivelActual->getPlataforma(i,j).top
			 && hitBoxPlayer.intersects(hitBoxMapPlatform)
			 && _personaje->getVelocidadSalto() < 0)
			{
				_personaje->quieto(_personaje->getPosicion().x, nivelActual->getPlataforma(i,j).top - _personaje->getCajaCuerpo().height/2);
			}
			if(hitBoxPlayerHead.intersects(hitBoxMapHead))
			{
				_personaje->cayendo();
			}

			sf::FloatRect hitBoxEnemigo = enemigo->getHitBox();
			if (hitBoxEnemigo.intersects(nivelActual->getMapa(i,j)) && hitBoxEnemigo.top - hitBoxEnemigo.height < nivelActual->getMapa(i,j).top)			
			{
				enemigo->quieto(enemigo->getPosition().x,nivelActual->getMapa(i,j).top - enemigo->getHitBox().height/2);
			}
			
			if(enemigo->getHitBox().left > nivelActual->getMapa(i,j).left + nivelActual->getMapa(i,j).width
			   && enemigo->getHitBox().intersects(hitBoxMapDer))
			{
				enemigo->setIzquierda();
				std::cout << "IZQUERDA\n";
			}
			if(enemigo->getHitBox().left + enemigo->getHitBox().width <= nivelActual->getMapa(i,j).left
			   && enemigo->getHitBox().intersects(hitBoxMapIzq))
			{
				enemigo->setDerecha();
				std::cout << "DERECHA\n";
			}
		    
		}
	}

	if(_personaje->getAtacando() == true && _personaje->getCajaAtaque().getGlobalBounds().intersects(enemigo->getHitBox()))
	{
		enemigo->setSalud(_personaje->getDanio());
		enemigo->recibiendoDanio();

	}

	
}

sf::Vector2f Gameplay::getPosicionPersonaje()
{
	return _personaje->getPosicion();
}	

void Gameplay::draw(sf::RenderWindow& window)
{	
	switch(numeroMapa)
	{
		case 1:
			nivel1->dibujar(window);
			break;
		case 2:
			nivel2->dibujar(window);
			break;
		case 3:
			nivel3->dibujar(window);
			break;
	}
	
	window.draw(*_personaje);
	
}

