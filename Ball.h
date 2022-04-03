#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

class Ball : public Transformable, public Drawable
{
public:
	Ball();
	void SetDirection();
	Vector2f direction;
	float angle;
	CircleShape circle;
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;
};

