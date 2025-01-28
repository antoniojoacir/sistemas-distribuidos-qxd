#include "../include/Reservation.hpp"
#include "../aux/fn.hpp"
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

Reservation::Reservation() {}

void Reservation::EffectiveRoomBooking(std::string _key) {
  auto it = this->reservations.find(_key);
  if (it == this->reservations.end())
    throw std::runtime_error("Error: cpf não encontrado");
  for (auto &_person : this->rooms) {
    auto it2 = _person->getPerson();
    if (it2->getName() == it->second.second->getName())
      throw std::runtime_error("Error: pessoa já efetivou a reserva");
  }
  int room = it->second.first;
  auto person = it->second.second;
  this->rooms.push_back(std::make_shared<Room>(room, person));
}

void Reservation::BookRoom(const int &_room, const std::string &_name,
                           const std::string &_cpf) {

  if (_room < 1)
    throw std::runtime_error(
        fn::format("Error: {} é um numero invalido", _room));

  auto it = this->reservations.find(_cpf);
  if (it != this->reservations.end())
    throw std::runtime_error(fn::format("Error: {} já registrado", _cpf));

  this->reservations.emplace(
      _cpf, std::make_pair(_room, std::make_shared<Person>(_name, _cpf)));
}

void Reservation::CancelRoomBooking(const int &_room, const std::string &_cpf) {
  if (_room < 1)
    throw std::runtime_error(
        fn::format("Error: {} é um numero invalido", _room));
  auto it = this->reservations.find(_cpf);
  if (it == this->reservations.end())
    throw std::runtime_error(fn::format("Error: {} cpf invalido", _cpf));
  this->reservations.erase(it);
}
