package com.example.model;

import java.io.Serializable;

public class Cliente implements Serializable {
	private String nome;
	private String cpf;
	private String telefone;
	private String email;

	public Cliente(String nome, String cpf, String telefone, String email) {
		this.nome = nome;
		this.cpf = cpf;
		this.telefone = telefone;
		this.email = email;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	@Override
	public String toString() {
		return "Cliente{" +
				"nome='" + nome + '\'' +
				", cpf='" + cpf + '\'' +
				", telefone='" + telefone + '\'' +
				", email='" + email + '\'' +
				'}';
	}
}
