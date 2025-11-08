#include "Forest.h"

Forest::~Forest()
{
	cutAll();
}

size_t Forest::getTreesNumber()
{
	return _size;
}

void Forest::growUp(Tree* tree)
{
	if (_size == _capacity)
		reserve(_capacity == 0 ? 1 : _capacity * 2);

	_trees[_size++] = tree;
}

void Forest::cutAll()
{
	for (size_t i = 0; i < this->_size; ++i)
	{
		delete _trees[i];
		_trees[i] = nullptr;
	}
	delete[] _trees;
	_trees = nullptr;
	_size = 0;
	_capacity = 0;
}

Forest Forest::operator+(const Forest& other) const
{
	Forest resultForest;
	resultForest.reserve(this->_size + other._size);

	for (size_t i = 0; i < this->_size; ++i)
	{
		resultForest.growUp(this->_trees[i]);
	}

	for (size_t i = 0; i < other._size; ++i)
	{
		resultForest.growUp(other._trees[i]);
	}

	return resultForest;
}

void Forest::wind() const
{
	for (size_t i = 0; i < _size; ++i)
	{
		_trees[i]->wind();
	}
}

void Forest::reserve(size_t newCapacity)
{
	Tree** newArray = new Tree* [newCapacity];

	for (size_t i = 0; i < _size; ++i)
	{
		newArray[i] = _trees[i];
	}

	delete[] _trees;
	_trees = newArray;
	_capacity = newCapacity;
}
