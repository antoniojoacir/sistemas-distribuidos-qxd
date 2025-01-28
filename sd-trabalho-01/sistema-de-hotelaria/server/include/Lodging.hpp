#ifndef LODGING_HPP
#define LODGING_HPP

#include "Hotel.hpp"
#include "Motel.hpp"
#include <filesystem>
#include <fstream>
#include <memory>
#include <string.h>
#include <string>
#include <unordered_map>

namespace fs = std::filesystem;

class Lodging {
private:
  std::unordered_map<std::string, std::shared_ptr<Reservation>> lodgings;

  struct ReservationData {
    char type[10]; // Type of lodging (Hotel/Motel)
    int room;      // Room number
    char name[50]; // Name of the person
    char cpf[15];  // CPF of the person
  };

  const std::string basePath = ".db";

  void createFoldersIfNotExist(const std::string &type) {
    if (!fs::exists(basePath)) {
      fs::create_directory(basePath);
    }
    std::string typePath = basePath + "/" + type;
    if (!fs::exists(typePath)) {
      fs::create_directory(typePath);
    }
  }

  void createBinaryFile(const std::string &cpf, const std::string &type,
                        int room, const std::string &name) {
    std::string typePath = basePath + "/" + type;
    createFoldersIfNotExist(type);

    ReservationData data;
    strncpy(data.type, type.c_str(), sizeof(data.type) - 1);
    data.type[sizeof(data.type) - 1] = '\0';
    data.room = room;
    strncpy(data.name, name.c_str(), sizeof(data.name) - 1);
    data.name[sizeof(data.name) - 1] = '\0';
    strncpy(data.cpf, cpf.c_str(), sizeof(data.cpf) - 1);
    data.cpf[sizeof(data.cpf) - 1] = '\0';

    std::ofstream file(typePath + "/" + cpf + ".bin", std::ios::binary);
    if (file.is_open()) {
      file.write(reinterpret_cast<char *>(&data), sizeof(data));
      file.close();
    } else {
      throw std::runtime_error("Error: Unable to create binary file for CPF " +
                               cpf);
    }
  }

  void deleteBinaryFile(const std::string &cpf, const std::string &type) {
    std::string filePath = basePath + "/" + type + "/" + cpf + ".bin";
    if (fs::exists(filePath)) {
      if (std::remove(filePath.c_str()) != 0) {
        throw std::runtime_error(
            "Error: Unable to delete binary file for CPF " + cpf);
      }
    }
  }

  void loadExistingReservations() {
    if (!fs::exists(basePath)) {
      return; // Se a pasta base não existir, não há reservas para carregar
    }

    for (const auto &typeEntry : fs::directory_iterator(basePath)) {
      if (typeEntry.is_directory()) {
        std::string type = typeEntry.path().filename().string();

        for (const auto &fileEntry : fs::directory_iterator(typeEntry.path())) {
          if (fileEntry.is_regular_file() &&
              fileEntry.path().extension() == ".bin") {
            std::string cpf = fileEntry.path()
                                  .stem()
                                  .string(); // Obtém o CPF do nome do arquivo
            std::ifstream file(fileEntry.path().string(), std::ios::binary);
            if (file.is_open()) {
              ReservationData data;
              file.read(reinterpret_cast<char *>(&data), sizeof(data));
              file.close();

              std::string name(data.name);
              int room = data.room;

              auto it = lodgings.find(type);
              if (it != lodgings.end()) {
                it->second->BookRoom(room, name, cpf);
              } else {
                throw std::runtime_error(
                    "Error: Invalid lodging type in file " + cpf + ".bin");
              }
            }
          }
        }
      }
    }
  }

public:
  Lodging() {
    this->lodgings.emplace("Hotel", std::make_shared<Hotel>());
    this->lodgings.emplace("Motel", std::make_shared<Motel>());

    loadExistingReservations();
  }

  void bookRoom(const std::string &type, int room, const std::string &name,
                const std::string &cpf) {
    auto it = lodgings.find(type);
    if (it != lodgings.end()) {
      it->second->BookRoom(room, name, cpf);
      createBinaryFile(cpf, type, room, name); // Cria o arquivo binário
    } else {
      throw std::runtime_error("Error: Invalid lodging type");
    }
  }

  void cancelRoomBooking(const std::string &type, int room,
                         const std::string &cpf) {
    auto it = lodgings.find(type);
    if (it != lodgings.end()) {
      it->second->CancelRoomBooking(room, cpf);
      deleteBinaryFile(cpf, type); // Deleta o arquivo binário
    } else {
      throw std::runtime_error("Error: Invalid lodging type");
    }
  }

  std::string getReservationDetails(const std::string &type) const {
    auto it = lodgings.find(type);
    if (it != lodgings.end()) {
      return it->second->str();
    } else {
      throw std::runtime_error("Error: Invalid lodging type");
    }
  }
};

#endif // LODGING_HPP
