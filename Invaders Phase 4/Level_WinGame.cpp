#include "GameController.h"
#include "Level_WinGame.h"
#include "Level_Loading.h"


Level_WinGame::Level_WinGame()
{
}

void Level_WinGame::Load()
{
	txtWinMsg = new Object_Text(gfx, D2D1::RectF(SCREENWIDTH / 2 - 250, 200, SCREENWIDTH / 2 + 250, 250), L"You Win!!!", L"Veranda", 50.0f, D2D1::ColorF::LimeGreen, 1.0f);
	txtNewGameMsg = new Object_Text(gfx, D2D1::RectF(SCREENWIDTH / 2 - 250, SCREENHEIGHT / 2 + 25, SCREENWIDTH / 2 + 250, SCREENHEIGHT / 2 + 75), L"New Game? Y/N", L"Veranda", 20.0f, D2D1::ColorF::Yellow, 1.0f);
}

void Level_WinGame::Render() {
	gfx->ClearScreen(0.0f, 0.0f, 0.0f);

	wchar_t gameMsg[50];
	txtWinMsg->RenderText();
	txtNewGameMsg->RenderText();
}

void Level_WinGame::UnLoad()
{
	if (txtWinMsg) delete txtWinMsg;
	if (txtNewGameMsg) delete txtNewGameMsg;
}

void Level_WinGame::Update() {

	if (GetKeyState('Y') & 0x8000)
		GameController::SwitchLevel(new Level_Loading());
	else if (GetKeyState('N') & 0x8000)
		GameController::QuitGame();
}