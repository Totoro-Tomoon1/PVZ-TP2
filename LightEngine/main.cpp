
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "SampleScene.h"
#include "PVZScene.h"

#include <cstdlib>
#include <crtdbg.h>

int main() 
{
    GameManager* pInstance = GameManager::Get();

	pInstance->CreateWindow(1280, 720, "SampleScene", 60, sf::Color::Black);
	
	//pInstance->LaunchScene<SampleScene>();
	pInstance->LaunchScene<PVZScene>();

	return 0;
}