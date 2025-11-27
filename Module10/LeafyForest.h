#pragma once

#include "Forest.h"

class LeafyForest : public Forest
{
public:
	void growUp(Tree* tree) override;
};

