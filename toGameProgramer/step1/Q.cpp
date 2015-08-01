
#include "lib/framework.hpp"


int main() {
  AppEnv env(640, 480);

  float a, b, c, d;

  while (env.isOpen()) {
    env.begin();

    a = 0;
    b = 0;
    c = 50;
    d = 50;

    if (env.isPressKey('A')) {
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
    }

    env.end();
  }
}
