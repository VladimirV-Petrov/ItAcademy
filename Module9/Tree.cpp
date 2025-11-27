#include <iostream>
#include "Tree.h"

void Tree::wind() const
{
	std::cout << "Tree name: " << getName() << ", ID: " << getId() << std::endl;
}
