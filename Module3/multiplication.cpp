#include <iostream>

#include "multiplication.h"

void printMultiplicationOver3Loops()
{
	std::cout << std::endl << "Multiplication table using 'for' loop:" << std::endl;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			std::cout << i << " * " << j << " = " << i * j << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "Multiplication table using 'while' loop:" << std::endl;
	int i = 1;
	while (i <= 10) {
		int j = 1;
		while (j <= 10) {
			std::cout << i << " * " << j << " = " << i * j << "\t";
			j++;
		}
		std::cout << std::endl;
		i++;
	}

	std::cout << std::endl << "Multiplication table using 'do-while' loop:" << std::endl;
	i = 1;
	do {
		int j = 1;
		do {
			std::cout << i << " * " << j << " = " << i * j << "\t";
			j++;
		} while (j <= 10);
		std::cout << std::endl;
		i++;
	} while (i <= 10);
}