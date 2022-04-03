#include "Line.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Ball.h"
#include <cstdlib>

using namespace std;
using namespace sf;

Line::Line()
{
	rectangle.setSize(Vector2f(15.f, 100.f));
	rectangle.setFillColor(Color::Green);
	rectangle.setOrigin(7.5, 50.f);
}

void Line::draw(RenderTarget& target, RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(rectangle, states);
}

void Line::change_position(Ball& ball)
{
	rectangle.setPosition(ball.getPosition());
	rectangle.move(ball.direction.x * 10, ball.direction.y * 10);
	rotation_angle = (rand() % 179) * (3.14159265359 / 180);
	if (rotation_angle == ball.angle)
		++rotation_angle;
	rectangle.setRotation(rotation_angle);
}
