#define SDL_MAIN_HANDLED

#include <iostream>
#include <cmath>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "header_files/calculation.h"
#include "header_files/animation.h"

int main(int argc, char* argv[]){
    // screen size
    const int screen_width = 700;
    const int screen_height = 700;

    double x_center = screen_width / 2;
    double y_center = screen_height / 2;

    // initial setup
    double m_1 = 100;
    double m_2 = 100;
    double L_1 = 150;
    double L_2 = 150;

    // constants
    const double g = 9.81;
    const double pi = 3.14;

    // initial starting angles
    double ini_theta_1 = pi;
    double ini_theta_2 = pi;
    
    // stepsize
    double h = 0.1; 

    // delay time of animation in milliseconds
    Uint32 delay_time = 1.5;

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


    bool is_running = true;
    while(is_running){
        SDL_Event event;
        while(SDL_PollEvent(&event) != 0){
            if(event.type == SDL_QUIT){
                is_running = false;   
            }
        }

        std::cout << t << " : " << "(" << x_1 << "," << y_1 << ")" << "," << "(" << x_2 << "," << y_2 << ")"<< std::endl;

        // positions of two disks
        double x_1_pos = x_center + x_1;
        double y_1_pos = y_center - y_1;
        double x_2_pos = x_center + x_2;
        double y_2_pos = y_center - y_2;

        // draw on window
        draw(renderer, disk, x_center, y_center, x_1_pos, y_1_pos, x_2_pos, y_2_pos, delay_time);

        // apply Runge-Kutta of order 4
        RK4(t, h, theta_1, theta_2, omega_1, omega_2, m_1, m_2, L_1, L_2, g, pi);

        // convert to cartesian coordinates
        polar_to_cartesian_transform(x_1, y_1, x_2, y_2, theta_1, theta_2, L_1, L_2);
            
    }

    // destroy everything
    destroy(window, renderer, disk);

    window = nullptr;
    renderer = nullptr;
    disk = nullptr;

    SDL_Quit();

    return 0;
}