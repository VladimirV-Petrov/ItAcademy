#pragma once

#include <iostream>

#include "Garage.h"

/// <summary>
/// Сервисная станция. Отвечает за хранение списка машин, их добавление и ремонт.
/// </summary>
/// <typeparam name="T">Тип машины.</typeparam>
template<typename T>
class ServiceStation
{
public:
	ServiceStation(size_t maxCars) : _limit(maxCars) {}

	void addCar(const T& car)
	{
		if (_cars.size() < _limit)
		{
			_cars.push_back(car);
		}
		else
		{
			std::cout << "Error: Limit exceeded, cannot add more cars." << std::endl;
		}
	}

	void repairAll()
	{
		for (auto& car : _cars)
		{
			car.repair();
			_garage.addToGarage(car);
		}
		_cars.clear();
	}

	void displayCars() const
	{
		if (_cars.size() == 0)
		{
			std::cout << "No cars on station." << std::endl;
		}

		for (const auto& car : _cars)
		{
			std::cout << car << std::endl;
		}
	}

	void displayGarage() const
	{
		_garage.displayAll();
	}

private:
	std::vector<T> _cars;
	size_t _limit;
	Garage<T> _garage;
};
