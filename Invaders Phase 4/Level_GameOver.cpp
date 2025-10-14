#include "GameController.h"
#include "Level_GameOver.h"
#include "Level_Loading.h"


Level_GameOver::Level_GameOver() 
{
}

void Level_GameOver::Load() 
{
	txtGameOverMsg = new Object_Text(gfx, D2D1::RectF(SCREENWIDTH / 2 - 250, 200, SCREENWIDTH / 2 + 250, 250), L"Game Over!", L"Veranda", 50.0f, D2D1::ColorF::Red, 1.0f);
	txtGameOverMsg2 = new Object_Text(gfx, D2D1::RectF(SCREENWIDTH / 2 - 250, 300, SCREENWIDTH / 2 + 250, 350), L"Out of Lives!", L"Veranda", 30.0f, D2D1::ColorF::Red, 1.0f);
	txtNewGameMsg = new Object_Text(gfx, D2D1::RectF(SCREENWIDTH / 2 - 250, SCREENHEIGHT / 2 + 25, SCREENWIDTH / 2 + 250, SCREENHEIGHT / 2 + 75), L"New Game? Y/N", L"Veranda", 20.0f, D2D1::ColorF::LawnGreen, 1.0f);
}

void Level_GameOver::Render() {
	gfx->ClearScreen(0.0f, 0.0f, 0.0f);

	wchar_t gameMsg[50];
	txtGameOverMsg->RenderText();
	txtNewGameMsg->RenderText();
	txtGameOverMsg2->RenderText();
}

void Level_GameOver::UnLoad() 
{
	if (txtGameOverMsg) delete txtGameOverMsg;
	if (txtGameOverMsg2) delete txtGameOverMsg2;
	if (txtNewGameMsg) delete txtNewGameMsg;
}

void Level_GameOver::Update() {

	if (GetKeyState('Y') & 0x8000)
		GameController::SwitchLevel(new Level_Loading());
	else if (GetKeyState('N') & 0x8000)
		GameController::QuitGame();
}