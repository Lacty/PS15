
#include "title.h"
#include "../scene_state.h"
#include "../Collision/collision.h"


// �ϐ��͂����Ő錾
namespace TitleVar {
  
}

void titleSetup() {
  using namespace TitleVar;

}

void titleUpdate(AppEnv& env) {
  using namespace TitleVar;
  if (env.isPushKey('G')) {
    setSceneState(SceneState::GameMain);
  }
}

void titleDraw() {
  using namespace TitleVar;
}