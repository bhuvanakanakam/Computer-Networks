# bhuvana kanakam - se21ucse035
# march 7, lab

import socket
import time

# server configuration
HOST = '127.0.0.1'
PORT = 8082

# Create a TCP/IP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client_socket.connect((HOST, PORT))

# Set timeout for 2 minutes
client_socket.settimeout(30)

start_time = time.time()

while True:
    try:
        message = input("Client: ")
        client_socket.sendall(message.encode())
        response = client_socket.recv(1024).decode()
        print(f"Server: {response}")

    except socket.timeout:
        print("Connection timed out.")
        break

    # Check if 2 minutes have elapsed
    if time.time() - start_time >= 30:
        print("Timeout reached.")
        break

client_socket.close()

