/*
  libsdl2-dev
  libsdl2-gfx-dev:amd64
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *win = SDL_CreateWindow("EyeSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 360, 256, SDL_WINDOW_SHOWN);
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface *surface = SDL_GetWindowSurface(win);
	SDL_Event e;

	Uint32 current_time = 0;
	bool quit = false;

	while(!quit) {
		current_time = SDL_GetTicks();
		while(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT) {
				quit = true;
			}

			if(e.type == SDL_KEYDOWN) {
				switch(e.key.keysym.sym) {
					case SDLK_ESCAPE:
						quit = true;
						break;

					default:
						break;
				}
			}
		}

		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);
		
		filledCircleColor(ren, 140, 128, 15, 0xFFFFFFFF);
		filledCircleColor(ren, 235, 128, 15, 0xFFFFFFFF);

		SDL_RenderPresent(ren);

		if((1000/60) > SDL_GetTicks() - current_time) {
			SDL_Delay(1000/60 - (SDL_GetTicks() - current_time));
		}
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	SDL_Quit();
	return 0;
}
