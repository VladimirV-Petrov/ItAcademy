#include <iostream>
#include <string>

#include "factorial.h"

//Определение компилятора
#if defined(__clang__)
	#define COMPILER_INFO "Clang " __clang_version__
#elif defined(__GNUC__) || defined(__GNUG__)
	#define COMPILER_INFO "GCC " __VERSION__
#elif defined(_MSC_VER)
	#define COMPILER_INFO "Microsoft Visual C++ " + std::to_string(_MSC_VER)
#else
	#define COMPILER_INFO "Unknown Compiler"
#endif

//Определение операционной системы
#if defined(_WIN32) || defined(_WIN64)
	#define OS_INFO "Windows"
#elif defined(__linux__)
	#define OS_INFO "Linux"
#elif defined(__APPLE__) && defined(__MACH__)
	#define OS_INFO "macOS"
#elif defined(__unix__)
	#define OS_INFO "Unix"
#else
	#define OS_INFO "Unknown OS"
#endif

//Определение архитектуры
#if defined(__x86_64__) || defined(_M_X64)
	#define ARCH_INFO "x86_64"
#elif defined(__i386__) || defined(_M_IX86)
	#define ARCH_INFO "x86"
#elif defined(__arm__)
	#define ARCH_INFO "ARM"
#else
	#define ARCH_INFO "Unknown Architecture"
#endif

int main()
{
  TYPE_FOR_FACTORIAL number = 5;
  auto result = factorial(number);
  std::cout << "Factorial of " << number << " is " << result << std::endl << std::endl;

  std::cout << "System information:" << std::endl << std::endl;

  std::cout << "Compiler:" << std::endl;
  std::cout << "  " << COMPILER_INFO << std::endl << std::endl;

	std::cout << "Operation system:" << std::endl;
  std::cout << "  " << OS_INFO << std::endl << std::endl;

  std::cout << "Architecture:" << std::endl;
  std::cout << "  " << ARCH_INFO << std::endl << std::endl;

	//Так и не заставил студию отдавать правильный стандарт, отличный от 199711
	//Добавление опции /Zc:__cplusplus в проект не помогло.
  std::cout << "Standard C++:" << std::endl;
  std::cout << "  " << __cplusplus << std::endl << std::endl;

/*
	 На ресурсе: https://www.onlinegdb.com/online_c++_compiler
	 Вывод программы следующий:
	 
		System information:

		Compiler:
			GCC 13.3.0

		Operation system:
			Linux

		Architecture:
			x86_64

		Standard C++:
			201103



	 На ресурсе: https://www.programiz.com/cpp-programming/online-compiler/
	 Вывод программы следующий:
	 
		System information:

		Compiler:
			GCC 14.2.0

		Operation system:
			Linux

		Architecture:
			x86_64

		Standard C++:
			201703
*/

	return 0;
}
