#pragma once
#include "HyperTriangle.h"

class HyperQuad
{
public:
	HyperQuad(void);
	HyperQuad( HyperTriangle In_TriA, HyperTriangle In_TriB );
	HyperQuad( HyperVertex In_VertA, HyperVertex In_VertB, HyperVertex In_VertC, HyperVertex In_VertD );
	~HyperQuad(void);

	void DrawQuad( sf::RenderWindow &In_Window );
	void DrawQuadSansH( sf::RenderWindow &In_Window );

	void SetTri( int Address, HyperTriangle In_Tri );
	HyperTriangle GetTri( int Address );

	HyperQuad operator+( HyperVertex In_Vert );
	std::string ToString( void );


private:
	HyperTriangle TriA;
	HyperTriangle TriB;
};

