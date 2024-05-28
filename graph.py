import serial
import time
import matplotlib.pyplot as plt

# Configure the serial port (adjust 'COM3' and baud rate as needed)
ser = serial.Serial('COM3', 9600)  # Replace 'COM3' with the actual COM port of your ESP32

times = []
distances = []
num_readings = 1000  # Number of readings to collect

start_time = time.time()

while len(times) < num_readings:
    line = ser.readline().decode('utf-8').strip()
    if line:
        try:
            distance = float(line)
            current_time = time.time() - start_time  # Calculate elapsed time
            times.append(current_time)
            distances.append(distance)
        except ValueError:
             pass  # Ignore lines that cannot be converted to float

ser.close()

# Process and visualize the data
plt.plot(times, distances)
plt.xlabel('Time (seconds)')
plt.ylabel('Distance (cm)')
plt.title('Distance vs. Time')
plt.show()
