#pragma once


double f1(double theta_1, double theta_2, double omega_1, double omega_2, double m_1, double m_2, double L_1, double L_2, const double g, const double pi);
double f2(double theta_1, double theta_2, double omega_1, double omega_2, double m_1, double m_2, double L_1, double L_2, const double g, const double pi);
void RK4(double& t, double h, double& theta_1, double& theta_2, double& omega_1, double& omega_2, double m_1, double m_2, double L_1, double L_2, const double g, const double pi);
void polar_to_cartesian_transform(double& x_1, double& y_1, double& x_2, double& y_2, double theta_1, double theta_2, double L_1, double L_2);
