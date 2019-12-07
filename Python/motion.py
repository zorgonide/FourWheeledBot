
import serial
import sys,tty,termios
from time import sleep # Import the sleep function from the time module
global count
count = 0

#For use with PC
ser = serial.Serial('/dev/ttyACM3', 19200)
#Use polling to get user input
class _Getch:
	def __call__(self):
            fd = sys.stdin.fileno()
            old_settings = termios.tcgetattr(fd)
            try:
                tty.setraw(sys.stdin.fileno())
                ch = sys.stdin.read(3)
            finally:
                termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
            return ch
def get():
#Detect arrow keys
        global count
        inkey = _Getch()
        while(1):
                k=inkey()
                if k!='e' : break
        
        if k=='\x1b[A':
                
                if count < 5:
                	ser.write(b't')
                	count+=1
                	print('Trot')
                	sleep(0.5)
                else:
	            	print ("up")
	                ser.write(b'w')
	                sleep(0.5)
                get()
        elif k=='\x1b[B':
                print ("down")
                ser.write(b's')
                sleep(0.5)
                get()
        elif k=='\x1b[C':
                print ("right")
                ser.write(b'a')
                sleep(0.25)
                get()
        elif k=='\x1b[D':
                print ("left")
                ser.write(b'd')
                sleep(0.25)
                get()
        elif k=='\x1b6a':
                print ("forward left")
                ser.write('j')
                sleep(0.5)
                get()
        elif k=='\x1b6c':
                print ("forward right")
                ser.write('l')
                sleep(0.5)
                get()
        else:
                print ("not an arrow key!")
                return True
                return
		#get()

#Delay of 0.15s on both arduino and RPi, chosen after hit and trial
sleep(2) # wait for the serial connection to initialize
if __name__=='__main__':
    print("Enter option with arrow keys\n")
    get()
