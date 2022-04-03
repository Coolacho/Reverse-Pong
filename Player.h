#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

class Player : public Transformable, public Drawable
{
public:
	Player(float x, float y);
	const float Speed = 0.050;
	int points = 0;
	RectangleShape rectangle;
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;
};

