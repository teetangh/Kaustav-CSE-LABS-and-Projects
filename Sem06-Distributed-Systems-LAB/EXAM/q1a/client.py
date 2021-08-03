import socket
host = socket.gethostname()
port = 2001
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((host, port))
    n = int(input("Enter a number : "))
    s.sendall(bytes(str(n), 'utf-8'))
    print("Reversed Number recieved from server : "+str(s.recv(1024).decode()))
    s.close()
