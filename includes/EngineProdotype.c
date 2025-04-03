#include "EngineProdotype.h"

SDL_Window* windows[10];
int current_window = 0;

void JSE_Init(){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){ // Main library
		printf("[ERROR]:%s", SDL_GetError());
		system("pause");
		exit(0);
	}
	if (!(IMG_Init(IMG_INIT_PNG) && IMG_Init(IMG_INIT_JPG))){ // PNG and JPG support
		printf("[ERROR]:%s", IMG_GetError());
		system("pause");
		exit(0);
	}
	if (!(SDL_TTF())){ // Text support
		printf("[ERROR]:%s", TTF_GetError());
		system("pause");
		exit(0);
	}
}

void JSE_Quit(){
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
	
	int win_i;
	for (win_i=0;win_i<current_window;win_i++){
		if (windows[win_i] != NULL){
			SDL_DestroyWindow(windows[win_i]);	
			windows[win_i] = NULL;
		}
	}
}

SDL_Window* Create_window(JSE_WindowHandler *winHandle, int w, int h, const char* title, bool fullscreen){
	Uint32 screen_state = fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN;

	winHandle->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTER, SDL_WINDOWPOS_CENTER, w, h, screen_state);
	if (!winHandle->window){
		printf("[ERROR]:%s", SDL_GetError());
		system("pause");
		exit(0);
	}
	
	// Storing all argument data in the struct to act like a getter function
	winHandle->width = w;
	winHandle->height = h;
	winHandle->title = title;
	winHandle->fullscreen = fullscreen;
	
	return winHandle->window;
	windows[current_window] = winHandle->window;
	current_window++;
}

void JSE_SetWindowActive(JSE_WindowHandler *winHandle){
	winHandle->Create_window = Create_window;
	winHandle->window = NULL;
}

