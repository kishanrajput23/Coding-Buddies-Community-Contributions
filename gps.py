__author__ = 'Amal G Jose'

import time
import serial
import string
from pynmea import nmea

ser = serial.Serial()
# Reading serial data from COM5 port. Change this port according to your settings.
ser.port = "COM5"
ser.baudrate = 9600
ser.timeout = 1
ser.open()
gpgga = nmea.GPGGA()
while True:
    data = ser.readline()
    if data[0:6] == '$GPGGA':
        ##method for parsing the sentence
        gpgga.parse(data)
        lats = gpgga.latitude
        print("Latitude values : " + str(lats))

        lat_dir = gpgga.lat_direction
        print("Latitude direction : " + str(lat_dir))

        longitude = gpgga.longitude
        print("Longitude values : " + str(longitude))

        long_dir = gpgga.lon_direction
        print("Longitude direction : " + str(long_dir))

        time_stamp = gpgga.timestamp
        print("GPS time stamp : " + str(time_stamp))

        alt = gpgga.antenna_altitude
        print("Antenna altitude : " + str(alt))

        lat_deg = lats[0:2]
        lat_mins = lats[2:4]
        lat_secs = round(float(lats[5:])*60/10000, 2)

        latitude_string = lat_deg + u'\N{DEGREE SIGN}' + lat_mins + string.printable[68] + str(lat_secs) + string.printable[63]
        print("Latitude : " + str(latitude_string))

        lon_deg = longitude[0:3]
        lon_mins = longitude[3:5]
        lon_secs = round(float(longitude[6:])*60/10000, 2)
        lon_str = lon_deg + u'\N{DEGREE SIGN}' + lon_mins + string.printable[68] + str(lon_secs) + string.printable[63]
        print("Longitude : " + str(lon_str))