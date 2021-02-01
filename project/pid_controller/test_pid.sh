#!/bin/bash

g++ -o main_pid.o main_pid.cpp pid_controller.cpp

./main_pid.o

gnuplot -p "plot_pid.plt"