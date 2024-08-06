#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Window* get_window(int screen_width, int screen_height);
SDL_Renderer* get_renderer(SDL_Window* window);
SDL_Texture* get_texture(SDL_Renderer* renderer, const char* filepath);
void draw(SDL_Renderer* renderer, SDL_Texture* disk, int screen_width, int screen_height, double x_1_pos, double y_1_pos, double x_2_pos, double y_2_pos, Uint32 delay_time);
void destroy(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* disk);












