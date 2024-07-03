#include "CamaraPrincipal.h"

CamaraPrincipal::CamaraPrincipal(sf::RenderWindow *w, int width, int height, int worldLimitWidth, int worldLimitHeight)
{
	window = w;
	windowDimension.x = width;
	windowDimension.y = height;
	worldDimension.x = worldLimitWidth;
	worldDimension.y = worldLimitHeight;
	setSize(width, height);
	setCenter(worldLimitWidth / 2, worldLimitHeight / 2);
}
CamaraPrincipal::CamaraPrincipal()
{
	
}
CamaraPrincipal::~CamaraPrincipal()
{
	
}
void CamaraPrincipal::CalcularPosicion(sf::Vector2f target){
	cameraPosition = target;
	if (cameraPosition.x < windowDimension.x / 2) {
		cameraPosition.x = windowDimension.x / 2;
	}
	if (cameraPosition.x > worldDimension.x - windowDimension.x / 2) {
		cameraPosition.x = worldDimension.x - windowDimension.x / 2;
	}
	if (cameraPosition.y < windowDimension.y / 2) {
		cameraPosition.y = windowDimension.y / 2;
	}
	if (cameraPosition.y > worldDimension.y - windowDimension.y / 2) {
		cameraPosition.y = worldDimension.y - windowDimension.y / 2;
	}
}
void CamaraPrincipal::MoveCamera(){
	setCenter(cameraPosition);
}
void CamaraPrincipal::FollowAndUpdate(sf::Vector2f target, CamaraPrincipal *camera) {
	CalcularPosicion(target);
	MoveCamera();
	window->setView(*camera);
}

void CamaraPrincipal::setCamera(int x, int y){
	cameraPosition.x = x;
	cameraPosition.y = y;
	FollowAndUpdate(cameraPosition, this);
	MoveCamera();
}
sf::Vector2f CamaraPrincipal::getCameraPosition(){
	return cameraPosition;
}


