#include "Player.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

Player::Player(float x, float y)
{
	rectangle.setSize(Vector2f(10.f, 60.f));
	rectangle.setFillColor(Color::White);
	rectangle.setPosition(x,y);
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(rectangle,states);
}