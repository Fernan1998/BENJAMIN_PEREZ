#include "Gameplay.h"
#include <iostream>

Gameplay::Gameplay(CamaraPrincipal &camaraPrincipal)
{
	numeroMapa = 7;	
	
	_camaraPrincipal = camaraPrincipal;
	
	_personaje = new Personaje();
	
	_objetoOjo = new Objetos(34,22, "Textura/Objetos/ojoBabosa.png");
	_objetoLobizon = new Objetos(56,48, "Textura/Objetos/objetoLobizon.png");
	
	cinematicaPersonaje = new  Cinematica("dia_noche/dia_noche", 251);
	
	nivel1 = new Nivel("Mapas_txt/mapa_tutorial/mapa_tutorial_piso.txt", "Mapas_txt/mapa_tutorial/mapa_tutorial_fondo.txt", "Mapas_txt/mapa_tutorial/mapa_tutorial_plataforma.txt", "Sonido/Folklore.ogg", 1);
	nivel1->creadorDeEnemigos(100, 25, "Textura/Babosa/Baboscompleta.png", 63, 84, 84, 800, 3, 8);
	nivel2 = new Nivel("Mapas_txt/mapa_agujero/mapa_noche2.txt", "Mapas_txt/mapa_agujero/fondo_noche.txt", "Mapas_txt/mapa_agujero/mapa_tutorial_relleno.txt", "Sonido/Folklore.ogg", 2);
	nivel2->creadorDeJefes(100, 25, "Textura/Babosa/Baboscompleta.png", 63, 84, 84, 800, 3, 8);
	nivel3 = new Nivel("Mapas_txt/mapa_luz_mala/mapa_luz_mala_piso.txt", "Mapas_txt/mapa_luz_mala/fondo_noche.txt", "Mapas_txt/mapa_luz_mala/mapa_luz_mala_agua.txt", "Sonido/Folklore.ogg", 0, false);
	nivel4 = new Nivel("Mapas_txt/mapa_cueva_1/mapa_cueva1.txt", "Mapas_txt/mapa_cueva_1/mapa_cueva1_fondo.txt", "Mapas_txt/mapa_cueva_1/mapa_cueva1_plataformas.txt", "Sonido/Folklore.ogg", 2);
	nivel4->creadorDeEnemigos(100, 25, "Textura/Wolf/idle1.png", 170, 160, 84, 800, 3, 10);
	nivel5 = new Nivel("Mapas_txt/mapa_cueva_2/mapa_cueva2.txt", "Mapas_txt/mapa_cueva_2/mapa_cueva2_fondo.txt", "Mapas_txt/mapa_cueva_2/mapa_cueva2_plataformas.txt", "Sonido/Folklore.ogg", 2);
	nivel5->creadorDeEnemigos(100, 25, "Textura/Wolf/idle1.png", 170, 160, 84, 800, 3, 10);
	nivel6 = new Nivel("Mapas_txt/mapa_cueva_3/mapa_cueva3.txt", "Mapas_txt/mapa_cueva_3/mapa_cueva3_fondo.txt", "Mapas_txt/mapa_cueva_3/mapa_cueva3_plataformas.txt", "Sonido/Folklore.ogg", 1);
	nivel6->creadorDeEnemigos(100, 25, "Textura/Wolf/idle1.png", 170, 160, 84, 800, 3, 10);
	nivel7 = new Nivel("Mapas_txt/mapa_infierno/infernal_piso.txt", "Mapas_txt/mapa_infierno/infernal_fondo.txt", "Mapas_txt/mapa_infierno/infernal_relleno.txt", "Sonido/Folklore.ogg", 1);
	nivel7->creadorDeEnemigos(100, 25, "Textura/Wolf/idle1.png", 170, 160, 84, 800, 3, 10);
	nivel8 = new Nivel("Mapas_txt/mapa_montania/noche_piso_montania.txt", "Mapas_txt/mapa_montania/noche_fondo_montania.txt", "Mapas_txt/mapa_montania/noche_relleno_montania.txt", "Sonido/Folklore.ogg", 0, false);
	nivel9 = new Nivel("Mapas_txt/mapa_pombero/pombero_piso.txt", "Mapas_txt/mapa_pombero/pombero_fondo.txt", "Mapas_txt/mapa_pombero/pombero_plataforma.txt", "Sonido/Folklore.ogg", 0, false);
	
	listaNiveles[0] = nivel1;
	listaNiveles[1] = nivel2;
	listaNiveles[2] = nivel3;
	listaNiveles[3] = nivel4;
	listaNiveles[4] = nivel5;
	listaNiveles[5] = nivel6;
	listaNiveles[6] = nivel7;
	listaNiveles[7] = nivel8;
	listaNiveles[8] = nivel9;
	
	nivel1->reiniciarNivel(sf::Vector2f(1735,700), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0));
	nivel2->reiniciarNivel(sf::Vector2f(941,700), sf::Vector2f(1300,700), sf::Vector2f(0,0), sf::Vector2f(0,0));
	nivel3->reiniciarNivel(sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0));
	nivel4->reiniciarNivel(sf::Vector2f(1500,260), sf::Vector2f(1341,700), sf::Vector2f(0,0), sf::Vector2f(0,0));
	nivel5->reiniciarNivel(sf::Vector2f(650,700), sf::Vector2f(1680,260), sf::Vector2f(0,0), sf::Vector2f(0,0));
	nivel6->reiniciarNivel(sf::Vector2f(360,790), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0));
	nivel7->reiniciarNivel(sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0));
	nivel8->reiniciarNivel(sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0));
	nivel9->reiniciarNivel(sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0));
	
	
	
	_aux.setPosition(sf::Vector2f(0, 224));
	_aux.setSize(sf::Vector2f(1024, 768));	
	_boleadora.setPosition(_personaje->getPosicion());
	_boleando = false;
}
Gameplay::~Gameplay()
{
	
}

void Gameplay::cargarPartida(){
	cargarJuego(_personaje, numeroMapa);
}

void Gameplay::actualizar(float deltaTime)
{
	getDatosPoronga(_personaje->getPosicion(), _personaje->getSalud(), numeroMapa);
	
	_camaraPrincipal.FollowAndUpdate(_personaje->getPosicion(), &_camaraPrincipal);
	
	ponerPausa();
	
	if(_personaje->getObjetos(1))
	{
	}
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
			case 9:
				nivel9->actualizar(deltaTime);
				break;
		}
	}
	
	
	if(_personaje->getBoleadora() || _boleando)
	{
		if(_boleando == false)
		{
			escala = _personaje->getScale();
		}
		_boleando = true;
		if(escala == 1)
		{
			if(_boleadora.getPosition().x < _personaje->getPosicion().x +1000)
			{
				_boleadora.actualizar(1);
			}
			else
			{
				_boleando = false;
				_boleadora.setPosition(_personaje->getPosicion());
				_boleadora.setColor(sf::Color::Transparent);
			}
		}
		else if(escala == -1)
		{
			if(_boleadora.getPosition().x > _personaje->getPosicion().x -1000)
			{
				_boleadora.actualizar(2);
			}
			else
			{
				_boleando = false;
				_boleadora.setPosition(_personaje->getPosicion());
				_boleadora.setColor(sf::Color::Transparent);
			}
			
		}	
	}
	else
	{
		_boleadora.setColor(sf::Color::Transparent);
		_boleadora.setPosition(_personaje->getPosicion());
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
		if(_personaje->getPosicion().x <= 0)
		{
			_personaje->setPosicion(0,_personaje->getPosicion().y);
		}
		if(_personaje->getPosicion().y >= 980)
		{
			_personaje->recibiendoDanio(100, 0);
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
			_personaje->setPosicion(1900,_personaje->getPosicion().y);
		}
		if(_personaje->getPosicion().x >= 1920)
		{
			numeroMapa = 8;
			_personaje->setPosicion(20,_personaje->getPosicion().y);
		}
		
		if(_personaje->getPosicion().y >= 980)
		{
			_personaje->recibiendoDanio(100, 0);
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
			_personaje->recibiendoDanio(100, 0);
		}
	}
	if(numeroMapa == 6)
	{
		
		if(_personaje->getPosicion().x >= 1920)
		{
			numeroMapa = 4;
			_personaje->setPosicion(20,_personaje->getPosicion().y);
		} 
		if(_personaje->getObjetos(1))
		{
			numeroMapa = 2;
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
			_personaje->recibiendoDanio(100, 0);
		}
		
	}
	if(numeroMapa == 8)
	{
		if(_personaje->getPosicion().x <= 0)
		{
			numeroMapa = 3;
			_personaje->setPosicion(1900,_personaje->getPosicion().y);
		}
		if(_personaje->getPosicion().x >= 1920)
		{
			numeroMapa = 9;
			_personaje->setPosicion(20,_personaje->getPosicion().y);
		}
		
		if(_personaje->getPosicion().y >= 980)
		{
			_personaje->recibiendoDanio(100, 0);
		}
		
	}
	if(numeroMapa == 9)
	{
		if(_personaje->getPosicion().x <= 0)
		{
			_personaje->setPosicion(0,_personaje->getPosicion().y);
		}
		if(_personaje->getPosicion().y >= 980)
		{
			_personaje->recibiendoDanio(100, 0);
		}
		if(_personaje->getPosicion().x >= 1920)
		{
			_personaje->setPosicion(1920,_personaje->getPosicion().y);
		}
	}
	
	if(_personaje->getSalud()<=0)
	{
		if(numeroMapa != 9 && numeroMapa != 1)
		{

			nivel2->reiniciarNivel(sf::Vector2f(941,700), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0));
			nivel3->reiniciarNivel(sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0));
			nivel4->reiniciarNivel(sf::Vector2f(1500,260), sf::Vector2f(1341,700), sf::Vector2f(0,0), sf::Vector2f(0,0));
			nivel5->reiniciarNivel(sf::Vector2f(650,700), sf::Vector2f(1680,260), sf::Vector2f(0,0), sf::Vector2f(0,0));
			nivel6->reiniciarNivel(sf::Vector2f(360,790), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0));
			nivel7->reiniciarNivel(sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0));
			nivel8->reiniciarNivel(sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0));
			
			_personaje->reiniciar(sf::Vector2f(100,750));
			numeroMapa = 2;
		}
		else if(numeroMapa == 9)
		{
			nivel9->reiniciarNivel(sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0));
			_personaje->reiniciar(sf::Vector2f(100,750));
			numeroMapa = 9;
		}
		else if(numeroMapa == 1)
		{
			nivel1->reiniciarNivel(sf::Vector2f(1735,700), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0));
			_personaje->reiniciar(sf::Vector2f(100,750));
			numeroMapa = 1;
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
		case 9:
			nivel9->comando(*_personaje);
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
	
	std::vector<Enemigo*> _vectorEnemigo = nivelActual->getEnemigo();
	
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
			if(playerGlobalBounds.left + playerGlobalBounds.width <= nivelActual->getMapa(i,j).left +10
			   && playerGlobalBounds.intersects(hitBoxMapIzq))
			{
				_personaje->setDerecha();
			}
			//Colision lado izquierdo   
		    if(playerGlobalBounds.left > nivelActual->getMapa(i,j).left + nivelActual->getMapa(i,j).width -10
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
			for(int a=0; a<nivelActual->getCantidadEnemigos(); a++)
			{
				sf::FloatRect hitBoxEnemigo = _vectorEnemigo[a]->getHitBox();
				
				if (hitBoxEnemigo.intersects(hitBoxMap))
				{
					if (hitBoxEnemigo.top - hitBoxEnemigo.height < hitBoxMap.top)
					{
						_vectorEnemigo[a]->quieto();
					} 
				}
				//Colision enemigo derecha
				if (hitBoxEnemigo.left + hitBoxEnemigo.width <= hitBoxMap.left &&
					hitBoxEnemigo.intersects(hitBoxMapIzq))
				{
					_vectorEnemigo[a]->setDerecha();
				}
				//Colision enemigo Izquierda
				if (hitBoxEnemigo.left > hitBoxMap.left + hitBoxMap.width &&
					hitBoxEnemigo.intersects(hitBoxMapDer))
				{ 
					
					_vectorEnemigo[a]->setIzquierda();
				}
		    }
		}
	}
	if(_personaje->getCajaCuerpo().intersects(_objetoOjo->getCuerpo()))
	{
		_objetoOjo->setPause();
		_personaje->setObjetos(0);
	}
	if(_personaje->getCajaCuerpo().intersects(_objetoLobizon->getCuerpo()))
	{
		_objetoLobizon->setPause();
		_personaje->setObjetos(1);
	}
	for(int i=0; i<nivelActual->getCantidadEnemigos(); i++)
	{
		//Ataque Personaje >> Enemigo
		if(_personaje->getAtacando() == true && _personaje->getCajaAtaque().getGlobalBounds().intersects(_vectorEnemigo[i]->getHitBox()) && _vectorEnemigo[i]->getSalud() >0)
		{
			_vectorEnemigo[i]->setSalud(_personaje->getDanio());
			if(_personaje->getPosicion().x < _vectorEnemigo[i]->getPosition().x)
			{
				_vectorEnemigo[i]->recibiendoDanio(1);
			}
			else
			{
				_vectorEnemigo[i]->recibiendoDanio(2);
			}
		}
		if(_vectorEnemigo[i]->getHitBox().intersects(playerGlobalBounds)&&_vectorEnemigo[i]->getSalud() >0)
		{
			if (clock.getElapsedTime().asSeconds() - _ultimoAtaque >= 1.0f)
			{
				_vectorEnemigo[i]->setAtacando();
				if(_personaje->getPosicion().x < _vectorEnemigo[i]->getPosition().x)
				{
					_personaje->recibiendoDanio(_vectorEnemigo[i]->getDanio(), -35);
				}
				if(_personaje->getPosicion().x > _vectorEnemigo[i]->getPosition().x)
				{
					_personaje->recibiendoDanio(_vectorEnemigo[i]->getDanio(), 35);
				}
				_ultimoAtaque = clock.getElapsedTime().asSeconds();
			}
		}
		if(_boleadora.getCuerpo().intersects(_vectorEnemigo[i]->getHitBox()))
		{
			_vectorEnemigo[i]->setVelocidadCaminata(0.5f);
			
		}
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
			case 9:
				nivel9->dibujar(window);
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
				if(nivel1->getEnemigo()[0]->getSalud() <= 0)
				{
					_objetoOjo->setPosition(nivel1->getEnemigo()[0]->getPosition());
					window.draw(*_objetoOjo);
				}
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
				if(nivel6->getEnemigo()[0]->getSalud() <= 0)
				{
					_objetoLobizon->setPosition(nivel6->getEnemigo()[0]->getPosition());
					window.draw(*_objetoLobizon);
				}
				break;
			case 7:
				nivel7->dibujar(window);
				break;
			case 8:
				nivel8->dibujar(window);
				break;
			case 9:
				if (_personaje->getPosicion().x > 1400) 
				{
					camaraBloqueada = true;
				}
				else if (_personaje->getPosicion().x < 200)
				{
					camaraBloqueada = false;
				}
				if (camaraBloqueada)
				{
					_camaraPrincipal.setCamera(1488, _personaje->getPosicion().y);
				}
				nivel9->dibujar(window);
				
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
