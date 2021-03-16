#!/usr/bin/env python3
import socket
import time

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_host = socket.gethostname()
udp_port = 12345

sock.bind((udp_host, udp_port))

while True:
    print("Waiting for client")
    data, address = sock.recvfrom(1024)
    currentTime = time.ctime(time.time()) + "\r\n"
    print("Received Messages: ", data.decode(), "from", address)
    sock.sendto(currentTime.encode() , address)