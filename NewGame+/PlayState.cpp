#include <SDL.h>
#include <SDL_image.h>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include "PlayState.h"
#include "PauseState.h"

int worldMap1[mapWidth][mapHeight] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1 },
	{ 1,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1 },
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
	{ 1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1 },
	{ 1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,1,0,0,0,1,1,1,1 },
	{ 1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1 },
	{ 1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1 },
	{ 1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
	{ 1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,1,1,1,1,1,0,1,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};

int worldMap2[mapWidth][mapHeight] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1 },
	{ 1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1 },
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
	{ 1,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1 },
	{ 1,0,1,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1 },
	{ 1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1 },
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
	{ 1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,1 },
	{ 1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,1,1 },
	{ 1,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,1,0,1,1 },
	{ 1,0,0,0,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};


int worldMap3[mapWidth][mapHeight] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1 },
	{ 1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1 },
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1 },
	{ 1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1 },
	{ 1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1 },
	{ 1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0 },
	{ 1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,1,1,0,0 },
	{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,0,0 },
	{ 1,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1 },
	{ 1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,1 },
	{ 1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,1,1 },
	{ 1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1 },
	{ 1,1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,1,1,0,1,1 },
	{ 1,1,1,1,1,0,0,0,0,1,1,0,0,1,0,0,1,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0,1,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};


int worldMap4[mapWidth][mapHeight] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1 },
	{ 1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1 },
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
	{ 1,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1 },
	{ 1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,1,1,1,1 },
	{ 1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1 },
	{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
	{ 1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1 },
	{ 1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,1,0,0,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1 },
	{ 1,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1 },
	{ 1,0,0,1,0,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,1,0,1,1 },
	{ 1,0,1,0,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};


void renderTexture(SDL_Texture*, SDL_Renderer*, int, int);
SDL_Texture* loadTexture(const std::string &, SDL_Renderer*);

SDL_Texture* PlayState::background;
PlayState PlayState::ActivePlayState;

void PlayState::Init(StateManager* game) {
	SDL_Texture* bg = loadTexture("test.bmp", game->SMRender);
	background = bg;
	std::srand(std::time(0));
	choice = rand() % 4;
}

void PlayState::Clear() {
	
}

void PlayState::Update(StateManager* game) {
	auto keys = SDL_GetKeyboardState(NULL);
	for (int x = 0; x < ScreenWidth; x++)
	{
		double cameraX = 2 * x / double(ScreenWidth) - 1;
		double rayPosX = posX;
		double rayPosY = posY;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;
		int mapX = int(rayPosX);
		int mapY = int(rayPosY);
		double sideDistX;
		double sideDistY;
		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;

		int stepX;
		int stepY;
		int hit = 0; //Touching a wall?
		int side; //Member of the walls to determine shadowpoints

		//calculate step and initial sideDist
		if (rayDirX < 0) {
			stepX = -1;
			sideDistX = (rayPosX - mapX) * deltaDistX;
		}
		else {
			stepX = 1;
			sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
		}
		if (rayDirY < 0) {
			stepY = -1;
			sideDistY = (rayPosY - mapY) * deltaDistY;
		}
		else {
			stepY = 1;
			sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
		}

		//Algorithm to detect hits
		while (hit == 0)
		{
			//advances square by square until hit is confirmed
			if (sideDistX < sideDistY) {
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else {
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			switch (choice) {
			case 0:  if (worldMap1[mapX][mapY] > 0) hit = 1;  break; 
			case 1: if (worldMap2[mapX][mapY] > 0) hit = 1;  break; 
			case 2: if (worldMap3[mapX][mapY] > 0) hit = 1; break; 
			case 3:  if (worldMap4[mapX][mapY] > 0) hit = 1; break; 
			default: if (worldMap1[mapX][mapY] > 0) hit = 1; break; 
			}
			
		}

		//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
		if (side == 0)
			perpWallDist = fabs((mapX - rayPosX + (1 - stepX) / 2) / rayDirX);
		else
			perpWallDist = fabs((mapY - rayPosY + (1 - stepY) / 2) / rayDirY);

		//Calculate height of line to draw on screen
		int lineHeight = abs(int(ScreenHeight / perpWallDist));

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + ScreenHeight / 2;
		if (drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + ScreenHeight / 2;
		if (drawEnd >= ScreenHeight) drawEnd = ScreenHeight - 1;

		SDL_Color color = { 255, 0, 0 };
		 //Changes colors based on distance from wall
		if (side == 1) {
			color.r /= sideDistY;
			color.g /= sideDistY;
			color.b /= sideDistY;
		}
		else {
			color.r /= 1.30;
			color.g /= 1.30;
			color.b /= 1.30;
		}
		SDL_SetRenderDrawColor(game->SMRender, color.r, color.g, color.b, 255);
		SDL_RenderDrawLine(game->SMRender, x, drawStart, x, drawEnd);
	}
		oldTime = time;
		time = SDL_GetTicks();
		double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
		//std::cout << (1.0 / frameTime); //FPS counter
		SDL_RenderPresent(game->SMRender);
		SDL_SetRenderDrawColor(game->SMRender, 245, 220, 220, 255);
		SDL_RenderClear(game->SMRender);

		//speed modifiers
		double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
		double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

		//move forward if no wall in front of you
		if (keys[SDL_SCANCODE_UP])
		{
			switch (choice) {
			case 0:
				if (worldMap1[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
				if (worldMap1[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
				break;
			case 1:
				if (worldMap2[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
				if (worldMap2[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
				break; //green
			case 2:
				if (worldMap3[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
				if (worldMap3[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
				break; //blue
			case 3:
				if (worldMap4[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
				if (worldMap4[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
				break; //white
			default:
				if (worldMap1[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
				if (worldMap1[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
				break;
			}
		}
		//move backwards if no wall behind you
		if (keys[SDL_SCANCODE_DOWN])
		{
			switch (choice) {
			case 0:  
				if (worldMap1[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
				if (worldMap1[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed; 
				break; 
			case 1: 
				if (worldMap2[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
				if (worldMap2[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed; 
				break; //green
			case 2: 
				if (worldMap3[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
				if (worldMap3[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed; 
				break; //blue
			case 3: 
				if (worldMap4[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
				if (worldMap4[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
				break; //white
			default: 
				if (worldMap1[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
				if (worldMap1[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
				break;
			}
		}
		//rotate to the right
		if (keys[SDL_SCANCODE_RIGHT])
		{
			//both camera direction and camera plane must be rotated
			double oldDirX = dirX;
			dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
			dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
			double oldPlaneX = planeX;
			planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
			planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
		}
		//rotate to the left
		if (keys[SDL_SCANCODE_LEFT])
		{
			//both camera direction and camera plane must be rotated
			double oldDirX = dirX;
			dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
			dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
			double oldPlaneX = planeX;
			planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
			planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
		}
}


void PlayState::Draw(StateManager* game) {
	//SDL_RenderClear(game->SMRender);
	//renderTexture(background, game->SMRender, 0, 0);
	//SDL_RenderPresent(game->SMRender);
}


void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y) {
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren) {
	//Initialize to nullptr to avoid dangling pointer issues
	SDL_Texture *texture = nullptr;
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	texture = SDL_CreateTextureFromSurface(ren, loadedImage);
	SDL_FreeSurface(loadedImage);
	return texture;
}