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
	
	for (int i = 0; i < 78; i++)
	{
		switch (i)
		{
		case 0:
			break;
		case 1:
			_textura[i].loadFromFile("Textura/Mapa/pared_der.png");
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
			_textura[i].loadFromFile("Textura/Mapa/plataforma0.png");
			break;
		case 13:
			_textura[i].loadFromFile("Textura/Mapa/plataforma1.png");
			break;
		case 14:
			_textura[i].loadFromFile("Textura/Mapa/plataforma2.png");
			break;
		case 15:
			_textura[i].loadFromFile("Textura/Mapa/Cielito.png");
			break;
		case 16:
			_textura[i].loadFromFile("Textura/Mapa/estrellita.png");
			break;
		case 17:
			_textura[i].loadFromFile("Textura/Mapa/techo_der.png");
			break;
		case 18:
			_textura[i].loadFromFile("Textura/Mapa/fondo noche.png");
			break;
		case 19:
			_textura[i].loadFromFile("Textura/Mapa/fondo.png");
			break;
		case 20:
			_textura[i].loadFromFile("Textura/Mapa/fondo1.png");
			break;
		case 21:
			_textura[i].loadFromFile("Textura/Mapa/fondo2.png");
			break;
		case 22:
			_textura[i].loadFromFile("Textura/Mapa/grass.png");
			break;
		case 23:
			_textura[i].loadFromFile("Textura/Mapa/grass_derecha.png");
			break;
		case 24:
			_textura[i].loadFromFile("Textura/Mapa/grass_izquierda.png");
			break;
		case 25:
			_textura[i].loadFromFile("Textura/Mapa/grass1.png");
			break;
		case 26:
			_textura[i].loadFromFile("Textura/Mapa/grass1.png");
			break;
		case 27:
			_textura[i].loadFromFile("Textura/Mapa/Nubecita.png");
			break;
		case 28:
			_textura[i].loadFromFile("Textura/Mapa/piedra_1.png");
			break;
		case 29:
			_textura[i].loadFromFile("Textura/Mapa/piedra_2.png");
			break;
		case 30:
			_textura[i].loadFromFile("Textura/Mapa/piedra_3.png");
			break;
		case 31:
			_textura[i].loadFromFile("Textura/Mapa/piedras.png");
			break;
		case 32:
			_textura[i].loadFromFile("Textura/Mapa/piedritas.png");
			break;
		case 33:
			_textura[i].loadFromFile("Textura/Mapa/solcito.png");
			break;
		case 34:
			_textura[i].loadFromFile("Textura/Mapa/sombreado luna 2.png");
			break;
		case 35:
			_textura[i].loadFromFile("Textura/Mapa/sombreado luna.png");
			break;
		case 36:
			_textura[i].loadFromFile("Textura/Mapa/sprite_00.png");
			break;
		case 37:
			_textura[i].loadFromFile("Textura/Mapa/sprite_01.png");
			break;
		case 38:
			_textura[i].loadFromFile("Textura/Mapa/sprite_02.png");
			break;
		case 39:
			_textura[i].loadFromFile("Textura/Mapa/sprite_03.png");
			break;
		case 40:
			_textura[i].loadFromFile("Textura/Mapa/sprite_04.png");
			break;
		case 41:
			_textura[i].loadFromFile("Textura/Mapa/sprite_05.png");
			break;
		case 42:
			_textura[i].loadFromFile("Textura/Mapa/sprite_06.png");
			break;
		case 43:
			_textura[i].loadFromFile("Textura/Mapa/sprite_07.png");
			break;
		case 44:
			_textura[i].loadFromFile("Textura/Mapa/sprite_08.png");
			break;
		case 45:
			_textura[i].loadFromFile("Textura/Mapa/sprite_09.png");
			break;
		case 46:
			_textura[i].loadFromFile("Textura/Mapa/sprite_10.png");
			break;
		case 47:
			_textura[i].loadFromFile("Textura/Mapa/sprite_11.png");
			break;
		case 48:
			_textura[i].loadFromFile("Textura/Mapa/plataforma0.png");
			break;
		case 52:
			_textura[i].loadFromFile("Textura/Mapa/agua_grande.png");
			break;
		case 53:
			_textura[i].loadFromFile("Textura/Mapa/agua_mediana.png");
			break;
		case 54:
			_textura[i].loadFromFile("Textura/Mapa/agua_petisa.png");
			break;
		case 55:
			_textura[i].loadFromFile("Textura/Mapa/barro_central.png");
			break;
		case 56:
			_textura[i].loadFromFile("Textura/Mapa/barro_derecho.png");
			break;
		case 57:
			_textura[i].loadFromFile("Textura/Mapa/barro_izquierdo.png");
			break;
		case 58:
			_textura[i].loadFromFile("Textura/Mapa/plataforma_barro_central.png");
			break;
		case 59:
			_textura[i].loadFromFile("Textura/Mapa/plataforma_barro_derecho.png");
			break;
		case 60:
			_textura[i].loadFromFile("Textura/Mapa/plataforma_barro_izquierdo.png");
			break;
		case 61:
			_textura[i].loadFromFile("Textura/Mapa/plataforma_barro_izquierdo.png");
			break;
		case 65:
			_textura[i].loadFromFile("Textura/Mapa/montanita.png");
			break;
		case 66:
			_textura[i].loadFromFile("Textura/Mapa/luna_infernal.png");
			break;
		case 67:
			_textura[i].loadFromFile("Textura/Mapa/sombreado_luna_infernal.png");
			break;
		case 68:
			_textura[i].loadFromFile("Textura/Mapa/sombreado_luna_infernal2.png");
			break;
		case 69:
			_textura[i].loadFromFile("Textura/Mapa/infernal1.png");
			break;
		case 70:
			_textura[i].loadFromFile("Textura/Mapa/infernal2.png");
			break;
		case 71:
			_textura[i].loadFromFile("Textura/Mapa/infernal3.png");
			break;
		case 72:
			_textura[i].loadFromFile("Textura/Mapa/infernal4.png");
			break;
		case 73:
			_textura[i].loadFromFile("Textura/Mapa/infernal5.png");
			break;
		case 74:
			_textura[i].loadFromFile("Textura/Mapa/infernal6.png");
			break;
		case 75:
			_textura[i].loadFromFile("Textura/Mapa/infernal7.png");
			break;
		case 76:
			_textura[i].loadFromFile("Textura/Mapa/agua_grande1.png");
			break;
		case 77:
			_textura[i].loadFromFile("Textura/Mapa/agua_dia.png");
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
int Mapa::solicitarNumero(int i, int j)
{
	return _script[i][j];
}
void Mapa::CreadorMapa(std::ifstream& file)
{
	
	int spriteType;
	
	for (int i = 0; i < nFilas; i++)
	{
		for (int j = 0; j < nColumnas; j++)
		{
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
			case 14:
				_bloque[i][j].setTexture(_textura[14]);
				break;
			case 15:
				_bloque[i][j].setTexture(_textura[15]);
				break;
			case 16:
				_bloque[i][j].setTexture(_textura[16]);
				break;
			case 17:
				_bloque[i][j].setTexture(_textura[17]);
				break;
			case 18:
				_bloque[i][j].setTexture(_textura[18]);
				break;
			case 19:
				_bloque[i][j].setTexture(_textura[19]);
				break;
			case 20:
				_bloque[i][j].setTexture(_textura[20]);
				break;
			case 21:
				_bloque[i][j].setTexture(_textura[21]);
				break;
			case 22:
				_bloque[i][j].setTexture(_textura[22]);
				break;
			case 23:
				_bloque[i][j].setTexture(_textura[23]);
				break;
			case 24:
				_bloque[i][j].setTexture(_textura[24]);
				break;
			case 25:
				_bloque[i][j].setTexture(_textura[25]);
				break;
			case 26:
				_bloque[i][j].setTexture(_textura[26]);
				break;
			case 27:
				_bloque[i][j].setTexture(_textura[27]);
				break;
			case 28:
				_bloque[i][j].setTexture(_textura[28]);
				break;
			case 29:
				_bloque[i][j].setTexture(_textura[29]);
				break;
			case 30:
				_bloque[i][j].setTexture(_textura[30]);
				break;
			case 31:
				_bloque[i][j].setTexture(_textura[31]);
				break;
			case 32:
				_bloque[i][j].setTexture(_textura[32]);
				break;
			case 33:
				_bloque[i][j].setTexture(_textura[33]);
				break;
			case 34:
				_bloque[i][j].setTexture(_textura[34]);
				break;
			case 35:
				_bloque[i][j].setTexture(_textura[35]);
				break;
			case 36:
				_bloque[i][j].setTexture(_textura[36]);
				break;
			case 37:
				_bloque[i][j].setTexture(_textura[37]);
				break;
			case 38:
				_bloque[i][j].setTexture(_textura[38]);
				break;
			case 39:
				_bloque[i][j].setTexture(_textura[39]);
				break;
			case 40:
				_bloque[i][j].setTexture(_textura[40]);
				break;
			case 41:
				_bloque[i][j].setTexture(_textura[41]);
				break;
			case 42:
				_bloque[i][j].setTexture(_textura[42]);
				break;
			case 43:
				_bloque[i][j].setTexture(_textura[43]);
				break;
			case 44:
				_bloque[i][j].setTexture(_textura[44]);
				break;
			case 45:
				_bloque[i][j].setTexture(_textura[45]);
				break;
			case 46:
				_bloque[i][j].setTexture(_textura[46]);
				break;
			case 47:
				_bloque[i][j].setTexture(_textura[47]);
				break;
			case 48:
				_bloque[i][j].setTexture(_textura[48]);
				break;
			case 49:
				_bloque[i][j].setTexture(_textura[49]);
				break;
			case 50:
				_bloque[i][j].setTexture(_textura[50]);
				break;
			case 51:
				_bloque[i][j].setTexture(_textura[51]);
				break;
			case 52:
				_bloque[i][j].setTexture(_textura[52]);
				break;
			case 53:
				_bloque[i][j].setTexture(_textura[53]);
				break;
			case 54:
				_bloque[i][j].setTexture(_textura[54]);
				break;
			case 55:
				_bloque[i][j].setTexture(_textura[55]);
				break;
			case 56:
				_bloque[i][j].setTexture(_textura[56]);
				break;
			case 57:
				_bloque[i][j].setTexture(_textura[57]);
				break;
			case 58:
				_bloque[i][j].setTexture(_textura[58]);
				break;
			case 59:
				_bloque[i][j].setTexture(_textura[59]);
				break;
			case 60:
				_bloque[i][j].setTexture(_textura[60]);
				break;
			case 61:
				_bloque[i][j].setTexture(_textura[61]);
				break;
			case 62:
				_bloque[i][j].setTexture(_textura[65]);
				break;
			case 63:
				_bloque[i][j].setTexture(_textura[66]);
				break;
			case 64:
				_bloque[i][j].setTexture(_textura[67]);
				break;
			case 65:
				_bloque[i][j].setTexture(_textura[68]);
				break;
			case 66:
				_bloque[i][j].setTexture(_textura[66]);
				break;
			case 67:
				_bloque[i][j].setTexture(_textura[67]);
				break;
			case 68:
				_bloque[i][j].setTexture(_textura[68]);
				break;
			case 69:
				_bloque[i][j].setTexture(_textura[69]);
				break;
			case 70:
				_bloque[i][j].setTexture(_textura[70]);
				break;
			case 71:
				_bloque[i][j].setTexture(_textura[71]);
				break;
			case 72:
				_bloque[i][j].setTexture(_textura[72]);
				break;
			case 73:
				_bloque[i][j].setTexture(_textura[73]);
				break;
			case 74:
				_bloque[i][j].setTexture(_textura[74]);
				break;
			case 75:
				_bloque[i][j].setTexture(_textura[75]);
				break;
			case 76:
				_bloque[i][j].setTexture(_textura[76]);
				break;
			case 77:
				_bloque[i][j].setTexture(_textura[77]);
				break;
				
			}
			_bloque[i][j].setPosition(j * 32, i * 32);
			switch(spriteType)
			{
				case 100:
					_script[i][j] = 0;
					break;
				case 101:
					_script[i][j] = 1;
					break;
				case 102:
					_script[i][j] = 2;
					break;
			}
			
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
