package com.example.model;

public class Hotel extends MeiosDeHospedagem {
	private int estrelas;

	public Hotel(String nome, Endereco endereco, int numeroQuartos, double precoDiaria, int estrelas) {
		super(nome, endereco, numeroQuartos, precoDiaria);
		this.estrelas = estrelas;
	}

	public int getEstrelas() {
		return estrelas;
	}

	public void setEstrelas(int estrelas) {
		this.estrelas = estrelas;
	}

	@Override
	public String toString() {
		return "Hotel{" +
				"nome='" + getNome() + '\'' +
				", endereco=" + getEndereco() +
				", numeroQuartos=" + getNumeroQuartos() +
				", precoDiaria=" + getPrecoDiaria() +
				", estrelas=" + estrelas +
				'}';
	}
}
