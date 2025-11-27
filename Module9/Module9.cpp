#include <iostream>

#include "TreeType.h"
#include "Tree.h"
#include "Forest.h"

int Tree::_treeCount = 0;

int main()
{
	std::cout << "Module 9" << std::endl;

	Tree oak("Oak", TreeType::Oak);
	Tree pine("Pine", TreeType::Pine);
	Tree birch("Birch", TreeType::Birch);

	Forest forest1;
	forest1.growUp(oak);
	forest1.growUp(pine);
	std::cout << "Forest 1 has " << forest1.getTreesNumber() << " trees." << std::endl;
	forest1.wind();

	Forest forest2;
	forest2.growUp(birch);
	std::cout << "Forest 2 has " << forest2.getTreesNumber() << " trees." << std::endl;
	forest2.wind();

	Forest forest = forest1 + forest2;
	std::cout << "Merged forest has " << forest.getTreesNumber() << " trees." << std::endl;
	forest.wind();

	forest.cutAll();
	std::cout << "After cutting, merged forest has " << forest.getTreesNumber() << " trees.\n";

	return 0;
}
