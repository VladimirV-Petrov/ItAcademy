#pragma once

#include <vector>

#include "Tree.h"

class Forest
{
public:
	/// <summary>
	/// Получение количества деревьев в лесу
	/// </summary>
	size_t getTreesNumber();

	/// <summary>
	/// Добавление дерева в лес
	/// </summary>
	void growUp(const Tree& tree);

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
	std::vector<Tree> _trees;
};

