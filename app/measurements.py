import sys
import numpy as np
from rplidar import RPLidar

PORT_NAME = 'COM4'


def run():
    lidar = RPLidar(PORT_NAME)
    try:
        print('Recording measurments... Press Crl+C to stop.')
        for scan in lidar.iter_scans():
            print(scan)
    except KeyboardInterrupt:
        print('Stoping.')
    lidar.stop()
    lidar.disconnect()


if __name__ == '__main__':
    run()
