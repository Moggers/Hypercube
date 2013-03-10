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

	HyperVertex operator+( HyperVertex In_HV );
	HyperVertex operator-( HyperVertex In_HV );
	HyperVertex operator*( HyperVertex In_HV );
	HyperVertex operator/( HyperVertex In_HV );
	HyperVertex operator/( float In_Float );
	sf::Vector2<float> Project2D( void );
	std::string ToString( void );

private:
	float Depth_Coefficient;
};

