#include <iostream>

#include "TreeType.h"
#include "Tree.h"
#include "Oak.h"
#include "Pine.h"
#include "Birch.h"
#include "Forest.h"
#include "LeafyForest.h"
#include "ConiferousForest.h"

int Oak::_oakCount = 0;
int Pine::_pineCount = 0;
int Birch::_birchCount = 0;

int main()
{
	std::cout << "Module 10" << std::endl;

	Tree* oak = new Oak("Oak");
	Tree* pine = new Pine("Pine");
	Tree* birch = new Birch("Birch");
	Tree* birch2= new Birch("Birch2");

	Forest* forest1 = new LeafyForest();
	forest1->growUp(oak);
	forest1->growUp(pine);
	forest1->growUp(birch);
	forest1->growUp(birch2);
	std::cout << "Forest 1 has " << forest1->getTreesNumber() << " trees." << std::endl;
	forest1->wind();

	Forest* forest2 = new ConiferousForest();
	forest2->growUp(birch);
	forest2->growUp(pine);
	std::cout << "Forest 2 has " << forest2->getTreesNumber() << " trees." << std::endl;
	forest2->wind();

	std::cout << "Tree count in forests Oak:" << Oak::getOakCount() << " Pine:" << Pine::getPineCount() << " Birch:" << Birch::getBirchCount() << std::endl;

	forest1->cutAll();
	std::cout << "After cutting, forest1 has " << forest1->getTreesNumber() << std::endl;

	forest2->cutAll();
	std::cout << "After cutting, forest2 has " << forest2->getTreesNumber() << std::endl;

	delete forest1;
	delete forest2;

	std::cout << "Tree count in forests after destroy Oak:" << Oak::getOakCount() << " Pine:" << Pine::getPineCount() << " Birch:" << Birch::getBirchCount() << std::endl;

	return 0;
}
