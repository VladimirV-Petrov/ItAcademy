#pragma once

#include <vector>

#include "Tree.h"

class Forest
{
public:
	/// <summary>
	/// Конструктор.
	/// </summary>
	Forest() : _trees(nullptr), _size(0), _capacity(0) {}

	/// <summary>
	/// Дестркутор.
	/// </summary>
	~Forest();

	/// <summary>
	/// Получение количества деревьев в лесу
	/// </summary>
	size_t getTreesNumber();

	/// <summary>
	/// Добавление дерева в лес
	/// </summary>
	virtual void growUp(Tree* tree);

	/// <summary>
	/// Вырубка всех деревьев в лесу
	/// </summary>
	void cutAll();

	/// <summary>
	/// Нужно соединить все деревья обоих лесов и вернуть новый лес
	/// </summary>
	Forest operator+(const Forest& other) const;

	/// <summary>
	/// Выводит на экран информацию о всех деревьях в лесу
	/// </summary>
	void wind() const;

private:
	void reserve(size_t newCapacity);

private:
	Tree** _trees;
	size_t _size;
	size_t _capacity;
};

