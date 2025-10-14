#include "Object_Enemy.h"

Object_Enemy::Object_Enemy(int objectIndex, float velocityx, float velocityy, int x, int y, SpriteSheet* ss, Object_Game** objectArray, int frames, int speed, float scaleFactor) : Object_Mobile(objectIndex, velocityx, velocityy, x, y, ss, objectArray, scaleFactor)
{
	this->speed = speed;
	this->frames = frames;
	index = 0;
}

void Object_Enemy::AnimateSprite() {
	int aniframe = index++ / speed % frames;
	ss->Draw(aniframe, x, y, scaleFactor);
}