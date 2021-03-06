#include "Game.h"
int frames;

int Game::Width = 0;
int Game::Height = 0;
SDL_Renderer* Game::renderer = nullptr;

Game::Game(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {
	Game::Width = width;
	Game::Height = height;
	std::cout << Game::Width << ", " << Game::Height << '\n';
	camera = new Camera(5);
	std::cout << camera->position.x << ", " << camera->position.y << '\n';
	renderer = nullptr;
	window = nullptr;
	frames = 0;
	uniformGrid = new UniformGrid(5);
	player = new PlayerObject();
	enemy = new PlayerObject();
	mouseX = mouseY = 0;
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
	renderManager = new RenderManager();
	isRunning = false;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window) std::cout << "Window created.\n";

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) std::cout << "Renderer created.\n";
		isRunning = true;

		//SDL_Rect view = { 0, 0, 320, 180 };
		//SDL_RenderSetViewport(renderer, &view);
	}
}

Game::~Game() {

}

void Game::Initialise() {
	player->Initialise(renderer, Vector2(50, 0), Vector2(1, 1));
	enemy->Initialise(renderer, Vector2(0, 0), Vector2(0.5f, 3));
}

void Game::Update() {
	player->Update();
	enemy->Update();
	SDL_GetMouseState(&mouseX, &mouseY);
	player->MoveHorizontal(-50.0f * Time::GetDeltaTime(), enemy->GetBox());
	enemy->SetPosition(Camera::Instance->ScreenToWorldUnits(Vector2(mouseX, mouseY)));
	//enemy->SetPosition(camera->WorldToScreenUnits(Vector2(0, 0)));
	if (!player->GetBox().IsColliding(enemy->GetBox())) {
		//player->Fall(0.1f * Time::GetDeltaTime());
		//enemy->Fall(10 * Time::GetDeltaTime());
		//enemy->SetPosition(camera->WorldToScreenUnits(enemy->GetPos()));
		//player->MoveHorizontal(50.0f * Time::GetDeltaTime());
		//enemy->MoveHorizontal(-50.0f * Time::GetDeltaTime());
	}
	frames++;
}

//This function handles keyboard movement (moving the player and quitting)
void Game::HandleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			isRunning = false;
		}
	}
}

void Game::Render() {
	SDL_SetRenderDrawColor(renderer, 15, 15, 15, 255);	//Set the background colour
	SDL_RenderClear(renderer);							//Clear the render view

	//Add stuff to render here
	renderManager->Render(renderer);
	player->Render(renderer);
	enemy->Render(renderer);

	camera->Render(renderer);

	SDL_RenderPresent(renderer);						//Render the frame
}

//This function is called when the game exits
void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned.\n";
}