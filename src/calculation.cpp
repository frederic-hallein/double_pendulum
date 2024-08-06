#include <cmath>
#include <vector>

#include "calculation.hpp"

double f1(double theta_1, double theta_2, double omega_1, double omega_2, double m_1, double m_2, double L_1, double L_2, const double g, const double pi){
    return (-g * (2 * m_1 + m_2) * sin(theta_1) - m_2 * g * sin(theta_1 - 2 * theta_2) 
           - 2 * sin(theta_1 - theta_2) * m_2 * (pow(omega_2, 2) * L_2 + pow(omega_1, 2) * L_1 * cos(theta_1 - theta_2))) 
           / (L_1 * (2 * m_1 + m_2 - m_2 * cos(2 * (theta_1 - theta_2))));
}
double f2(double theta_1, double theta_2, double omega_1, double omega_2, double m_1, double m_2, double L_1, double L_2, const double g, const double pi){
    return (2 *sin(theta_1 - theta_2) * (pow(omega_1, 2) * L_1 * (m_1 + m_2) + g * (m_1 + m_2) * cos(theta_1)
           + pow(omega_2, 2) * L_2 * m_2 * cos(theta_1 - theta_2)))
           / (L_2 * (2 * m_1 + m_2 - m_2 * cos(2 * (theta_1 - theta_2))));
}

void RK4(double& t, double h, double& theta_1, double& theta_2, double& omega_1, double& omega_2, double m_1, double m_2, double L_1, double L_2, const double g, const double pi){
    double k_1, k_2, l_1, l_2, 
           k_11, k_21, l_11, l_21, 
           k_12, k_22, l_12, l_22, 
           k_13, k_23, l_13, l_23, 
           k_14, k_24, l_14, l_24;

    k_11 = h * omega_1;
    k_21 = h * omega_2;
    l_11 = h * f1(theta_1, theta_2, omega_1, omega_2, m_1, m_2, L_1, L_2, g, pi);
    l_21 = h * f2(theta_1, theta_2, omega_1, omega_2, m_1, m_2, L_1, L_2, g, pi);

    k_12 = h * (omega_1 + l_11/2);
    k_22 = h * (omega_2 + l_21/2);
    l_12 = h * f1(theta_1 + k_11/2, theta_2 + k_21/2, omega_1 + l_11/2, omega_2 + l_21/2, m_1, m_2, L_1, L_2, g, pi);
    l_22 = h * f2(theta_1 + k_11/2, theta_2 + k_21/2, omega_1 + l_11/2, omega_2 + l_21/2, m_1, m_2, L_1, L_2, g, pi);

    k_13 = h * (omega_1 + l_12/2);
    k_23 = h * (omega_2 + l_22/2);
    l_13 = h * f1(theta_1 + k_12/2, theta_2 + k_22/2, omega_1 + l_12/2, omega_2 + l_22/2, m_1, m_2, L_1, L_2, g, pi);
    l_23 = h * f2(theta_1 + k_12/2, theta_2 + k_22/2, omega_1 + l_12/2, omega_2 + l_22/2, m_1, m_2, L_1, L_2, g, pi);

    k_14 = h * (omega_1 + l_13);
    k_24 = h * (omega_2 + l_23);
    l_14 = h * f1(theta_1 + k_13, theta_2 + k_23, omega_1 + l_13, omega_2 + l_23, m_1, m_2, L_1, L_2, g, pi);
    l_24 = h * f2(theta_1 + k_13, theta_2 + k_23, omega_1 + l_13, omega_2 + l_23, m_1, m_2, L_1, L_2, g, pi);


    k_1 = (k_11 + 2*k_12 + 2*k_13 + k_14) / 6;
    k_2 = (k_21 + 2*k_22 + 2*k_23 + k_24) / 6;
    l_1 = (l_11 + 2*l_12 + 2*l_13 + l_14) / 6;
    l_2 = (l_21 + 2*l_22 + 2*l_23 + l_24) / 6;

    t += h;
    theta_1 += k_1;
    theta_2 += k_2;
    omega_1 += l_1;
    omega_2 += l_2;  
}


void polar_to_cartesian_transform(double& x_1, double& y_1, double& x_2, double& y_2, double theta_1, double theta_2, double L_1, double L_2){
    x_1 = L_1 * sin(theta_1);
    y_1 = -L_1 * cos(theta_1);
    x_2 = x_1 + L_2 * sin(theta_2);
    y_2 = y_1 - L_2 * cos(theta_2);
}
