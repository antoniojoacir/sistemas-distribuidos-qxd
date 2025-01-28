#include "../include/Motel.hpp"
#include "../include/fn.hpp"
#include <ostream>
#include <string>

Motel::Motel(int _rooms) : Reservation(_rooms) {}

std::string Motel::str() const {
  std::string outputString{""};
  for (auto [first, second] : this->reservations) {
    outputString += fn::format("({}) Room - [{}] || Client [{}]", this->name,
                               first, second.second->getName());
  }
  return outputString;
}

std::ostream &operator<<(std::ostream &os, const Motel &r) {
  return os << r.str();
}
