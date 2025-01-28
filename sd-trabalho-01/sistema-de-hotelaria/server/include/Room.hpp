#ifndef ROOM_HPP
#define ROOM_HPP

#include "Person.hpp"
#include <memory>
#include <ostream>
#include <string>

struct Room {
private:
  int number;
  std::shared_ptr<Person> person;

public:
  Room(int _number = 0, std::shared_ptr<Person> _person = nullptr);

  int getRoomNumber() const;

  std::shared_ptr<Person> getPerson() const;

  std::string str() const;

  friend std::ostream &operator<<(std::ostream &os, const Room &r);
};
#endif // !ROOM_HPP
