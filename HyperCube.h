#pragma once
#include <vector>
#include "HyperVertex.h"
#include <bitset>

class HyperCube
{
public:
	HyperCube(void);
	HyperCube( int n );
	~HyperCube(void);

private:
	std::vector<HyperVertex> VertList;
};