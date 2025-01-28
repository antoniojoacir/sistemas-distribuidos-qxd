#include "../include/Hotel.hpp"
#include "../aux/fn.hpp"
#include <string>

Hotel::Hotel() : Reservation() {}

std::string Hotel::str() const {
  std::string _str{""};
  _str += "Reservas:\n";
  for (auto [key, value] : this->reservations) {
    auto it = *value.second;
    _str += fn::format("{}", it);
  }
  _str += "\nRooms\n";
  for (auto it : this->rooms)
    _str += fn::format("{}", *it);
  return _str;
}
