#include "./include/Lodging.hpp"
#include <iostream>

int main() {
  try {
    // Cria uma instância de Lodging
    Lodging lodging;

    // Teste 1: Reservar um quarto no Hotel
    std::cout << "Reservando um quarto no Hotel..." << std::endl;
    lodging.bookRoom("Hotel", 101, "João Silva", "123.456.789-00");
    std::cout << "Reserva realizada com sucesso!" << std::endl;

    // Teste 2: Reservar um quarto no Motel
    std::cout << "Reservando um quarto no Motel..." << std::endl;
    lodging.bookRoom("Motel", 202, "Maria Oliveira", "987.654.321-00");
    std::cout << "Reserva realizada com sucesso!" << std::endl;

    // Teste 3: Exibir detalhes das reservas
    std::cout << "\nDetalhes das reservas no Hotel:" << std::endl;
    std::cout << lodging.getReservationDetails("Hotel") << std::endl;

    std::cout << "\nDetalhes das reservas no Motel:" << std::endl;
    std::cout << lodging.getReservationDetails("Motel") << std::endl;

    // Teste 4: Cancelar uma reserva no Hotel
    std::cout << "\nCancelando a reserva no Hotel..." << std::endl;
    lodging.cancelRoomBooking("Hotel", 101, "123.456.789-00");
    std::cout << "Reserva cancelada com sucesso!" << std::endl;

    // Teste 5: Exibir detalhes das reservas após o cancelamento
    std::cout << "\nDetalhes das reservas no Hotel após o cancelamento:"
              << std::endl;
    std::cout << lodging.getReservationDetails("Hotel") << std::endl;

    // Teste 6: Tentar reservar um quarto em um tipo de hospedagem inválido
    try {
      std::cout << "\nTentando reservar um quarto em um tipo de hospedagem "
                   "inválido..."
                << std::endl;
      lodging.bookRoom("Pousada", 303, "Carlos Souza", "111.222.333-44");
    } catch (const std::runtime_error &e) {
      std::cout << "Erro capturado: " << e.what() << std::endl;
    }

  } catch (const std::exception &e) {
    std::cerr << "Erro: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
