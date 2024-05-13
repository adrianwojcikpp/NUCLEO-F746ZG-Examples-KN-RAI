import pibotlib
import math 
import time
import serial
import json
import matplotlib.pyplot as plt

def main():
	# create PiBot object
	pibot = pibotlib.web_api.PiBot('192.168.137.179')
	# Open serial port
	ser = serial.Serial('COM8', 115200)  

	try:
		while True:
			# Read data from serial port
			data = ser.readline().decode().strip()

			# Decode JSON data
			jsonData = json.loads(data)

			x = jsonData['x']
			y = -jsonData['y'] 
			v = jsonData['v']
			
			alpha = 0.5
			right = int(100*v*y*min(1+alpha*x, 1))
			left = int(100*v*y*min(1-alpha*x, 1))
			print('(' + str(left) + ',' + str(right) + ')')

			pibot.set_motors(-right, -left)
			
	except KeyboardInterrupt:
		pass
	finally:
		# Close serial port
		ser.close()


if __name__ == "__main__":
	main()
