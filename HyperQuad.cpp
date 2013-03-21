#include "stdafx.h"
#include "HyperQuad.h"

HyperQuad::HyperQuad( void )
{
	TriA = HyperTriangle();
	TriB = HyperTriangle();
}

HyperQuad::HyperQuad( HyperTriangle In_TriA, HyperTriangle In_TriB )
{
	TriA = In_TriA;
	TriB = In_TriB;
}

HyperQuad::HyperQuad( HyperVertex In_VertA, HyperVertex In_VertB, HyperVertex In_VertC, HyperVertex In_VertD )
{
	TriA = HyperTriangle( In_VertA, In_VertB, In_VertC );
	TriB = HyperTriangle( In_VertC, In_VertD, In_VertA );
}

HyperQuad::~HyperQuad( void )
{
}

void HyperQuad::DrawQuad( sf::RenderWindow &In_Window )
{
	TriA.DrawTriangle( In_Window );
	TriB.DrawTriangle( In_Window );
}

void HyperQuad::DrawQuadSansH( sf::RenderWindow &In_Window )
{
	TriA.DrawTriangleSansH( In_Window );
	TriB.DrawTriangleSansH( In_Window );
}

void HyperQuad::SetTri( int Address, HyperTriangle In_Tri )
{
	switch( Address )
	{
	case 0:
		TriA = HyperTriangle( In_Tri );
	case 1:
		TriB = HyperTriangle( In_Tri );
	default:
		return;
	}
}

HyperTriangle HyperQuad::GetTri( int Address )
{
	switch( Address )
	{
	case 0:
		return TriA;
	case 1:
		return TriB;
	default:
		return HyperTriangle();
	}
}

HyperQuad HyperQuad::operator+( HyperVertex In_Vert )
{
	HyperQuad TempQuad = HyperQuad( *this );
	TempQuad.TriA = TempQuad.TriA + In_Vert;
	TempQuad.TriB = TempQuad.TriB + In_Vert;

	return TempQuad;
}

std::string HyperQuad::ToString( void )
{
	return TriA.ToString() + "/" + TriB.ToString();
}