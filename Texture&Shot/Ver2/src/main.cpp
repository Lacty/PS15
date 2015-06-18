
#include "lib/framework.hpp"


enum Direction {
  Right = 1,
  Left = -1
};

struct Player {
  Vec2f pos;
  Vec2f size;
  Direction dir;
};

int main() {
  AppEnv env(640, 480);
  env.bgColor(Color::white);

  Texture pic("res/right.png");

  Player player;
  player.pos = Vec2f(0, 0);
  player.size = Vec2f(pic.width(), pic.height()); // 読み込んだ画像からサイズを取得する
  player.dir = Right;

  while (env.isOpen()) {
    env.begin();

    if (env.isPushKey(GLFW_KEY_A)) {
      player.dir = Left;
    }
    if (env.isPushKey(GLFW_KEY_D)) {
      player.dir = Right;
    }

    drawTextureBox(player.pos.x() + (player.dir * -(player.size.x() * 0.5f)), player.pos.y(),
                   player.size.x(), player.size.y(),
                   0, 0, player.size.x(), player.size.y(),
                   pic, Color::white,
                   0,
                   Vec2f(player.dir, 1),
                   Vec2f::Zero());

    env.end();
  }
}
