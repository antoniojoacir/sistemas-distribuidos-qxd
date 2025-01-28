#include "fn.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

class Person {
private:
  std::string name;
  std::string cpf;
  bool eff = false;

public:
  Person(std::string _name, std::string _cpf) : name(_name), cpf(_cpf) {}

  std::string getName() const { return this->name; }
  std::string getCpf() const { return this->cpf; }

  void setEff(bool _eff) { this->eff = _eff; }

  std::string str() const { return fn::format("{}:{}", this->name, this->cpf); }

  friend std::ostream &operator<<(std::ostream &os, const Person &p) {
    return os << p.str();
  }
};

class Reservation {
protected:
  std::unordered_map<int, std::pair<std::string, std::shared_ptr<Person>>>
      reservations;

public:
  Reservation(int _rooms) {
    for (int i = 0; i < _rooms; i++) {
      this->reservations.emplace(i, std::make_pair("Empty", nullptr));
    }
  }

  virtual std::string WhoIsIn(int _room) const {
    return this->reservations.find(_room)->second.second->getName();
  }

  virtual void EffReservation(std::shared_ptr<Person> _person) {
    _person->setEff(true);
  }

  virtual bool RegisterReservation(int _room, std::shared_ptr<Person> _person) {
    if (reservations.find(_room) == reservations.end()) {
      throw std::runtime_error("Quarto não existe.");
    }

    if (reservations[_room].first != "Empty") {
      throw std::runtime_error("Quarto já está ocupado.");
    }

    reservations[_room] = std::make_pair(_person->getCpf(), _person);
    return true;
  }

  virtual bool CancelReservation(int _room, std::string _cpf) {
    if (reservations.find(_room) == reservations.end()) {
      throw std::runtime_error("Quarto não existe.");
    }

    if (reservations[_room].first == "Empty") {
      throw std::runtime_error("Quarto já está vazio.");
    }

    if (reservations[_room].second->getCpf() != _cpf) {
      throw std::runtime_error("CPF não corresponde à reserva.");
    }

    reservations[_room] = std::make_pair("Empty", nullptr);
    return true;
  }

  virtual std::string str() const {
    std::string outputString{""};
    for (auto [first, second] : this->reservations) {
      outputString +=
          fn::format("Room - [{}] || Client [{}]", first, second.second);
    }
    return outputString;
  }
};

class Motel : public Reservation {
protected:
  std::string name = "Motel";

public:
  Motel(int _rooms) : Reservation(_rooms) {}

  bool RegisterReservation(int _room,
                           std::shared_ptr<Person> _person) override {
    return Reservation::RegisterReservation(_room, _person);
  }

  bool CancelReservation(int _room, std::string _cpf) override {
    return Reservation::CancelReservation(_room, _cpf);
  }

  std::string str() const override {
    std::string outputString{""};
    for (auto [first, second] : this->reservations) {
      if (second.first != "Empty") {
        auto it = second.second;
        outputString += fn::format("({}) Room - [{}] || Client [{}]",
                                   this->name, first, *it);
      }
    }
    return outputString;
  }

  friend std::ostream &operator<<(std::ostream &os, const Motel &r) {
    return os << r.str();
  }
};

class Hotel : public Reservation {
protected:
  std::string name = "Hotel";

public:
  Hotel(int _rooms) : Reservation(_rooms) {}

  bool RegisterReservation(int _room,
                           std::shared_ptr<Person> _person) override {
    return Reservation::RegisterReservation(_room, _person);
  }

  bool CancelReservation(int _room, std::string _cpf) override {
    return Reservation::CancelReservation(_room, _cpf);
  }

  std::string str() const override {
    std::string outputString{""};
    for (auto [first, second] : this->reservations) {
      if (second.first != "Empty") {
        auto it = second.second;
        outputString += fn::format("({}) Room - [{}] || Client [{}]",
                                   this->name, first, *it);
      }
    }
    return outputString;
  }

  friend std::ostream &operator<<(std::ostream &os, const Hotel &r) {
    return os << r.str();
  }
};
