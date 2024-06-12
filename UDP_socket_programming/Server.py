import socket

# Server configuration
HOST = '127.0.0.1'
PORT = 8082

# Create a UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to the address and port
server_socket.bind((HOST, PORT))

print(f"Server listening on {HOST}:{PORT}")

while True:
    # Receive data from the client
    data, _ = server_socket.recvfrom(1024)
    print(f"Client: {data.decode()}")

    # Send response back to the client
    response = input("Server: ")
    server_socket.sendto(response.encode(), _)

# Close the socket
server_socket.close()

