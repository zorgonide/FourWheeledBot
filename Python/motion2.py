#Improved code usind WASD and JL
import tty, termios, sys
from serial import Serial
from time import sleep # Import the sleep function from the time module
import time
i = 0
while(1):
        time.sleep(1)
        try:    
                # ser = Serial('COM'+str(i), 19200, timeout=.1) #PC
                ser = Serial('/dev/ttyACM'+str(i), 19200, timeout=.1) #UNIX
                # ser = Serial('/dev/ttyACM0', 19200, timeout=.1) #UNIX
                print('All Ok')
                break
        except:
                print('PORT '+str(i)+ ' ERROR')
                i = (i+1)%8
                

def getchar():
   #Returns a single character from standard input
   fd = sys.stdin.fileno()
   old_settings = termios.tcgetattr(fd)
   try:
      tty.setraw(sys.stdin.fileno())
      ch = sys.stdin.read(1)
   finally:
      termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
   return ch
time.sleep(2)   
print("Enter options in WASD")
while 1:
    ch = getchar()
    if ch.strip() == '':
        print('bye!')
        break
    else:
        # print(ch)
        if ch=='w':
                print ("up")
                ser.write(b'w')
                sleep(0.5)
        elif ch=='s':
                print ("down")
                ser.write(b's')
                sleep(0.5)
        elif ch=='d':
                print ("right")
                ser.write(b'a')
                sleep(0.25)
        elif ch=='a':
                print ("left")
                ser.write(b'd')
                sleep(0.25)
        elif ch=='j':
                print ("rotateLeft")
                ser.write(b'i')
                sleep(0.25)
        elif ch=='l':
                print ("roteteRight")
                ser.write(b'p')
                sleep(0.25)
        elif ch=='t':
                print ("Trot")
                ser.write(b't')
                sleep(0.5)