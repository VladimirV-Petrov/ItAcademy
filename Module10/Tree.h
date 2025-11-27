#pragma once

#include <string>

#include "TreeType.h"

class Tree
{
public:
	/// <summary>
	/// Конструктор
	/// </summary>
	Tree(std::string name, TreeType treeType) : _name(name), _treeType(treeType) {}

	/// <summary>
	/// Деструктор.
	/// </summary>
	virtual ~Tree() = default;

	/// <summary>
	/// Выводит на экран имя дерева и его вид
	/// </summary>
	virtual void wind() const = 0;

	// Геттеры
	const std::string& getName() const { return _name; }

protected:
	std::string _name;
	TreeType _treeType;
};


