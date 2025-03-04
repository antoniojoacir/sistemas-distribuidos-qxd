# Sistema de Reservas de Hospedagem com RMI

Este projeto implementa um sistema de reservas de hospedagem (hotéis, motéis e pousadas) utilizando **RMI** (Remote Method Invocation) para comunicação entre cliente e servidor. O sistema permite registrar, consultar, efetivar e cancelar reservas, além de listar todas as reservas ativas.

## Tecnologias Utilizadas

- **Java**: Linguagem de programação principal.
- **RMI**: Remote Method Invocation, usado para comunicação remota entre cliente e servidor.
- **Serialização**: Os objetos são serializados para serem transmitidos via RMI.

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

O sistema expõe os seguintes métodos remotos via RMI:

#### 1. **Registrar Reserva**
- **Método**: `registrarReserva(Reserva reserva)`
- **Descrição**: Registra uma nova reserva no sistema.
- **Entrada**: Objeto `Reserva` contendo os dados da reserva.
- **Saída**: Número da reserva registrada.

#### 2. **Cancelar Reserva**
- **Método**: `cancelarReserva(int numeroReserva)`
- **Descrição**: Cancela uma reserva existente.
- **Entrada**: Número da reserva.
- **Saída**: `true` se a reserva foi cancelada com sucesso, `false` caso contrário.

#### 3. **Efetivar Reserva**
- **Método**: `efetivarReserva(int numeroReserva)`
- **Descrição**: Efetiva uma reserva pendente.
- **Entrada**: Número da reserva.
- **Saída**: `true` se a reserva foi efetivada com sucesso, `false` caso contrário.

#### 4. **Consultar Reserva**
- **Método**: `consultarReserva(int numeroReserva)`
- **Descrição**: Retorna os detalhes de uma reserva específica.
- **Entrada**: Número da reserva.
- **Saída**: Objeto `Reserva` com os detalhes da reserva.

#### 5. **Listar Reservas**
- **Método**: `listarReservas()`
- **Descrição**: Retorna uma lista de todas as reservas ativas.
- **Saída**: Lista de objetos `Reserva`.

### Arquivos Principais

- **Server.java**: Inicia o servidor RMI e registra o serviço de reservas.
- **ClientRMI.java**: Cliente que se conecta ao servidor RMI e faz chamadas remotas.
- **HotelService.java**: Interface que define os métodos remotos.
- **HotelServiceImpl.java**: Implementação do serviço de reservas.
- **Modelos de Dados**: `Cliente.java`, `Endereco.java`, `Hotel.java`, `Motel.java`, `Pousada.java`, `Reserva.java`.

### Como Executar

#### Pré-requisitos

- Java JDK instalado.
- Maven instalado.

#### Passos

1. **Inicie o servidor RMI**:
   - Execute o arquivo `Server.java` para iniciar o servidor RMI:
     ```bash
     mvn package -Pserver
     ```
   - O servidor estará aguardando conexões na porta **1099**.

2. **Execute o cliente**:
   - Execute o arquivo `ClientRMI.java` para conectar ao servidor e interagir com o sistema:
     ```bash
     mvn package -Pclient
     ```
3. **Excutar os arquivos**
    - como executamos dois perfis diferentes `server` e `client`, criamos dois jar's diferentes agora basta executar os dois.
        ```bash
        java -jar target/[perfil]-jar-with-dependencies.jar
        ```
4. **Interaja com o sistema**:
   - O cliente fará chamadas remotas ao servidor para registrar, consultar, efetivar e cancelar reservas.

### Exemplo de Funcionamento

1. **Registrar Reserva**:
   - O cliente registra uma reserva para um hotel, motel ou pousada.
   - O servidor retorna o número da reserva.

2. **Efetivar Reserva**:
   - O cliente efetiva uma reserva pendente.
   - O servidor retorna `true` se a reserva foi efetivada com sucesso.

3. **Cancelar Reserva**:
   - O cliente cancela uma reserva existente.
   - O servidor retorna `true` se a reserva foi cancelada com sucesso.

4. **Consultar Reserva**:
   - O cliente consulta os detalhes de uma reserva específica.
   - O servidor retorna os detalhes da reserva.

5. **Listar Reservas**:
   - O cliente solicita a lista de todas as reservas ativas.
   - O servidor retorna a lista de reservas.


