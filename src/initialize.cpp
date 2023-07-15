#include <iostream>
#include <sstream>
#include <string>

#include "header_files/initialize.h"

void initialize(bool& is_initialized, double& m_1, double& m_2, double& L_1, double& L_2, double& ini_theta_1, double& ini_theta_2){

    std::cout << "Press enter to set up initial conditions, otherwise type \"d\" for default values. ";

    std::string input;
    std::getline(std::cin, input);
    if (input == "d"){
        std::cout << "\nDefault setup: \n" << std::endl;
        std::cout << "m_1 = 1" << std::endl;
        std::cout << "m_2 = 1" << std::endl;
        std::cout << "L_1 = 1.5" << std::endl;
        std::cout << "L_2 = 1.5" << std::endl;
        std::cout << "ini_theta_1 = 3.14" << std::endl;
        std::cout << "ini_theta_2 = 3.14" << std::endl;

        is_initialized = true;
    }
    else if (input.empty()){
        std::cout << "Enter mass of disk 1" << std::endl;
        std::cout << "m_1 = ";
        while (!(std::cin >> m_1) || m_1 <= 0)
        {
            std::cout << "Invalid. Enter again." << std::endl;
            std::cout << "m_1 = ";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }

        std::cout << "Enter mass of disk 2" << std::endl;
        std::cout << "m_2 = ";
        while (!(std::cin >> m_2) || m_2 <= 0)
        {
            std::cout << "Invalid. Enter again." << std::endl;
            std::cout << "m_2 = ";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }

        std::cout << "Enter length of pendulum 1" << std::endl;
        std::cout << "L_1 = ";
        while (!(std::cin >> L_1) || L_1 <= 0)
        {
            std::cout << "Invalid. Enter again." << std::endl;
            std::cout << "L_1 = ";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }

        std::cout << "Enter length of pendulum 2" << std::endl;
        std::cout << "L_2 = ";
        while (!(std::cin >> L_2) || L_2 <= 0)
        {
            std::cout << "Invalid. Enter again." << std::endl;
            std::cout << "L_2 = ";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }

        std::cout << "Enter initial angle 1" << std::endl;
        std::cout << "ini_theta_1 = ";
        while (!(std::cin >> ini_theta_1))
        {
            std::cout << "Invalid. Enter again." << std::endl;
            std::cout << "ini_theta_1 = ";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }

        std::cout << "Enter initial angle 2" << std::endl;
        std::cout << "ini_theta_2 = ";
        while (!(std::cin >> ini_theta_2))
        {
            std::cout << "Invalid. Enter again." << std::endl;
            std::cout << "ini_theta_2 = ";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }

        is_initialized = true;
    }

}