#pragma once
#include <SFML/Graphics.hpp>

class CamaraPrincipal : public sf::View 
{
	private:
		sf::RenderWindow *window;
		sf::Vector2f windowDimension;
		sf::Vector2f worldDimension;
		sf::Vector2f cameraPosition;
		
	public:
		CamaraPrincipal(sf::RenderWindow *w, int width, int height, int worldLimitWidth, int worldLimitHeight);
		CamaraPrincipal();
		~CamaraPrincipal();
		void CalcularPosicion(sf::Vector2f target);
		void MoveCamera();
		void FollowAndUpdate(sf::Vector2f target, CamaraPrincipal *camera);
		
		/// Getters
		sf::Vector2f getCameraPosition();

		/// Setters
		void setCamera(int x, int y);
		
		sf::Vector2f getPosition()
		{
			return sf::Vector2f(cameraPosition.x,cameraPosition.y);
			
		}
};
