// Module5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "shapes.h"

int main()
{
	std::cout << "Module 5" << std::endl;

	const auto shape { Shapes::Shape::TRIANGLE };

	Shapes::printShape(shape);

	std::string strShape;
	std::cout << "Enter a shape (circle, square, triangle): ";
	std::cin >> strShape;

	Shapes::printShapeByString(strShape);
}
