#include <iostream>

#include "shapes.h"

namespace Shapes
{
	void printShape(Shape shape)
	{
		switch (shape)
		{
		case Shape::CIRCLE:
			std::cout << "CIRCLE" << std::endl;
			break;
		case Shape::SQUARE:
			std::cout << "SQUARE" << std::endl;
			break;
		case Shape::TRIANGLE:
			std::cout << "TRIANGLE" << std::endl;
			break;
		default:
			std::cout << "UNKNOWN SHAPE" << std::endl;
		}
	}

	void printShapeByString(const std::string& str)
	{
		Shape shape;
		if (str == "circle")
		{
			shape = Shape::CIRCLE;
		}
		else if (str == "square")
		{
			shape = Shape::SQUARE;
		}
		else if (str == "triangle")
		{
			shape = Shape::TRIANGLE;
		}
		else
		{
			std::cout << "Unknown shape entered" << std::endl;
			return;
		}

		printShape(shape);
	}
}
