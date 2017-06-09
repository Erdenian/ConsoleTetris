#include "ScoreScript.h"
#include <string>


void ScoreScript::onUpdate()
{
	score += 5;
	GameObject* obj = getGameObject();
	obj->graphics.clear();
	obj->graphics.drawText(0, 0, std::to_string(score));
}

void ScoreScript::onStart() {

}
