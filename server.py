import socket

# Step 1: Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Step 2: Bind the socket to an IP and port
HOST = '0.0.0.0'  # Localhost (can also use your LAN IP for offline chat)
PORT = 5000          # Port > 1023
server_socket.bind((HOST, PORT))

# Step 3: Start listening for connections
server_socket.listen(1)
print(f"[SERVER] Listening on {HOST}:{PORT}...")

# Step 4: Accept a connection
conn, addr = server_socket.accept()
print(f"[SERVER] Connected with {addr}")

# Step 5: Chat loop — keep communicating until "exit"

while True:
    # Receive message from client
    data = conn.recv(1024).decode()
    if not data:
        # Client closed the connection
        print("[SERVER] Client disconnected.")
        break

    print(f"Client: {data}")

    # If client wants to exit
    if data.lower() == "exit":
        print("[SERVER] Client ended the chat.")
        break

    # Server reply
    reply = input("You: ")
    conn.send(reply.encode())

    if reply.lower() == "exit":
        print("[SERVER] Chat ended by server.")
        break

# Step 6: Close connection
conn.close()
server_socket.close()
print("[SERVER] Connection closed.")