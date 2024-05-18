#pragma once
#include <SFML/Graphics.hpp>

class CamaraPrincipal : public sf::View 
{
	private:
		sf::RenderWindow *window;
		sf::Vector2f windowDimension;
		sf::Vector2f worldDimension;
		sf::Vector2f cameraPosition;
		
		void CalcularPosicion(sf::Vector2f target);
		void MoveCamera();
		
	public:
		CamaraPrincipal(sf::RenderWindow *w, int width, int height, int worldLimitWidth, int worldLimitHeight);
		~CamaraPrincipal();
	void FollowAndUpdate(sf::Vector2f target, CamaraPrincipal *camera);
};
