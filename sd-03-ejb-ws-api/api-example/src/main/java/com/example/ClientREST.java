package com.example;

import com.example.model.Cliente;
import com.example.model.Endereco;
import com.example.model.Hotel;
import com.example.model.Motel;
import com.example.model.Pousada;
import com.example.model.Reserva;

import javax.ws.rs.client.Client;
import javax.ws.rs.client.ClientBuilder;
import javax.ws.rs.client.Entity;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

public class ClientREST {
    private static final String BASE_URL = "http://localhost:8080/reservas";

    public static void main(String[] args) {
        Client client = ClientBuilder.newClient();

        // Cria objetos para teste
        Endereco enderecoHotel = new Endereco("Rua A", "123", "Cidade", "Estado", "12345-678");
        Endereco enderecoMotel = new Endereco("Rua B", "456", "Cidade", "Estado", "87654-321");
        Endereco enderecoPousada = new Endereco("Rua C", "789", "Cidade", "Estado", "54321-876");

        Hotel hotel = new Hotel("Hotel Teste", enderecoHotel, 100, 200.0, 4);
        Motel motel = new Motel("Motel Relax", enderecoMotel, 50, 150.0, 6);
        Pousada pousada = new Pousada("Pousada Natureza", enderecoPousada, 30, 100.0, true);

        Cliente cliente1 = new Cliente("João", "123.456.789-00", "11999999999", "joao@email.com");
        Cliente cliente2 = new Cliente("Maria", "987.654.321-00", "11888888888", "maria@email.com");
        Cliente cliente3 = new Cliente("Pedro", "456.789.123-00", "11777777777", "pedro@email.com");

        // Registra as reservas
        int reserva1 = registrarReserva(client, new Reserva(0, cliente1, hotel, "2024-02-23", "2024-02-25"));
        int reserva2 = registrarReserva(client, new Reserva(0, cliente2, motel, "2024-03-01", "2024-03-03"));
        int reserva3 = registrarReserva(client, new Reserva(0, cliente3, pousada, "2024-04-10", "2024-04-15"));

        System.out.println("Reservas registradas com números: " + reserva1 + ", " + reserva2 + ", " + reserva3);

        // Efetiva a reserva do hotel
        boolean efetivada1 = efetivarReserva(client, reserva1);
        System.out.println("Reserva do hotel efetivada: " + efetivada1);

        // Cancela a reserva do motel
        boolean cancelada2 = cancelarReserva(client, reserva2);
        System.out.println("Reserva do motel cancelada: " + cancelada2);

        // Lista as reservas
        listarReservas(client);
    }

    private static int registrarReserva(Client client, Reserva reserva) {
        Response response = client.target(BASE_URL)
                .request(MediaType.APPLICATION_JSON)
                .post(Entity.entity(reserva, MediaType.APPLICATION_JSON));
        return response.readEntity(Integer.class);
    }

    private static boolean cancelarReserva(Client client, int numeroReserva) {
        Response response = client.target(BASE_URL)
                .path(String.valueOf(numeroReserva))
                .request(MediaType.APPLICATION_JSON)
                .delete();
        return response.readEntity(Boolean.class);
    }

    private static boolean efetivarReserva(Client client, int numeroReserva) {
        Response response = client.target(BASE_URL)
                .path(String.valueOf(numeroReserva))
                .path("efetivar")
                .request(MediaType.APPLICATION_JSON)
                .put(Entity.entity("", MediaType.APPLICATION_JSON));
        return response.readEntity(Boolean.class);
    }

    private static void listarReservas(Client client) {
        Response response = client.target(BASE_URL)
                .request(MediaType.APPLICATION_JSON)
                .get();
        System.out.println("Reservas ativas: " + response.readEntity(String.class));
    }
}
