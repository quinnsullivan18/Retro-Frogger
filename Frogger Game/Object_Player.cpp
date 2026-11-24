#include "Object_Player.h"
#include "Level_Main.h"

Object_Player::Object_Player(int objectIndex, float velocityx, float velocityy, int x, int y, SpriteSheet* ss, SpriteSheet* deadfrogimg, int liveamount, Object_Game** objectArray, float scaleFactor) : Object_Mobile(objectIndex, velocityx, velocityy, x, y, ss, objectArray, scaleFactor)
{
	imgdeadfrog = deadfrogimg;
	livesleft = liveamount;
}

void Object_Player::Setvelocity(float xMod, float yMod) 
{
	velocityX = xMod;
	velocityY = yMod;
}

void Object_Player::SetX(float newx)
{
	x = newx;
}

void Object_Player::SetY(float newy)
{
	y = newy;
}

int Object_Player::GetLives()
{
	return livesleft;
}

bool Object_Player::Getalive()
{
	return isalive;
}

void Object_Player::Increasetick()
{
	tickcount++;
}

int Object_Player::Checktick()
{
	return tickcount;
}

void Object_Player::Resettick()
{
	tickcount = 0;
	if (livesleft > 0)
	{
		isalive = true;
	}
}

void Object_Player::AnimateSprite() 
{
	if (isalive)
	{
		ss->Draw(x, y, scaleFactor);
	}
	else
	{
		imgdeadfrog->Draw(x, y, scaleFactor);
	}
}

void Object_Player::UpdateObjectPosition()
{
	x += velocityX;
	y += velocityY;
	if (!ridingonlogorturtle)// Move once per click
	{
		velocityX = velocityY = 0;
	}

	if (y < 0) y = 0; // Can not go below the screen
	else if (y > 350 && x < 0) // Can not go off the screen to the left
	{
		x = 0;
	}
	else if (y > 350 && x > SCREENWIDTH - GetWidth()) // Can not go off the screen to the right
	{
		x = SCREENWIDTH - GetWidth();
	}
	else if (y < 350 && x > SCREENWIDTH - GetWidth())// Right of screen on water
	{
		x = SCREENWIDTH - GetWidth();
		isalive = false;
	}
	else if (y < 350 && x < 0)// Left of screen on water
	{
		x = 0;
		isalive = false;
	}
	else if (y > SCREENHEIGHT - GetHeight())
	{
		y = SCREENHEIGHT - GetHeight();
	}	
}

void Object_Player::CollisionCheck()
{
	if (isalive)
	{
		RECT frog;
		if (y < 360) // On the water
		{
			frog.left = (long)x + 10;
			frog.top = (long)y + 5;
			frog.right = (long)x + GetWidth() - 10;
			frog.bottom = (long)y + GetHeight() - 5;
		}
		else
		{
			frog.left = (long)x + 5;
			frog.top = (long)y + 5;
			frog.right = (long)x + GetWidth() - 5;
			frog.bottom = (long)y + GetHeight() - 5;
		}

		for (int idx = 3; idx < 59; idx++)
		{
			if (objectArray[idx])
			{
				RECT r2;
				if (idx >= 3 && idx <= 7) // Safe Place
				{
					r2.left = (long)objectArray[idx]->GetX() + 15;
					r2.top = (long)objectArray[idx]->GetY() + 15;
					r2.right = (long)objectArray[idx]->GetX() + objectArray[idx]->GetWidth() - 15;
					r2.bottom = (long)objectArray[idx]->GetY() + objectArray[idx]->GetHeight() - 15;
				}
				if (idx >= 10 && idx <= 24) // Turtles
				{
					r2.left = (long)objectArray[idx]->GetX() + 10;
					r2.top = (long)objectArray[idx]->GetY() + 15;
					r2.right = (long)objectArray[idx]->GetX() + objectArray[idx]->GetWidth() - 15;
					r2.bottom = (long)objectArray[idx]->GetY() + objectArray[idx]->GetHeight() - 5;
				}
				else if (idx >= 25 && idx <= 39) //Logs
				{
					r2.left = (long)objectArray[idx]->GetX() + 10;
					r2.top = (long)objectArray[idx]->GetY() + 10;
					r2.right = (long)objectArray[idx]->GetX() + objectArray[idx]->GetWidth() - 10;
					r2.bottom = (long)objectArray[idx]->GetY() + objectArray[idx]->GetHeight() - 10;
				}
				else if(idx >= 41 && idx < 60) // Cars
				{
					r2.left = (long)objectArray[idx]->GetX();
					r2.top = (long)objectArray[idx]->GetY();
					r2.right = (long)objectArray[idx]->GetX() + objectArray[idx]->GetWidth();
					r2.bottom = (long)objectArray[idx]->GetY() + objectArray[idx]->GetHeight();
				}
				RECT dest; //not used

				if (IntersectRect(&dest, &frog, &r2))
				{
					if (idx >= 3 && idx <= 7) //Safe Place
					{
						Object_Block* tempptr = dynamic_cast <Object_Block*>(objectArray[idx]);
						switch (idx)
						{
						case 3:
							if (!tempptr->FrogSafe())
							{
								tempptr->SetSafe();
								this->SetX((SCREENWIDTH / 2));
								this->SetY(SCREENHEIGHT - 50);
								onsafeplace = true;
							}
							else
							{
								isalive = false;
								livesleft--;
							}
							break;
						case 4:
							if (!tempptr->FrogSafe())
							{
								tempptr->SetSafe();
								this->SetX((SCREENWIDTH / 2));
								this->SetY(SCREENHEIGHT - 50);
								onsafeplace = true;
							}
							else
							{
								isalive = false;
								livesleft--;
							}
							break;
						case 5:
							if (!tempptr->FrogSafe())
							{
								tempptr->SetSafe();
								this->SetX((SCREENWIDTH / 2));
								this->SetY(SCREENHEIGHT - 50);
								onsafeplace = true;
							}
							else
							{
								isalive = false;
								livesleft--;
							}
							break;
						case 6:
							if (!tempptr->FrogSafe())
							{
								tempptr->SetSafe();
								this->SetX((SCREENWIDTH / 2));
								this->SetY(SCREENHEIGHT - 50);
								onsafeplace = true;
							}
							else
							{
								isalive = false;
								livesleft--;
							}
							break;
						case 7:
							if (!tempptr->FrogSafe())
							{
								tempptr->SetSafe();
								this->SetX((SCREENWIDTH / 2));
								this->SetY(SCREENHEIGHT - 50);
								onsafeplace = true;
							}
							else
							{
								isalive = false;
								livesleft--;
							}
							break;
						}
						break;
					}
					if (idx >= 10 && idx <= 24) // Turtles
					{
						Object_Mobile* tempturtleptr = dynamic_cast <Object_Mobile*>(objectArray[idx]);
						this->Setvelocity(tempturtleptr->GetXVelocity(), tempturtleptr->GetYVeloctiy());
						ridingonlogorturtle = true;
						break;
					}
					else if (idx >= 25 && idx <= 39) // Logs  
					{
						Object_Mobile* templogptr = dynamic_cast <Object_Mobile*>(objectArray[idx]);
						this->Setvelocity(templogptr->GetXVelocity(), templogptr->GetYVeloctiy());
						ridingonlogorturtle = true;
						break;
					}
					else if (idx >= 41 && idx < 60) // Vehicles
					{
						livesleft--;
						isalive = false;
						break;
					}
				}
			}
		}

		if (y < 360) // Check if the frog needs to die on the water
		{		
			if (!ridingonlogorturtle && !onsafeplace)
			{
				isalive = false;
				livesleft--;
			}
			else
			{
				ridingonlogorturtle = false;
				onsafeplace = false;
			}
		}
	}
	else // Frog is not alive
		return;
}