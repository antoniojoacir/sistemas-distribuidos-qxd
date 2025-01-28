#include "../include/Person.hpp"
#include "../include/fn.hpp"

Person::Person(std::string _name, std::string _cpf) : name(_name), cpf(_cpf) {}

std::string Person::getName() const { return this->name; }

std::string Person::getCpf() const { return this->cpf; }

void Person::setEff(bool _eff) { this->eff = _eff; }

std::string Person::str() const {
  return fn::format("{}:{}", this->name, this->cpf);
}

std::ostream &operator<<(std::ostream &os, const Person &p) {
  return os << p.str();
}
