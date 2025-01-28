#ifndef MOTEL_HPP
#define MOTEL_HPP
#include "Reservation.hpp"
#include <ostream>
#include <string>

class Motel : public Reservation {
protected:
  std::string name = "Motel";
public:
  Motel(int _rooms);

  bool RegisterReservation() override;
  bool CancelReservation() override;

  std::string str() const override;

  friend std::ostream &operator<<(std::ostream &os, const Motel &r);
};

#endif // !MOTEL_HPP
