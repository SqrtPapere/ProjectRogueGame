## Installation and Test

Requires following dependencies:
* SFML
* Mac OSX (it’s not a must but the “how to run” is based on it)

#How to Run

Download and open the repository.

Open the Xcode Project: Roguemon  2.0.xcodeproj

Press the Build button.

Now in Roguemon 2.0 -> Products -> Roguemon 2.0app press “Show in Finder”
Move directory “rasp-parkDetecting” to RaspberryPi and position it looking to the area to be monitored. 
Move directory “pc-parkDetecting” to PC.

Connect to it by SSH. 

+ run: python3 waitCoordRASP.py on RaspberryPI
+ run: python3 selectCoordPC.py on PC
+ Select target of interest
+ press "c" key two times
+ run: python3 yoloRaspArray.py on raspberry
+ run: client.py on PC

## Results
Every time a change of state happens, a pic will be taken:

[![4.png](https://s26.postimg.org/nahhmzm2d/Park0full_at_Sat_Jul_8_15_02_18_2017.jpg)](http://postimg.org/image/nahhmzm2d/)[![2.png](https://s26.postimg.org/8d90lz8tx/Park0empty_at_Sat_Jul_8_14_19_56_2017.jpg)](http://postimg.org/image/8d90lz8tx/)[![3.png](https://s26.postimg.org/6b8j7qaut/Park0full_at_Sat_Jul_8_11_53_17_2017.jpg)](http://postimg.org/image/6b8j7qaut/)[![1.png](https://s26.postimg.org/qes5js2ut/Park0empty_at_Sat_Jul_8_11_51_37_2017.jpg)](http://postimg.org/image/qes5js2ut/)

## Contributors
Developed by [Francesco Pegoraro](https://github.com/SqrtPapere) and Daniele Giacomelli

## YOLO 

Joseph Redmon. Darknet: Open Source Neural Networks in C, 2013–2016. http://pjreddie.com/darknet/.
