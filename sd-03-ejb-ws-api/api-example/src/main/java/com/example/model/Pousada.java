package com.example.model;

public class Pousada extends MeiosDeHospedagem {
	private boolean cafeDaManha;

	public Pousada(String nome, Endereco endereco, int numeroQuartos, double precoDiaria, boolean cafeDaManha) {
		super(nome, endereco, numeroQuartos, precoDiaria);
		this.cafeDaManha = cafeDaManha;
	}

	public boolean getCafeDaManha() {
		return cafeDaManha;
	}

	public void setCafeDaManha(boolean cafeDaManha) {
		this.cafeDaManha = cafeDaManha;
	}

	@Override
	public String toString() {
		return "Pousada{" +
				"nome='" + getNome() + '\'' +
				", endereco=" + getEndereco() +
				", numeroQuartos=" + getNumeroQuartos() +
				", precoDiaria=" + getPrecoDiaria() +
				", cafeDaManha=" + cafeDaManha +
				'}';
	}
}
