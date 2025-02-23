package com.example.model;

public class Motel extends MeiosDeHospedagem {
	private int horasMinimas;

	public Motel(String nome, Endereco endereco, int numeroQuartos, double precoDiaria, int horasMinimas) {
		super(nome, endereco, numeroQuartos, precoDiaria);
		this.horasMinimas = horasMinimas;
	}

	public int getHorasMinimas() {
		return horasMinimas;
	}

	public void setHorasMinimas(int horasMinimas) {
		this.horasMinimas = horasMinimas;
	}

	@Override
	public String toString() {
		return "Motel{" +
				"nome='" + getNome() + '\'' +
				", endereco=" + getEndereco() +
				", numeroQuartos=" + getNumeroQuartos() +
				", precoDiaria=" + getPrecoDiaria() +
				", horasMinimas=" + horasMinimas +
				'}';
	}
}
