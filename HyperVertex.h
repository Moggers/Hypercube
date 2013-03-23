#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <iostream>
#include <stdarg.h>
#include <sstream>

class HyperVertex: public std::vector<float>
{
public:
	HyperVertex( int n, ... );
	HyperVertex( void );
	~HyperVertex( void );

	HyperVertex operator+( const HyperVertex In_HV ) const;
	HyperVertex operator-( const HyperVertex In_HV ) const;
	HyperVertex operator*( const HyperVertex In_HV ) const;
	HyperVertex operator/( const HyperVertex In_HV ) const;
	HyperVertex operator/( const float In_Float ) const;
	HyperVertex static Rotate( const HyperVertex In_Source, const HyperVertex In_Rotate, const float In_Angle );
	float static DotProduct( const HyperVertex In_HV1, const HyperVertex In_HV2 );
	HyperVertex static ExteriorProduct( const HyperVertex In_HV1, const HyperVertex In_HV2 ); //Not implemented
	sf::Vector2<float> Project2D( void ) const;
	std::string ToString( void ) const;

private:
	float Depth_Coefficient;
};

