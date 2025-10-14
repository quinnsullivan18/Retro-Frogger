#pragma once
#include "Object_Mobile.h"

class Object_Player : public Object_Mobile
{
private:
	SpriteSheet* imgdeadfrog = NULL;
protected:
	int livesleft;
	bool isalive = true;
	bool ridingonlogorturtle = false;
	bool onsafeplace = false;
	int tickcount = 0;
	bool Safeplace[5];
public:
	Object_Player(int objectIndex, float velocityx, float velocityy, int x, int y, SpriteSheet* ss, SpriteSheet* deadfrogimg, int liveamount, Object_Game** objectArray, float scaleFactor = 1.0f);
	void Setvelocity(float xMod, float yMod);	
	void AnimateSprite() override;
	void UpdateObjectPosition() override;
	void CollisionCheck() override;
	int GetLives();
	bool Getalive();
	void SetX(float newx);
	void SetY(float newy);
	void Increasetick();
	int Checktick();
	void Resettick();
};
