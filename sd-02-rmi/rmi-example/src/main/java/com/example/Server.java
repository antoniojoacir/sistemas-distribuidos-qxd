package com.example;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server {
	public static void main(String[] args) {
		try {
			HotelServiceImpl hotelService = new HotelServiceImpl();

			Registry registry = LocateRegistry.createRegistry(1099);

			registry.rebind("HotelService", hotelService);

			System.out.println("Servidor RMI iniciado e aguardando conexões na porta 1099...");
		} catch (Exception e) {
			System.err.println("Erro ao iniciar o servidor RMI:");
			e.printStackTrace();
		}
	}
}
