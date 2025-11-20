#pragma once

#include <iostream>

/// <summary>
/// Гараж. Отвечает за хранение отремонтированных машин.
/// </summary>
/// <typeparam name="T">Тип машины.</typeparam>
template<typename T>
class Garage
{
public:
	void addToGarage(const T& car)
	{
		_repairedCars.push_back(car);
	}

	void displayAll() const
	{
		if (_repairedCars.size() == 0)
		{
			std::cout << "No cars in garage." << std::endl;
		}

		for (const auto& car : _repairedCars)
		{
			std::cout << car << std::endl;
		}
	}

private:
	std::vector<T> _repairedCars;
};