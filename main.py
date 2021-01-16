# imports
import cv2
import numpy as np
import sys
import serial
import time


def readingimg(img_path):
    img = cv2.imread(img_path, 0)
    # configure the image resolution here
    dim = (64, 32)
    img = cv2.resize(img, dim)

    # _,img = cv2.threshold(img,127,255,cv2.THRESH_BINARY)
    data = ""

    for row in img:
        for cell in row:
            if cell <= 120:
                data += '0'
            else:
                data += '1'
    return data


def extractbytearray(data):
    intarray = []
    for i in range(0, len(data), 8):
        intarray.append(int(data[i:i + 8], 2))
    return bytearray(intarray)


def main():
    # please make sure the arduino is connected to "/dev/ttyACM0" this port.
    # or replace the value with the port from your pc

    sp = serial.Serial(port="/dev/ttyUSB0", baudrate=115200)
    if(len(sys.argv) == 1):
        print("No imge was supplied :/ exiting")
        sys.exit()

    for arg in sys.argv[1:]:
        if arg.endswith("jpg") or arg.endswith("png"):
            data = readingimg(arg)
            sp.write(b'c')
            sp.write(extractbytearray(data))
            time.sleep(1)

    print("Done ")


if __name__ == "__main__":
    main()
