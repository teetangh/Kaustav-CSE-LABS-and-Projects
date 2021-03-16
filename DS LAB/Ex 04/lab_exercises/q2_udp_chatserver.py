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
    
    print("Received Messages: ", data.decode(), "from", address)
    msg = str(input("Enter message to send to client: "))
    sock.sendto(msg.encode(), address)
