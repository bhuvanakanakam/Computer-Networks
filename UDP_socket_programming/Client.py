#In UDP, the server will not have to listen or accept.
#Instead, it just binds to a specific port.

import socket

# Server configuration
HOST = '127.0.0.1'
PORT = 8082

# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while True:
    message = input("Client: ")

    # Send data to the server
    client_socket.sendto(message.encode(), (HOST, PORT))

    # Receive response from the server
    response, server_address = client_socket.recvfrom(1024)
    print(f"Server: {response.decode()}")

# Close the socket
client_socket.close()

