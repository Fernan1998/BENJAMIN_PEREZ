#include "Gameplay.h"
#include <iostream>

Gameplay::Gameplay(CamaraPrincipal &camaraPrincipal)
{
	numeroMapa = 4;
	
	_camaraPrincipal = camaraPrincipal;
	
	_personaje = new Personaje();
	
	cinematicaPersonaje = new  Cinematica("dia_noche/dia_noche", 251);
	
	nivel1 = new Nivel("Mapas_txt/mapa_tutorial/mapa_tutorial_piso.txt", "Mapas_txt/mapa_tutorial/mapa_tutorial_fondo.txt", "Mapas_txt/mapa_tutorial/mapa_tutorial_relleno.txt", "Sonido/Folklore.ogg");
	nivel2 = new Nivel("Mapas_txt/mapa_agujero/mapa_noche.txt", "Mapas_txt/mapa_agujero/fondo_noche.txt", "Mapas_txt/mapa_agujero/mapa_tutorial_relleno.txt", "Sonido/Folklore.ogg");
	nivel3 = new Nivel("Mapas_txt/mapa_luz_mala/mapa_luz_mala_piso.txt", "Mapas_txt/mapa_luz_mala/fondo_noche.txt", "Mapas_txt/mapa_luz_mala/mapa_luz_mala_agua.txt", "Sonido/Folklore.ogg");
	nivel4 = new Nivel("Mapas_txt/mapa_cueva_1/mapa_cueva1.txt", "Mapas_txt/mapa_cueva_1/mapa_cueva1_fondo.txt", "Mapas_txt/mapa_cueva_1/mapa_cueva1_plataformas.txt", "Sonido/Folklore.ogg");
	nivel5 = new Nivel("Mapas_txt/mapa_cueva_2/mapa_cueva2.txt", "Mapas_txt/mapa_cueva_2/mapa_cueva2_fondo.txt", "Mapas_txt/mapa_cueva_2/mapa_cueva2_plataformas.txt", "Sonido/Folklore.ogg");
	nivel6 = new Nivel("Mapas_txt/mapa_cueva_3/mapa_cueva3.txt", "Mapas_txt/mapa_cueva_3/mapa_cueva3_fondo.txt", "Mapas_txt/mapa_cueva_3/mapa_cueva3_plataformas.txt", "Sonido/Folklore.ogg");
	nivel7 = new Nivel("Mapas_txt/mapa_pombero/pombero_piso.txt", "Mapas_txt/mapa_pombero/pombero_fondo.txt", "Mapas_txt/mapa_pombero/pombero_plataforma.txt", "Sonido/Folklore.ogg");
	nivel8 = new Nivel("Mapas_txt/mapa_pombero/pombero_piso.txt", "Mapas_txt/mapa_pombero/pombero_fondo.txt", "Mapas_txt/mapa_pombero/pombero_plataforma.txt", "Sonido/Folklore.ogg");
	
	listaNiveles[0] = nivel1;
	listaNiveles[1] = nivel2;
	listaNiveles[2] = nivel3;
	listaNiveles[3] = nivel4;
	listaNiveles[4] = nivel5;
	listaNiveles[5] = nivel6;
	listaNiveles[6] = nivel7;
	listaNiveles[7] = nivel8;
	nivel1->reiniciarNivel();
	nivel2->reiniciarNivel();
	nivel3->reiniciarNivel();
	nivel4->reiniciarNivel();
	nivel5->reiniciarNivel();
	nivel6->reiniciarNivel();
	nivel7->reiniciarNivel();
	nivel8->reiniciarNivel();
	
	_aux.setPosition(sf::Vector2f(0, 224));
	_aux.setSize(sf::Vector2f(1024, 768));	
	_boleadora.setPosition(_personaje->getPosicion());
	_boleando = false;
	
	cargarJuego(_personaje, numeroMapa);
}
Gameplay::~Gameplay()
{
	
}
void Gameplay::actualizar(float deltaTime)
{
	getDatosPoronga(_personaje->getPosicion(), _personaje->getSalud(), numeroMapa);
	
	_camaraPrincipal.FollowAndUpdate(_personaje->getPosicion(), &_camaraPrincipal);
	ponerPausa();
	if (!pausa)
	{
		_personaje->actualizar(deltaTime);
		
		switch(numeroMapa)
		{
			case 1:
				nivel1->actualizar(deltaTime);
				break;
			case 2:
				nivel2->actualizar(deltaTime);
				texAux = cinematicaPersonaje->cargarImagenes(i);
				_aux.setTexture(&texAux);
				break;
			case 3:
				nivel3->actualizar(deltaTime);
				break;
			case 4:
				nivel4->actualizar(deltaTime);
				break;
			case 5:
				nivel5->actualizar(deltaTime);
				break;
			case 6:
				nivel6->actualizar(deltaTime);
				break;
			case 7:
				nivel7->actualizar(deltaTime);
				break;
			case 8:
				nivel8->actualizar(deltaTime);
				break;
		}
	}
	
	
	if(_personaje->getBoleadora() || _boleando)
	{
		
		_boleando = true;
		if(_personaje->getScale() == 1 && _boleadora.getPosition().x)
		{
			if(_boleadora.getPosition().x < _personaje->getPosicion().x +500)
			{
				_boleadora.actualizar(1);
			}
			else
			{

				_boleando = false;
			}
		}
		else if(_personaje->getScale() == -1)
		{
			if(_boleadora.getPosition().x > _personaje->getPosicion().x -500)
			{
				_boleadora.actualizar(2);
			}
			else
			{
				_boleando = false;
			}
			
		}	
	}
	else
	{
		_boleadora.setPosition(_personaje->getPosicion());
		_boleadora.setColor(sf::Color::Transparent);
	}

	
	
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
	}
	if(numeroMapa == 2)
	{
		if(_personaje->getPosicion().x <= 0)
		{
			_personaje->setPosicion(0,_personaje->getPosicion().y);
		}
		if(_personaje->getPosicion().x >= 1920)
		{
			numeroMapa = 3;
			_personaje->setPosicion(20,_personaje->getPosicion().y);
		} 
		if(_personaje->getPosicion().x >= 138 && _personaje->getPosicion().x <= 224 && _personaje->getPosicion().y > 980)
		{
			numeroMapa = 4;
			_personaje->setPosicion(_personaje->getPosicion().x, 0);
		}
	}
	if(numeroMapa == 3)
	{
		if(_personaje->getPosicion().x <= 0)
		{
			numeroMapa = 2;
			_personaje->setPosicion(1920,_personaje->getPosicion().y);
		}
		if(_personaje->getPosicion().x >= 1900)
		{
			numeroMapa = 8;
			_personaje->setPosicion(20,_personaje->getPosicion().y);
		}
		if(_personaje->getPosicion().y >= 980)
		{
			_personaje->recibiendoDanio(100);
		}
	}
	if(numeroMapa == 4)
	{
		if(_personaje->getPosicion().x <= 0)
		{
			numeroMapa = 6;
			_personaje->setPosicion(1900,_personaje->getPosicion().y);
		}
		if(_personaje->getPosicion().x >= 1920)
		{
			numeroMapa = 5;
			_personaje->setPosicion(20,_personaje->getPosicion().y);
		} 
		if(_personaje->getPosicion().y >= 980)
		{
			_personaje->recibiendoDanio(100);
		}
	}
	if(numeroMapa == 6)
	{
		
		if(_personaje->getPosicion().x >= 1920)
		{
			numeroMapa = 4;
			_personaje->setPosicion(20,_personaje->getPosicion().y);
		} 
	}
	if(numeroMapa == 5)
	{
		if(_personaje->getPosicion().x <= 0)
		{
			numeroMapa = 4;
			_personaje->setPosicion(1900,_personaje->getPosicion().y);
		}
		if(_personaje->getPosicion().y >= 980)
		{
			_personaje->recibiendoDanio(100);
		}
		
	}
	if(numeroMapa == 8)
	{
		if(_personaje->getPosicion().y >= 980)
		{
			_personaje->recibiendoDanio(100);
		}
		
	}
	if(_personaje->getSalud()<=0)
	{
		if(numeroMapa != 8)
		{
			nivel1->reiniciarNivel();
			nivel2->reiniciarNivel();
			nivel3->reiniciarNivel();
			nivel4->reiniciarNivel();
			nivel5->reiniciarNivel();
			nivel6->reiniciarNivel();
			nivel7->reiniciarNivel();
			nivel8->reiniciarNivel();
			
			_personaje->reiniciar(sf::Vector2f(100,750));
			numeroMapa = 2;
		}
		else if(numeroMapa == 8)
		{
			_personaje->reiniciar(sf::Vector2f(100,750));
			numeroMapa = 8;
		}
	
		
	}
	
}
void Gameplay::comando(int c)
{
	_personaje->comandos(c);
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
		case 4:
			nivel4->comando(*_personaje);
			break;
		case 5:
			nivel5->comando(*_personaje);
			break;
		case 6:
			nivel6->comando(*_personaje);
			break;
		case 7:
			nivel7->comando(*_personaje);
			break;
		case 8:
			nivel8->comando(*_personaje);
			break;
	}
	
}
void Gameplay::ChequeoColisiones()
{
	//Creacion de las diferentes HitBox/s
	sf::FloatRect hitBoxPlayer(_personaje->getCajaCuerpo().left +10, _personaje->getCajaCuerpo().top + _personaje->getCajaCuerpo().height,_personaje->getCajaCuerpo().width -20, 16);
	auto playerGlobalBounds = _personaje->getCajaCuerpo();
	
	sf::FloatRect hitBoxMap;
	sf::FloatRect hitBoxMapIzq;
	sf::FloatRect hitBoxMapDer;
	sf::FloatRect hitBoxMapPlatform;
	sf::FloatRect hitBoxPlayerHead;
	sf::FloatRect hitBoxMapHead;
	
	Nivel *nivelActual = listaNiveles[numeroMapa-1];
	
	Enemigo *enemigo = nivelActual->getEnemigo();
	
	sf::FloatRect hitBoxEnemigo = enemigo->getHitBox();
	
	for(int i=0; i<31; i++)
	{
		for(int j=0; j<60; j++)
		{	
			
			hitBoxMap = sf::FloatRect(nivelActual->getMapa(i,j).left, nivelActual->getMapa(i,j).top, nivelActual->getMapa(i,j).width, 16);
			hitBoxMapIzq = sf::FloatRect(nivelActual->getMapa(i,j).left - 4, nivelActual->getMapa(i,j).top+4, nivelActual->getMapa(i,j).width + 8, nivelActual->getMapa(i,j).height);
			hitBoxMapDer = sf::FloatRect(nivelActual->getMapa(i,j).left + 32, nivelActual->getMapa(i,j).top+4, 4, nivelActual->getMapa(i,j).height);
			hitBoxPlayerHead = sf::FloatRect(playerGlobalBounds.left, playerGlobalBounds.top, playerGlobalBounds.width, 16);
			hitBoxMapHead = sf::FloatRect(nivelActual->getMapa(i,j).left, nivelActual->getMapa(i,j).top + 32, nivelActual->getMapa(i,j).width , 2);
			hitBoxMapPlatform = sf::FloatRect(nivelActual->getPlataforma(i,j).left, nivelActual->getPlataforma(i,j).top, nivelActual->getPlataforma(i,j).width, 16);
			
			//Colision personaje mapa
			if(playerGlobalBounds.top - playerGlobalBounds.height < hitBoxMap.top 
			   && hitBoxPlayer.intersects(hitBoxMap) && _personaje->getVelocidadSalto() <= 0)
			{
				_personaje->quieto(_personaje->getPosicion().x, hitBoxMap.top - _personaje->getCajaCuerpo().height/2);
			}
			//Colision personaje plataformas
			if(playerGlobalBounds.top - playerGlobalBounds.height < hitBoxMapPlatform.top
			   && hitBoxPlayer.intersects(hitBoxMapPlatform)
			   && _personaje->getVelocidadSalto() < 0)
			{
				_personaje->quieto(_personaje->getPosicion().x, hitBoxMap.top - _personaje->getCajaCuerpo().height/2);
			}
			//Activar bajar plataformas
			if(playerGlobalBounds.top - playerGlobalBounds.height < nivelActual->getPlataforma(i,j).top
			   && hitBoxPlayer.intersects(hitBoxMapPlatform))
			{
				_personaje->saltoInvertido();
			}
			//Colision lado derecho   
			if(playerGlobalBounds.left + playerGlobalBounds.width <= nivelActual->getMapa(i,j).left +5
			   && playerGlobalBounds.intersects(hitBoxMapIzq))
			{
				_personaje->setDerecha();
			}
			//Colision lado izquierdo   
		    if(playerGlobalBounds.left > nivelActual->getMapa(i,j).left + nivelActual->getMapa(i,j).width -5
			  && playerGlobalBounds.intersects(hitBoxMapDer))
		    {
			   _personaje->setIzquierda();
		    }
			//Colision cabeza
			if(hitBoxPlayerHead.intersects(hitBoxMapHead))
			{
				_personaje->cayendo();
			}
			//Colision enemigo mapa
			if (hitBoxEnemigo.intersects(hitBoxMap))
			{
				if (hitBoxEnemigo.top - hitBoxEnemigo.height < hitBoxMap.top)
				{
					enemigo->quieto();
				} 
			}
			//Colision enemigo derecha
			if (hitBoxEnemigo.left + hitBoxEnemigo.width <= hitBoxMap.left &&
				hitBoxEnemigo.intersects(hitBoxMapIzq))
			{
				enemigo->setDerecha();
			}
			//Colision enemigo Izquierda
			if (hitBoxEnemigo.left > hitBoxMap.left + hitBoxMap.width &&
				hitBoxEnemigo.intersects(hitBoxMapDer))
			{ 
				
				enemigo->setIzquierda();
			}
		    
		}
	}
	//Ataque Personaje >> Enemigo
	if(_personaje->getAtacando() == true && _personaje->getCajaAtaque().getGlobalBounds().intersects(enemigo->getHitBox()) && enemigo->getSalud() >0)
	{
		enemigo->setSalud(_personaje->getDanio());
		if(_personaje->getPosicion().x < enemigo->getPosition().x)
		{
			enemigo->recibiendoDanio(1);
		}
		else
		{
			enemigo->recibiendoDanio(2);
		}
	}
	if(enemigo->getHitBox().intersects(playerGlobalBounds)&&enemigo->getSalud() >0)
	{
		if (clock.getElapsedTime().asSeconds() - _ultimoAtaque >= 1.0f)
		{
			enemigo->setAtacando();
			_personaje->recibiendoDanio(enemigo->getDanio());
			_ultimoAtaque = clock.getElapsedTime().asSeconds();
		}
	}
	if(_boleadora.getCuerpo().intersects(enemigo->getHitBox()))
	{
		enemigo->setVelocidadCaminata(0.5f);
		
	}
}

sf::Vector2f Gameplay::getPosicionPersonaje()
{
	return _personaje->getPosicion();
}	

int Gameplay::draw(sf::RenderWindow& window)
{
	
	if (pausa)
	{
		switch (numeroMapa)
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
			case 4:
				nivel4->dibujar(window);
				break;
			case 5:
				nivel5->dibujar(window);
				break;
			case 6:
				nivel6->dibujar(window);
				break;
			case 7:
				nivel7->dibujar(window);
				break;
			case 8:
				nivel8->dibujar(window);
				break;
		}
		switch(menu.mostrar(window, getPosicionPersonaje()))
		{
			case 1:
				pausa = false;
				return 1;
				break;
			case 2:
				return 2;
				break;
			case 3:
				pausa = false;
				return 3;
				break;
		}
	}
	else 
	{
		switch(numeroMapa)
		{
			case 1:
				nivel1->dibujar(window);
				break;
			case 2:
				nivel2->dibujar(window);
				if(i<=251)
				{
					window.draw(_aux);
					_personaje->modoPausa();
				}
				break;
			case 3:
				nivel3->dibujar(window);
				break;
			case 4:
				nivel4->dibujar(window);
				break;
			case 5:
				nivel5->dibujar(window);
				break;
			case 6:
				nivel6->dibujar(window);
				break;
			case 7:
				nivel7->dibujar(window);
				break;
			case 8:
				nivel8->dibujar(window);
				break;
		}
	}
	window.draw(*_personaje);
	window.draw(_personaje->getBarraVida());
	window.draw(_boleadora);
}

void Gameplay::ponerPausa()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
	{
		pausa = true;
	}
}
