package com.example;

import com.example.model.Cliente;
import com.example.model.Endereco;
import com.example.model.Hotel;
import com.example.model.Motel;
import com.example.model.Pousada;
import com.example.model.Reserva;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.RemoteException;
import java.util.List;

public class ClientRMI {
    public static void main(String[] args) {
        try {
            // Obtém o registro RMI
            Registry registry = LocateRegistry.getRegistry("localhost", 1099);

            // Obtém a referência remota do serviço
            HotelService hotelService = (HotelService) registry.lookup("HotelService");

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
            int reserva1 = hotelService.registrarReserva(new Reserva(0, cliente1, hotel, "2024-02-23", "2024-02-25"));
            int reserva2 = hotelService.registrarReserva(new Reserva(0, cliente2, motel, "2024-03-01", "2024-03-03"));
            int reserva3 = hotelService.registrarReserva(new Reserva(0, cliente3, pousada, "2024-04-10", "2024-04-15"));

            System.out.println("Reservas registradas com números: " + reserva1 + ", " + reserva2 + ", " + reserva3);

            // Mostra o estado atual das reservas
            mostrarReservas(hotelService);

            // Efetiva a reserva do hotel
            boolean efetivada1 = hotelService.efetivarReserva(reserva1);
            System.out.println("Reserva do hotel efetivada: " + efetivada1);

            // Cancela a reserva do motel
            boolean cancelada2 = hotelService.cancelarReserva(reserva2);
            System.out.println("Reserva do motel cancelada: " + cancelada2);

            // Mostra o estado atual das reservas após operações
            mostrarReservas(hotelService);
        } catch (Exception e) {
            System.err.println("Erro no cliente:");
            e.printStackTrace();
        }
    }

    private static void mostrarReservas(HotelService hotelService) {
        try {
            System.out.println("\n=== Estado Atual das Reservas ===");
            List<Reserva> reservas = hotelService.listarReservas();
            if (reservas.isEmpty()) {
                System.out.println("Nenhuma reserva ativa no momento.");
            } else {
                for (Reserva reserva : reservas) {
                    System.out.println(formatarReserva(reserva));
                }
            }
            System.out.println("===============================\n");
        } catch (RemoteException e) {
            System.err.println("Erro ao listar reservas: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private static String formatarReserva(Reserva reserva) {
        return String.format(
            "Reserva #%d\n" +
            "  Cliente: %s (%s)\n" +
            "  Hospedagem: %s\n" +
            "  Endereço: %s, %s, %s, %s, %s\n" +
            "  Período: %s a %s\n" +
            "  Status: %s\n",
            reserva.getNumero(),
            reserva.getCliente().getNome(),
            reserva.getCliente().getEmail(),
            reserva.getHospedagem().getNome(),
            reserva.getHospedagem().getEndereco().getRua(),
            reserva.getHospedagem().getEndereco().getNumero(),
            reserva.getHospedagem().getEndereco().getCidade(),
            reserva.getHospedagem().getEndereco().getEstado(),
            reserva.getHospedagem().getEndereco().getCep(),
            reserva.getDataEntrada(),
            reserva.getDataSaida(),
            reserva.isEfetivada() ? "Efetivada" : "Pendente"
        );
    }
}
