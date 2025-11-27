#include <iostream>

#include "ConiferousForest.h"
#include "Pine.h"

void ConiferousForest::growUp(Tree* tree)
{
	Pine* pine = dynamic_cast<Pine*>(tree);
	if (!pine)
	{
		std::cout << "Can not add leafy tree to coniferous forest" << std::endl;
		return;
	}

	Forest::growUp(tree);
}
