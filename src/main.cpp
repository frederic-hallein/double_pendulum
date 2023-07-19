#define SDL_MAIN_HANDLED

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "header_files/calculation.h"
#include "header_files/animation.h"
#include "header_files/initialize.h"

int main(int argc, char* argv[]){
    // screen size
    const int screen_width = 700;
    const int screen_height = 700;

    int x_center = screen_width / 2;
    int y_center = screen_height / 2;

    // constants
    const double g = 9.81;
    const double pi = 3.14;

    // initial setup (default)
    double m_1 = 1;
    double m_2 = 1;
    double L_1 = 150;
    double L_2 = 150;

    // initial starting angles (default)
    double ini_theta_1 = 180;
    double ini_theta_2 = 180;

    // friction
    char with_friction = 'n';
    double friction = 0.999;

    // initialize set up
    bool is_initialized = false;
    while(!(is_initialized))
    {
        initialize(is_initialized, m_1, m_2, L_1, L_2, ini_theta_1, ini_theta_2, with_friction);
    }

    // convert to radians
    ini_theta_1 *= (pi / 180);
    ini_theta_2 *= (pi / 180);

    // stepsize
    double h = 0.1; 

    // delay time of animation in milliseconds
    Uint32 delay_time = 5;

    double t = h;
    double theta_1 = ini_theta_1;
    double theta_2 = ini_theta_2;
    double omega_1 = t;
    double omega_2 = t;
    double x_1 = L_1 * sin(ini_theta_1);
    double y_1 = -L_1 * cos(ini_theta_1);
    double x_2 = x_1 + L_2 * sin(ini_theta_2);
    double y_2 = y_1 - L_2 * cos(ini_theta_2);

    
    // create window and renderer
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = get_window(screen_width, screen_height);
    SDL_Renderer* renderer = get_renderer(window);

    // load red disk
    const char* filepath = "res/red_disk.png";
    SDL_Texture* disk = get_texture(renderer, filepath);

    // check if winow, renderer and disk are created
    if(window == NULL || renderer == NULL || disk == NULL){
        return 1;
    }


    bool is_running = true;
    while(is_running){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                is_running = false;   
            }
        }

        //std::cout << t << " : " << "(" << x_1 << "," << y_1 << ")" << "," << "(" << x_2 << "," << y_2 << ")"<< std::endl;

        // positions of two disks
        double x_1_pos = x_center + x_1;
        double y_1_pos = y_center - y_1;
        double x_2_pos = x_center + x_2;
        double y_2_pos = y_center - y_2;

        // draw on window
        draw(renderer, disk, x_center, y_center, x_1_pos, y_1_pos, x_2_pos, y_2_pos, delay_time);

        // apply Runge-Kutta of order 4
        RK4(t, h, theta_1, theta_2, omega_1, omega_2, m_1, m_2, L_1, L_2, g, pi);

        // apply friction
        if (with_friction == 'y'){
            theta_1 *= friction;
            theta_2 *= friction;
        }

        // convert to cartesian coordinates
        polar_to_cartesian_transform(x_1, y_1, x_2, y_2, theta_1, theta_2, L_1, L_2);
            
    }

    // destroy everything
    destroy(window, renderer, disk);

    window = NULL;
    renderer = NULL;
    disk = NULL;

    SDL_Quit();

    return 0;
}
