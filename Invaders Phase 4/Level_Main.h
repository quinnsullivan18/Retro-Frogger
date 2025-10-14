#pragma once
#include "Level_Game.h"

class Level_Main : public Level_Game {
private:
	SpriteSheet* imgTopmap = NULL;
	SpriteSheet* imgSidewalk = NULL;
	SpriteSheet* imgSafeplace = NULL;
	SpriteSheet *imgStillFrog = NULL;
	SpriteSheet* imgDeadFrog = NULL;
	SpriteSheet* imgSafefrog = NULL;
	SpriteSheet* imgFiretruckRight = NULL;
	SpriteSheet* imgFiretruckLeft = NULL;
	SpriteSheet* imgRacecarRight = NULL;
	SpriteSheet* imgRacecarLeft = NULL;
	SpriteSheet* imgBluecarRight = NULL;
	SpriteSheet* imgBluecarLeft = NULL;
	SpriteSheet* imgGreencarRight = NULL;
	SpriteSheet* imgGreencarLeft = NULL;
	SpriteSheet* imgTurtles = NULL;
	SpriteSheet* imgLonglog = NULL;
	SpriteSheet* imgMediumlog = NULL;
	SpriteSheet* imgShortlog = NULL;
	bool moving;
	bool gameover;
	int livesleft;
	float speed;

	Object_Text* txtGameOverMsg;
	Object_Text* txtScoreMsg;
	Object_Text* txtNewGameMsg;

public:
	void Load() override;
	void UnLoad() override;
	void Render() override;
	void Update() override;
};