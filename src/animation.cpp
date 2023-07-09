#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "header_files/animation.h"

SDL_Window* get_window(int screen_width, int screen_height){
    SDL_Window* window = SDL_CreateWindow("double pendulum simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_ALLOW_HIGHDPI);
    if(window == nullptr){
        std::cout << "Could not create window: " << SDL_GetError() <<std::endl;
    }

    return window;
}

SDL_Renderer* get_renderer(SDL_Window* window){
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == nullptr){
        std::cout << "Could not create renderer: " << SDL_GetError() <<std::endl;
    }

    return renderer;
}

SDL_Texture* get_texture(SDL_Renderer* renderer, const char* filepath){
    SDL_Texture* texture = IMG_LoadTexture(renderer, filepath);
    if(texture == nullptr){
        std::cout << "Image could not be loaded from file path: " << filepath << std::endl;
        std::cout << "Error: " << SDL_GetError() << std::endl;
    }

    return texture;
}

void draw(SDL_Renderer* renderer, SDL_Texture* disk, int x_center, int y_center, double x_1_pos, double y_1_pos, double x_2_pos, double y_2_pos, Uint32 delay_time){
    // disk size
    int disk_size = 64;  
    // offset       
    double offset = 30;
    
    SDL_Rect line_dst_1;
    line_dst_1.x = x_1_pos;
    line_dst_1.y = y_1_pos;
    line_dst_1.w = disk_size; 
    line_dst_1.h = disk_size;

    SDL_Rect disk_dst_1;
    disk_dst_1.x = line_dst_1.x - offset;
    disk_dst_1.y = line_dst_1.y - offset;
    disk_dst_1.w = disk_size; 
    disk_dst_1.h = disk_size;

    SDL_Rect line_dst_2;
    line_dst_2.x = x_2_pos;
    line_dst_2.y = y_2_pos;
    line_dst_2.w = disk_size; 
    line_dst_2.h = disk_size;

    SDL_Rect disk_dst_2;
    disk_dst_2.x = line_dst_2.x - offset;
    disk_dst_2.y = line_dst_2.y - offset;
    disk_dst_2.w = disk_size; 
    disk_dst_2.h = disk_size;
    
    SDL_RenderClear(renderer);

    // draw background
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
    SDL_RenderClear(renderer);

    // draw pendulum lines
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, x_center, y_center, line_dst_1.x, line_dst_1.y);
    SDL_RenderDrawLine(renderer,  line_dst_1.x, line_dst_1.y, line_dst_2.x, line_dst_2.y);

    // draw disks
    SDL_RenderCopy(renderer, disk, NULL, &disk_dst_1);
    SDL_RenderCopy(renderer, disk, NULL, &disk_dst_2);

    SDL_RenderPresent(renderer);
    SDL_Delay(delay_time);
}

void destroy(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* disk){
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(disk);
    SDL_DestroyRenderer(renderer);
}