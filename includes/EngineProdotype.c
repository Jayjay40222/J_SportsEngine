#include "EngineProdotype.h"

SDL_Window* windows[10];
int current_window = 0;

void JSE_Init(){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){ // Main library
		printf("[ERROR]:%s", SDL_GetError());

		exit(0);
	}
	if (!(IMG_Init(IMG_INIT_PNG) && IMG_Init(IMG_INIT_JPG))){ // PNG and JPG support
		printf("[ERROR]:%s", IMG_GetError());

		exit(0);
	}
	if (!(TTF_Init())){ // Text support
		printf("[ERROR]:%s", TTF_GetError());

		exit(0);
	}
}

void JSE_Quit(){
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
	
	for (int win_i=0;win_i<current_window;win_i++){
		if (windows[win_i] != NULL){
			SDL_DestroyWindow(windows[win_i]);	
			windows[win_i] = NULL;
		}
	}
}

SDL_Window* Create_window(struct JSE_WindowHandler *winHandle, int w, int h, const char* title, bool fullscreen) {
    Uint32 screen_state = fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN;

    winHandle->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, screen_state);
    if (!winHandle->window) {
        printf("[ERROR]: %s", SDL_GetError());

        exit(0);
    }
    
    // Store argument data in the struct
    winHandle->width = w;
    winHandle->height = h;
    winHandle->title = title;
    winHandle->fullscreen = fullscreen;
    
    return winHandle->window;
}

