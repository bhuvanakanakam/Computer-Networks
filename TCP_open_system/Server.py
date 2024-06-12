# bhuvana kanakam - se21ucse035
# march 7, lab
# another device 

import socket
import time 

#server configuration
HOST = '10.40.64.233'
PORT = 8088

# create a TCP/IP socket
# becuase using IPV4, have to use AF_INET, if IPV6 can use socker.AF.INET6
#using TCP socket so can use socket stream for TCP connect, but for UDP can use socket.SOCK_DBRAN
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)

#Bind the socket to the address and port
server_socket.bind((HOST,PORT))

#listen for incoming connections
server_socket.listen()
print(f"Server listening on {HOST}:{PORT}")

#accept incoming connections
client_socket, client_address = server_socket.accept()
print(f"Connection from {client_address}")

# Set timeout for 2 minutes
client_socket.settimeout(30)
start_time = time.time()

while True:
    try:
        # Receive data from the client
        message = client_socket.recv(1024).decode()
        print(f"Client: {message}")

        # Send response back to the client
        response = input("Server: ")
        client_socket.sendall(response.encode())

    except socket.timeout:
        print("Connection timed out.")
        break

    # Check if 2 minutes have elapsed
    if time.time() - start_time >= 30:
        print("Timeout reached.")
        break

# Close the connection
client_socket.close()
server_socket.close()

