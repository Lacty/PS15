
#include "title.h"
#include "../scene_state.h"


void titleSetup() {

}

void titleUpdate(AppEnv& env) {
  if (env.isPushKey('G')) {
    setSceneState(SceneState::GameMain);
  }
}

void titleDraw() {
  drawFillCircle(0, 0, 50, 50, 4, Color(1, 1, 1));
}