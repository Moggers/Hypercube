#include "stdafx.h"
#include "HyperCube.h"


HyperCube::HyperCube(void)
{
}

HyperCube::HyperCube( int n )
{
	VertList.push_back( HyperVertex( n, 0, 0, 0 ) );
}

HyperCube::~HyperCube(void)
{
}
