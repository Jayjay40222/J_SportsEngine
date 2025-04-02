// *************************************************************************** //
//
// This library is a framework wraper for SDL it is mainly used for sports games //
// The project is on github: github.com/Jayjay40222/J_SportsEngine //
// 
// *************************************************************************** //


#ifndef ENGINEPRODOTYPE_H
#define ENGINEPRODOTYPE_H

// All includes
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "include/stb_image.h"

void JSE_Init();
void JSE_Quit();

typedef struct{
	int width;
	int height;
	const char* title;
	bool fullscreen;
	SDL_Window* (*Create_window)(struct JSE_Window *win, int w, int h, const char* title, bool fullscreen);
	SDL_Window* window;
}JSE_WindowHandler;

void JSE_SetWindowActive(JSE_WindowHandler *winhandle);

#endif
