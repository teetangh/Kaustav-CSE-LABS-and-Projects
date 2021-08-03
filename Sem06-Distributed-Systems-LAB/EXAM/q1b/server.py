import socket

socket = socket.socket()
print("Socket successfully created")

port = 1235

socket.bind(('', port))
print("socket binded to", port)

socket.listen(5)
print("socket is listening")

while True:

    conn, address = socket.accept()
    print('Got connection from', address)

    data = conn.recv(1024).decode()
    data = int(data)

    reverse = 0

    while(data > 0):
        lastDigit = data % 10
        reverse = reverse * 10 + lastDigit
        data = data // 10

    reverse = str(reverse)

    conn.sendall(bytes(reverse, 'utf-8'))

    conn.close()
