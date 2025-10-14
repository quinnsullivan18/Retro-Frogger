#include "Object_Block.h"

Object_Block::Object_Block(int objectIndex, int x, int y, SpriteSheet* ss, SpriteSheet* winningfrog, Object_Game** objectArray, float scaleFactor) : Object_Game(objectIndex, x, y, ss, objectArray, scaleFactor)
{
	imgsafefrog = winningfrog;
}

void Object_Block::AnimateSprite()
{
	if (frogissafe)
	{
		imgsafefrog->Draw(x, y, scaleFactor);
	}
	else
	{
		ss->Draw(x, y, scaleFactor);
	}
}

bool Object_Block::FrogSafe()
{
	return frogissafe;
}

void Object_Block::SetSafe()
{
	frogissafe = true;
}

bool Object_Block::CheckWin()
{
	if (frogissafe)
	{
		return true;
	}
	else
		return false;
}