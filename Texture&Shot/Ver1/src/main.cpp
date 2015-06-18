
#include "lib/framework.hpp"


struct Player {
  Vec2f pos;
  Vec2f size;
  bool isLeft;
};

int main() {
  AppEnv env(640, 480);
  env.bgColor(Color::white);

  Texture left_pic("res/left.png");
  Texture right_pic("res/right.png");

  Player player;
  player.pos = Vec2f(0, 0);
  player.size = Vec2f(left_pic.width(), left_pic.height()); // 読み込んだ画像からサイズを取得する
  player.isLeft = false;

  while (env.isOpen()) {
    env.begin();

    if (env.isPushKey(GLFW_KEY_A)) {
      player.isLeft = true;
    }
    if (env.isPushKey(GLFW_KEY_D)) {
      player.isLeft = false;
    }

    if (player.isLeft) {
      drawTextureBox(player.pos.x(), player.pos.y(),
                     player.size.x(), player.size.y(),
                     0, 0, player.size.x(), player.size.y(),
                     left_pic, Color::white);
    } else {
      drawTextureBox(player.pos.x(), player.pos.y(),
                     player.size.x(), player.size.y(),
                     0, 0, player.size.x(), player.size.y(),
                     right_pic, Color::white);
    }

    env.end();
  }
}
