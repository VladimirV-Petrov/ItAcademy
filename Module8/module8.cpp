// Module8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "book.h"

int main()
{
  Book book1("1984", "George Orwell", 1949, "00000000000001");
  book1.printInfo();

  std::cout << "-------------------------------------------" << std::endl;

  {
    Book book2 = book1;
    book2.printInfo();

    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "Title of book2: " << book2.title() << std::endl;
    std::cout << "Author of book2: " << book2.author() << std::endl;
    std::cout << "Year of book2: " << book2.year() << std::endl;
    std::cout << "ISBN of book2: " << book2.isbn() << std::endl;
  }

  std::cout << std::endl << "Destructor book2 should be called" << std::endl;

  Book book3("2001: A Space Odyssey", "Arthur C. Clarke", 1968);
  book3.printInfo();
  Book book2 = book3;
  book2.printInfo();

  Book book5;
  book5.printInfo();
}
