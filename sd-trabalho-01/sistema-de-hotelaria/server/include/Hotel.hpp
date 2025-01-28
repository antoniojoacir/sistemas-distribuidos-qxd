#ifndef HOTEL_HPP
#define HOTEL_HPP
#include "Reservation.hpp"
#include <ostream>
#include <string>

class Hotel : public Reservation {
protected:
  const std::string type = "Hotel";

public:
  Hotel();

  virtual std::string str() const override;

  friend std::ostream &operator<<(std::ostream &os, const Hotel &h) {
    return os << h.str();
  }
};
#endif // !HOTEL_HPP
