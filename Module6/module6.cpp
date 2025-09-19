// Module6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>

void reverseString(char* str)
{
	const auto length = std::strlen(str);
	for (int i = 0; i < static_cast<int>(length / 2); ++i)
	{
		const char temp = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = temp;
	}
}

void readAndReverseString()
{
	std::string stdStr;
	std::cout << "Enter string: ";
	std::cin >> stdStr;

	char* cStr = new char[stdStr.size() + 1];
	std::copy(stdStr.c_str(), stdStr.c_str() + stdStr.size() + 1, cStr);
	reverseString(cStr);
	std::cout << cStr << std::endl << std::endl;
	delete[] cStr;

	//Или так
	const auto cStr1 = new char[stdStr.size() + 1];
	std::memcpy(cStr1, stdStr.c_str(), stdStr.size());
	cStr1[stdStr.size()] = '\0';
	reverseString(cStr1);
	std::cout << cStr1 << std::endl << std::endl;
	delete[] cStr1;
}

void createAndPrintArray(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		arr[i] = new int[cols];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			arr[i][j] = i * j;
		}
	}

	std::cout << "Array " << rows << " x " << cols << ":" << std::endl;
	for (int i = 0; i < rows; ++i) 
	{
		for (int j = 0; j < cols; ++j) 
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < rows; ++i) 
	{
		delete[] arr[i];
	}

	delete[] arr;
}

void sortVector(const int size)
{
	std::vector<int> vector(size);

	for (int& val : vector) 
	{
		val = std::rand() % 100 + 1;
	}

	std::cout << "Before sort: " << std::endl;
	for (const int& val : vector) 
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;

	std::sort(vector.begin(), vector.end());

	std::cout << "After sort: " << std::endl;
	for (const int& val : vector) 
	{
		std::cout << val << ' ';
	}
	std::cout << std::endl;
}

void workWithUniquePtr(const int arrayLength)
{
	std::unique_ptr<int[]> ptrArray = std::make_unique<int[]>(arrayLength);

	std::cout << "Enter " << arrayLength << " integer numbers : " << std::endl;
	for (int i = 0; i < arrayLength; ++i)
	{
		std::cin >> ptrArray[i];
	}

	std::cout << "Entered array: " << std::endl;
	for (int i = 0; i < arrayLength; ++i)
	{
		std::cout << ptrArray[i] << ' ';
	}
	std::cout << std::endl;

	auto minVal = std::numeric_limits<int>::max();
	auto maxVal = std::numeric_limits<int>::min();

	for (int i = 0; i < arrayLength; ++i)
	{
		if (ptrArray[i] < minVal) 
			minVal = ptrArray[i];
		if (ptrArray[i] > maxVal) 
			maxVal = ptrArray[i];
	}

	std::cout << "Minimal value: " << minVal << std::endl;
	std::cout << "Maximum value: " << maxVal << std::endl;
}

int main()
{
	std::cout << "Module 6" << std::endl;

	readAndReverseString();

	createAndPrintArray(3, 3);

	sortVector(10);

	workWithUniquePtr(10);
}
