#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include "Time.h"
#include <iostream>
#include "Camera.h"
#include "RenderManager.h"
#include "PlayerObject.h"
#include "UniformGrid.h"

class Game {
public:
	Game(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	~Game();

	void Initialise();
	void Update();
	void HandleEvents();
	void Render();
	void Clean();
	bool Running() { return isRunning; }

	static SDL_Renderer* renderer;
	static int Width, Height;

private:
	bool isRunning = false;
	bool isMainMenu = true;
	SDL_Window* window;
	static int m_Width, m_Height;
	int mouseX, mouseY;

	UniformGrid* uniformGrid;
	RenderManager* renderManager;
	Camera* camera;
	PlayerObject* player;
	PlayerObject* enemy;
};

#endif // !GAME_H