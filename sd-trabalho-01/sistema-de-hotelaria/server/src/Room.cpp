#include "../include/Room.hpp"
#include "../aux/fn.hpp"
#include <memory>
#include <ostream>
#include <string>

Room::Room(int _number, std::shared_ptr<Person> _person)
    : number(_number), person(_person) {}

int Room::getRoomNumber() const { return this->number; }

std::shared_ptr<Person> Room::getPerson() const { return this->person; }

std::string Room::str() const {
  return fn::format("[{}] - {}", this->number, this->person);
}

std::ostream &operator<<(std::ostream &os, const Room &r) {
  return os << r.str();
}
