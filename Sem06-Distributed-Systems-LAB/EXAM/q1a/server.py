import socket


def revNumber(number):
    rev = 0
    while (number > 0):
        remainder = number % 10
        rev = (rev * 10) + remainder
        number = number // 10
    return rev


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Socket successfully created")
port = 2001
host = socket.gethostname()
s.bind((host, port))
print("Socket binded to", port)
s.listen(5)
print("Socket is listening")
while True:
    conn, addr = s.accept()
    print('Got connection from', addr)
    data = int(conn.recv(1024).decode())
    print("Number recieved from client : "+str(data))
    data = revNumber(data)
    if not data:
        break
    conn.sendall(bytes(str(data), 'utf-8'))
    print("Reversed number sent to client : "+str(data))
    conn.close()
