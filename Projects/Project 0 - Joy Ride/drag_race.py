#!/usr/bin/env python
# coding: utf-8

# # Joy Ride - Part 1: Drag Race
# 
# The goal here is to get you familiar with how to control the simulated car with code. To get started:
# 
# 1. Run the cell below this one by pressing `Ctrl + Enter`
# 1. The simulator will appear below the cell.
# 1. Run the cell below the simulator, marked `CODE CELL` (hit `Ctrl + Enter`). The car in the simulator should start moving. You should notice a problem...
# 1. Press the **Reset** button in the simulator and then modify the code in the code cell. You should only need to change one line of code...
# 1. When you think you've fixed the problem, run the code cell again. Did the car make it over the trees?
# 
# #### NOTE - depending on your computer it may take a few minutes for the simulator to load! Please be patient.

# In[1]:


get_ipython().run_cell_magic('HTML', '', '<script src="setupLauncher.js"></script><div id="simulator_frame"></sim>')


# In[8]:


# CODE CELL
# 
# This is the code you should 
# edit and run to control the car.

from Car import Car # you don't need to change this line of code...
import time
def jump(car):
    # TODO - make modifications in this function
    #   so that your car makes it safely over the trees.
    
    car.steer(0.0) # any value between -25 and 25 works here for
                   # steering angle (in degrees)
        
    car.gas(0)   # any value between -1.0 (full reverse) and 
                   # 1.0 (full throttle) works here
    gas=0
    for i in range (15):      #speed up the car slowly
        gas += 0.1
        car.gas(gas)
        time.sleep(1.5)       #delay because we don't want to go from 0 to 1 (gas) instantly
    gas = 1.0
    for i in range (5):       #when we cross the trees we want to resist the forward velocity, so we apply reverse velocity
        gas -= 0.4
        car.gas(gas)
        time.sleep(0.5)       #adding delay because we don't want to go from 1 to -1 instantly
    car.gas(-1)
    time.sleep(2)             #we still want to have full reverse velocity for a while for the car to stop
    gas=-1
    for i in range (5):       #now the car would start going back, so we apply forward velocity a bit to resist the change
        gas += 0.2
        car.gas(gas)
        time.sleep(0.8)
car = Car()  
jump(car)

