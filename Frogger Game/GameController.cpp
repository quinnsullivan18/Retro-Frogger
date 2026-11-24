#include "GameController.h"

Level_Game* GameController::currentLevel;
bool GameController::Loading;
winner GameController::GameWinner;

bool GameController::contactRed;
bool GameController::contactYellow;
wchar_t GameController::address[64];

void GameController::Init() {
	Loading = true;
	currentLevel = 0;
}

void GameController::LoadInitialLevel(Level_Game* lev) {
	Loading = true;
	currentLevel = lev;
	currentLevel->Load();
	Loading = false;
}

void GameController::SwitchLevel(Level_Game* lev) {
	Loading = true;
	currentLevel->UnLoad();
	lev->Load();
	delete currentLevel;
	currentLevel = lev;
	Loading = false;
}

void GameController::Render() {
	if (Loading) return;
	currentLevel->Render();
}

void GameController::Update() {
	if (Loading) return;
	currentLevel->Update();
}

void GameController::QuitGame() {
	Shutdown();
	PostQuitMessage(0);
}

void GameController::Shutdown() {
	if (!currentLevel) return;

	Loading = true;
	currentLevel->UnLoad();
	delete currentLevel;
	currentLevel = nullptr;
}