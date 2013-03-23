#include "stdafx.h"
#include "HyperVertex.h"

HyperVertex::HyperVertex( int n , ... )
{
	Depth_Coefficient = 0.013f;

	va_list args;
	va_start( args, n );
	for( int i = 0; i < n; ++i )
		push_back( (float)va_arg( args, double ) );
	va_end( args );
}

HyperVertex::HyperVertex( void )
{
	Depth_Coefficient = 0.013f; //Field of view
}

HyperVertex::~HyperVertex( void )
{
}

HyperVertex HyperVertex::operator+( const HyperVertex In_HV ) const
{
	if( In_HV.empty() )
		return *this;

	HyperVertex Ret_Vert = HyperVertex();

	std::vector<float>::const_iterator it;
	std::vector<float>::const_iterator it1;

	for( it = begin(), it1 = In_HV.begin() ; it != end() && it1 != In_HV.end() ; ++it, ++it1 )
		Ret_Vert.push_back( *it + *it1 );

	return Ret_Vert;
}

HyperVertex HyperVertex::operator-( const HyperVertex In_HV ) const
{
	if( In_HV.empty() )
		return *this;

	HyperVertex Ret_Vert = HyperVertex();

	std::vector<float>::const_iterator it;
	std::vector<float>::const_iterator it1;

	for( it = begin(), it1 = In_HV.begin() ; it != end() && it1 != In_HV.end() ; ++it, ++it1 )
		Ret_Vert.push_back( *it - *it1 );

	return Ret_Vert;
}

HyperVertex HyperVertex::operator*( const HyperVertex In_HV ) const
{
	if( In_HV.empty() )
		return *this;

	HyperVertex Ret_Vert = HyperVertex();

	std::vector<float>::const_iterator it;
	std::vector<float>::const_iterator it1;

	for( it = begin(), it1 = In_HV.begin() ; it != end() && it1 != In_HV.end() ; ++it, ++it1 )
		Ret_Vert.push_back( *it * *it1 );

	return Ret_Vert;
}

HyperVertex HyperVertex::operator/( const HyperVertex In_HV ) const
{
	if( In_HV.empty() )
		return *this;

	HyperVertex Ret_Vert = HyperVertex();

	std::vector<float>::const_iterator it;
	std::vector<float>::const_iterator it1;

	for( it = begin(), it1 = In_HV.begin() ; it != end() && it1 != In_HV.end() ; ++it, ++it1 )
		Ret_Vert.push_back( *it / *it1 );

	return Ret_Vert;
}

HyperVertex HyperVertex::operator/( const float In_Float ) const
{
	HyperVertex Ret_Vert = HyperVertex();

	std::vector<float>::const_iterator it;

	for( it = begin(); it != end(); ++it )
		Ret_Vert.push_back( *it / In_Float );

	return Ret_Vert;
}

HyperVertex HyperVertex::Rotate( const HyperVertex In_Source, const HyperVertex In_Rotate, const float In_Angle )
{
	HyperVertex TempVert = HyperVertex( In_Source );

	float Temp_Cos = std::cos( In_Angle );
	float Temp_Sin = std::sin( In_Angle );

	TempVert = ( TempVert * Temp_Cos ) + HyperVertex::ExteriorProduct( In_Rotate, TempVert ) * Temp_Sin + In_Rotate * HyperVertex::DotProduct( In_Rotate, TempVert ) * ( 1 - Temp_Cos );

	return TempVert;
}

float HyperVertex::DotProduct( const HyperVertex In_HV1, const HyperVertex In_HV2 )
{
	if( In_HV1.empty() )
		return -1.0f;

	HyperVertex Ret_Vert = HyperVertex();

	std::vector<float>::const_iterator it;
	std::vector<float>::const_iterator it1;

	float x, y = 0;

	for( it = In_HV1.begin(), it1 = In_HV2.begin() ; it != In_HV1.end() && it1 != In_HV2.end() ; ++it, ++it1 )
	{
		x = ( *it / *it1 );
		y += x;
	}

	return y;
}

HyperVertex HyperVertex::ExteriorProduct( const HyperVertex In_HV1, const HyperVertex In_HV2 )
{
	return HyperVertex();
}

sf::Vector2<float> HyperVertex::Project2D( void ) const
{
	HyperVertex TempHyp = HyperVertex( *this );
	std::vector<float>::reverse_iterator it;

	for( it = TempHyp.rbegin(); it != TempHyp.rend(); ++it )
	{
		TempHyp = TempHyp / ( (*it) * Depth_Coefficient );
	}
	return sf::Vector2<float>( TempHyp[0], TempHyp[1] );
}

std::string HyperVertex::ToString( void ) const
{
	std::string Ret_String = "";
	std::stringstream ss = std::stringstream();
	std::vector<float>::const_iterator it;

	for( it = begin(); it != end(); it++ )
		ss << *it << ';';

	ss >> Ret_String;

	return Ret_String;
}