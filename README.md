# Double Pendulum
A double pendulum is a pendulum with another pendulum attached to its end. This code simulates the temporal evolution of the
double pendulum by solving a set of coupled ordinary differential equations (using the Runge Kutta method) with given user specified
initial conditions. The rendering is done using the SDL2 library. 

## How To Install & Run (Linux)

1. Install the C++ compiler g++ using the following command:
```bash
sudo apt-get install g++
```

To check which version is installed run the following command: 
```bash
g++ --version
```

2. Install the SDL2 library using the following command:
```bash
sudo apt install libsdl2-image-dev
```

3. Clone the remote repository to your local machine using the following command:
```bash
git clone https://github.com/frederic-hallein/double-pendulum
```
4. To compile the project, go inside the `double_pendulum/` directory and run the following command: 
```bash
make all
``` 
This should create a `main` executable file in the same directory. 

5. Run the executable by using the following command: 
```bash
./main
```

## Setup

To set up custom initial conditions, simply press `ENTER`. This prompts the user the following variables that require custom input: 
- `m_1`: mass 1st pendulum [unitless]
- `m_2`: mass 2nd pendulum [unitless]
- `L_1`: length 1st pendulum [unitless]
- `L_2`: length 2nd pendulum [unitless]
- `ini_theta_1`: initial angle 1st pendulum [degrees] 
- `ini_theta_2`: initial angle 2nd pendulum [degrees]
- `With friction? (y/n)`: air friction 


To run the default initial conditions, simply run the command `d`. The default setup is the following:

- `m_1 = 1` 
- `m_2 = 1` 
- `L_1 = 150` 
- `L_2 = 150` 
- `ini_theta_1 = 180`
- `ini_theta_2 = 180`
- `friction: no` 

## Screencast

Screencast of the simulation running the default setup.

[Screencast from 2024-08-06 14-48-29.webm](https://github.com/user-attachments/assets/11727669-aa58-4828-b112-ed4d8f248b12)
