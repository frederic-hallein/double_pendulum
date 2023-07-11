# double_pendulum
Simulation double pendulum through Runge Kutta method. The calculation is based on this simulation:
https://www.myphysicslab.com/pendulum/double-pendulum-en.html. The animation is made using the SDL library. 

# Run simulation
By default, the code is compatible with vscode using the powershell terminal.

In main.cpp, set up the initial conditions, i.e. choosing the masses of the disks (m_1 and m_2) and lengths of rods (L_1 and L_2).
Moreover, one can change the initial starting angles (ini_theta_1 and ini_theta). Note that the y-axis is set up vertically downwards, which implies 
that the angles are postive in the counter-clockwise direction. Furthermore, the stepsize h sets the size of timestep in the Runge Kutta calculation,
while the delay_time sets up the speed of the animation. 

To save the changes, type the command "mingw32-make -f makefile" inside the terminal inside the double_pendulum directory. After that, run the code 
by typing "./main".
