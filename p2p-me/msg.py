import socket
import time

UDP_IP = "10.18.112.66"
UDP_Port = 5005
tunnel = (UDP_IP, UDP_Port)
sock = socket.socket(socket.AF_INET, socket.DGRAM )# interet,udp

while True:
    x = raw_inpu("message:   ")
    message = str(x)
    socket.sendto(message, tunnel)
