#include "stdafx.h"
#include "HyperTriangle.h"

HyperTriangle::HyperTriangle( HyperVertex In_VertA, HyperVertex In_VertB, HyperVertex In_VertC )
{
	VertA = In_VertA;
	VertB = In_VertB;
	VertC = In_VertC;
}

HyperTriangle::HyperTriangle(void)
{
	VertA = HyperVertex();
	VertB = HyperVertex();
	VertC = HyperVertex();
}

HyperTriangle::~HyperTriangle(void)
{
}

void HyperTriangle::DrawTriangle( sf::RenderWindow &Window )
{
	sf::VertexArray DrawMe = sf::VertexArray( sf::LinesStrip, 4 );
	DrawMe[0] = VertA.Project2D() + sf::Vector2<float>( 256, 256 );
	DrawMe[0].color = sf::Color( 255, 255, 255, 255 );
	DrawMe[1] = VertB.Project2D() + sf::Vector2<float>( 256, 256 );
	DrawMe[1].color = sf::Color( 255, 255, 255, 255 );
	DrawMe[2] = VertC.Project2D() + sf::Vector2<float>( 256, 256 );
	DrawMe[2].color = sf::Color( 255, 255, 255, 255 );
	DrawMe[3] = VertA.Project2D() + sf::Vector2<float>( 256, 256 );
	DrawMe[3].color = sf::Color( 255, 255, 255, 255 );

	Window.draw( DrawMe );
}

void HyperTriangle::DrawTriangleSansH( sf::RenderWindow &Window )
{
	sf::VertexArray DrawMe = sf::VertexArray( sf::LinesStrip, 3 );
	DrawMe[0] = VertA.Project2D() + sf::Vector2<float>( 256, 256 );
	DrawMe[0].color = sf::Color( 255, 255, 255, 255 );
	DrawMe[1] = VertB.Project2D() + sf::Vector2<float>( 256, 256 );
	DrawMe[1].color = sf::Color( 255, 255, 255, 255 );
	DrawMe[2] = VertC.Project2D() + sf::Vector2<float>( 256, 256 );
	DrawMe[2].color = sf::Color( 255, 255, 255, 255 );

	Window.draw( DrawMe );
}

void HyperTriangle::SetVert( int Address, HyperVertex In_HypVert )
{
	switch (Address)
	{
	case 0:
		VertA = In_HypVert;
		return;
	case 1:
		VertB = In_HypVert;
		return;
	case 2:
		VertC = In_HypVert;
		return;
	default:
		return;				
	}
}

HyperVertex HyperTriangle::GetVert( int Address )
{
	switch ( Address )
	{
	case 0:
		return VertA;
	case 1:
		return VertB;
	case 2:
		return VertC;
	default:
		return HyperVertex();
	}
}

HyperTriangle HyperTriangle::operator+( HyperVertex In_Vert )
{
	HyperTriangle TempTri = HyperTriangle( *this );

	TempTri.VertA = TempTri.VertA + In_Vert;
	TempTri.VertB = TempTri.VertB + In_Vert;
	TempTri.VertC = TempTri.VertC + In_Vert;
	
	return TempTri;
}

std::string HyperTriangle::ToString( void )
{
	return VertA.ToString() + '|' + VertB.ToString() + '|' + VertC.ToString();
}