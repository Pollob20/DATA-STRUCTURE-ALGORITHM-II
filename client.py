import socket

# Step 1: Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Step 2: Connect to the server
HOST = '10.10.117.2'
PORT = 5000
client_socket.connect((HOST, PORT))
print(f"[CLIENT] Connected to server at {HOST}:{PORT}")

# Step 3: Chat loop
while True:
    msg = input("You: ")
    client_socket.send(msg.encode())

    if msg.lower() == "exit":
        print("[CLIENT] Chat ended by you.")
        break

    # Receive server’s reply
    reply = client_socket.recv(1024).decode()
    if not reply:
        print("[CLIENT] Server disconnected.")
        break

    print(f"Server: {reply}")

    if reply.lower() == "exit":
        print("[CLIENT] Server ended the chat.")
        break

# Step 4: Close connection
client_socket.close()
print("[CLIENT] Connection closed.")
