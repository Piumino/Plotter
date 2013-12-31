#include <stdio.h>
#include "SDL.h"
#include "stuff.h"


int drawAxis(SDL_Renderer* ren){

	int x0 = 0;
	int y0 = DIM_W / 2;
	int x1 = DIM_H;
	int y1 = DIM_W / 2; 

	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0); //set the color (0, 0, 0, 0) is black.

	if (SDL_RenderDrawLine(ren, x0, y0, x1, y1) == -1) //draw x-axis, if there are error then return 1
		return 1;

	if (SDL_RenderDrawLine(ren, y0, x0, y1, x1) == -1)//draw y-axis, if there are error then return 1
		return 1;

	return 0;
}


int drawGraph(SDL_Renderer* ren){

	point center = { 350.0, 350.0 };
	
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0); //set the color (0, 0, 0, 0) is black.

	for (point p = { -11, -10 }; p.x < DIM_H / (SCALE * 2); p.x += STEP)
		SDL_RenderDrawPoint(ren, (int)(getX(&center, &p)), (int)(getY(&center, &p)));
	/*if(SDL_RenderDrawLine(ren, int(getX(&center, &p)), int(getY(&center, &p)), int(getNextX(&center, &p)), int(getNextY(&center, &p)))==-1)
	return 1;*/

	return 0;

}

int main(int argc, char** argv){

	SDL_Window *win = NULL;
	SDL_Renderer* ren = NULL;
	//SDL_Surface* surf = NULL;
	SDL_Event event;

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
		printf("Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	if (!(win = SDL_CreateWindow("f(x)'s graph", 150, 150, DIM_H, DIM_W, SDL_WINDOW_SHOWN))){
		printf("Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	SDL_RenderClear(ren);

	if (drawAxis(ren)){
		printf("Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	drawGraph(ren);
	SDL_RenderPresent(ren);




	for (;;){
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			break;
	}
	//SDL_Delay(2000);
	SDL_Quit();

	return 0;


}