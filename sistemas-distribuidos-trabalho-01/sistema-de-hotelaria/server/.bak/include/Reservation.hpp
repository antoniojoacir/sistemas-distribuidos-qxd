#ifndef RESERVATION_HPP
#define RESERVATION_HPP
#include "Person.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

class Reservation {
protected:
  std::unordered_map<int, std::pair<std::string, std::shared_ptr<Person>>>
      reservations;

public:
  Reservation(int _rooms);

  virtual std::string WhoIsIn(int _room) const;

  virtual void EffReservation(std::shared_ptr<Person> _person);

  virtual bool RegisterReservation() = 0;

  virtual bool CancelReservation() = 0;

  virtual std::string str() const;
};
#endif
