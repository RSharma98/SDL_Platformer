#include "UniformGrid.h"
#include <iostream>



UniformGrid::UniformGrid(unsigned int gridSize){
	std::vector<BoxCollider2D*>** grid = new std::vector<BoxCollider2D*> * [gridSize];
	for (int i = 0; i < gridSize; i++) grid[i] = new std::vector<BoxCollider2D*>();
	uniformGrid = grid;
}

void UniformGrid::AddToGrid(BoxCollider2D* object){
	int minX = object->GetTopLeft().x;
	int maxX = object->GetBottomRight().x;
	int minY = object->GetBottomRight().y;
	int maxY = object->GetTopLeft().y;
}

void UniformGrid::AddToGrid(std::vector<BoxCollider2D*> objects){
}

void UniformGrid::Render(SDL_Renderer* renderer){
}
