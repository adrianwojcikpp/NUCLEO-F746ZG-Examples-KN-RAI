import serial
import json
import matplotlib.pyplot as plt

# Initialize serial port
ser = serial.Serial('COM8', 115200) 
ser.flushInput()

# Initialize plot
plt.ion()
fig, ax = plt.subplots()
line, = ax.plot([], [], '-o')  # 'o' represents a circle marker

# Set plot limits
ax.set_xlim(-1.05, 1.05)
ax.set_ylim(-1.05, 1.05)

# Set plot labels
ax.set_xlabel('X')
ax.set_ylabel('Y')

# Set plot title
plt.title('Real-time XY Plot')

try:
    while True:
        # Read line from serial port
        line_data = ser.readline().decode('utf-8').strip()
        
        # Load JSON data
        data = json.loads(line_data)
        
        # Extract x and y values
        x = data['x']
        y = data['y']
        
        # Replace existing data with new data point
        line.set_xdata([0,x])
        line.set_ydata([0,y])
        
        # Redraw plot
        plt.draw()
        plt.pause(0.01)

except KeyboardInterrupt:
    # Close serial port and plot
    ser.close()
    plt.close()
