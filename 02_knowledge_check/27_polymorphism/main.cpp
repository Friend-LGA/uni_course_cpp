// https://www.cplusplus.com/doc/tutorial/polymorphism/

#include <iostream>
#include <memory>
#include <vector>

class Vehicle {
 public:
  virtual void move() = 0;
  virtual ~Vehicle() = default;
};

class TwoWheeledVehicle : public Vehicle {};
class FourWheeledVehicle : public Vehicle {};
class CaterpillarVehicle : public Vehicle {};

class Bicycle : public Vehicle {
 public:
  void move() override { std::cout << "Bicycle is moving" << std::endl; }
};

class Motorcycle : public Vehicle {
 public:
  void move() override { std::cout << "Motorcycle is moving" << std::endl; }
};

class Car : public FourWheeledVehicle {
 public:
  void move() override { std::cout << "Car is moving" << std::endl; }
};

class Truck : public FourWheeledVehicle {
 public:
  void move() override { std::cout << "Truck is moving" << std::endl; }
};

class Tank : public CaterpillarVehicle {
 public:
  void move() override { std::cout << "Tank is moving" << std::endl; }
};

int main() {
  auto bicycle = std::make_unique<Bicycle>();
  auto motorcycle = std::make_unique<Motorcycle>();
  auto car = std::make_unique<Car>();
  auto truck = std::make_unique<Truck>();
  auto tank = std::make_unique<Tank>();

  std::vector<std::unique_ptr<Vehicle>> vehicles;
  vehicles.push_back(std::move(bicycle));
  vehicles.push_back(std::move(motorcycle));
  vehicles.push_back(std::move(car));
  vehicles.push_back(std::move(truck));
  vehicles.push_back(std::move(tank));

  for (const auto& vehicle : vehicles) {
    vehicle->move();
  }

  return 0;
}
