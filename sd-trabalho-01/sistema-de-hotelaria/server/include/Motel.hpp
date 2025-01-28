#ifndef MOTEL_HPP
#define MOTEL_HPP
#include "Reservation.hpp"
#include <string>

class Motel : public Reservation {
protected:
  const std::string type = "Motel";

public:
  Motel();

  virtual std::string str() const override;

};

#endif
