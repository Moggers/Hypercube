// Hypercube Wireframe Rendering.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HyperTriangle.h"
#include "HyperVertex.h"
#include "HyperQuad.h"
#include <iostream>
#include <SFML\Graphics.hpp>

int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow Window = sf::RenderWindow( sf::VideoMode( 512, 512 ), "Testing 1, 2, 3" );

	HyperQuad Quad = HyperQuad( 
		HyperVertex( 3, -50.0f, -50.0f, 50.0f ),
		HyperVertex( 3, 50.0f, -50.0f, 50.0f ),
		HyperVertex( 3, 50.0f, 50.0f, 50.0f ),
		HyperVertex( 3, -50.0f, 50.0f, 50.0f ) );

	while( Window.isOpen() )
	{
		sf::Event TheEvent = sf::Event();
		
		while( Window.pollEvent( TheEvent ) )
		{
			if( TheEvent.type == sf::Event::Closed )
			{
				Window.close();
				return 0;
			}
		}

		HyperVertex Mov = HyperVertex( 3, 0.0f, 0.0f, 0.0f );
		Mov = Mov + ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) ? HyperVertex( 3, -0.2f, 0.0f, 0.0f ) : HyperVertex() );
		Mov = Mov + ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) ? HyperVertex( 3, 0.2f, 0.0f, 0.0f ) : HyperVertex() );
		Mov = Mov + ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) ? HyperVertex( 3, 0.0f, -0.2f, 0.0f ) : HyperVertex() );
		Mov = Mov + ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) ? HyperVertex( 3, 0.0f, 0.2f, 0.0f ) : HyperVertex() );
		Quad = Quad + Mov;

		Window.clear( sf::Color( 0, 0, 0, 255 ) );
		Quad.DrawQuadSansH( Window );
		Window.display();
	}

	return 0;
}