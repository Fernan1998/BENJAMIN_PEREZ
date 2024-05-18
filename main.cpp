#include <SFML/Graphics.hpp>

int main(int argc, char *argv[]){
	sf::RenderWindow ventana(sf::VideoMode(1024,768),"BENJAMIN PEREZ");
	
	while(ventana.isOpen()) {
		sf::Event e;
		while(ventana.pollEvent(e)) {
			if(e.type == sf::Event::Closed)
				ventana.close();	
		}
		
		ventana.clear();
		
		ventana.display();
	}
	return 0;
}

