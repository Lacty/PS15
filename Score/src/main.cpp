
#include "lib/framework.hpp"


int main() {
  AppEnv env(640, 480);
  env.bgColor(Color(0.8f, 0.8f, 0.8f));

  Font font("res/MeiryoConsolas.ttf", 2);
  font.size(100);

  while (env.isOpen()) {
    env.begin();
    
    font.draw("aaa", Vec2f::Zero(), Color::white);

    env.end();
  }
}
