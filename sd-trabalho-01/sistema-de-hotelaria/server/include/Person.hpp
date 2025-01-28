#ifndef PERSON_HPP
#define PERSON_HPP

#include <ostream>
#include <string>
struct Person {
private:
  std::string name;
  std::string cpf;

public:
  Person(std::string _name = "", std::string _cpf = "");

  std::string getName() const;
  std::string getCpf() const;

  std::string str() const;

  friend std::ostream &operator<<(std::ostream &os, const Person &p);
};

#endif // !PERSON_HPP
