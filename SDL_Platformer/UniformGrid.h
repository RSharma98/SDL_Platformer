#ifndef UNIFORMGRID_H
#define UNIFORMGRID_H

#include "BoxCollider2D.h"
#include <vector>

class UniformGrid {
public:
	UniformGrid(unsigned int gridSize);
	void AddToGrid(BoxCollider2D* object);
	void AddToGrid(std::vector<BoxCollider2D*> objects);
	void Render(SDL_Renderer* renderer);
	void CheckCollision(BoxCollider2D* object);

private:
	void UpdateObject(BoxCollider2D* object);
	std::vector<BoxCollider2D*>** uniformGrid;
};
#endif // !UNIFORMGRID_H
