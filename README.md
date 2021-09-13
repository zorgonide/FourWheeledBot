# 4 wheeled keyboard controlled bot, Bottas

4 wheeled test bot controlled using python and Arduino


https://user-images.githubusercontent.com/48021258/133042829-de243633-d26d-4bf9-a414-fce09bef93cb.mp4



## Getting Started

This is a keyboard controlled bot developed to use as a testing base for autonomous functions by Formula Manipal Driverless.

### Prerequisites

UNIX based OS
Arduino Mega
Cytron Motor Driver 4-16V
4x12V 100 RPM motors
LiPo Battery 
Raspberry Pi 3 (optional)

### Set Up

Upload motionArduino in Arduino folder onto Arduino Mega 2560, set up pin connections as specified. 

Run python script motion2.py on your computer connected to Arduino. Set up port if needed, it should auto-detect otherwise.
```
python motion2.py
```
For using Raspberry Pi to control the bot, connect Arduino to RPi,run motion2.py on RPi, and you can send inputs to RPi through SSH for controlling the bot. 

### Video Streaming
Attach PiCamera to RPi to set up video streaming between two computers on the same network using socket programming.

Run videoStreamingClient.py on RPi, set up IP address as host PC Ip address
```
python videoStreamingClient.py
```
Run videoStreamingServer.py on Host PC.
```
python videoStreamingServer.py
```
For video streaming using ROS, follow https://www.theconstructsim.com/publish-image-stream-ros-kinetic-raspberry-pi/ 

If you want to use Master Slave Configuration and stream from RPi to PC using ROS - 

On the master device open the .bashrc file:
```
nano ~/.bashrc
```
Then add two lines at file ending, replacing X.X.X.X and Y.Y.Y.Y with IP address of master device.
```
export ROS_MASTER_URI=http://X.X.X.X:11311
export ROS_IP=Y.Y.Y.Y
```
On second robot also open the .bashrc file, comment Husarnet entries and add two lines at file ending. This time replace X.X.X.X with IP address of master device and Y.Y.Y.Y with IP address of second robot.

TIP! Remember that roscore must be running on the device indicated as ROS master!!!

## Running the tests

Use keyboard key WASD to control bot in up, down, left and right directions. Use J/L to rotate left or right. If it does not move as specified change pin numbers on arduino C file until the desired effect is attained.
Run video streaming scripts if you want video streaming using PiCamera as specified above.

## Acknowledgments

* https://husarion.com/tutorials/ros-tutorials/5-running-ros-on-multiple-machines/
* https://www.theconstructsim.com/publish-image-stream-ros-kinetic-raspberry-pi/
