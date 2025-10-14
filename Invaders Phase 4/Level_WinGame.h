#pragma once
#include "Level_Game.h"

class Level_WinGame : public Level_Game {
private:
	Object_Text* txtWinMsg;
	Object_Text* txtScoreMsg;
	Object_Text* txtNewGameMsg;
	//int level;
	//int score;

public:
	Level_WinGame();
	void Load() override;
	void UnLoad() override;
	void Render() override;
	void Update() override;
};