#include "../include/Reservation.hpp"
#include "../include/fn.hpp"
#include <memory>
#include <string>

Reservation::Reservation(int _roomQtd) {
  for (int i = 0; i < _roomQtd; i++) {
    this->reservations.emplace(i, std::make_pair("Empty", nullptr));
  }
}

std::string Reservation::WhoIsIn(int _room) const {
  /*
  usando o numero do quarto para pegar o nome da pessoa que está
  nele(Empty||NAME)
  */
  return this->reservations.find(_room)->second.second->getName();
}

void Reservation::EffReservation(std::shared_ptr<Person> _person) {
  _person->setEff(true);
}

std::string Reservation::str() const {
  std::string outputString{""};
  for (auto [first, second] : this->reservations) {
    outputString += fn::format("Room - [{}] || Client [{}]", first, second.second);
  }
  return outputString;
}
