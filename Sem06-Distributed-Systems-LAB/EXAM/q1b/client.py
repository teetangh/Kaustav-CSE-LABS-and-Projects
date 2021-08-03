import socket

socket = socket.socket()

port = 1235

socket.connect(('127.0.0.1', port))


input_string = input("Enter data you want to send->")
socket.sendall(bytes(input_string, 'utf-8'))

print(socket.recv(1024).decode())

socket.close()
