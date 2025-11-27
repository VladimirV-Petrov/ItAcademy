#pragma once

#include <iostream>

#include "Car.h"

/// <summary>
/// Класс легкового автомобиля
/// </summary>
class PassengerCar : public Car
{
public:
	PassengerCar(const std::string& name) : Car(name) {}

	friend std::ostream& operator<<(std::ostream& os, const PassengerCar& car)
	{
		os << "PassengerCar: " << car._name << ", Repaired: " << (car._isRepaired ? "Yes" : "No");
		return os;
	}
};
