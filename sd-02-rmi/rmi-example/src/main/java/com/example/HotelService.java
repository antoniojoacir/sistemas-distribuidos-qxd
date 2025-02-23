package com.example;

import com.example.model.Reserva;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;

public interface HotelService extends Remote {
	int registrarReserva(Reserva reserva) throws RemoteException;

	boolean cancelarReserva(int numeroReserva) throws RemoteException;

	boolean efetivarReserva(int numeroReserva) throws RemoteException;

	Reserva consultarReserva(int numeroReserva) throws RemoteException;

	List<Reserva> listarReservas() throws RemoteException;
}
