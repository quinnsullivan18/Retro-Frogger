#include "Object_Vehicle.h"

Object_Vehicles::Object_Vehicles(int objectIndex, float velocityx, float velocityy, int x, int y, SpriteSheet* ss, Object_Game** objectArray, int frames, int speed, float scaleFactor) : Object_Enemy(objectIndex, velocityx, velocityy, x, y, ss, objectArray, frames, speed, scaleFactor)
{}

void Object_Vehicles::UpdateObjectPosition()
{
	x += velocityX;
	y += velocityY;

	//Turtles
	if (objectIndex >= 10 && objectIndex <= 24) 
	{
		if (x > (SCREENWIDTH + GetWidth()) + 15) //Off Right
		{
			x = 0 - GetWidth();
		}
	}
	//Logs
	else if (objectIndex >= 25 && objectIndex <= 39) 
	{
		if (x < (0 - GetWidth())) //Off Left
		{
			x = SCREENWIDTH;
		}
		else if (x > (SCREENWIDTH + GetWidth())) //Off Right
		{
			x = 0 - GetWidth();
		}
	}
	// Vehicles
	else 
	{
		if (x < (0 - GetWidth()) - 100) //Off Left
		{
			x = SCREENWIDTH;
		}
		else if (x > (SCREENWIDTH + GetWidth() + 100)) //Off Right
		{
			x = 0 - GetWidth();
		}
	}
}