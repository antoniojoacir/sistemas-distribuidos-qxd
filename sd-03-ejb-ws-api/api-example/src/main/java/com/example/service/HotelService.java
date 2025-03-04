package com.example.service;

import com.example.model.Reserva;
import java.util.List;

public interface HotelService {
	int registrarReserva(Reserva reserva);

	boolean cancelarReserva(int numeroReserva);

	boolean efetivarReserva(int numeroReserva);

	Reserva consultarReserva(int numeroReserva);

	List<Reserva> listarReservas();
}
