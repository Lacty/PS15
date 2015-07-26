
#include "game_main.h"
#include "../scene_state.h"


void gameMainSetup() {

}

void gameMainUpdate(AppEnv& env) {
  if (env.isPushKey('R')) {
    setSceneState(SceneState::Result);
  }
}

void gameMainDraw() {
  drawFillCircle(0, 0, 50, 50, 3, Color(1 ,1, 1));
}