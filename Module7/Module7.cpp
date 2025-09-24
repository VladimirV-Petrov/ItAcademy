// Module7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

/**
 * \brief Функция для печати массива.
 */
void printUArray(const std::unique_ptr<int[]>& uArray, int size)
{
	std::cout << "Array from unique_ptr: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << uArray[i] << " ";
	}
	std::cout << std::endl;
}

void enterAndPrintUArray(const int size = 10)
{
	std::unique_ptr<int[]> uArray = std::make_unique<int[]>(size);
	std::cout << "Enter " << size << " integer numbers:" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cin >> uArray[i];
	}

	printUArray(uArray, size);
}

/**
 * \brief Функция для вычисления суммы всех элементов массива.
 */
int sumArray(const std::weak_ptr<int[]>& wArray, int size)
{
	if (auto sArray = wArray.lock())
	{
		int sum{ 0 };
		for (int i = 0; i < size; ++i)
		{
			sum += sArray[i];
		}
		return sum;
	}

	std::cerr << "No more shared array." << std::endl;

	return 0;
}

/**
 * \brief Функция для поиска максимального и минимального элементов массива.
 */
void findMinMax(const std::weak_ptr<int[]>& wArray, int size, int& minVal, int& maxVal)
{
	minVal = std::numeric_limits<int>::max();
	maxVal = std::numeric_limits<int>::min();

	if (auto sArray = wArray.lock())
	{
		for (int i = 0; i < size; ++i)
		{
			const int val = sArray[i];
			if (val < minVal) minVal = val;
			if (val > maxVal) maxVal = val;
		}

		return;
	}

	std::cerr << "No more shared array." << std::endl;
}

void enterAndCalcSArray()
{
	int size{ 0 };
	std::cout << "Enter array size: ";
	std::cin >> size;

	std::shared_ptr<int[]> sArray(new int[size]);
	std::cout << "Enter " << size << " integer numbers:" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cin >> sArray[i];
	}

	std::cout << "Array sum: " << sumArray(sArray, size) << std::endl;

	int minVal{ 0 };
	int maxVal{ 0 };
	findMinMax(sArray, size, minVal, maxVal);
	std::cout << "Array min value: " << minVal << " Array max value: " << maxVal << std::endl;
}

void print(const int value)
{
	std::cout << "int: " << value << std::endl;
}

void print(const float value)
{
	std::cout << "float: " << value << std::endl;
}

void print(const std::string& value)
{
	std::cout << "std::string: " << value << std::endl;
}

void print(const char* array, const int size)
{
	std::cout << "char array: [";
	for (int i = 0; i < size; i++)
	{
		std::cout << "'" << array[i] << "'";
		if (i < size - 1) 
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

void print(const int* array, const int size)
{
	std::cout << "int array: [";
	for (int i = 0; i < size; i++) 
	{
		std::cout << array[i];
		if (i < size - 1) 
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

void print(const std::vector<int>& vector)
{
	std::cout << "std::vector: [";
	for (size_t i = 0; i < vector.size(); i++) 
	{
		std::cout << vector[i];
		if (i < vector.size() - 1) 
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

void print(const std::shared_ptr<int>& sPtr)
{
	if (sPtr != nullptr)
	{
		std::cout << "std::shared_ptr<int>: " << *sPtr << std::endl;
	}
	else 
	{
		std::cout << "std::shared_ptr<int>: nullptr" << std::endl;
	}
}

void print(const std::unique_ptr<double>& uPtr)
{
	if (uPtr != nullptr)
	{
		std::cout << "std::unique_ptr<double>: " << *uPtr << std::endl;
	}
	else 
	{
		std::cout << "std::unique_ptr<double>: nullptr" << std::endl;
	}
}

void printAll()
{
	const char charArr[] = { '1', '2', '3', '4'};
	const int intArr[] = { 1, 2, 3, 4 };

	const std::vector<int> vector = { 10, 20, 30 };

	const auto sharedPtr = std::make_shared<int>(42);
	const auto uniquePtr = std::make_unique<double>(2.71);

	print(777);
	print(3.14f);
	print("String");
	print(charArr, sizeof(charArr) / sizeof(charArr[0]));
	print(intArr, sizeof(intArr) / sizeof(intArr[0]));
	print(vector);
	print(sharedPtr);
	print(uniquePtr);
}

int main()
{
	std::cout << "Module 7" << std::endl;

	enterAndPrintUArray();

	enterAndCalcSArray();

	printAll();
}
