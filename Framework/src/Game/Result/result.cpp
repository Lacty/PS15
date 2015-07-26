
#include "result.h"
#include "../scene_state.h"


void resultSetup() {

}

void resultUpdate(AppEnv& env) {
  if (env.isPushKey('T')) {
    setSceneState(SceneState::Title);
  }
}

void resultDraw() {
  drawFillCircle(0, 0, 50, 50, 100, Color(1, 1, 1));
}