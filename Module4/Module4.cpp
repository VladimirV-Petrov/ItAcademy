#include <iostream>

int main()
{
	std::cout << "Module 4" << std::endl;

	int num;
	std::cout << "Enter an integer: ";
	std::cin >> num;

	std::cout << "Result: " << (num > 0 && num % 2 == 0 ? num << 2 : num >> 2) << std::endl;
}
