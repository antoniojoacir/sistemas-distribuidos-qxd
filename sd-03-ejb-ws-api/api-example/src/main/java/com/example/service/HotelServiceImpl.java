package com.example.service;

import com.example.model.Reserva;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class HotelServiceImpl implements HotelService {
	private Map<Integer, Reserva> reservas;
	private int proximoNumeroReserva;

	public HotelServiceImpl() {
		this.reservas = new HashMap<>();
		this.proximoNumeroReserva = 1;
	}

	@Override
	public int registrarReserva(Reserva reserva) {
		System.out.println("Registrando nova reserva para o cliente: " + reserva.getCliente().getNome());
		reservas.put(proximoNumeroReserva, reserva);
		return proximoNumeroReserva++;
	}

	@Override
	public boolean cancelarReserva(int numeroReserva) {
		System.out.println("Cancelando reserva número: " + numeroReserva);
		return reservas.remove(numeroReserva) != null;
	}

	@Override
	public boolean efetivarReserva(int numeroReserva) {
		System.out.println("Efetivando reserva número: " + numeroReserva);
		Reserva reserva = reservas.get(numeroReserva);
		if (reserva != null && !reserva.isEfetivada()) {
			reserva.setEfetivada(true);
			return true;
		}
		return false;
	}

	@Override
	public Reserva consultarReserva(int numeroReserva) {
		System.out.println("Consultando reserva número: " + numeroReserva);
		return reservas.get(numeroReserva);
	}

	@Override
	public List<Reserva> listarReservas() {
		System.out.println("Listando todas as reservas ativas");
		return reservas.values().stream().collect(Collectors.toList());
	}
}
