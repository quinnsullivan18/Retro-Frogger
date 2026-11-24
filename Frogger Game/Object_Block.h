#pragma once
#include "Object_Game.h"

class Object_Block : public Object_Game
{
private:
	SpriteSheet* imgsafefrog = NULL;
	bool frogissafe = false;
public:
	Object_Block(int objectIndex, int x, int y, SpriteSheet* ss, SpriteSheet* winningfrog, Object_Game** objectArray, float scaleFactor = 1.0f);
	bool FrogSafe();
	void SetSafe();
	void AnimateSprite() override;
	bool CheckWin();
};