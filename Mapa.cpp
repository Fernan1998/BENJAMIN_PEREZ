#include "Mapa.h"

Mapa::Mapa()
{
	nFilas = 31;
	nColumnas = 60;
	
	_bloque.resize(nFilas);
	for(int i = 0; i < nFilas; i++)
	{
		_bloque[i].resize(nColumnas);
	}
	
	for (int i = 0; i < 20; i++)
	{
		switch (i)
		{
		case 0:
			break;
		case 1:
			_textura[i].loadFromFile("Textura/Mapa/pared_fondo.png");
			break;
		case 2:
			_textura[i].loadFromFile("Textura/Mapa/pared_der.png");
			break;
		case 3:
			_textura[i].loadFromFile("Textura/Mapa/pared_fondo.png");
			break;
		case 4:
			_textura[i].loadFromFile("Textura/Mapa/pared_izq.png");
			break;
		case 5:
			_textura[i].loadFromFile("Textura/Mapa/suelo.png");
			break;
		case 6:
			_textura[i].loadFromFile("Textura/Mapa/suelo_der.png");
			break;
		case 7:
			_textura[i].loadFromFile("Textura/Mapa/suelo_izq.png");
			break;
		case 8:
			_textura[i].loadFromFile("Textura/Mapa/techo.png");
			break;
		case 9:
			_textura[i].loadFromFile("Textura/Mapa/techo_der.png");
			break;
		case 10:
			_textura[i].loadFromFile("Textura/Mapa/techo.png");
			break;
		case 11:
			_textura[i].loadFromFile("Textura/Mapa/fondo1.png");
			break;
		case 12:
			_textura[i].loadFromFile("Textura/Mapa/techo_izq.png");
			break;
		case 13:
			_textura[i].loadFromFile("Textura/Mapa/piedras.png");
			break;
		}
	}
}
Mapa::~Mapa()
{
	
}
sf::Sprite Mapa::getSprite(int i, int j)
{
	return _bloque[i][j];
}

void Mapa::CreadorMapa(std::ifstream& file)
{
	
	int spriteType;
	
	for (int i = 0; i < nFilas; i++) {
		for (int j = 0; j < nColumnas; j++) {
			file >> spriteType;
			switch (spriteType) {
			case 0:
				break;
			case 1:
				_bloque[i][j].setTexture(_textura[1]);
				break;
			case 2:
				_bloque[i][j].setTexture(_textura[2]);
				break;
			case 3:
				_bloque[i][j].setTexture(_textura[3]);
				break;
			case 4:
				_bloque[i][j].setTexture(_textura[4]);
				break;
			case 5:
				_bloque[i][j].setTexture(_textura[5]);
				break;
			case 6:
				_bloque[i][j].setTexture(_textura[6]);
				break;
			case 7:
				_bloque[i][j].setTexture(_textura[7]);
				break;
			case 8:
				_bloque[i][j].setTexture(_textura[8]);
				break;
			case 9:
				_bloque[i][j].setTexture(_textura[9]);
				break;
			case 10:
				_bloque[i][j].setTexture(_textura[10]);
				break;
			case 11:
				_bloque[i][j].setTexture(_textura[11]);
				break;
			case 12:
				_bloque[i][j].setTexture(_textura[12]);
				break;
			case 13:
				_bloque[i][j].setTexture(_textura[13]);
				break;
			}
			_bloque[i][j].setPosition(j * 32, i * 32); 
		}
	}
	file.close();
}




sf::FloatRect Mapa::getOrigen(int i, int j)
{
	return _bloque[i][j].getGlobalBounds();
}
sf::Vector2f Mapa::getPosicion(int i, int j)
{
	return _bloque[i][j].getPosition();
}	
