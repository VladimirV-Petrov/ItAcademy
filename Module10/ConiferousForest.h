#pragma once

#include "Forest.h"

class ConiferousForest : public Forest
{
public:
	void growUp(Tree* tree) override;
};

