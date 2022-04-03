#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Ball.h"

using namespace std;
using namespace sf;

class Line : public Transformable, public Drawable
{
public:
	Line();
	void change_position(Ball& ball);
	RectangleShape rectangle;
	float rotation_angle;
private:
	virtual void draw(RenderTarget& target, RenderStates states) const;
};

