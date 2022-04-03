#include "Ball.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;

Ball::Ball()
{
	//initialize the ball
	circle.setRadius(7.5);
	circle.setFillColor(Color::White);
	circle.setPosition(480.f, 270.f);
	//choosing random angle between 0 and 360 which will determine the ball direction
	angle = (rand() % 360) * (3.14159265359 / 180);
	SetDirection();
}

void Ball::draw(RenderTarget& target, RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(circle, states);
}

void Ball::SetDirection()
{
	//divided by a factor to slow down the ball' speed
	direction.x = cos(angle)/10;
	direction.y = sin(angle)/10;
}