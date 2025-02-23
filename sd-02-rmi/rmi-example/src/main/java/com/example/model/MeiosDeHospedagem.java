package com.example.model;

import java.io.Serializable;

public abstract class MeiosDeHospedagem implements Serializable {
	protected String nome;
	protected Endereco endereco;
	protected int numeroQuartos;
	protected double precoDiaria;

	public MeiosDeHospedagem(String nome, Endereco endereco, int numeroQuartos, double precoDiaria) {
		this.nome = nome;
		this.endereco = endereco;
		this.numeroQuartos = numeroQuartos;
		this.precoDiaria = precoDiaria;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public Endereco getEndereco() {
		return endereco;
	}

	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}

	public int getNumeroQuartos() {
		return numeroQuartos;
	}

	public void setNumeroQuartos(int numeroQuartos) {
		this.numeroQuartos = numeroQuartos;
	}

	public double getPrecoDiaria() {
		return precoDiaria;
	}

	public void setPrecoDiaria(double precoDiaria) {
		this.precoDiaria = precoDiaria;
	}

	@Override
	public String toString() {
		return "MeiosDeHospedagem{" +
				"nome='" + nome + '\'' +
				", endereco=" + endereco +
				", numeroQuartos=" + numeroQuartos +
				", precoDiaria=" + precoDiaria +
				'}';
	}
}
