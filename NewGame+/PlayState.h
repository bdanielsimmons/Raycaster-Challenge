#pragma once
#include <SDL.h>
#include<SDL_image.h>
#include <vector>
#include "Constants.h"
#include "State.h"
#define mapWidth 24
#define mapHeight 24
#define texWidth 64
#define texHeight 64


class PlayState : public State
{
private:
	double posX, posY, dirX, dirY, planeX, planeY, time, oldTime;
	Uint32 buffer[ScreenHeight][ScreenWidth];
	int choice;
	static PlayState ActivePlayState;
	static SDL_Texture* background;
public:
	PlayState() {
		posX = 22;
		posY = 11.5;
		dirX = -1; 
		dirY = 0;
		planeX = 0;
		planeY = 0.99;
		time = 0;
		oldTime = 0;
	}
	void Init(StateManager* game);
	void Clear();

	void Pause() {};
	void Resume() {};

	void Manage(StateManager* game) {};
	void Update(StateManager* game);
	void Draw(StateManager* game);

	static PlayState* Instance() {
		return &ActivePlayState;
	}
};
