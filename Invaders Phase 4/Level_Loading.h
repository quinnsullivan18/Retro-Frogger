#pragma once
#include "Level_Game.h"

class Level_Loading : public Level_Game {
private:
	Object_Text* txtGameMsg;
	Object_Text* txtStartingMsg;
	std::clock_t loadTime;

public:
	void Load() override;
	void UnLoad() override;
	void Render() override;
	void Update() override;
};