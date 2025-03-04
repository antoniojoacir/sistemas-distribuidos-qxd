# Hotel REST API

Este projeto implementa uma API RESTful para gerenciar reservas de hospedagens (hotéis, motéis e pousadas). A API permite registrar, consultar, efetivar e cancelar reservas, além de listar todas as reservas ativas.

## Tecnologias Utilizadas

- **Java**: Linguagem de programação principal.
- **JAX-RS**: Java API for RESTful Web Services, usada para criar os endpoints RESTful.
- **JSON**: Formato de troca de dados entre o cliente e o servidor.
- **Maven**: Gerenciador de dependências e build do projeto.
- **Servidor de Aplicações**: WildFly, TomEE ou qualquer outro compatível com JAX-RS.

## Estrutura do Projeto

### Modelos de Dados

- **Cliente**: Representa um cliente que faz uma reserva.
  - Atributos: `nome`, `cpf`, `telefone`, `email`.
- **Endereco**: Representa o endereço de uma hospedagem.
  - Atributos: `rua`, `numero`, `cidade`, `estado`, `cep`.
- **Hospedagem**: Classe abstrata que representa um meio de hospedagem.
  - Atributos: `nome`, `endereco`, `numeroQuartos`, `precoDiaria`.
- **Hotel**: Representa um hotel.
  - Atributos adicionais: `estrelas`.
- **Motel**: Representa um motel.
  - Atributos adicionais: `horasMinimas`.
- **Pousada**: Representa uma pousada.
  - Atributos adicionais: `cafeDaManha`.
- **Reserva**: Representa uma reserva feita por um cliente.
  - Atributos: `numero`, `cliente`, `hospedagem`, `dataEntrada`, `dataSaida`, `efetivada`.

### Serviços Implementados

A API RESTful expõe os seguintes endpoints:

#### 1. **Registrar Reserva**
- **Método**: `POST`
- **Endpoint**: `/reservas`
- **Descrição**: Registra uma nova reserva.
- **Entrada**: JSON contendo os dados da reserva.
  ```json
  {
    "cliente": { ... },
    "hospedagem": { ... },
    "dataEntrada": "2024-02-23",
    "dataSaida": "2024-02-25"
  }
  ```
- **Saída**: Número da reserva registrada.
``` json
1
```
#### 2. **Cancelar Reserva**

- **Método**: `DELETE`
- **Endpoint**: `/reservas/{numeroReserva}`
- **Descrição**: Cancela uma reserva existente.
- **Entrada**: Número da reserva no caminho da URL.
- **Saída**: true se a reserva foi cancelada com sucesso, false caso contrário.
``` json
true 
```

##### 3. **Efetivar Reserva**

- **Método**: `PUT`
- **Endpoint**: `/reservas/{numeroReserva}/efetivar`
- **Descrição**: Efetiva uma reserva pendente.
- **Entrada**: Número da reserva no caminho da URL.
- **Saída**: true se a reserva foi efetivada com sucesso, false caso contrário.
```json
    true
```
#### 4. **Consultar Reserva**

- **Método**: `GET`
- **Endpoint**: `/reservas/{numeroReserva}`
- **Descrição**: Retorna os detalhes de uma reserva específica.
- **Entrada**: Número da reserva no caminho da URL.
- **Saída**: JSON com os detalhes da reserva.
```json
{
    "numero": 1,
    "cliente": { ... },
    "hospedagem": { ... },
    "dataEntrada": "2024-02-23",
    "dataSaida": "2024-02-25",
    "efetivada": true
}
```
#### 5. **Listar Reservas**

- **Método**: `GET`

- **Endpoint**: /reservas

- **Descrição**: Retorna uma lista de todas as reservas ativas.

- **Saída**: Lista de reservas em formato JSON.
```json
    [
      {
        "numero": 1,
        "cliente": { ... },
        "hospedagem": { ... },
        "dataEntrada": "2024-02-23",
        "dataSaida": "2024-02-25",
        "efetivada": true
      },
      {
        "numero": 2,
        "cliente": { ... },
        "hospedagem": { ... },
        "dataEntrada": "2024-03-01",
        "dataSaida": "2024-03-03",
        "efetivada": false
      }
    ]
```
