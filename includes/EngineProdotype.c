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
	
	SDL_Event win_ev;
	if (SDL_PollEvent(&win_ev)){
		if (win_ev.type == SDL_QUIT){
			int win_i;
			for (win_i=0;win_i<current_window;win_i++){
				SDL_DestroyWindow(windows[win_i]);
			}
		}
	}
}

SDL_Window* Create_window(JSE_WindowHandler *winhandle, int w, int h, const char* title, bool fullscreen){
	Uint32 screen_state = fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN;

	winhandle->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTER, SDL_WINDOWPOS_CENTER, w, h, screen_state);
	if (!winhandle->window){
		printf("[ERROR]:%s", SDL_GetError());
		system("pause");
		exit(0);
	}
	
	// Storing all argument data in the struct to act like a getter function
	winhandle->width = w;
	winhandle->height = h;
	winhandle->title = title;
	winhandle->fullscreen = fullscreen;
	
	return winhandle->window;
	windows[current_window] = winhandle->window;
	current_window++;
}

void JSE_SetWindowActive(JSE_WindowHandler *winhandle){
	winhandle->Create_window = Create_window;
	winhandle->window = NULL;
}
