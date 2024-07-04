#include "Cinematica.h"
#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include <vector>


Cinematica::Cinematica(std::string ruta, int cantFrames)
{
	_ruta = ruta;
	_cantFrames = cantFrames;
}

sf::Texture Cinematica::cargarImagenes(int &i)
{	
	i++;
	sf::Texture aux;
	std::string numRuta;

	while(i<_cantFrames){
		
		if(i < 10)
		{
			numRuta = "00" + std::to_string(i);
		}
		else if(i < 100)
		{
			numRuta = "0" + std::to_string(i);
		}
		else 
		{
			numRuta = std::to_string(i);
		}
		
		std::string rutaCompleta = _ruta + numRuta + ".png";
		if(aux.loadFromFile(rutaCompleta))
		{
			return aux;
		}
		else
		{
			std::cout << "Error al cargar la imagen " << rutaCompleta << std::endl;
		}
	}
	if(i==_cantFrames)exit;
}
