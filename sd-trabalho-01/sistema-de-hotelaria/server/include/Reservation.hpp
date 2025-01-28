#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include "Room.hpp"

#include <memory>
#include <sched.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Reservation {
protected:
  const int maxRooms = 10;
  std::unordered_map<std::string, std::pair<int, std::shared_ptr<Person>>>
      reservations;
  std::vector<std::shared_ptr<Room>> rooms;

public:
  Reservation();
  virtual ~Reservation() = default;

  virtual void BookRoom(const int &_room, const std::string &_name,
                        const std::string &_cpf);
  virtual void CancelRoomBooking(const int &_room, const std::string &_cpf);
  virtual void EffectiveRoomBooking(std::string _key);
  virtual std::string str() const = 0;
};
#endif // !RESERVATION_HPP
