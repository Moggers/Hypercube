#include "HyperVertex.h"
#include <SFML\Graphics.hpp>
#include <iostream>

#pragma once
class HyperTriangle
{
public:
	HyperTriangle( void );
	HyperTriangle( HyperVertex In_VertA, HyperVertex In_VertB, HyperVertex In_VertC );
	~HyperTriangle( void );

	HyperTriangle operator+( HyperVertex In_Vert );

	void DrawTriangle( sf::RenderWindow &In_Window );
	void DrawTriangleSansH( sf::RenderWindow &In_Window );

	void SetVert( int Address, HyperVertex In_HypVert );
	HyperVertex GetVert( int Address );

	void MoveTriangle( HyperVertex In_Vert );
	std::string ToString( void );

private:
	HyperVertex VertA;
	HyperVertex VertB;
	HyperVertex VertC;
};

