import serial
from visual import *
import csv

#arduinoSerialData = serial.Serial('/dev/cu.usbmodem1411', 9600)

iFlex0 = box(color=color.green, length=.2, width=0, height=.2, pos=(-1,0,-.1))
iFlex1 = box(color=color.green, length=.2, width=0, height=.2, pos=(-.5,0,-.1))
iFlex2 = box(color=color.green, length=.2, width=0, height=.2, pos=(0,0,-.1))
iFlex3 = box(color=color.green, length=.2, width=0, height=.2, pos=(.5,0,-.1))
iFlex4 = box(color=color.green, length=.2, width=0, height=.2, pos=(1,0,-.1))

#xInd = box(color=color.white, length=.2, width=0, height=.05, pos=(-.5,0,-.1))
#yInd = box(color=color.white, length=.2, width=0, height=.05, pos=(0,0,-.1))
#zInd = box(color=color.white, length=.2, width=0, height=.05, pos=(.5,0,-.1))

#xLab = label(text="x", pos=(-.5,0,-.1), height=30, color=color.blue, box=False)
#yLab = label(text="y", pos=(0,0,-.1), height=30, color=color.blue, box=False)
#zLab = label(text="z", pos=(.5,0,-.1), height=30, color=color.blue, box=False)

while 1:
    rate(20)
    if 0 == 1:#arduinoSerialData.inWaiting() > 0:
        reader = csv.reader([arduinoSerialData.readline()], skipinitialspace=True)
        vals = []
        for r in reader:
            vals.append(r)
        flex0 = float(vals[0][0])
        flex1 = float(vals[0][1])
        flex2 = float(vals[0][2])
        flex3 = float(vals[0][3])
        flex4 = float(vals[0][4])
        
        if flex0 < 0:
            iFlex0.color = color.red
        else:
            iFlex0.color = color.green
            
        if flex1 < 0:
            iFlex1.color = color.red
        else:
            iFlex1.color = color.green

        if flex2 < 0:
            iFlex2.color = color.red
        else:
            iFlex2.color = color.green

        if flex3 < 0:
            iFlex3.color = color.red
        else:
            iFlex3.color = color.green

        if flex4 < 0:
            iFlex4.color = color.red
        else:
            iFlex4.color = color.green
            
 #       x = float(vals[0][1])
 #       y = float(vals[0][2])
 #       z = float(vals[0][3])
 #       xInd.pos = (-.5,x/10,-.1)
 #       yInd.pos = (0,y/10,-.1)
 #       zInd.pos = (.5,z/10,-.1)
 #       print "x: " + str(x) + " | y: " + str(y) + " | z: " + str(z)
 
