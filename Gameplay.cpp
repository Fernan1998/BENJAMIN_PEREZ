#include "Gameplay.h"
#include <iostream>


Gameplay::Gameplay(Personaje* personaje, CamaraPrincipal &camaraPrincipal, std::string mapa, std::string fondo, std::string plataformas)
{
	_camaraPrincipal = camaraPrincipal;
	_personaje = personaje;
	nivel1 = new Nivel(mapa, fondo, plataformas);	
}
Gameplay::~Gameplay()
{
	
}
void Gameplay::actualizar(float deltaTime)
{	
	_personaje->actualizar(deltaTime);
	_camaraPrincipal.FollowAndUpdate(_personaje->getPosicion(), &_camaraPrincipal);
	nivel1->actualizar(deltaTime);
	
}
void Gameplay::comando()
{
	_personaje->comandos();
	nivel1->comando(*_personaje);
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
	Enemigo *enemigo = nivel1->getEnemigo();
	for(int i=0; i<31; i++)
	{
		for(int j=0; j<60; j++)
		{	
			
			hitBoxMap = sf::FloatRect(nivel1->getMapa(i,j).left, nivel1->getMapa(i,j).top - 16, nivel1->getMapa(i,j).width, 16);
			hitBoxMapIzq = sf::FloatRect(nivel1->getMapa(i,j).left - 4, nivel1->getMapa(i,j).top+4, nivel1->getMapa(i,j).width + 4, nivel1->getMapa(i,j).height);
			hitBoxMapDer = sf::FloatRect(nivel1->getMapa(i,j).left + 32, nivel1->getMapa(i,j).top, 4, nivel1->getMapa(i,j).height);
			hitBoxPlayerHead = sf::FloatRect(playerGlobalBounds.left, playerGlobalBounds.top, playerGlobalBounds.width, 16);
			hitBoxMapHead = sf::FloatRect(nivel1->getMapa(i,j).left, nivel1->getMapa(i,j).top + 32, nivel1->getMapa(i,j).width , 2);
			hitBoxMapPlatform = sf::FloatRect(nivel1->getPlataforma(i,j).left, nivel1->getPlataforma(i,j).top - 16, nivel1->getPlataforma(i,j).width, 16);
			hitBoxMapHead = sf::FloatRect(nivel1->getMapa(i,j).left, nivel1->getMapa(i,j).top + 32, nivel1->getMapa(i,j).width , 2);
			
			if(playerGlobalBounds.top - playerGlobalBounds.height < nivel1->getMapa(i,j).top
			   && hitBoxPlayer.intersects(hitBoxMap) && _personaje->getVelocidadSalto() < 0)
			{
				_personaje->quieto(_personaje->getPosicion().x, nivel1->getMapa(i,j).top - _personaje->getCajaCuerpo().height/2);
			}
			if(playerGlobalBounds.left + playerGlobalBounds.width <= nivel1->getMapa(i,j).left
			   && playerGlobalBounds.intersects(hitBoxMapIzq))
			{
				_personaje->setDerecha();
			}
		    if(playerGlobalBounds.left > nivel1->getMapa(i,j).left + nivel1->getMapa(i,j).width
			  && playerGlobalBounds.intersects(hitBoxMapDer))
		    {
			   _personaje->setIzquierda();
		    }
			if(playerGlobalBounds.top - playerGlobalBounds.height < nivel1->getPlataforma(i,j).top
			 && hitBoxPlayer.intersects(hitBoxMapPlatform)
			 && _personaje->getVelocidadSalto() < 0)
			{
				_personaje->quieto(_personaje->getPosicion().x, nivel1->getPlataforma(i,j).top - _personaje->getCajaCuerpo().height/2);
			}
			if(hitBoxPlayerHead.intersects(hitBoxMapHead))
			{
				_personaje->cayendo();
			}

			sf::FloatRect hitBoxEnemigo = enemigo->getHitBox();
			if (hitBoxEnemigo.intersects(nivel1->getMapa(i,j)) && hitBoxEnemigo.top - hitBoxEnemigo.height < nivel1->getMapa(i,j).top)			
			{
				enemigo->quieto(enemigo->getPosition().x,nivel1->getMapa(i,j).top - enemigo->getHitBox().height/2);
			}
			
			if(enemigo->getHitBox().left > nivel1->getMapa(i,j).left + nivel1->getMapa(i,j).width
			   && enemigo->getHitBox().intersects(hitBoxMapDer))
			{
				enemigo->setIzquierda();
				std::cout << "IZQUERDA\n";
			}
			if(enemigo->getHitBox().left + enemigo->getHitBox().width <= nivel1->getMapa(i,j).left
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

	nivel1->dibujar(window);
	window.draw(*_personaje);
	
}

