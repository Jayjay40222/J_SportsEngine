#include "includes/EngineProdotype.h"
#include <stdbool.h>

int main(){
	JSE_Init();
	
	JSE_WindowHandle win_handle;
	JSE_SetWindowActive(&win_handle);
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
