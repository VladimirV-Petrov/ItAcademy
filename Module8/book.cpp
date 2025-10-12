#include <iostream>

#include "book.h"

Book::Book() : _title(""), _author(""), _year(0), _isbn(nullptr)
{
}

Book::Book(const std::string& title, const std::string& author, int year, const char* isbn) : _title(title), _author(author), _year(year)
{
  if (isbn != nullptr)
  {
    size_t len = strlen(isbn);
    _isbn = new char[len + 1];
    strcpy_s(_isbn, len + 1, isbn);
  }
  else
  {
    _isbn = nullptr;
  }

  std::cout << "Constructor with parameters called" << std::endl;
}

Book::Book(const Book& book) : _title(book._title), _author(book._author), _year(book._year)
{
  if (book._isbn != nullptr)
  {
    size_t len = strlen(book._isbn);
    _isbn = new char[len + 1];
    strcpy_s(_isbn, len + 1, book._isbn);
  }
  else
  {
    _isbn = nullptr;
  }

  std::cout << "Copy constructor called" << std::endl;
}

Book::~Book()
{
  delete[] _isbn;

  std::cout << "Destructor called" << std::endl;
}

std::string Book::title() const
{
  return _title;
}

std::string Book::author() const
{
  return _author;
}

int Book::year() const
{
  return _year;
}

const char* Book::isbn() const
{
  return _isbn;
}

void Book::printInfo() const
{
  std::cout << std::endl << "Title: " << _title << std::endl
    << "Author: " << _author << std::endl
    << "Year: " << _year << std::endl
    << "ISBN: " << (_isbn ? _isbn : "N/A") << std::endl << std::endl;
}
