# Description

This script will show a monochrome bitmap image on the SSD1306 I2C OLED screen.
You have to wire the arduino and oled screen properly
make sure to edit the resolution of the picure if you are using
a bigger oled or just prefer a wider screen.
this will show an image of 64x32 res on the center of an 0.91 inch 128x32 oled
you have to compile the arduino code and upload it to the connected arduino 

**Please note this code is very poorly implemented performance for live video transefer is still out of question ! I am still working on improving the algorithm for generating a bytearray from image that can be displayed.**

<br>
<br>

# Precautions
Make sure the serial port is correct and also don't use the serial monitor while
this script is running and also make sure to increase the screen buffer size
here my image is 64x32  = 2048bit = 256 byte
if you want to use a larger image make sure to calculate and increase the size of
the scrbuffer array as that is where the image would be stored


# Prerequisite
to run these script you need these following modules
    
        pyserial
        numpy
        opencv
        pyautogui

The required modules can be installed via

    pip install -r requirements.txt


you need to connect the I2C oled wires as the following config 

      OLED      Arduino
     ------------------   
        GND  ->   GND
        VCC  ->   5V
        SDA  ->   A4
        SCL  ->   A5

you will have to compile and upload the supplid arduino code to your arduino

# Usage
just use 

    python3 main.py "name of your image or a directory of images"

for example

    python3 main.py wallpaper.jpg
or
    
    python3 main.py ~/Wallpapers/*
