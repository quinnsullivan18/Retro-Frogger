#pragma once
#include "Object_Mobile.h"

class Object_Enemy : public Object_Mobile 
{
protected:
	int speed;					//Speed divisor to slow animation
	int frames;					//Frames in the animation
	int index;					//Index of our sprite animation
public: 
	Object_Enemy(int objectIndex, float velocityx, float velocityy, int x, int y, SpriteSheet* ss, Object_Game** objectArray, int frames, int speed = 1, float scaleFactor = 1.0f);
	void AnimateSprite() override;
};