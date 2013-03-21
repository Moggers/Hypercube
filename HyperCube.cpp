#include "stdafx.h"
#include "HyperCube.h"


HyperCube::HyperCube(void)
{
}

HyperCube::HyperCube( int n )
{
	int VertCount = std::pow( n, 2 ) - 1;


	std::bitset<64>( 0 ).to_string();
	VertList.push_back( HyperVertex( n, 0, 0, 0 ) );
}

HyperCube::~HyperCube(void)
{
}