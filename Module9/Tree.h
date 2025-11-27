#pragma once

#include <string>

#include "TreeType.h"

class Tree
{
public:
	/// <summary>
	/// Конструктор
	/// </summary>
	Tree(std::string name, TreeType treeType) : _name(name), _treeType(treeType), _id(++_treeCount) {}

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	Tree(const Tree& other) : _name(other._name), _treeType(other._treeType), _id(++_treeCount) {}

	/// <summary>
	/// Выводит на экран имя дерева и его id
	/// </summary>
	void wind() const;

	// Геттеры
	int getId() const { return _id; }
	const std::string& getName() const { return _name; }

	static int getTreeCount() { return _treeCount; }

private:
	int _id;
	std::string _name;
	TreeType _treeType;

	static int _treeCount;
};


