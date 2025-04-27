#include "includes/EngineProdotype.h"
#include <stdbool.h>

int main(int argc, char *argv[]){
	JSE_Init();
	
	JSE_WindowHandler win_handle = {0};
	win_handle.Create_window = Create_window;
	JSE_Window* window = win_handle.Create_window(&win_handle, 500, 500, "JSE window", false);
	
	bool running = true;
	while (running){
		SDL_Event ev;
		if (SDL_PollEvent(&ev)){
			if (ev.type == SDL_QUIT){
				running = false;
			}
		}
	}
	
	JSE_Quit();
	return 0;
}
