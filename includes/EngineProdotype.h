// *************************************************************************** //
//
// This library is a framework wraper for SDL it is mainly used for sports games //
// The project is on github: github.com/Jayjay40222/J_SportsEngine //
// 
// *************************************************************************** //


#ifndef ENGINEPRODOTYPE_H
#define ENGINEPRODOTYPE_H

#define SDL_MAIN_HANDLED

// All includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

typedef struct SDL_Window JSE_Window;
typedef struct SDL_Texture JSE_Object;

void JSE_Init();
void JSE_Quit();

typedef struct JSE_WindowHandler{
	int width;
	int height;
	const char* title;
	bool fullscreen;
	JSE_Window* (*Create_window)(struct JSE_WindowHandler *winHandle, int w, int h, const char* title, bool fullscreen);
	JSE_Window* window;
}JSE_WindowHandler;

typedef struct{
	const char* path;
	int width;
	int height;
	float xpos;
	float ypos;
	//JSE_Object* (*Load_object)(struct JSE_SpriteHandler* sH, const char* path);
}JSE_SpriteHandler;

SDL_Window* Create_window(struct JSE_WindowHandler *winHandle, int w, int h, const char* title, bool fullscreen);

#endif

