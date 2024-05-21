#include "Gameplay.h"


Gameplay::Gameplay(CamaraPrincipal &camaraPrincipal, std::string mapa, std::string fondo, std::string plataformas)
{
	_camaraPrincipal = camaraPrincipal;
	nivel1 = new Nivel(mapa, fondo, plataformas);	
}
Gameplay::~Gameplay()
{
	
}
void Gameplay::actualizar(float deltaTime)
{	
	_personaje.actualizar(deltaTime);
	_camaraPrincipal.FollowAndUpdate(_personaje.getPosicion(), &_camaraPrincipal);
	nivel1->actualizar(deltaTime);
	
}
void Gameplay::comando()
{
	_personaje.comandos();
	nivel1->comando(_personaje);
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
			hitBoxMap = sf::FloatRect(nivel1->getMapa(i,j).left, nivel1->getMapa(i,j).top - 16, nivel1->getMapa(i,j).width, 16);
			hitBoxMapIzq = sf::FloatRect(nivel1->getMapa(i,j).left - 4, nivel1->getMapa(i,j).top, nivel1->getMapa(i,j).width + 4, nivel1->getMapa(i,j).height);
			hitBoxMapDer = sf::FloatRect(nivel1->getMapa(i,j).left + 32, nivel1->getMapa(i,j).top, 4, nivel1->getMapa(i,j).height);
			hitBoxPlayerHead = sf::FloatRect(playerGlobalBounds.left, playerGlobalBounds.top, playerGlobalBounds.width, 16);
			hitBoxMapHead = sf::FloatRect(nivel1->getMapa(i,j).left, nivel1->getMapa(i,j).top + 32, nivel1->getMapa(i,j).width , 2);
			hitBoxMapPlatform = sf::FloatRect(nivel1->getPlataforma(i,j).left, nivel1->getPlataforma(i,j).top - 16, nivel1->getPlataforma(i,j).width, 16);
			hitBoxMapHead = sf::FloatRect(nivel1->getMapa(i,j).left, nivel1->getMapa(i,j).top + 32, nivel1->getMapa(i,j).width , 2);
			
			if(playerGlobalBounds.top - playerGlobalBounds.height < nivel1->getMapa(i,j).top
			   && hitBoxPlayer.intersects(hitBoxMap)
			   && _personaje.getVelocidadSalto() < 0)
			{
				_personaje.quieto(_personaje.getPosicion().x, nivel1->getMapa(i,j).top - _personaje.getCuerpo().getGlobalBounds().height/2);
			}
			if(playerGlobalBounds.left + playerGlobalBounds.width <= nivel1->getMapa(i,j).left
			   && playerGlobalBounds.intersects(hitBoxMapIzq))
			{
				_personaje.setDerecha();
			}
		    if(playerGlobalBounds.left > nivel1->getMapa(i,j).left + nivel1->getMapa(i,j).width
			  && playerGlobalBounds.intersects(hitBoxMapDer))
		    {
			   _personaje.setIzquierda();
		    }
			if(playerGlobalBounds.top - playerGlobalBounds.height < nivel1->getPlataforma(i,j).top
			 && hitBoxPlayer.intersects(hitBoxMapPlatform)
			 && _personaje.getVelocidadSalto() < 0)
			{
			  _personaje.quieto(_personaje.getPosicion().x, nivel1->getPlataforma(i,j).top - _personaje.getCuerpo().getGlobalBounds().height/2);
			}
			if(hitBoxPlayerHead.intersects(hitBoxMapHead))
			{
			  _personaje.cayendo();
			}
		}
	}
//	if(_personaje.getAtacando() == true && _personaje.getCajaAtaque().getGlobalBounds().intersects(.getCuerpo().getGlobalBounds()))
//	{
//		.setSalud(_personaje.getDanio());
//		.recibiendoDanio();
//
//	}

	
}

sf::Vector2f Gameplay::getPosicionPersonaje()
{
	return _personaje.getPosicion();
}	

void Gameplay::draw(sf::RenderWindow& window)
{	

	nivel1->dibujar(window);
	window.draw(_personaje);
	
}

