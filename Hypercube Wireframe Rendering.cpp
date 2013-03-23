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
	//Iniitialize rendering resources
	sf::RenderWindow Window = sf::RenderWindow( sf::VideoMode( 512, 512 ), "Testing 1, 2, 3" );
	sf::Font Comic_Sans;
	Comic_Sans.loadFromFile( "comic.ttf" );

	//Initialize debugging text
	sf::Text TheText;
	TheText.setPosition( sf::Vector2<float>( 10, 10 ) );
	TheText.setColor( sf::Color( 255, 255, 255, 255 ) );
	TheText.setScale( 0.5, 0.5 );
	TheText.setFont( Comic_Sans );

	//Debugging vector
	HyperVertex Temp = HyperVertex( 3, 30.0f, 0.0f, 0.0f );

	//Main loop
	while( Window.isOpen() )
	{
		//Handle events
		sf::Event TheEvent = sf::Event();

		while( Window.pollEvent( TheEvent ) )
		{
			if( TheEvent.type == sf::Event::Closed )
			{
				Window.close();
				return 0;
			}
		}

		//Execute debugging (Euler vector manipulation)
		Temp = HyperVertex::Rotate( Temp, HyperVertex( 3, 1.0f, 1.0f, 0.0f ), 1 );
		TheText.setString( Temp.ToString() );

		//Push rendering commands through the pipeline
		Window.clear( sf::Color( 0, 0, 0, 255 ) );
		Window.draw( TheText );
		Window.display();
		system( "pause" );
	}

	return 0;
}