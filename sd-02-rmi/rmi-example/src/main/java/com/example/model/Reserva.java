package com.example.model;

import java.io.Serializable;

public class Reserva implements Serializable {
	private int numero;
	private Cliente cliente;
	private MeiosDeHospedagem hospedagem;
	private String dataEntrada;
	private String dataSaida;
	private boolean efetivada;

	public Reserva(int numero, Cliente cliente, MeiosDeHospedagem hospedagem, String dataEntrada,
			String dataSaida) {
		this.numero = numero;
		this.cliente = cliente;
		this.hospedagem = hospedagem;
		this.dataEntrada = dataEntrada;
		this.dataSaida = dataSaida;
		this.efetivada = false;
	}

	public int getNumero() {
		return numero;
	}

	public Cliente getCliente() {
		return cliente;
	}

	public MeiosDeHospedagem getHospedagem() {
		return hospedagem;
	}

	public String getDataEntrada() {
		return dataEntrada;
	}

	public String getDataSaida() {
		return dataSaida;
	}

	public boolean isEfetivada() {
		return efetivada;
	}

	public void setEfetivada(boolean efetivada) {
		this.efetivada = efetivada;
	}

	@Override
	public String toString() {
		return "Reserva{" +
				"numero=" + numero +
				", cliente=" + cliente +
				", hospedagem=" + hospedagem +
				", dataEntrada='" + dataEntrada + '\'' +
				", dataSaida='" + dataSaida + '\'' +
				", efetivada=" + efetivada +
				'}';
	}
}
