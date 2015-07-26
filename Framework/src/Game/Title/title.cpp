
#include "title.h"
#include "../scene_state.h"
#include "../Collision/collision.h"


// •Ï”‚Í‚±‚±‚ÅéŒ¾
namespace TitleVar {
  int a;
}

void titleSetup() {
  using namespace TitleVar;
  a = 0;
}

void titleUpdate(AppEnv& env) {
  using namespace TitleVar;
  if (env.isPushKey('G')) {
    setSceneState(SceneState::GameMain);
  }
}

void titleDraw() {
  using namespace TitleVar;
  drawFillCircle(0, 0, 50, 50, 4, Color(1, 1, 1));
}