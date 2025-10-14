#pragma once
#include "Object_Enemy.h"

class Object_Vehicles : public Object_Enemy
{
public:
	Object_Vehicles(int objectIndex, float velocityx, float velocityy, int x, int y, SpriteSheet* ss, Object_Game** objectArray, int frames, int speed = 1, float scaleFactor = 1.0f);
	void UpdateObjectPosition() override;
};