#include "../include/Motel.hpp"
#include "../aux/fn.hpp"
#include <ostream>
#include <string>

Motel::Motel() : Reservation() {}

std::string Motel::str() const {
  std::string _str{""};
  _str += "Reservas:\n";
  for (auto &[key, value] : this->reservations){
    auto it = *value.second;
    _str += fn::format("{}", it);
  }
  _str += "\nRooms\n";
  for (auto it : this->rooms)
    _str += fn::format("{}", *it);
  return _str;
}

std::ostream &operator<<(std::ostream &os, const Motel &m) {
  return os << m.str();
}
