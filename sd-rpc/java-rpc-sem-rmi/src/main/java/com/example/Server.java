package com.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(5000)) {
            System.out.println("Servidor pronto na porta 5000");
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client conectado!");
                try (BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                        PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true)) {
                    String input = in.readLine();
                    System.out.println("Requisição recebida " + input);

                    if (input.startsWith("sayHello:")) {
                        String name = input.split(":")[1];
                        HelloService service = new HelloServiceImpl();
                        String response = service.sayHello(name);
                        out.println(response);
                    } else {
                        out.println("Metodo não suportado.");
                    }
                    clientSocket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
