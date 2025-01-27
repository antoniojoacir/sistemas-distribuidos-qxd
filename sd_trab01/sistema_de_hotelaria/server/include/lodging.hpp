#include "body.hpp"
#include "fn.hpp"
#include <filesystem>
#include <fstream>
#include <memory>
#include <string>
namespace fs = std::filesystem;

struct Lodging {
  std::shared_ptr<Reservation> hotel;
  std::shared_ptr<Reservation> motel;
  std::string basePath = ".db";
  void criarPastaSeNaoExistir(const std::string &pasta) {
    if (!fs::exists(pasta)) {
      fs::create_directory(pasta);
    }
  }
  void salvarReservaEmArquivo(const std::string &classe, const std::string &cpf,
                              const std::string &dados) {
    std::string pasta = basePath + "/" + classe;
    criarPastaSeNaoExistir(pasta);

    std::string arquivo = pasta + "/" + cpf + ".bin";
    std::ofstream ofs(arquivo, std::ios::binary);
    if (!ofs) {
      throw std::runtime_error("Erro ao abrir arquivo para escrita: " +
                               arquivo);
    }

    ofs.write(dados.c_str(), dados.size());
    ofs.close();
  }

  std::string lerReservaDoArquivo(const std::string &classe,
                                  const std::string &cpf) {
    std::string arquivo = basePath + "/" + classe + "/" + cpf + ".bin";
    std::ifstream ifs(arquivo, std::ios::binary);
    if (!ifs) {
      throw std::runtime_error("Erro ao abrir arquivo para leitura: " +
                               arquivo);
    }

    std::string dados((std::istreambuf_iterator<char>(ifs)),
                      std::istreambuf_iterator<char>());
    ifs.close();
    return dados;
  }

  Lodging() {
    hotel = std::make_shared<Hotel>(10);

    motel = std::make_shared<Motel>(5);

    criarPastaSeNaoExistir(basePath);
  }

  void addReservation(std::string _type, int _room,
                      std::shared_ptr<Person> _person) {
    if (_type == "hotel") {

      this->hotel->RegisterReservation(_room, _person);
      std::string dados = "Quarto: " + std::to_string(_room) +
                          ", CPF: " + _person->getCpf() +
                          ", Nome: " + _person->getName();
      salvarReservaEmArquivo("Hotel", _person->getCpf(), dados);
    } else

      this->motel->RegisterReservation(_room, _person);
    std::string dados = "Quarto: " + std::to_string(_room) +
                        ", CPF: " + _person->getCpf() +
                        ", Nome: " + _person->getName();
    salvarReservaEmArquivo("Motel", _person->getCpf(), dados);
  }

  void rmReservation(std::string _type, int _room, std::string _cpf) {
    if (_type == "hotel")

      this->hotel->CancelReservation(_room, _cpf);
    else

      this->motel->CancelReservation(_room, _cpf);
  }
  std::string listarReservas(const std::string &classe) {
    std::string pasta = basePath + "/" + classe;
    std::string resultado;

    if (!fs::exists(pasta)) {
      return "Nenhuma reserva encontrada para a classe " + classe + ".\n";
    }

    for (const auto &entry : fs::directory_iterator(pasta)) {
      if (entry.path().extension() == ".bin") {
        std::string cpf = entry.path().stem().string();
        std::string dados = lerReservaDoArquivo(classe, cpf);
        resultado += dados + "\n";
      }
    }

    return resultado.empty()
               ? "Nenhuma reserva encontrada para a classe " + classe + ".\n"
               : resultado;
  }
  std::string show() const {
    auto h = this->hotel->str();

    auto m = this->motel->str();
    return fn::format("HOTEL\n{}\nMOTEL\n{}\n", h, m);
  }
};
