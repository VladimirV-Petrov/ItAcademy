#pragma once

#include <string>

/// <summary>
/// Класс автомобиля
/// </summary>
class Car
{
public:
	Car(const std::string& name) : _name(name), _isRepaired(false) {}

	void repair()
	{
		_isRepaired = true;
	}

public:
	std::string _name;
	bool _isRepaired;
};

