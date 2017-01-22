#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "StateManager.h"
#include "PlayState.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#undef main

int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	SDL_Window *window = SDL_CreateWindow("Sacred Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	StateManager game;
	game.Init(renderer);
	game.ChangeState(PlayState::Instance());
	SDL_Event Event;
	while (game.Running()) {
		game.Manage();
		game.Update();
		game.Draw();
	}
    return 0;
}

