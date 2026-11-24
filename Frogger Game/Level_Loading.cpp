#include "GameController.h"
#include "Level_Loading.h"
#include "Level_Main.h"

void Level_Loading::Load() {

	txtGameMsg = new Object_Text(gfx, D2D1::RectF(SCREENWIDTH / 2 - 350, SCREENHEIGHT / 2 - 25, SCREENWIDTH / 2 + 350, SCREENHEIGHT / 2 + 55), L"FROGGER", L"Veranda", 75.0f, D2D1::ColorF::LawnGreen, 1.0f);
	txtStartingMsg = new Object_Text(gfx, D2D1::RectF(SCREENWIDTH / 2 - 350, SCREENHEIGHT / 2 + 55, SCREENWIDTH / 2 + 350, SCREENHEIGHT / 2 + 105), L"", L"Veranda", 50.0f, D2D1::ColorF::Yellow, 1.0f);
	loadTime = clock();
}

void Level_Loading::Render() {
	gfx->ClearScreen(0.0f, 0.0f, 0.0f);

	txtGameMsg->RenderText();

	wchar_t startingMsg[40];
	swprintf_s(startingMsg, L"Click Mouse or Space to start ");
	txtStartingMsg->RenderText(startingMsg);

	if (GetKeyState(' ') || GetKeyState(VK_LBUTTON) & 0x8000) //Start when the space bar is pressed 
	{
		GameController::SwitchLevel(new Level_Main());
	}
}

void Level_Loading::UnLoad() {

	if (txtGameMsg) delete txtGameMsg;
	if (txtStartingMsg) delete txtStartingMsg;
}

void Level_Loading::Update() {

}
