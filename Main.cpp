#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Player.h"
#include "Ball.h"
#include "Line.h"
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace sf;

int main()
{
	srand((unsigned)time(0));
	//create the elements of the game
	RenderWindow window(VideoMode(960, 540), "Reversed Pong");
	Player p1(0.f, 0.f), p2(950.f, 0.f);
	Ball ball;
	Line line;

	while (window.isOpen())
	{
		//event handling
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::Resized)
				window.setSize(Vector2u(event.size.width, event.size.height));
		}
		
		//drawing the game screen
		window.clear(Color::Black);
		window.draw(p1);
		window.draw(p2);
		window.draw(ball);
		window.draw(line);
		window.display();

		//the movement of the players
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			if (p1.rectangle.getPosition().y > 0.f)
				p1.rectangle.move(0.f, -p1.Speed);
		}

		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			if (p1.rectangle.getPosition().y < 480.f)
				p1.rectangle.move(0.f, p1.Speed);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (p2.rectangle.getPosition().y > 0.f)
				p2.rectangle.move(0.f, -p2.Speed);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (p2.rectangle.getPosition().y < 480.f)
				p2.rectangle.move(0.f, p2.Speed);
		}

		//check where the ball is in the window by the x-axis; if it is at the border, teleport it to the other side, else move it
		Vector2f ball_position = ball.circle.getPosition();
		if (ball_position.x > 0.f && ball_position.x < 960.f)
		{
			ball.circle.move(ball.direction);
		}
		else if (ball_position.x > 960.f)
		{
			ball.circle.move(-960.f, 0.f);
			line.change_position(ball);
		}
		else if (ball_position.x < 0.f)
		{
			ball.circle.move(960.f, 0.f);
			line.change_position(ball);
		}

		//check if the ball hits the top or bottom border; if true then change direction of movement
		if (ball_position.y < 0.f)
		{
			if (ball.direction.y < 0.f)
			{
				ball.direction.y *= -1;
			}
		}
		else if (ball_position.y > 525.f)
		{
			if (ball.direction.y > 0.f)
			{
				ball.direction.y *= -1;
			}
		}

		//check if the ball hits players
		if (ball.circle.getGlobalBounds().intersects(p1.rectangle.getGlobalBounds()))
		{
			++p1.points;
		}
		if (ball.circle.getGlobalBounds().intersects(p2.rectangle.getGlobalBounds()))
		{
			++p2.points;
		}
	}
}