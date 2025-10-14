#pragma once
#include "Level_Game.h"

class Level_GameOver : public Level_Game {
private:
	Object_Text* txtGameOverMsg;
	Object_Text* txtGameOverMsg2;
	Object_Text* txtScoreMsg;
	Object_Text* txtNewGameMsg;
	//int level;
	//int score;

public:
	Level_GameOver();
	void Load() override;
	void UnLoad() override;
	void Render() override;
	void Update() override;
};
