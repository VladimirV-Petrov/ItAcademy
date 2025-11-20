#pragma once

#include <iostream>

#include "Car.h"

/// <summary>
/// Класс грузового автомобиля
/// </summary>
class CargoCar : public Car
{
public:
	CargoCar(const std::string& name) : Car(name) {}

	friend std::ostream& operator<<(std::ostream& os, const CargoCar& car)
	{
		os << "CargoCar: " << car._name << ", Repaired: " << (car._isRepaired ? "Yes" : "No");
		return os;
	}
};
