
#include "lib/framework.hpp"


enum {
  Shot_Max = 5,
  Shot_Speed = 10
};

enum Direction {
  Right = 1,
  Left = -1
};

struct Player {
  Vec2f pos;
  Vec2f size;
  Direction dir;
};

struct Shot {
  Vec2f pos;
  Vec2f size;
  Direction dir;
  bool active;
};

int main() {
  AppEnv env(640, 480);
  env.bgColor(Color::white);

  Texture pic("res/right.png");

  Player player;
  player.pos = Vec2f(0, 0);
  player.size = Vec2f(pic.width(), pic.height()); // 読み込んだ画像からサイズを取得する
  player.dir = Right;

  Shot shots[Shot_Max];
  for (int i = 0; i < Shot_Max; ++i) {
    shots[i].active = false;
    shots[i].size = Vec2f(5, 5);
  }

  while (env.isOpen()) {
    env.begin();

    if (env.isPushKey(GLFW_KEY_A)) {
      player.dir = Left;
    }
    if (env.isPushKey(GLFW_KEY_D)) {
      player.dir = Right;
    }

    // 弾の生成
    if (env.isPushKey(GLFW_KEY_SPACE)) {
      for (int i = 0; i < Shot_Max; ++i) {
        if (!shots[i].active) {
          shots[i].dir = player.dir;
          shots[i].pos = player.pos;
          shots[i].active = true;
          break;
        }
      }
    }

    // 弾の移動
    for (int i = 0; i < Shot_Max; ++i) {
      if (shots[i].active) {
        shots[i].pos.x() += (Shot_Speed * shots[i].dir);
      }
    }

    drawTextureBox(player.pos.x() + (player.dir * -(player.size.x() * 0.5f)), player.pos.y(),
                   player.size.x(), player.size.y(),
                   0, 0, player.size.x(), player.size.y(),
                   pic, Color::white,
                   0,
                   Vec2f(player.dir, 1),
                   Vec2f::Zero());

    for (int i = 0; i < Shot_Max; ++i) {
      if (shots[i].active) {
        drawCircle(shots[i].pos.x(), shots[i].pos.y(),
                   shots[i].size.x(), shots[i].size.y(),
                   20, 2, Color::black);
      }
    }

    env.end();
  }
}
