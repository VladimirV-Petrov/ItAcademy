#include "Forest.h"

size_t Forest::getTreesNumber() 
{ 
	return _trees.size(); 
}

void Forest::growUp(const Tree& tree)
{
	_trees.push_back(tree);
}

void Forest::cutAll()
{
	_trees.clear();
}

Forest Forest::operator+(const Forest& other) const
{
	Forest resultForest;

	resultForest._trees = this->_trees;
	resultForest._trees.insert(resultForest._trees.end(), other._trees.begin(), other._trees.end());

	return resultForest;
}

void Forest::wind() const
{
	for (const auto& tree: _trees)
	{
		tree.wind();
	}
}
