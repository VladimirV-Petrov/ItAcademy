#include <iostream>
#include <string>
#include <vector>

#include "Car.h"
#include "PassengerCar.h"
#include "CargoCar.h"

#include "ServiceStation.h"

int main() 
{
	ServiceStation<PassengerCar> passengerStation(5);
	ServiceStation<CargoCar> cargoStation(5);

	// Добавляем 6 машин в каждую СТО (при лимите 5)
	for (int i = 1; i <= 6; i++) 
	{
		passengerStation.addCar(PassengerCar("PassengerCar_" + std::to_string(i)));
		cargoStation.addCar(CargoCar("CargoCar_" + std::to_string(i)));
	}

	std::cout << "Passenger cars at station before repair:" << std::endl;
	passengerStation.displayCars();
	std::cout << std::endl;

	std::cout << "Cargo cars at station before repair:" << std::endl;
	cargoStation.displayCars();
	std::cout << std::endl;

	passengerStation.repairAll();
	cargoStation.repairAll();

	std::cout << "Passenger cars at station after repair:" << std::endl;
	passengerStation.displayCars();
	std::cout << std::endl;

	std::cout << "Cargo cars at station after repair:" << std::endl;
	cargoStation.displayCars();
	std::cout << std::endl;

	std::cout << "Passenger cars in garage:" << std::endl;
	passengerStation.displayGarage();
	std::cout << std::endl;

	std::cout << "Cargo cars in garage:" << std::endl;
	cargoStation.displayGarage();
	std::cout << std::endl;

	return 0;
}
