# Control and Trajectory Tracking for Autonomous Vehicle 

# Proportional-Integral-Derivative (PID)

In this project, you will apply the skills you have acquired in this course to design a PID controller to perform vehicle trajectory tracking. Given a trajectory as an array of locations, and a simulation environment, you will design and code a PID controller and test its efficiency on the CARLA simulator used in the industry.

## Getting Started

Instructions for how to get a copy of the project running on your local machine.


### Installation

Run the following commands to install the starter code in the Udacity Workspace:

Clone the [repository](https://github.com/udacity/nd013-c6-control-refresh/tree/master):

`git clone https://github.com/udacity/nd013-c6-control-refresh.git`

Run Carla Simulator
-------------------
Open new window
- `su - student`
// Will say permission denied, ignore and continue 
- `cd /opt/carla-simulator/`
- `SDL_VIDEODRIVER=offscreen ./CarlaUE4.sh -opengl`


Compile and Run the Controller
------------------------------
Open new window
- `cd nd013-c5-planning-starter/project`
- `./install-ubuntu.sh`
- `cd pid_controller/`
- `rm -rf rpclib`
- `git clone https://github.com/rpclib/rpclib.git`
- `cmake .`
- `make` (This last command compiles your c++ code, run it after every change in your code)

## Testing

To test your installation run the following commands. 

- `cd nd013-c5-planning-starter/project`
- `./run_main_pid.sh`
This will silently fail `ctrl + C` to stop 
- `./run_main_pid.sh` (again)
Go to desktop mode to see CARLA

If error bind is already in use, or address already being used
- `ps -aux | grep carla`
- `kill id`


## Project Instructions

In the previous project you built a path planner for the autonomous vehicle. Now you will build the steer and throttle controller so that the car follows the trajectory. 

You will design and run the a PID controller as described in the previous course. 

In the directory [/pid_controller](https://github.com/udacity/nd013-c5-planning-starter/tree/mathilde/project_c6/project/pid_controller)  you will find the files [pid.cpp](https://github.com/udacity/nd013-c5-planning-starter/tree/mathilde/project_c6/project/pid_controller/pid.cpp)  and [pid.h](https://github.com/udacity/nd013-c5-planning-starter/tree/mathilde/project_c6/project/pid_controller/pid.h). This is where you will code your pid controller. 
The function pid is called in [main.cpp](https://github.com/udacity/nd013-c5-planning-starter/tree/mathilde/project_c6/project/pid_controller/main.cpp) but you should not modify this file. 

### Step 1: Build the PID controller object


### Step 2: PID controller for throttle: 


### Step 3: PID controller for steer:


### Step 4: Evaluate the PID efficiency


### Step 4: Improve the PID with a changing time interval
