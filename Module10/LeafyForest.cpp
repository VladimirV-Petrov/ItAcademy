#include <iostream>

#include "LeafyForest.h"
#include "Pine.h"

void LeafyForest::growUp(Tree* tree)
{
	if (Pine* pine = dynamic_cast<Pine*>(tree))
	{
		std::cout << "Can not add coniferous tree to leafy forest" << std::endl;
		return;
	}

	Forest::growUp(tree);
}
