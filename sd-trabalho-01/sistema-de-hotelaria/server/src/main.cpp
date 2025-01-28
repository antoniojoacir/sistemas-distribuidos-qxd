#include "../aux/fn.hpp"
#include "../include/Lodging.hpp"
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <memory>
#include <mutex>
#include <netdb.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <thread>
#include <unistd.h>
#include <vector>

class TCPServer {
private:
  int listening;
  std::vector<std::thread> client_threads;
  std::mutex thread_mutex;

  Lodging hospedagem;
  void handleClient(int clientSocket, sockaddr_in client) {
    char host[NI_MAXHOST];
    char svc[NI_MAXSERV];
    memset(host, 0, NI_MAXHOST);
    memset(svc, 0, NI_MAXSERV);

    int response = getnameinfo((sockaddr *)&client, sizeof(client), host,
                               NI_MAXHOST, svc, NI_MAXSERV, 0);

    if (response)
      std::cout << host << " connected on " << svc << std::endl;
    else {
      inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
      std::cout << host << " connected on " << ntohs(client.sin_port)
                << std::endl;
    }

    char buf[4096];
    while (true) {
      memset(buf, 0, 4096);
      int bytesRecv = recv(clientSocket, buf, 4096, 0);

      if (bytesRecv == -1) {
        std::cerr << "Error: Connection issue" << std::endl;
        break;
      }
      if (bytesRecv == 0) {
        std::cout << "[" << svc << "]" << " Client disconnected" << std::endl;
        break;
      }

      std::string command(buf, 0, bytesRecv);
      auto args = fn::split(command, ' ');
      std::cout << command << std::endl;
      try {
        if (args[0] == "res") {
          hospedagem.bookRoom(args[1], +args[2], args[3], args[4]);
        } else if (args[0] == "cancel") {
          hospedagem.cancelRoomBooking(args[1], +args[2], args[3]);
        } else if (args[0] == "list") {
          std::string response = hospedagem.getReservationDetails(args[1]);
          send(clientSocket, response.c_str(), response.length() + 1, 0);
        } else {
          fn::write("Comando inválido.");
        }
      } catch (const std::exception &e) {
        fn::write("Erro: " + std::string(e.what()));
      }
    }
    close(clientSocket);
  }

public:
  TCPServer(int port = 50500) {
    listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1) {
      throw std::runtime_error("Error: Can't create the socket");
    }

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    if (bind(listening, (sockaddr *)&hint, sizeof(hint)) == -1) {
      throw std::runtime_error("Error: Can't bind the IP");
    }

    if (listen(listening, SOMAXCONN) == -1) {
      throw std::runtime_error("Error: Can't listen");
    }
  }

  void start() {
    while (true) {
      sockaddr_in client;
      socklen_t clientSize = sizeof(client);

      int clientSocket = accept(listening, (sockaddr *)&client, &clientSize);
      if (clientSocket == -1) {
        std::cerr << "Error: Client cannot connect" << std::endl;
        continue;
      }

      std::lock_guard<std::mutex> lock(thread_mutex);
      client_threads.emplace_back(&TCPServer::handleClient, this, clientSocket,
                                  client);
      client_threads.back().detach();
    }
  }

  ~TCPServer() { close(listening); }
};

int main() {
  try {
    TCPServer server;
    server.start();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return -1;
  }
  return 0;
}
