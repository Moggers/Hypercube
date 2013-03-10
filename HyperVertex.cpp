#include "stdafx.h"
#include "HyperVertex.h"

HyperVertex::HyperVertex( int n , ... )
{
	Depth_Coefficient = 0.013;

	va_list args;
	va_start( args, n );
	for( int i = 0; i < n; ++i )
		push_back( (float)va_arg( args, double ) );
	va_end( args );
}

HyperVertex::HyperVertex( void )
{
	Depth_Coefficient = 0.013;
}

HyperVertex::~HyperVertex( void )
{
}

HyperVertex HyperVertex::operator+( HyperVertex In_HV )
{
	if( In_HV.empty() )
		return *this;

	HyperVertex Ret_Vert = HyperVertex();

	std::vector<float>::iterator it;
	std::vector<float>::iterator it1;

	for( it = begin(), it1 = In_HV.begin() ; it != end() && it1 != In_HV.end() ; ++it, ++it1 )
		Ret_Vert.push_back( *it + *it1 );

	return Ret_Vert;
}

HyperVertex HyperVertex::operator-( HyperVertex In_HV )
{
	if( In_HV.empty() )
		return *this;

	HyperVertex Ret_Vert = HyperVertex();

	std::vector<float>::iterator it;
	std::vector<float>::iterator it1;

	for( it = begin(), it1 = In_HV.begin() ; it != end() && it1 != In_HV.end() ; ++it, ++it1 )
		Ret_Vert.push_back( *it - *it1 );

	return Ret_Vert;
}

HyperVertex HyperVertex::operator*( HyperVertex In_HV )
{
	if( In_HV.empty() )
		return *this;

	HyperVertex Ret_Vert = HyperVertex();

	std::vector<float>::iterator it;
	std::vector<float>::iterator it1;

	for( it = begin(), it1 = In_HV.begin() ; it != end() && it1 != In_HV.end() ; ++it, ++it1 )
		Ret_Vert.push_back( *it * *it1 );

	return Ret_Vert;
}

HyperVertex HyperVertex::operator/( HyperVertex In_HV )
{
	if( In_HV.empty() )
		return *this;

	HyperVertex Ret_Vert = HyperVertex();

	std::vector<float>::iterator it;
	std::vector<float>::iterator it1;

	for( it = begin(), it1 = In_HV.begin() ; it != end() && it1 != In_HV.end() ; ++it, ++it1 )
		Ret_Vert.push_back( *it / *it1 );

	return Ret_Vert;
}

HyperVertex HyperVertex::operator/( float In_Float )
{
	HyperVertex Ret_Vert = HyperVertex();

	std::vector<float>::iterator it;

	for( it = begin(); it != end(); ++it )
		Ret_Vert.push_back( *it / In_Float );

	return Ret_Vert;
}

sf::Vector2<float> HyperVertex::Project2D( void )
{
	HyperVertex TempHyp = HyperVertex( *this );

	for( int i = capacity() - 1; i > 1; i-- )
	{
		TempHyp = TempHyp / ( TempHyp[i] * Depth_Coefficient );
	}
	return sf::Vector2<float>( TempHyp[0], TempHyp[1] );
}

std::string HyperVertex::ToString( void )
{
	std::string Ret_String = "";
	std::stringstream ss = std::stringstream();
	std::vector<float>::iterator it;

	for( it = begin(); it != end(); it++ )
		ss << *it << ';';

	ss >> Ret_String;

	return Ret_String;
}