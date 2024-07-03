#include "Gameplay.h"
#include <iostream>

Gameplay::Gameplay(CamaraPrincipal &camaraPrincipal) : _boleadora("boleadora.png")
{
	numeroMapa = 1;	
	
	_camaraPrincipal = camaraPrincipal;
	
	_personaje = new Personaje();
	
	_objetoOjo = new Objetos(51,25, "Textura/Objetos/ojoBabosa.png");
	_objetoLobizon = new Objetos(68,48, "Textura/Objetos/objetoLobizon.png");
	_cabezaDiablo = new Objetos(51,40, "Textura/Objetos/objetoDiablo.png");
	_cabezaPombero = new Objetos(69,53, "Textura/Objetos/objetoPombero1.png");
	_objetoLuz = new Objetos(56,52,"Textura/Objetos/objetoLuz.png");
	
	cinematicaPersonaje = new  Cinematica("dia_noche/dia_noche", 251);
	nocheADia = new  Cinematica("noche_dia/noche_dia", 125);
	introJuego = new  Cinematica("intro/intro", 360);
	cinematicaDesaparece = new Cinematica("desaparece/desaparece", 75);
	cinematicaDerrumbe = new Cinematica("derrumbe/aaa",167);
	
	
	nivel1 = new Nivel("Mapas_txt/mapa_tutorial/mapa_tutorial_piso.txt", "Mapas_txt/mapa_tutorial/mapa_tutorial_fondo.txt", "Mapas_txt/mapa_tutorial/mapa_tutorial_plataforma.txt", "Sonido/Folklore.ogg", 1);
	nivel1->creadorDeEnemigos(100, 10, "Textura/Babosa/Baboscompleta.png", 63, 84, 84, 800, 3, 8);
	
	nivel2 = new Nivel("Mapas_txt/mapa_agujero/mapa_noche.txt", "Mapas_txt/mapa_agujero/fondo_noche.txt", "Mapas_txt/mapa_agujero/mapa_tutorial_relleno.txt", "Sonido/Folklore.ogg", 0);
	
	nivel10 = new Nivel("Mapas_txt/mapa_agujero/mapa_noche2.txt", "Mapas_txt/mapa_agujero/fondo_noche.txt", "Mapas_txt/mapa_agujero/mapa_tutorial_relleno.txt", "Sonido/Folklore.ogg", 2);
	nivel10->creadorDeEnemigos(100, 25, "Textura/Wolf/idle.png", 170, 160, 84, 800, 3, 10);
	
	nivel3 = new Nivel("Mapas_txt/mapa_luz_mala/mapa_luz_mala_piso.txt", "Mapas_txt/mapa_luz_mala/fondo_noche.txt", "Mapas_txt/mapa_luz_mala/mapa_luz_mala_agua.txt", "Sonido/Folklore.ogg", 1);
	nivel3->creadorDeEnemigos(100, 100, "Textura/Luz Mala/luzmala.png", 98, 98, 1000, 1000, 3, 8);
	
	nivel12 = new Nivel("Mapas_txt/mapa_luz_mala/mapa_luz_mala_dia.txt", "Mapas_txt/mapa_luz_mala/fondo_dia.txt", "Mapas_txt/mapa_luz_mala/mapa_luz_mala_plataformas.txt", "Sonido/Folklore.ogg", 0);
	
	nivel4 = new Nivel("Mapas_txt/mapa_cueva_1/mapa_cueva1.txt", "Mapas_txt/mapa_cueva_1/mapa_cueva1_fondo.txt", "Mapas_txt/mapa_cueva_1/mapa_cueva1_plataformas.txt", "Sonido/Folklore.ogg", 2);
	nivel4->creadorDeEnemigos(100, 10, "Textura/Wolf/idle.png", 170, 160, 84, 800, 3, 10);
	
	nivel5 = new Nivel("Mapas_txt/mapa_cueva_2/mapa_cueva2.txt", "Mapas_txt/mapa_cueva_2/mapa_cueva2_fondo.txt", "Mapas_txt/mapa_cueva_2/mapa_cueva2_plataformas.txt", "Sonido/Folklore.ogg", 2);
	nivel5->creadorDeEnemigos(100, 25, "Textura/Wolf/idle.png", 170, 160, 84, 800, 4, 10);
	
	nivel6 = new Nivel("Mapas_txt/mapa_cueva_3/mapa_cueva3.txt", "Mapas_txt/mapa_cueva_3/mapa_cueva3_fondo.txt", "Mapas_txt/mapa_cueva_3/mapa_cueva3_plataformas.txt", "Sonido/Folklore.ogg", 3);
	nivel6->creadorDeEnemigos(100, 25, "Textura/Wolf/idle.png", 170, 160, 84, 800, 3, 10);
	nivel6->getEnemigo()[0]->setArmadura(2.5);
	
	nivel7 = new Nivel("Mapas_txt/mapa_infierno/infernal_piso.txt", "Mapas_txt/mapa_infierno/infernal_fondo.txt", "Mapas_txt/mapa_infierno/infernal_relleno.txt", "Sonido/Folklore.ogg", 1);
	nivel7->creadorDeEnemigos(100, 25, "Textura/Diablo/Diablo2b.png", 89, 128, 84, 800, 3, 7);
	
	nivel11 = new Nivel("Mapas_txt/mapa_infierno/infernal_piso.txt", "Mapas_txt/mapa_infierno/infernal_fondo.txt", "Mapas_txt/mapa_infierno/infernal_relleno.txt", "Sonido/Folklore.ogg", 1);
	nivel11->creadorDeEnemigos(100, 50, "Textura/Diablo/Diablo.png", 327, 245, 84, 800, 3, 8);
	nivel11->getEnemigo()[0]->setArmadura(3);
	
	nivel8 = new Nivel("Mapas_txt/mapa_montania/noche_piso_montania.txt", "Mapas_txt/mapa_montania/noche_fondo_montania.txt", "Mapas_txt/mapa_montania/noche_relleno_montania.txt", "Sonido/Folklore.ogg", 0);
	
	nivel9 = new Nivel("Mapas_txt/mapa_pombero/pombero_piso.txt", "Mapas_txt/mapa_pombero/pombero_fondo.txt", "Mapas_txt/mapa_pombero/pombero_plataforma.txt", "Sonido/Folklore.ogg", 1);
	nivel9->creadorDeJefes(100, 25, "Textura/Pombero/Pombero2.png", 98, 98, 50, 2000, 1, 6);
	nivel9->getEnemigo()[0]->setArmadura(1);
	
	listaNiveles[0] = nivel1;
	listaNiveles[1] = nivel2;
	listaNiveles[2] = nivel3;
	listaNiveles[3] = nivel4;
	listaNiveles[4] = nivel5;
	listaNiveles[5] = nivel6;
	listaNiveles[6] = nivel7;
	listaNiveles[7] = nivel8;
	listaNiveles[8] = nivel9;
	listaNiveles[9] = nivel10;
	listaNiveles[10] = nivel11;
	listaNiveles[11] = nivel12;
	
	nivel1->reiniciarNivel(sf::Vector2f(1735,700), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
	nivel2->reiniciarNivel(sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
	nivel3->reiniciarNivel(sf::Vector2f(-300,772), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
	nivel4->reiniciarNivel(sf::Vector2f(1500,260), sf::Vector2f(1341,700), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
	nivel5->reiniciarNivel(sf::Vector2f(650,750), sf::Vector2f(1680,260), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
	nivel6->reiniciarNivel(sf::Vector2f(250,240), sf::Vector2f(800,800), sf::Vector2f(1000,500), sf::Vector2f(0,0), 100);
	nivel7->reiniciarNivel(sf::Vector2f(950,700), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
	nivel8->reiniciarNivel(sf::Vector2f(1200,700), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
	nivel9->reiniciarNivel(sf::Vector2f(1800, 100), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
	nivel10->reiniciarNivel(sf::Vector2f(1735,700), sf::Vector2f(1100,700), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
	nivel11->reiniciarNivel(sf::Vector2f(1800,450), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
	nivel12->reiniciarNivel(sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
		
	_aux.setPosition(sf::Vector2f(0, 224));
	_aux.setSize(sf::Vector2f(1024, 768));	
	_boleadora.setPosition(_personaje->getPosicion());
	_boleando = false;
	
	texTutorial.loadFromFile("Textura/Tutorial/tutorial.png");
	_tutorial.setTexture(&texTutorial);
	_tutorial.setSize(sf::Vector2f(3072, 768));
	_tutorial.setPosition(sf::Vector2f(25, 170));
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
	nivel6->getEnemigo()[0]->setColor(sf::Color::Red);
	_camaraPrincipal.FollowAndUpdate(_personaje->getPosicion(), &_camaraPrincipal);
	ponerPausa();
	for(int i=0; i<3; i++)
	{
		std::cout<<_personaje->getObjetos(i)<<std::endl;
	
	}


	if (!pausa)
	{
		_personaje->actualizar(deltaTime);
		
		switch(numeroMapa)
		{
			case 1:
				nivel1->actualizar(deltaTime);
				texAux = introJuego->cargarImagenes(i);
				_aux.setTexture(&texAux);
				_objetoOjo->actualizar(deltaTime);
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
				_objetoLobizon->actualizar(deltaTime);
				break;
			case 7:
				nivel7->actualizar(deltaTime);
				_cabezaDiablo->actualizar(deltaTime);
				break;
			case 8:
				nivel8->actualizar(deltaTime);
				break;
			case 9:
				nivel9->actualizar(deltaTime);
				_cabezaPombero->actualizar(deltaTime);
				break;
			case 10:
				nivel10->actualizar(deltaTime);
				texAux = cinematicaDerrumbe->cargarImagenes(i);
				_aux.setTexture(&texAux);
				break;
			case 11:
				nivel11->actualizar(deltaTime);
				break;
			case 12:
				nivel12->actualizar(deltaTime);
				texAux = nocheADia->cargarImagenes(i);
				_aux.setTexture(&texAux);
				_objetoLuz->actualizar(deltaTime);
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
				_boleadora.setPosition(sf::Vector2f(_personaje->getPosicion().x,_personaje->getPosicion().y-20));
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
				_boleadora.setPosition(sf::Vector2f(_personaje->getPosicion().x,_personaje->getPosicion().y-20));
				_boleadora.setColor(sf::Color::Transparent);
			}
			
		}	
	}
	else
	{
		_boleadora.setColor(sf::Color::Transparent);
		_boleadora.setPosition(sf::Vector2f(_personaje->getPosicion().x,_personaje->getPosicion().y-20));
	}
}

void Gameplay::cambioEscena()
{
	if(numeroMapa == 1)
	{
		if(_personaje->getPosicion().x >= 1920)
		{
			numeroMapa = 2;
			i=0;
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
	if(numeroMapa == 10)
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

	}
	if(numeroMapa == 3)
	{
		if(!_personaje->getObjetos(1))
		{
			if(_personaje->getPosicion().x <= 0)
			{
				numeroMapa = 2;
				_personaje->setPosicion(1900,_personaje->getPosicion().y);
			}
		}
		else
		{
			if(_personaje->getPosicion().x <= 0)
			{
				numeroMapa = 10;
				_personaje->setPosicion(1900,_personaje->getPosicion().y);
			}
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
			i=0;
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
	if(numeroMapa == 12)
	{
		if(_personaje->getPosicion().x <= 0)
		{
			numeroMapa = 10;
			_personaje->setPosicion(1900,_personaje->getPosicion().y);
		}
		if(_personaje->getPosicion().x == 1920)
		{
			numeroMapa = 8;
			_personaje->setPosicion(20,_personaje->getPosicion().y);
		}
		if(_personaje->getPosicion().y >= 980)
		{
			_personaje->recibiendoDanio(100, 0);
		}
		
	}
	if(numeroMapa == 8)
	{
		if(_personaje->getPosicion().x <= 0 && !_personaje->getObjetos(2))
		{
			numeroMapa = 3;
			_personaje->setPosicion(1900,_personaje->getPosicion().y);
		}
		else if(_personaje->getPosicion().x <= 0 && _personaje->getObjetos(2))
		{
			numeroMapa = 12;
			_personaje->setPosicion(1900,_personaje->getPosicion().y);
		}
		if(_personaje->getPosicion().x >= 1920 && !_personaje->getObjetos(2))
		{
			numeroMapa = 9;
			_personaje->setPosicion(20,_personaje->getPosicion().y);
		}
		else if(_personaje->getPosicion().x >= 1920 && _personaje->getObjetos(2))
		{
			_personaje->setPosicion(1920,_personaje->getPosicion().y);
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
	if(numeroMapa == 11)
	{
		if(_personaje->getPosicion().x <= 0)
		{
			_personaje->setPosicion(0,_personaje->getPosicion().y);
		}
	}
	if(numeroMapa == 7)
	{
		if(_personaje->getPosicion().x <= 0)
		{
			_personaje->setPosicion(0,_personaje->getPosicion().y);
		}
	}
	if(_personaje->getSalud()<=0)
	{
		if(numeroMapa != 9 && numeroMapa != 1 && numeroMapa != 7 && numeroMapa != 11 )
		{

			
			nivel2->reiniciarNivel(sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
			nivel3->reiniciarNivel(sf::Vector2f(-300,772), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);			
			nivel4->reiniciarNivel(sf::Vector2f(1500,260), sf::Vector2f(1341,700), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
			nivel5->reiniciarNivel(sf::Vector2f(650,700), sf::Vector2f(1680,260), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
			nivel6->reiniciarNivel(sf::Vector2f(250,240), sf::Vector2f(800,800), sf::Vector2f(1000,500), sf::Vector2f(0,0), 100);
		
			nivel8->reiniciarNivel(sf::Vector2f(1200,700), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
			
			nivel10->reiniciarNivel(sf::Vector2f(1735,700), sf::Vector2f(1100,700), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
		
			
			
			
			if(!_personaje->getObjetos(1))
			{
				_personaje->reiniciar(sf::Vector2f(100,750));
				numeroMapa = 2;
			}
			else
			{
				_personaje->reiniciar(sf::Vector2f(100,750));
				numeroMapa = 10;
			}
		
		}
		else if(numeroMapa == 9)
		{
			nivel9->reiniciarNivel(sf::Vector2f(1800, 100), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);;
			_personaje->reiniciar(sf::Vector2f(100,750));
			numeroMapa = 9;
		}
		else if(numeroMapa == 1)
		{
			nivel1->reiniciarNivel(sf::Vector2f(1735,700), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
			_personaje->reiniciar(sf::Vector2f(100,750));
			numeroMapa = 1;
		}
		else if(numeroMapa == 7)
		{
			nivel7->reiniciarNivel(sf::Vector2f(950,700), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
			_personaje->reiniciar(sf::Vector2f(100,750));
			numeroMapa = 7;
		}
		else if(numeroMapa == 11)
		{
			nivel11->reiniciarNivel(sf::Vector2f(1800,450), sf::Vector2f(0,0), sf::Vector2f(0,0), sf::Vector2f(0,0), 100);
			_personaje->reiniciar(sf::Vector2f(100,750));
			numeroMapa = 11;
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
		case 10:
			nivel10->comando(*_personaje);
			break;
		case 11:
			   nivel11->comando(*_personaje);
			break;
		case 12:
			nivel12->comando(*_personaje);
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
				sf::FloatRect hitBoxPiesJefe(_vectorEnemigo[a]->getHitBox().left,_vectorEnemigo[a]->getHitBox().top+90,_vectorEnemigo[a]->getHitBox().width,_vectorEnemigo[a]->getHitBox().height -90);
				
				if (hitBoxEnemigo.intersects(hitBoxMap))
				{
					if (hitBoxEnemigo.top - hitBoxEnemigo.height < hitBoxMap.top)
					{
						_vectorEnemigo[a]->quieto();
					} 
				}
				
				if(_vectorEnemigo[a]->soyEnemigo() == false)
				{
					if (hitBoxPiesJefe.intersects(hitBoxMapPlatform))
					{
						if (hitBoxEnemigo.top - hitBoxEnemigo.height < hitBoxMapPlatform.top)
						{
							_vectorEnemigo[a]->quieto();
						} 
					}
					if(_vectorEnemigo[a]->devolver().intersects(_personaje->getCajaCuerpo()))
					{
						_personaje->recibiendoDanio(100, 1);
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
	if(_personaje->getCajaCuerpo().intersects(_objetoLobizon->getCuerpo()) && !_objetoLobizon->getPause())
	{
		_objetoLobizon->setPause();
		_personaje->setObjetos(1);
		_personaje->setPosicion(100, 780);
		numeroMapa = 10;
	}
	if(_personaje->getCajaCuerpo().intersects(_cabezaDiablo->getCuerpo()) && !_cabezaDiablo->getPause())
	{
		i=0;
		texAux = cinematicaDesaparece->cargarImagenes(i);
		_aux.setTexture(&texAux);
		_cabezaDiablo->setPause();
		_personaje->setObjetos(3);
		numeroMapa = 11;
	}
	if(_personaje->getCajaCuerpo().intersects(_cabezaPombero->getCuerpo()) && !_cabezaPombero->getPause())
	{
		_cabezaPombero->setPause();
		_personaje->setObjetos(2);
		_personaje->setPosicion(1850, 780);
		numeroMapa = 8;		
	}
	for(int i=0; i<nivelActual->getCantidadEnemigos(); i++)
	{
		//Ataque Personaje >> Enemigo
		if(_personaje->getAtacando() == true && _personaje->getCajaAtaque().getGlobalBounds().intersects(_vectorEnemigo[i]->getHitBox()) && _vectorEnemigo[i]->getSalud() >0)
		{
			_vectorEnemigo[i]->setSalud(_personaje->getDanio()/_vectorEnemigo[i]->getArmadura());
			if(_personaje->getPosicion().x < _vectorEnemigo[i]->getPosition().x)
			{
				_vectorEnemigo[i]->recibiendoDanio(1);
			}
			else
			{
				_vectorEnemigo[i]->recibiendoDanio(2);
			}
		}
		if(_vectorEnemigo[i]->getHitBox().intersects(playerGlobalBounds)&&_vectorEnemigo[i]->getSalud() >0 && _vectorEnemigo[i]->soyEnemigo())
		{
			if (clock.getElapsedTime().asSeconds() - _ultimoAtaque >= 2.0f)
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
	if (numeroMapa == 3 && _vectorEnemigo[0]->getPosition().y > 772) {
		_vectorEnemigo[0]->setPosition(sf::Vector2f(_vectorEnemigo[0]->getPosition().x, 772));
	}
	if (numeroMapa == 3) {
		_vectorEnemigo[0]->setVelocidadCaminata(4.3);
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
			case 10:
				nivel10->dibujar(window);
				break;
			case 11:
				nivel11->dibujar(window);
				break;
			case 12:
				nivel12->dibujar(window);
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
				
				if(i<=360)
				{
					window.draw(_aux);
					_personaje->modoPausa();
				}else{window.draw(_tutorial);}
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
				if(nivel7->getEnemigo()[0]->getSalud() <= 0)
				{
					_cabezaDiablo->setPosition(nivel7->getEnemigo()[0]->getPosition());
					window.draw(*_cabezaDiablo);
				}
				break;
			case 8:
				nivel8->dibujar(window);
				break;
			case 9:
				if (_personaje->getPosicion().x > 900) 
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
					if (_personaje->getPosicion().x < 916) {
						_personaje->setPosicion(916, _personaje->getPosicion().y);
					}
				}
				nivel9->dibujar(window);
				if(nivel9->getEnemigo()[0]->getSalud() <= 0)
				{
					_cabezaPombero->setPosition(nivel9->getEnemigo()[0]->getPosition());
					window.draw(*_cabezaPombero);
				}
				break;
			case 10:
				nivel10->dibujar(window);
				if(i<=167)
				{
					window.draw(_aux);
					_personaje->modoPausa();
				}
				break;
			case 11:
				nivel11->dibujar(window);
				if(i<=74)
				{
					window.draw(_aux);
					_personaje->modoPausa();
				}
				if(nivel11->getEnemigo()[0]->getSalud() <= 50)
				{
					nivel11->getEnemigo()[0]->setColor(sf::Color::Red);
				}
				break;
			case 12:
				nivel12->dibujar(window);
				if(i<=125)
				{
					window.draw(_aux);
					_personaje->modoPausa();
				}
				_objetoLuz->setPosition(sf::Vector2f(1800.0f,800.0f));
				window.draw(*_objetoLuz);
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
