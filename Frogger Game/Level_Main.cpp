#include "GameController.h"
#include "Level_Main.h"
#include "Level_GameOver.h"
#include "Level_WinGame.h"

void Level_Main::Load() 
{
	//Winning screen
	imgTopmap = new SpriteSheet(L"TopMap.png", gfx);
	imgSafeplace = new SpriteSheet(L"Safeplace.png", gfx);
	imgSidewalk = new SpriteSheet(L"Grass.png", gfx);
	imgStillFrog = new SpriteSheet(L"SittingFrog.png", gfx);
	imgDeadFrog = new SpriteSheet(L"DeadFrog.png", gfx);
	imgSafefrog = new SpriteSheet(L"Safefrog.png", gfx);
	imgFiretruckRight = new SpriteSheet(L"Firetruck.png", gfx);
	imgFiretruckLeft = new SpriteSheet(L"Firetruck2.png", gfx);
	imgRacecarRight = new SpriteSheet(L"Racecar.png", gfx);
	imgRacecarLeft = new SpriteSheet(L"Racecar2.png", gfx);
	imgBluecarRight = new SpriteSheet(L"Bluecar.png", gfx);
	imgBluecarLeft = new SpriteSheet(L"Bluecar2.png", gfx);
	imgGreencarRight = new SpriteSheet(L"Greencar.png", gfx);
	imgGreencarLeft = new SpriteSheet(L"Greencar2.png", gfx);
	imgTurtles = new SpriteSheet(L"Turtles.png", gfx, 62, 56);
	imgLonglog = new SpriteSheet(L"Longlog.png", gfx);
	imgShortlog = new SpriteSheet(L"Shortlog.png", gfx);
	imgMediumlog = new SpriteSheet(L"Mediumlog.png", gfx);
	objectArray = new Object_Game * [60];
	livesleft = 3;
	moving = false;
	gameover = false;
	speed = 1.0;

	// Set all of the object pointers to NULL
	for (int goCurrent = 0; goCurrent < 60; goCurrent++)
	{
		objectArray[goCurrent] = NULL;
	}

	Object_Block* Sidewalk1 = new Object_Block(0, 0, (SCREENHEIGHT - 50), imgSidewalk, imgSidewalk, objectArray);
	objectArray[0] = Sidewalk1;

	Object_Block* Sidewalk2 = new Object_Block(1, 0, (SCREENHEIGHT - 350), imgSidewalk, imgSidewalk, objectArray);
	objectArray[1] = Sidewalk2;

	Object_Block* Topofmap = new Object_Block(2, 0, 0, imgTopmap, imgTopmap, objectArray);
	objectArray[2] = Topofmap;

	//Creates 5 safe places for the frog
	for (int z = 3; z < 8; z++) 
	{
		Object_Block* Safepalce = new Object_Block(z, 67 + ((z-3) * 200) , 10, imgSafeplace, imgSafefrog, objectArray);
		objectArray[z] = Safepalce;
	}

	int q = rand() % 1000;
	int temp = q; //Creates 9 Turtles
	for (int a = 10; a < 19; a++) 
	{
		if (a == 13)
		{
			temp += 195;

			if (temp >= SCREENWIDTH)
			{
				temp -= SCREENWIDTH;
			}
		}

		if (a == 16)
		{
			temp += 195;

			if (temp >= SCREENWIDTH)
			{
				temp -= SCREENWIDTH;
			}
		}

		Object_Vehicles* Turtle1 = new Object_Vehicles(a, 1.4f, 0.0f, temp, 300, imgTurtles, objectArray, 7, 8);
		objectArray[a] = Turtle1;
		temp = temp+55;
	}

	q = rand() % 1000;
	temp = q; // Creats 6 Turtles
	for (int b = 19; b < 25; b++) 
	{
		if (b == 22)
		{
			temp += 350;

			if (temp >= SCREENWIDTH)
			{
				temp -= SCREENWIDTH;
			}
		}

		Object_Vehicles* Turtle2 = new Object_Vehicles(b, 3.0f, 0.0f, temp, 145, imgTurtles, objectArray, 7, 5);
		objectArray[b] = Turtle2;
		temp += 55;
	}
	
	q = rand() % 950;
	temp = q; 
	int logy = 105;
	speed = -4.5; //Creates 6 short logs
	for (int tempshortlog = 25; tempshortlog < 31; tempshortlog++)
	{
		if (tempshortlog == 28)
		{
			logy = 200;
			temp = rand() % 800;
			speed = -2.4;
		}

		if (temp >= SCREENWIDTH)
		{
			temp -= SCREENWIDTH;
		}
		
		Object_Vehicles* Shortlog = new Object_Vehicles(tempshortlog, speed, 0.0f, temp, logy, imgShortlog, objectArray, 1);
		objectArray[tempshortlog] = Shortlog;
		temp += 350;
	}

	temp = 50; 
	logy = 55;
	speed = 3.5; //Creates 4 medium logs
	for (int tempmedlog = 31; tempmedlog < 35; tempmedlog++)
	{
		Object_Vehicles* Shortlog = new Object_Vehicles(tempmedlog, speed, 0.0f, temp, logy, imgMediumlog, objectArray, 1);
		objectArray[tempmedlog] = Shortlog;
		temp += 330;
	}

	temp = 5;
	logy = 250;
	speed = 1.0; //Creates 4 Long logs
	for (int templonglog = 35; templonglog < 39; templonglog++)
	{

		Object_Vehicles* longlog = new Object_Vehicles(templonglog, speed, 0.0f, temp, logy, imgLonglog, objectArray, 1);
		objectArray[templonglog] = longlog;
		temp += 360;
	}

	SpriteSheet* tempimg = imgFiretruckLeft;
	temp = rand() % 500;;
	int vehicley = SCREENHEIGHT - 300;
	speed = -1.5; // Creates 2 Firetrucks
	for (int tempft = 41; tempft < 43; tempft++)
	{
		Object_Vehicles* Firetruckptr = new Object_Vehicles(tempft, speed, 0.0f, temp, vehicley, tempimg, objectArray, 1);
		objectArray[tempft] = Firetruckptr;
		temp += (rand() % 400) + 300;
	}

	tempimg = imgRacecarRight;
	temp = rand() % 1000;;
	vehicley = SCREENHEIGHT - 250;
	speed = 5.5; //Creates 5 RaceCars
	for (int temprc = 43; temprc < 48; temprc++)
	{
		if (temp >= SCREENWIDTH)
		{
			temp -= SCREENWIDTH;
		}

		if (temprc == 46)
		{
			vehicley += 150;
			tempimg = imgRacecarLeft;
			speed *= -1;
		}

		Object_Vehicles* Racecarptr = new Object_Vehicles(temprc, speed, 0.0f, temp, vehicley, tempimg, objectArray, 1);
		objectArray[temprc] = Racecarptr;
		temp += 350;
	}

	tempimg = imgBluecarRight;
	temp = rand() % 100;;
	vehicley = SCREENHEIGHT - 200;
	speed = 1.0; //Creates 4 blue cars 
	for (int tempbc = 48; tempbc < 52; tempbc++)
	{
		if (tempbc == 50) 
		{
			temp = rand() % 100;
			tempimg = imgBluecarLeft;
			speed *= -1;
			vehicley += 50;
		}

		Object_Vehicles* Bluecarptr = new Object_Vehicles(tempbc, speed, 0.0f, temp, vehicley, tempimg, objectArray, 1);
		objectArray[tempbc] = Bluecarptr;
		temp += (rand() % 100) + 550;
	}

	tempimg = imgGreencarLeft;
	temp = 910;
	vehicley = SCREENHEIGHT - 150;
	speed = -1.0; // Creates 3 Green cars
	for (int tempgc = 52; tempgc < 55; tempgc++)
	{
		if (tempgc == 53)
		{
			temp = 300;
			tempimg = imgGreencarRight;;
			speed *= -1;
			vehicley -= 50;
		}
		Object_Vehicles* Greencarptr = new Object_Vehicles(tempgc, speed, 0.0f, temp, vehicley, tempimg, objectArray, 1);
		objectArray[tempgc] = Greencarptr;
		temp += (rand() % 150) + 5000;
	}

	//Create 1 Player
	Object_Player *Player = new Object_Player(59, 0.0f, 0.0f, SCREENWIDTH / 2, SCREENHEIGHT - 50, imgStillFrog, imgDeadFrog, livesleft, objectArray);
	objectArray[59] = Player;
}

void Level_Main::Render() {
	gfx->ClearScreen(0.0f, 0.0f, 0.0f);
	for (int goCurrent = 0; goCurrent < 60; goCurrent++) {
		if (objectArray[goCurrent]) objectArray[goCurrent]->Render();
	}
}

void Level_Main::UnLoad() {
	//delete game objects
	for (int curObj = 0; curObj < 60; curObj++) {
		if (objectArray[curObj]) delete objectArray[curObj];
	}
	delete[] objectArray;

	//delete sprites
	if (imgSidewalk) delete imgSidewalk;
	if (imgTopmap) delete imgTopmap;
	if (imgSafeplace) delete imgSafeplace;
	if (imgStillFrog) delete imgStillFrog;
	if (imgDeadFrog) delete imgDeadFrog;
	if (imgSafefrog) delete imgSafefrog;
	if (imgFiretruckLeft) delete imgFiretruckLeft;
	if (imgRacecarLeft) delete imgRacecarLeft;
	if (imgRacecarRight) delete imgRacecarRight;
	if (imgGreencarLeft) delete imgGreencarLeft;
	if (imgGreencarRight) delete imgGreencarRight;
	if (imgBluecarLeft) delete imgBluecarLeft;
	if (imgBluecarRight) delete imgBluecarRight;
	if (imgLonglog) delete imgLonglog;
	if (imgMediumlog) delete imgMediumlog;
	if (imgShortlog) delete imgShortlog;
	if (imgTurtles) delete imgTurtles;
}

void Level_Main::Update() 
{
	Object_Player *p1 = (Object_Player *)objectArray[59];

	if (p1->Getalive())
	{
		Object_Block* tempwinptr = dynamic_cast <Object_Block*>(objectArray[3]);
		Object_Block* tempwinptr1 = dynamic_cast <Object_Block*>(objectArray[4]);
		Object_Block* tempwinptr2 = dynamic_cast <Object_Block*>(objectArray[5]);
		Object_Block* tempwinptr3 = dynamic_cast <Object_Block*>(objectArray[6]);
		Object_Block* tempwinptr4 = dynamic_cast <Object_Block*>(objectArray[7]);
		//Check if player beat the game
		if (tempwinptr->CheckWin() && tempwinptr1->CheckWin() && tempwinptr2->CheckWin() && tempwinptr3->CheckWin() && tempwinptr4->CheckWin())
		{
			GameController::SwitchLevel(new Level_WinGame());
		}

		if (GetKeyState('A') & 0x8000 && !moving || GetKeyState(37) & 0x8000 && !moving) // left
		{
			if (p1->GetY() < 360)
			{
				p1->Setvelocity(-55, 0);
				moving = true;
			}
			else
			{
				p1->Setvelocity(-50, 0);
				moving = true;
			}
		}
		else if (GetKeyState('D') & 0x8000 && !moving || GetKeyState(39) & 0x8000 && !moving) // right
		{
			if (p1->GetY() < 360)
			{
				p1->Setvelocity(+52, 0);
				moving = true;
			}
			else
			{
				p1->Setvelocity(50, 0);
				moving = true;
			}
		}
		else if (GetKeyState('W') & 0x8000 && !moving || GetKeyState(38) & 0x8000 && !moving) //up
		{
			if (p1->GetY() < 360)
			{
				p1->Setvelocity(0, -52);
				moving = true;
			}
			else
			{
				p1->Setvelocity(0, -50);
				moving = true;
			}
		}
		else if (GetKeyState('S') & 0x8000 && !moving || GetKeyState(40) & 0x8000 && !moving) // down
		{
			if (p1->GetY() < 425)
			{
				p1->Setvelocity(0, 52);
				moving = true;
			}
			else
			{
				p1->Setvelocity(0, 50);
				moving = true;
			}
		}
	}
	// Respawning/Checking if there are no lives left
	else
	{
		p1->Increasetick();
		if (p1->Checktick() > 100)
		{
			livesleft--;
			if (p1->GetLives() <= 0) // Losing Screen
			{
				GameController::SwitchLevel(new Level_GameOver());
			}
			else
			{
				p1->Resettick();
				delete objectArray[59];
				objectArray[59] = NULL;
				Object_Player* Player = new Object_Player(60, 0.0f, 0.0f, SCREENWIDTH / 2, SCREENHEIGHT - 50, imgStillFrog, imgDeadFrog, livesleft, objectArray);
				objectArray[59] = Player; //respawn the frog
			}
		}
	}

	//Not moving
	if (!(GetKeyState('S') & 0x8000 || GetKeyState('A') & 0x8000 || GetKeyState('W') & 0x8000 || GetKeyState('D') & 0x8000 || GetKeyState(37) & 0x8000 || GetKeyState(38) & 0x8000 || GetKeyState(39) & 0x8000 || GetKeyState(40) & 0x8000))
	{
		moving = false;
	}

	//Escape key ends program
	if (GetKeyState(VK_ESCAPE) & 0x8000)
	{
		GameController::QuitGame();
	}
}	