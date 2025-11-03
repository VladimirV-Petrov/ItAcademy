#pragma once

#include <string>

class Book
{
private:
	std::string _title;

	std::string _author;

	int _year;

	char* _isbn;

public:
	/// <summary>
	/// Констуктор по умолчанию.
	/// </summary>
	Book();

	/// <summary>
	/// Констуктор с параметрами
	/// </summary>
	Book(const std::string& title, const std::string& author, int year, const char* isbn = nullptr);

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	Book(const Book& book);

	/// <summary>
	/// Деструктор
	/// </summary>
	~Book();

	/// <summary>
	/// Название книги
	/// </summary>
	std::string title() const;

	/// <summary>
	/// Автор книги
	/// </summary>
	std::string author() const;

	/// <summary>
	/// Год выпуска книги
	/// </summary>
	int year() const;

	/// <summary>
	/// ISBN - International Standard Book Number
	/// </summary>
	const char* isbn() const;

	/// <summary>
	/// Печатает информацию о книге
	/// </summary>
	void printInfo() const;
};

