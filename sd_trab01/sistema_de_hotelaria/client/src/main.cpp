#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include "../includes/fn.hpp"

class TCPClient {
private:
  int sock;
  char buffer[4096];
  bool running;

  void receiveMessages() {
    while (running) {
      memset(buffer, 0, 4096);
      int bytesReceived = recv(sock, buffer, 4096, 0);

      if (bytesReceived <= 0) {
        std::cout << "Server disconnected" << std::endl;
        running = false;
        break;
      }

      std::cout << std::string(buffer, 0, bytesReceived)
                << std::endl;
    }
  }

public:
  TCPClient(const std::string &serverIP = "127.0.0.1", int port = 50500) {
    running = true;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
      throw std::runtime_error("Failed to create socket");
    }

    sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, serverIP.c_str(), &serv_addr.sin_addr) <= 0) {
      throw std::runtime_error("Invalid address");
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
      throw std::runtime_error("Connection failed");
    }

    std::cout << "Connected to server" << std::endl;
  }

  void start() {
    std::thread receiveThread(&TCPClient::receiveMessages, this);

    while (running) {
      fn::write("$", "");
      auto line = fn::input();

      if (line == "exit") {
        running = false;
        break;
      }

      send(sock, line.c_str(), line.length(), 0);
    }

    if (receiveThread.joinable()) {
      receiveThread.join();
    }

    close(sock);
  }

  ~TCPClient() { close(sock); }
};

int main() {
  try {
    TCPClient client;
    client.start();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return -1;
  }
  return 0;
}
