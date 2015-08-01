
#include "lib/framework.hpp"


int main() {
  AppEnv env(640, 480);

  // 意味をなさない変数名はやめよう
  // float a, b, c, d;
  
  float x, y;
  float size;
  Color color;

  x = 0;
  y = 0;
  size = 50;
  color = Color::white;

  float speed = 5;

  while (env.isOpen()) {
    env.begin();

    // ここは毎ループ実行される場所なので
    // 初期化は一度だけ実行される場所で行うべき
    // a = 0;
    // b = 0;
    // c = 50;
    // d = 50;

    // 描画と処理がぐっちゃになっている
    // 処理→描画の順番を守ろう
    // += 5, -= 5
    // この5は移動速度を表すものなので変数にしよう
    /*if (env.isPressKey('A')) {
      a -= 5;
    }

    drawFillBox(a, b, c, d, Color(1, 1, 1));

    if (env.isPressKey('D')) {
      a += 5;
    }
    if (env.isPressKey('W')) {
      b += 5;
    }
    if (env.isPressKey('S')) {
      b -= 5;
    }*/

    if (env.isPressKey('A')) { x -= speed; }
    if (env.isPressKey('D')) { x += speed; }
    if (env.isPressKey('W')) { y += speed; }
    if (env.isPressKey('S')) { y -= speed; }

    drawFillBox(x, y, size, size, color);

    env.end();
  }
}
